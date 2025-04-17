#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>
#include <vector>

bool validDouble(const std::string &str);
std::string addDouble(const std::string &num1, const std::string &num2);
std::vector<std::string> readNumFile(const std::string &filename);
double parse_number(const std::string &expression);

#endif // __CALCULATOR_HPP
