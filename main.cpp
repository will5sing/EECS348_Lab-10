#include <iostream>
#include "calculator.hpp"

int main(int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "File Error" << argv[0] << "<filenanme>\n" ; //error checking for proper file
        return 1; 
    }
    std::string filename = argv[1]; //takes file variable
    std::vector<std::string> numbers = readNumFile(filename); //Opens the file 
    std::string fixedDouble = "-123.456"; //The fixed number that is added to all numbers

    for(const std::string& num : numbers) { //Checking if the number is a double or not 
        if(validDouble(num)) {
            std::string result = addDouble(num, fixedDouble); //Adds the num and the fixed number
            std::cout << "Valid" << num << "+" << fixedDouble << "=" << result << std::endl; //If valid we print
        } else {
            std::cout << "Invalid Num:" << num << std::endl; //If invalid prints
        }
    }
    return 0; //Ends main
}
