#include "easyfind.hpp"

void ScalarConverter::convert(const std::string literal)
{
    if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'') {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
        literal == "-inf" || literal == "+inf" || literal == "nan") {
        float f = std::stof(literal);
        double d = std::stod(literal);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    try {
        size_t pos;
        int i = std::stoi(literal, &pos);
        if (pos == literal.length()) {
            if (i >= 32 && i <= 126)
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
            return;
        }
    } catch (...) {}
    
    try {
        size_t pos;
        float f = std::stof(literal, &pos);
        if (literal[pos - 1] == 'f') {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: " << static_cast<int>(f) << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
            return;
        }
    } catch (...) {}
    
    try {
        double d = std::stod(literal);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    } catch (...) {}
    
    std::cout << "Invalid input" << std::endl;
}

int main()
{
    ScalarConverter::convert("'c'");
}