#include <iostream>
#include <cmath>

enum IdAct{
    ACT_1_SUM_AND_ARITH_MEAN = 1,
    ACT_2_LUCKY_TICKET,
    ACT_3_REVERSE_NUMBERS,
    ACT_4_SUM_OF_ODD_ELEMENTS,
    ACT_5_BEST_DIVIDER    
};

bool getContinueTheProgram(){
    std::string Answer = std::basic_string<char>();
    std::operator>>(std::cin, Answer);
    if(((((std::operator==(Answer, "YES")) || (std::operator==(Answer, "Yes"))) || (std::operator==(Answer, "yes"))) || (std::operator==(Answer, "Y"))) || (std::operator==(Answer, "y"))) {
        return true;
    }
  
    return false;
}

long getNumberOfDigits(long NumValue){
    return static_cast<long>((NumValue == 0 ? 1 : int(log10(static_cast<double>(NumValue)) + 1)));
}

long getSumOfDigitsNum(long NumValue){
    constexpr const int CONST_DIVIDER_TEN = {10};
    long SumNumValue = {0};
    
    for(long ModifyValue = {NumValue}; ModifyValue >= 1; (ModifyValue /= static_cast<long>(CONST_DIVIDER_TEN))){
        SumNumValue += (ModifyValue % static_cast<long>(CONST_DIVIDER_TEN));
    }

    return SumNumValue;
}

int calcSumArithmeticMean(){
    long InputValue = {0};
    std::operator<<(std::operator<<(std::cout, "\n\t'Sum and arithmeric mean numbers'\n\n"), "Please, enter integer value: ");
    std::cin.operator>>(InputValue);
    long SizeValue = {getNumberOfDigits(InputValue)};
    long SumNumValue = {getSumOfDigitsNum(InputValue)};
    std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, "\n"), "Sum of digits: ").operator<<(SumNumValue), ".\n"), "Average of the sum of digits: ").operator<<((SumNumValue / SizeValue)), ".\n");
    return 0;
}

int calcLuckyTicket(){
    constexpr const int CONST_DIVIDER_TEN = {10};
    constexpr const int CONST_DIGIT_CAPACITY_SIX = {6};
    const int CONST_THREE = {static_cast<int>(pow(static_cast<double>(CONST_DIVIDER_TEN), static_cast<double>((CONST_DIGIT_CAPACITY_SIX / 2))))};
    long InputValue = {0};
    std::operator<<(std::cout, "\n\t'Lucky ticket'\n\n");
    
    for(; ; ){
        std::operator<<(std::cout, "Please, enter six value numbers: ");
        std::cin.operator>>(InputValue);
        std::operator<<(std::cout, ".\n");
        long SizeValue = {getNumberOfDigits(InputValue)};
        if(SizeValue == static_cast<long>(CONST_DIGIT_CAPACITY_SIX)) {
            break;
        }

        std::operator<<(std::operator<<(std::operator<<(std::cout, "You entered the wrong number: ").operator<<(InputValue), ".\n"), "Enter new value? [Y/n]: ");
        if(getContinueTheProgram()) {
            std::operator<<(std::cout, ".\n");
            continue;
        }

        return 1;
    }

    long FirstThreeDigits = {getSumOfDigitsNum(InputValue % static_cast<long>(CONST_THREE))};
    long LastThreeDigits = {getSumOfDigitsNum(InputValue / static_cast<long>(CONST_THREE))};
    if(FirstThreeDigits == LastThreeDigits) {
        std::operator<<(std::operator<<(std::cout, "\tYou wins!!!\n Sum first and last digets number ").operator<<(InputValue), " coincided\n");
        return 0;
    }

    std::operator<<(std::operator<<(std::cout, "\tYou lost!!!\nSum first and last digets number ").operator<<(InputValue), " did not match\n");
    return 0;
}

int calcReverseNumber(){
    constexpr const int CONST_DIVIDER_TEN = {10};
    long InputValue = {0};
    std::operator<<(std::operator<<(std::cout, "\n\t'Reverse number'\n\n"), "Please, enter integer value: ");
    std::cin.operator>>(InputValue);
    long ReversValue = {0};

    for(int ModifyValue = {abs(static_cast<int>(InputValue))}; ModifyValue >= 1; ModifyValue /= CONST_DIVIDER_TEN){
        ReversValue *= static_cast<long>(CONST_DIVIDER_TEN);
        ReversValue += (static_cast<long>(ModifyValue % CONST_DIVIDER_TEN));
    }

    ReversValue *= static_cast<long>(((InputValue > 0) ? 1 : -1));
    
    std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, "Input value: ").operator<<(InputValue), "\n"), "Revers value: ").operator<<(ReversValue), "\n");
    return 0;
}

