/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2023/08/07 15:02:27 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <iostream>
#include <iomanip>
#include <chrono>

#include "PmergeMe.hpp"

template <typename T>
void print_container(const T& vec)
{
    if (vec.size() < 1)
    {
        throw std::exception();
    }

    auto e = vec.begin();
    for (; e + 1 != vec.end(); e++)
    {
        std::cout << *e << ", ";
    }
    std::cout << *e << std::endl;
}

// returns false if one of the chars in string s is not a decimal, or the string is empty
static bool isAllDecimals(const std::string& s)
{
    if (s.length() == 0)
    {
        return false;
    }

    for (auto c : s)
    {
        if (std::isdigit(c) == false)
        {
            return false;
        }
    }
    return true;
}


static void processArg(std::vector<int>& res, const char *argCstr)
{
    std::string arg = std::string(argCstr);
    size_t posBegin = 0;
    size_t posEnd = 0;

    while (true)
    {
        posBegin = arg.find_first_not_of(' ', posEnd);
        if (posBegin == std::string::npos)
        {
            // the string is empty. Unacceptable
            if (posEnd == 0)
            {
                throw std::exception();
            }
            break;
        }
        posEnd = arg.find_first_of(' ', posBegin);
        std::string currentNumber = arg.substr(posBegin, posEnd - posBegin);
        
        if (!isAllDecimals(currentNumber))
        {
            throw std::exception(); // "Invalid arguments"
        }

        res.push_back(stoi(currentNumber));
    }
}

static void fillNumberVector(std::vector<int>& vec, int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        processArg(vec, argv[i]);
    }
}

int main(int argc, char **argv)
{
    std::vector<int>        vec;
    std::deque<int>         deq;

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <string of integers to sort>\n";
        return 1;
    }
    try
    {
        fillNumberVector(vec, argc, argv);
        if (vec.size() < 1)
        {
            throw std::exception();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Invalid arguments\n";
        return 1;
    }

    std::cout << "Before: ";
    print_container(vec);


    deq.resize(vec.size());

    // copy to deq
    std::copy(vec.begin(), vec.end(), deq.begin());


    const auto beforeVecSort = std::chrono::high_resolution_clock::now();
    FordJohnsonSort(vec, 0, vec.size() - 1);
    const auto afterVecSort = std::chrono::high_resolution_clock::now();
    auto duration = afterVecSort - beforeVecSort;
    auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

    std::cout << "After:  ";
    print_container(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
        << std::fixed << std::setprecision(3) // set to float with 3 decimals
        << static_cast<long double>(elapsed_time.count()) / 1000.0 << " µs" << std::endl;


    const auto beforeDeqSort = std::chrono::high_resolution_clock::now();
    FordJohnsonSort(deq, 0, deq.size() - 1);
    const auto afterDeqSort = std::chrono::high_resolution_clock::now();
    duration = afterDeqSort - beforeDeqSort;
    elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque:  "
        << static_cast<long double>(elapsed_time.count()) / 1000.0 << " µs" << std::endl;

    return 0;
}
