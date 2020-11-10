#include <iostream>
#include "cmath"

// User Communication
bool GetContinueTheProgram() {

	std::cout << "Do you want to continue running the program? [Y/n] ";

	std::string Answer;
	std::cin >> Answer;

    if((Answer == "YES")||(Answer == "Yes")||(Answer == "yes")||(Answer == "Y")||(Answer == "y")){
        return true;    
    }

    return false;

}
// Range Check Functions
long readRangeLimitedValue(std::string valueName, long minLim, long maxLim){

    long userValue;

    for(;;){
        std::cout << "Enter '" << valueName << "' argument in range [" << minLim << "..." << maxLim << "]: ";
        std::cin >> userValue; 

        if((minLim <= userValue) && (userValue <= maxLim)){
            return userValue;
        }else{
            std::cout << "ERROR! Entered value is out of range";
        }    
    }
}

long readNonZeroValue(std::string valueName){

    constexpr auto CONST_ZERO{0};
    long userValue;

    for (;;){
        std::cout << "Enter '" << valueName << "' argument not equal to ZERO: ";
        std::cin >> userValue;
        
        if(userValue != CONST_ZERO){
            return userValue;
        }else{
            std::cout << "ERROR! Entered value is out of range";
        }
    }

}

int main(){ 

    constexpr auto FOUMULA_CONST_TWO{2};
    constexpr auto FOUMULA_CONST_FOUR{4};

    constexpr auto FOUMULA_MAX_LIM{255};
    constexpr auto FOUMULA_MIN_LIM{1};
    
    std::cout << "\n The program performs calculation by formulas: "
                << "\nx1 = (-b + sqrt(b^2 - 4 * a *c)) / (2 * a)"
                << "\nx2 = (-b - sqrt(b^2 - 4 * a *c)) / (2 * a)"
                << "\n\n";

    auto a = readNonZeroValue("A");
    auto b = readRangeLimitedValue("B", FOUMULA_MIN_LIM, FOUMULA_MAX_LIM);
    auto c = readRangeLimitedValue("C", -FOUMULA_MAX_LIM, -FOUMULA_MIN_LIM);

    long long d = (b^2) - (FOUMULA_CONST_FOUR * a * c);
    
    if(d != 0){

        long divider = FOUMULA_CONST_TWO * a;

        double x1 = (-b) + sqrt(d) / divider;
        double x2 = (-b) - sqrt(d) / divider;

        std::cout << "Roots are:\n" 
            << "\tx1 = " << x1 << "\n"
            << "\tx2 = " << x2 << "\n"; 
    }else{
        std::cout << "There is no roots. D is equal to ZERO.\n";
    }

    if (GetContinueTheProgram()){
        main();
    }
    return 0;
}