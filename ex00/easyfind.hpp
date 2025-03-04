#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(const std::string str);
};

#endif