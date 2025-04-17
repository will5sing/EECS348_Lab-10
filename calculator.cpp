#include "calculator.hpp"
#include <fstream>
#include <iostream>
#include <cctype>

std::vector<std::string> readNumFile(const std::string& filename) { //Starts the file open function
    std::vector<std::string> numbers; //Creates the variable of what is taken from the file
    std::ifstream infile(filename); //Opens the given file
    std::string line; //The seperation of the file
    while (std::getline(infile, line)){ //Parses through the file 
        numbers.push_back(line); 
    }
    return numbers;
}

bool validDouble(const std::string& str) { //This is the process of checking if number valid
    int i=0; //Starts the variable i at 0
    int len = str.length(); //start variable length as the length of the string

    if (len == 0) return false; //If the string is empty
    if (str[i] == '+' || str[i] == '-') i++; //Seperates the note if number is positive or negative

    bool fullNum = false; //Checking for full length number
    while( i < len && isdigit(str[i])) { //Iterates through string - num
        fullNum = true; //Changes the string status of full or empty
        i++;
    }
    if (i < len && str[i] == '.'){ //Checks for decimals
        i++;
        bool decimals = false; //Statues of whether a number has decimal or not 
        while( i < len && isdigit(str[i])) { //Iterates through digit
            decimals = true; //Changes status
            i++;
        }
        return fullNum && decimals && i == len; //Adds the number plus the decimal again and the plus or minus
    }
    return fullNum && i == len; //Whole num into the new len
}
std::string padLeft(const std::string& str, size_t totallength) { //This is the function for adding 0's into the length of the number
    return std::string(totallength - str.length(), '0') + str; //Compares the two adds the right amount of 0's
}

std::string addzeroleft(const std::string& a, const std::string& b) { //This is where we use that pad left function
    std::string result = ""; //Creates a new string
    int carry = 0; //Starts variable carry as 0
    int len = std::max(a.length(), b.length()); //the comparison of length from the two given nums
    std::string A = padLeft(a, len); //Correctly adjust the numbers with 0's to match each other
    std::string B = padLeft(b, len);

    for (int i = len - 1; i >= 0; --i) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        carry = sum/ 10;
        result = char((sum % 10)+'0') + result;
    }
    if (carry > 0)
        result = '1' + result;
    return result;
}

std::string addDouble( const std::string& num1, const std::string& num2) {
    std::string n1 = num1, n2 = num2;
    //Checks for negative numbers
    bool neg1 = n1[0] == '-';
    bool neg2 = n2[0] == '-';

    if(n1[0] == '+' || n1[0] == '-') n1 = n1.substr(1); //Finds and removes the +/- in front of the strings
    if(n2[0] == '+' || n2[0] == '-') n2 = n2.substr(1);

    size_t dot1 = n1.find('.');//Splits the number between whole and fraction
    size_t dot2 = n2.find('.');

    std::string int1 = dot1 != std::string::npos ? n1.substr(0, dot1) : n1;
    std::string fraction1 = dot1 != std::string::npos ? n1.substr(dot1 + 1) : "";

    std::string int2 = dot2 != std::string::npos ? n2.substr(0, dot2) : n2;
    std::string fraction2 = dot2 != std::string::npos ? n2.substr(dot2 + 1) : "";

    size_t frac_len = std::max(fraction1.length(), fraction2.length()) ; //Adjust the numbers correctly with the zeroes
    fraction1 += std::string(frac_len - fraction1.length(), '0');
    fraction2 += std::string(frac_len - fraction2.length(), '0');

    std::string frac_sum = addzeroleft(fraction1, fraction2) ; //Adds 0's to fraction part so it can be used in str addition
    bool carry_int = frac_sum.length() > frac_len;
    if (carry_int){
        frac_sum = frac_sum.substr(1);
    }

    std::string int_sum = addzeroleft(int1, int2); //removes any extra 0's so every thing matches
    if (carry_int){
        int_sum = addzeroleft(int_sum, "1");
    }
    return int_sum + '.' + frac_sum;
    

}