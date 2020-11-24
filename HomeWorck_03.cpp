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

struct MenuAction {    
    char title[200];
    void (*handler)();
};

void actStringReverse() {
    constexpr int STR_MAX_LEN {10};
    char inStr[STR_MAX_LEN]; 

    printf("Enter your string [MAX_LEN: %d]: ", STR_MAX_LEN-2); // 2 chars are: user \n from console and \0
    fflush(stdin);
    fgets(inStr, STR_MAX_LEN, stdin);
    
    auto inStrLen = std::strlen(inStr);    
    inStr[inStrLen-1] = '\0'; // removing user console \n from tail of the string
    inStrLen--; // recalulating string lenght
    printf("You entered: '%s'\n", inStr);
    
    char swpBuff {};

    for (size_t leftIdx=0, rightIdx=inStrLen-1; leftIdx < rightIdx; leftIdx++, rightIdx--) {
        swpBuff = inStr[leftIdx];
        inStr[leftIdx] = inStr[rightIdx];
        inStr[rightIdx] = swpBuff;
    }

    printf("Reverse string are: '%s'\n", inStr);
}

void anotherAction() {
    std::cout << "Doing some other action\n";
}

int calcReversStr(){
    MenuAction actionsMenu[] = {
        {"Reverse string", actStringReverse},
        {"Action 2", anotherAction}
    };        
    
    const auto ACTIONS_COUNT {std::size(actionsMenu)};

    std::cout << "Choose action:\n";
    for (int i=0; i< ACTIONS_COUNT; i++) {
        std::cout << '[' << i+1 << "] " << actionsMenu[i].title << '\n';        
    }    

    int choose {0};    
    while (true) {
        std::cout << "> ";
        std::cin >> choose;

        if (choose > 0 && choose <= ACTIONS_COUNT) {
            std::cout << "Performing action: " << actionsMenu[choose-1].title << '\n';            
            actionsMenu[choose-1].handler();
            break;
        } else {        
            std::cout << "ERR!!! Wrong action id. Let's try again\n";            
        }        
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