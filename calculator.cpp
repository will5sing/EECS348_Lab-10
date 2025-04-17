#include "calculator.hpp"
#include <fstream>
#include <iostream>
#include <cctype>

std::vector<std::string> readNumFile(const std::string& filename) { //Starts the file open function
    std::vector<std::string> numbers; //Creates the variable of what is taken from the file
    std::ifstream infile(filename); //Opens the given file
    std::string line; //The seperation of the file
    while (std::getline(infile, line)){ //Parses through the file 
        numbers.pushback(line); 
    }
    return numbers;
}

bool validDouble(const std::string& str) { //This is the process of checking if number valid
    int i=0; //Starts the variable i at 0
    int len = str.length(); //start variable length as the length of the string

    if (len == 0) return false; //If the string is empty
    if (str[i] == '+' || str[i] == '-') i++; //Seperates the note if number is positive or negative

    bool fullNum = false; //
    while( i < len && isdigit(str[i])) {
        fullNum = true;
        i++;
    }
    if (i < len && str[i] == '-'){
        i++;
        bool decimals = false
        while( i < len && isdigit(str[i])) {
            decimals = true;
            i++;
        }
        return fullNum && decimals && i == len;
    }
    return fullNum && i == len;
}

std::string addzeroleft(const std::string& a, const std::string& b) {
    std::string result = "";
    int carry = 0;
    int len = std::max(a.length(), b.length());

    for (int i = len - 1; i >= 0; --i) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry
        carry = sum/ 10;
        result = char((sum % 10)+'0') + result;
    }
    if (carry > 0)
        result = '1' + result;
    return result;
}

std::string addDouble( const std::string& num1, const std::string& num2) {
    std::string n1 = num1, n2 = num2;
    bool neg1 = n1[0] == '-';
    bool neg2 = n2[0] == '-';
    if(n1[0] == '+' || n1[0] == '-') n1 = n1.substr
    if(n2[0] == '+' || n2[0] == '-') n2 = n2.substr

    size_t dot1 = n1.find('.');
    size_t dot2 = n2.find('.');

    std::string int1 = dot1 != std::string:spoz ? n1.substr(0, dot1) : n1;
    std::string fraction1 = dot1 != std::string:spoz ? n1.substr(dot1 + 1) : "";

    std::string int2 = dot2 != std::string:spoz ? n2.substr(0, dot2) : n2;
    std::string fraction2 = dot2 != std::string:spoz ? n2.substr(dot2 + 1) : "";

    size_t frac_len = std::max(fraction1.length(), fraction2.length()) ;
    fraction1 += std::string(fran_len - fraction1.length(), '0');
    fraction2 += std::string(fran_len - fraction2.length(), '0');

    std::string frac_sum = addPosStr(fraction1, fraction2) ;
    bool carry_int = frac_sum.length() > frac_len;
    if (carry_int)
        frac_sum = frac_sum.substr(1);

    std::string intSum
}