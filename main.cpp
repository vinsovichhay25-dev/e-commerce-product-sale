#include "include/system_menu.h"
#include "include/cloth_info.h"
#include "include/fileio.h"
#include <iostream>
using namespace std;

int main(){
    ClothList *list = createClothList();

    int user_choice;
    load_from_csv(list, "data/clothes.csv");

    do{
        cout<<"\n================================================================================================================================\n";
        cout<<"                                                 WELCOME TO CLOTHING E-COMMERCE SYSTEM\n";
        cout<<"================================================================================================================================\n\n";
        
        cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"1. System Menu \n0. Exit\n";
        cout<<"--------------------------------------------------------------------------------------------------------------------------------\n\n";

        while(true){
            cout<<"Enter your choice: "; cin>>user_choice;

            if(cin.fail()){
                cout<<"\n\tInvalid input! Please enter a number either 1 or 0).\n\n";

                cin.clear();
                cin.ignore(1000, '\n');
            }else if(user_choice <0 || user_choice >1){
                cout<<"\n\tInvalid input! Please enter a number either 1 or 0.\n\n";
                continue;
            }else{
                break;
            }
        }
        switch(user_choice){
            case 1: system_menu(list); break;
            case 0:
                cout<<"\n\tExiting the program. Goodbye!\n\n";
                break;
        }
    }while(user_choice != 0);

    save_to_csv(list, "data/clothes.csv");

    return 0;
}