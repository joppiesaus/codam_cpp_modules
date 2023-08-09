#include "BitcoinExchange.hpp"

// ha nothing here, except some util functions and the message that BITCOIN SUCKS!!!
// slower than a dial-up modem, only 7 transactions tops,
// yet consumes gigawatts of power and produces mountains of e-waste

static void	skip_whitespace(const char **str)
{
	while (std::isspace(**str))
	{
		(*str)++;
	}
}

// stolen from my fract-ol
// WARNING: has been modified, does NOT accept + or -
bool	is_valid_double_format(const char *str)
{
	const char	*str_before_numberskip;
	int			number_before_dot;

	skip_whitespace(&str);
	str_before_numberskip = str;
	while (std::isdigit(*str))
		str++;
	number_before_dot = str_before_numberskip < str;
	if (*str == 0 && number_before_dot)
		return (true);
	if (*str != '.')
		return (false);
	str++;
	str_before_numberskip = str;
	while (std::isdigit(*str))
		str++;
	if (str_before_numberskip == str && !number_before_dot)
		return (false);
	skip_whitespace(&str);
	return (*str == 0);
}
