/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2023/08/07 20:42:26 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
    __    _ __             _                          __        __
   / /_  (_) /__________  (_)___     _______  _______/ /_______/ /
  / __ \/ / __/ ___/ __ \/ / __ \   / ___/ / / / ___/ //_/ ___/ / 
 / /_/ / / /_/ /__/ /_/ / / / / /  (__  ) /_/ / /__/ ,< (__  )_/  
/_.___/_/\__/\___/\____/_/_/ /_/  /____/\__,_/\___/_/|_/____(_) 

*/

#include "BitcoinExchange.hpp"

#include <map>
#include <time.h>
#include <string>
#include <sstream>

#include <iomanip>
#include <iostream>
#include <fstream>

#include <regex>

time_t  parseDate(const std::string& date)
{
    if (date.length() != 10)
    {
        throw DateParseException();
    }

    // screw performance, use regex to validate input
    if (std::regex_match(date, std::regex("\\d\\d\\d\\d-\\d\\d-\\d\\d")) == false)
    {
        throw DateParseException();
    }

    std::tm tm = {};

    // cheeky error checking using strptime
    // also parses the date.
    if (strptime(date.c_str(), "%F", &tm) == NULL)
    {
        throw DateParseException();
    }

    return timegm(&tm); // convert to unix timestamp
}

std::pair<const time_t, float> parseLine(const std::string& line)
{
    size_t pos;
    time_t date;

    pos = line.find(" | ");
    if (pos != 10) {
        throw ParseException("bad input => " + line);
    }

    date = parseDate(line.substr(0, pos));

    std::string valueStr = line.substr(pos + 3);

    if (!is_valid_double_format(valueStr.c_str()))
    {
        throw ParseException("value is formatted incorrectly");
    }

    float value = 0.0f;
    try
    {
        value = stof(valueStr);
    }
    catch (const std::exception& e)
    {
        throw ParseException("value invalid or out of range");
    }

    if (value < 0.0f || value > 1000.0f)
    {
        throw ParseException("value out of range");
    }

    return std::pair<const time_t, float>(date, value);

}

float tryFindEntryExchangeRate(const std::map<time_t, float>& xchangerate, time_t timestamp)
{
    static constexpr time_t day = 60 * 60 * 24; // 60 minutes * 60 seconds * 24 hours

    while (timestamp >= xchangerate.begin()->first)
    {
        auto it = xchangerate.find(timestamp);
        if (it != xchangerate.end()) {
            return it->second;
        }
        timestamp -= day;
    }

    throw ParseException("date not found in database!");
    return -1.0f;
}

int main(int argc, char **argv)
{
    std::map<time_t, float> xchangerate;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }


    std::ifstream dbfile;
    dbfile.open("data.csv", std::ios::in);
    
    std::string line;
    std::getline(dbfile, line); // skip first line
    do
    {
        std::getline(dbfile, line);

        try
        {
            auto pair = xchangerate.insert( { parseDate(line.substr(0, 10)), stof(line.substr(11)) } );
            //std::cout << pair.first->first << ": " << pair.first->second << "\n";
            (void)pair;
        }
        catch (const DateParseException& e)
        {
            break;
        }

    }
    while (!dbfile.eof());
    dbfile.close();

    std::ifstream inputFile;
    inputFile.open(argv[1]);

    if (inputFile.fail()) {
        std::cerr << "IO error\n";
        return 1;
    }

    std::getline(inputFile, line);
    if (line != "date | value") {
        std::cerr << "good day sunshine, invalid first line of input file, must be ``date | value\".\n";
        return 1;
    }

    while (std::getline(inputFile, line))
    {
        try
        {
            auto pair = parseLine(line);

            float rate = tryFindEntryExchangeRate(xchangerate, pair.first);

            std::cout << line.substr(0, 10) << " => " << pair.second << " = " << pair.second * rate << "\n";

        }
        catch (const ParseException& e)
        {
            std::cerr << e.what() << "\n";
        }
    }

    if (inputFile.bad()) {
        std::cerr << "IO Error\n";
        inputFile.close();
        return 1;
    }

    inputFile.close();

    return 0;
}
