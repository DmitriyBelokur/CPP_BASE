#include <iostream>
#include <random>
#include <cmath>

bool getContinueTheProgram() {
	std::string Answer;
	std::cin >> Answer;

    if((Answer == "YES")||(Answer == "Yes")||(Answer == "yes")||(Answer == "Y")||(Answer == "y")){
        return true;    
    }

    return false;
}

long getNumberOfDigits(long NumValue){    
    return (NumValue == 0? 1: int (log10 (NumValue) + 1));
}

long getSumOfDigitsNum(long NumValue){
    constexpr auto CONST_DIVIDER_TEN{10};
    long SumNumValue{0};

    for(auto ModifyValue{NumValue}; ModifyValue >= 1; (ModifyValue/=CONST_DIVIDER_TEN)){
        SumNumValue += ModifyValue%CONST_DIVIDER_TEN;
    }

    return SumNumValue;
}

int calcSumArithmeticMean(){
    long InputValue{0};
    
    std::cout << "\n\t'Sum and arithmeric mean numbers'\n\n"
        << "Please, enter integer value: ";
    std::cin >> InputValue;
    
    auto SizeValue{getNumberOfDigits(InputValue)};    
    auto SumNumValue{getSumOfDigitsNum(InputValue)};
    
    std::cout << "\n"
        << "Sum of digits: " << SumNumValue << ".\n"
        << "Average of the sum of digits: " << (SumNumValue/SizeValue) << ".\n";

    return 0;
}

int calcLuckyTicket(){
    constexpr auto CONST_DIVIDER_TEN{10};
    constexpr auto CONST_DIGIT_CAPACITY_SIX{6};
    const auto CONST_THREE{static_cast<int>(pow(CONST_DIVIDER_TEN,(CONST_DIGIT_CAPACITY_SIX/2)))};
   
    long InputValue{0};
    
    std::cout << "\n\t'Lucky ticket'\n\n";

    for(;;){
        std::cout << "Please, enter six value numbers: ";
        std::cin >> InputValue;
        std::cout << ".\n";

        auto SizeValue{getNumberOfDigits(InputValue)};
        
        if(SizeValue == CONST_DIGIT_CAPACITY_SIX){
            break;
        }

        std::cout << "You entered the wrong number: " << InputValue << ".\n"
                << "Enter new value? [Y/n]: ";
        if(getContinueTheProgram()){
            std::cout << ".\n"; 
            continue;
        }        
        
        return 1; 
    }

    auto FirstThreeDigits{getSumOfDigitsNum(InputValue % CONST_THREE)};
    auto LastThreeDigits{getSumOfDigitsNum(InputValue / CONST_THREE)};  
    
    if(FirstThreeDigits == LastThreeDigits){
        std::cout << "\tYou wins!!!\n Sum first and last digets number " << InputValue << " coincided\n";
        return 0;
    }
    
    std::cout << "\tYou lost!!!\n Sum first and last digets number " << InputValue << " did not match\n";
    return 0;
}

int calcReverseNumber(){
    constexpr auto CONST_DIVIDER_TEN{10};

    long InputValue{0};
    
    std::cout << "\n\t'Reverse number'\n\n"
              << "Please, enter integer value: ";
    std::cin >> InputValue;
    
    long ReversValue{0};

    for(auto ModifyValue{abs(InputValue)}; 
        ModifyValue >= 1;
        ModifyValue/=CONST_DIVIDER_TEN){
            ReversValue*=CONST_DIVIDER_TEN;
            ReversValue += ModifyValue % CONST_DIVIDER_TEN;
    }

    ReversValue *= ((InputValue > 0)? 1 : -1);;
    std::cout << "Input value: " << InputValue << "\n"
        << "Revers value: " << ReversValue << "\n";
    
    return 0;
}

int calcSumOddElements(){
    constexpr auto CONST_MAX_ELEM{50};
    constexpr auto CONST_MAX_LIM{90};
    constexpr auto CONST_MIN_LIM{-60};

    int ArrElement[CONST_MAX_ELEM];

    std::cout << "\n\t'Sum of odd numbers'\n\n"
        << "Please, enter '" << CONST_MAX_ELEM << "' digits "
        << " in the range [" << CONST_MIN_LIM << ":" << CONST_MAX_LIM << "]\n";
        
    for(int i{0}, InputValue{0}; i < CONST_MAX_ELEM; ++i){
        std::cin >> InputValue;  

        if(InputValue < CONST_MIN_LIM || CONST_MAX_LIM < InputValue){
            std::cout << "Value is out range!\n"
                << "Do you enter new value? [Y/n]: ";

            if(getContinueTheProgram()){
                --i;
                continue;        
            }       

            return 1;      
        }

        ArrElement[i] = InputValue;
    }

    std::cout <<  "\nSum: ";  
    int SumOddvalue{0};
    for(int i{0}; i < CONST_MAX_ELEM; ++i){

        if(ArrElement[i]&1){
            SumOddvalue += ArrElement[i];
            std::cout << ArrElement[i] << " + ";
        }    
    }

    std::cout << "\b\b= " << SumOddvalue <<  " \n";
    return 0;
}

int calcBestDivider(){
    constexpr auto CONST_MIN_LIM_ONE{1};    
    
    std::cout << "\n\t'Best divider number'\n\n"
        << "Please, enter any positive natural number greater than one.\n";

    int InputValue{0};
    
    for(;;){
        std::cin >> InputValue;

        if(InputValue > CONST_MIN_LIM_ONE){
            break;
        }
       
        std::cout << "You number is less than one\n"
            << "Do you enter new value? [Y/n]: ";

        if(getContinueTheProgram()){
            continue;        
        }       

        return 1;         
    }    

    auto MaxDivider{InputValue - 1};
    for(;; MaxDivider -= 1){
        if(!(InputValue % MaxDivider)){
            break;
        }
    }

    std::cout << "Best divider of '" << InputValue << "' is '" << MaxDivider << "'\n";
    return 0;
}

int main(){

    std::cout << "Select the required action from the list\n"
        << "\t1 - Sum and arithmetic mean of digits.\n"
        << "\t2 - Lucky ticket.\n"
        << "\t3 - Reverse number.\n"
        << "\t4 - Sum of odd elements.\n"
        << "\t5 - Best divider.\n"
        << "\n"
        ;
            
    long IdAct{0};
    std::cin >> IdAct;

    switch (IdAct){
    case 1:
        calcSumArithmeticMean();
        break;
    case 2:
        calcLuckyTicket();
        break;
    case 3:
        calcReverseNumber();
        break;
    case 4:
        calcSumOddElements();
        break;
    case 5:
        calcBestDivider();
        break;
    default:
        std::cout << "You chose the wrong action\n";
        break;
    }

    std::cout << "Do you want to continue running the program? [Y/n]: ";
    
    if (getContinueTheProgram()){
        main();
    }

    return 0;
}