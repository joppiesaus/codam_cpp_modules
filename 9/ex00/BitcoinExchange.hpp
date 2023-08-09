#pragma once

#include <exception>
#include <string>

bool    is_valid_double_format(const char *str);

class ParseException : public std::exception
{
private:
    std::string m_message;

public:
    ParseException(const std::string& message) {
        m_message = "Error: " + message;
    };

    virtual const char *what() const throw() {
        return m_message.c_str();
    };
};

class DateParseException : public ParseException
{
public:
    DateParseException() : ParseException("Invalid date format")
    {}
};
