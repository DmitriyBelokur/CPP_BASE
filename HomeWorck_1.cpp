#include <iostream>
#include "cmath"

// User Communication
bool GetContinueTheProgram(){
    std::operator<<(std::cout, "Do you want to continue running the program? [Y/n] ");
    std::string Answer = std::basic_string<char>();
    std::operator>>(std::cin, Answer);
    if(((((std::operator==(Answer, "YES")) || (std::operator==(Answer, "Yes"))) || (std::operator==(Answer, "yes"))) || (std::operator==(Answer, "Y"))) || (std::operator==(Answer, "y"))){
        return true;
    }
    
    return false;
}

// Range Check Functions
long readRangeLimitedValue(std::basic_string<char> valueName, long minLim, long maxLim){
    long userValue;
    for(; ; ){
        std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, "Enter '"), valueName), "' argument in range [").operator<<(minLim), "...").operator<<(maxLim), "]: ");
        std::cin.operator>>(userValue);
        if((minLim <= userValue) && (userValue <= maxLim)){
            return userValue;
        }else{
            std::operator<<(std::cout, "ERROR! Entered value is out of range");
        }    
    }  
}

long readNonZeroValue(std::basic_string<char> valueName){
    constexpr const int CONST_ZERO = {0};
    long userValue;
    for(; ; ){
        std::operator<<(std::operator<<(std::operator<<(std::cout, "Enter '"), valueName), "' argument not equal to ZERO: ");
        std::cin.operator>>(userValue);
        if(userValue != static_cast<long>(CONST_ZERO)) {
            return userValue;
        } else {
            std::operator<<(std::cout, "ERROR! Entered value is out of range");
        }        
    }  
}

int main(){
    constexpr const int FOUMULA_CONST_TWO = {2};
    constexpr const int FOUMULA_CONST_FOUR = {4};
    constexpr const int FOUMULA_MAX_LIM = {255};
    constexpr const int FOUMULA_MIN_LIM = {1};
    std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, "\n The program performs calculation by formulas: "), "\nx1 = (-b + sqrt(b^2 - 4 * a *c)) / (2 * a)"), "\nx2 = (-b - sqrt(b^2 - 4 * a *c)) / (2 * a)"), "\n\n");
    long a = readNonZeroValue(std::basic_string<char>("A", std::allocator<char>()));
    long b = readRangeLimitedValue(std::basic_string<char>("B", std::allocator<char>()), static_cast<long>(FOUMULA_MIN_LIM), static_cast<long>(FOUMULA_MAX_LIM));
    long c = readRangeLimitedValue(std::basic_string<char>("C", std::allocator<char>()), static_cast<long>(-FOUMULA_MAX_LIM), static_cast<long>(-FOUMULA_MIN_LIM));
    long long d = static_cast<long long>((b ^ 2) - ((static_cast<long>(FOUMULA_CONST_FOUR) * a) * c));
    if(d != 0) {
        long divider = static_cast<long>(FOUMULA_CONST_TWO) * a;
        double x1 = static_cast<double>((-b)) + (sqrt(static_cast<double>(d)) / static_cast<double>(divider));
        double x2 = static_cast<double>((-b)) - (sqrt(static_cast<double>(d)) / static_cast<double>(divider));
        std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, "Roots are:\n"), "\tx1 = ").operator<<(x1), "\n"), "\tx2 = ").operator<<(x2), "\n");
    } else {
        std::operator<<(std::cout, "There is no roots. D is equal to ZERO.\n");
    }

    if(GetContinueTheProgram()) {
        main();
    }

    return 0;
}