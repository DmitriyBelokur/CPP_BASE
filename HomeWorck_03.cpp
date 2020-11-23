#include <iostream>
#include <string>

enum IdAct{
    ACT_1_REVERS_FOR_STR = 1,
    ACT_2_INSERTING_ELEM,
    ACT_3_REMOVING_ELEM,
    ACT_4_CHARACTER_TRANSLATION_UPPER,
    ACT_5_CHARACTER_TRANSLATION_LOWER,
    ACT_6_SEARCH_NUMBER_IN_STR
};

int calcReversStr(){
    
    char str[100]{};

    std::cin >> str;

    for(int i{0}; i < 100; ++i){
        std::cout << str[i];
    }

    return 0;    
}

int main(){
     std::cout << "Select the required action from the list\n"
        << "\t1 - Revers for str.\n"
        << "\t2 - Inserting an element into an array.\n"
        << "\t3 - Removing an element from an array.\n"
        //<< "\t4 - Sum of odd elements.\n"
        //<< "\t5 - Best divider.\n"
        //<< "\t5 - Best divider.\n"
        << "\n";

    long IdAct{0};
    std::cin >> IdAct;

    switch (IdAct){
    case ACT_1_REVERS_FOR_STR: calcReversStr();
        break;
    case ACT_2_INSERTING_ELEM:
        break;
    case ACT_3_REMOVING_ELEM:
        break;    
    default:
        break;
    }

    return 0;
}