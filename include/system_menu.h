#ifndef SYSTEM_MENU_H
#define SYSTEM_

#include "cloth_info.h"

#include "../system/add_cloth.h"
#include "../system/display_clothes.h"
#include "../system/update_cloth.h"
#include "../system/delete_cloth.h"
#include "../system/search_cloth.h"
#include "../system/restock_cloth.h"
#include "../system/sort_clothes.h"
#include "../system/inventory_report.h"

#include <string>
#include <iostream>
using namespace std;

void system_menu(ClothList *list){
    int user_choice;

    do{
        cout<<"\n================================================================================================================================\n";
        cout<<"                                                 WELCOME TO SYSTEM MENU\n";
        cout<<"================================================================================================================================\n";

        cout<<"\n--------------------------------------------------------------------------------------------------------------------------------\n";

        cout<<"1. Add Cloth"<<endl;
        cout<<"2. Display Clothes"<<endl;
        cout<<"3. Update Cloth"<<endl;
        cout<<"4. Delete Cloth"<<endl;
        cout<<"5. Search Cloth"<<endl;
        cout<<"6. Sorting Cloth"<<endl;
        cout<<"7. Restock Cloth"<<endl;
        cout<<"8. Inventory Report"<<endl;
        cout<<"0. Back to System Menu"<<endl;

        cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";

        while(true){
            cout<<"Enter your choice: "; 
            cin>>user_choice;

            if(cin.fail()){
                cout<<"\n\tInvalid input! Please enter a number between 0-8.\n\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            if(user_choice < 0 || user_choice > 7){
                cout<<"\n\tInvalid input! Please enter a number between 0-8.\n\n";
                continue;
            }else{
                break;
            }
        }
        switch(user_choice){
            case 1: add_cloth(list); break;
            case 2: display_clothes(list); break;
            case 3: update_cloth(list); break;
            case 4: delete_cloth(list); break;
            case 5: search_cloth(list); break;
            case 6: sort_clothes(list); break;
            case 7: restock_cloth(list); break;
            case 8: inventory_report(list, "data/inventory_report.txt"); break;
            case 0: cout<<"\n\tReturning to Main Menu...\n"; break;
        }
    }while(user_choice != 0);
}
#endif
