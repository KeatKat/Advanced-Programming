
#include "Functions.h"

int main(){
    char back;
    do{

        int choice = mainMenuOptions();

        switch (choice)
        {
        case 1: 
            optionOne();
            break;
        case 2: 
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        case 5:
            optionFive();
            break;
        case 6:
            optionSix();
            break;
        }

        if(choice == 7){
            break;
        }
        if(choice == 5) {
            cout << "Press any key to return to the main menu..." << endl;
            back = getchar();
            while(getchar() != '\n'){}
        }
       
    }while(true);

    return 0;
}