int calcSumOddElements(){
    constexpr const int CONST_MAX_ELEM = {50};
    constexpr const int CONST_MAX_LIM = {90};
    constexpr const int CONST_MIN_LIM = {-60};
    int ArrElement[50];
    std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, "\n\t'Sum of odd numbers'\n\n"), "Please, enter '").operator<<(CONST_MAX_ELEM), "' digits "), " in the range [").operator<<(CONST_MIN_LIM), ":").operator<<(CONST_MAX_LIM), "]\n");
    for(int i = {0}, InputValue = {0}; i < CONST_MAX_ELEM; ++i){
        std::cin.operator>>(InputValue);
        if((InputValue < CONST_MIN_LIM) || (CONST_MAX_LIM < InputValue)) {
            std::operator<<(std::operator<<(std::cout, "Value is out range!\n"), "Do you enter new value? [Y/n]: ");
            if(getContinueTheProgram()) {
                --i;
                continue;
            }
        
        return 1;
        }
        
        ArrElement[i] = InputValue;
    }
    
    std::operator<<(std::cout, "\nSum: ");
    int SumOddvalue = {0};
    for(int i = {0}; i < CONST_MAX_ELEM; ++i){
        if(static_cast<bool>(ArrElement[i] & 1)) {
        SumOddvalue += ArrElement[i];
        std::operator<<(std::cout.operator<<(ArrElement[i]), " + ");
        }
        
    }
    
    std::operator<<(std::operator<<(std::cout, "\b\b= ").operator<<(SumOddvalue), " \n");
    return 0;
}

int calcBestDivider(){
    constexpr const int CONST_MIN_LIM_ONE = {1};
    std::operator<<(std::operator<<(std::cout, "\n\t'Best divider number'\n\n"), "Please, enter any positive natural number greater than one.\n");
    int InputValue = {0};
    for(; ; ){
        std::cin.operator>>(InputValue);
        if(InputValue > CONST_MIN_LIM_ONE) {
            break;
        }
        
        std::operator<<(std::operator<<(std::cout, "You number is less than one\n"), "Do you enter new value? [Y/n]: ");
        if(getContinueTheProgram()) {
            continue;
        }
        
        return 1;
    }
  
    int MaxDivider = {0};
    for(int ModifyDivider = {CONST_MIN_LIM_ONE}; ModifyDivider <= InputValue; ++ModifyDivider){
        if(!static_cast<bool>((InputValue % ModifyDivider))) {
            if(getSumOfDigitsNum(static_cast<long>(ModifyDivider)) >= getSumOfDigitsNum(static_cast<long>(MaxDivider))) {
                MaxDivider = ModifyDivider;
            }      
        }    
    }
  
  std::operator<<(std::operator<<(std::operator<<(std::cout, "Best divider of '").operator<<(InputValue), "' is '").operator<<(MaxDivider), "'\n");
  return 0;
}

int main(){
    std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, "Select the required action from the list\n"), "\t1 - Sum and arithmetic mean of digits.\n"), "\t2 - Lucky ticket.\n"), "\t3 - Reverse number.\n"), "\t4 - Sum of odd elements.\n"), "\t5 - Best divider.\n"), "\n");
    long IdAct = {0};
    std::cin.operator>>(IdAct);
    switch(IdAct) {
    case static_cast<long>(ACT_1_SUM_AND_ARITH_MEAN): calcSumArithmeticMean();
        break;
    case static_cast<long>(ACT_2_LUCKY_TICKET): calcLuckyTicket();
        break;
    case static_cast<long>(ACT_3_REVERSE_NUMBERS): calcReverseNumber();
        break;
    case static_cast<long>(ACT_4_SUM_OF_ODD_ELEMENTS): calcSumOddElements();
        break;
    case static_cast<long>(ACT_5_BEST_DIVIDER): calcBestDivider();
        break;
    default: std::operator<<(std::cout, "You chose the wrong action\n");
        break;
    }
    std::operator<<(std::cout, "Do you want to continue running the program? [Y/n]: ");
    if(getContinueTheProgram()){
    main();
    }

    return 0;
}