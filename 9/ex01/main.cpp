/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/28 19:34:21 by jobvan-d      #+#    #+#                 */
/*   Updated: 2023/08/02 19:28:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack>
#include <iostream>

int main(int argc, char **argv)
{
    std::stack<int> numbers;

    try
    {
        if (argc != 2)
        {
            throw ParseException();
        }

        parseArgs(std::string(argv[1]), numbers);
    }
    catch (const ParseException& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
