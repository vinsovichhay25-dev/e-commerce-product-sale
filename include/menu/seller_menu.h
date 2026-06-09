#ifndef SELLER_MENU_H
#define SELLER_MENU_H

#include "../cloth_info.h"

#include "../../seller/add_cloth.h"
#include "../../seller/display_clothes.h"
#include "../../seller/update_cloth.h"
#include "../../seller/delete_cloth.h"
#include "../../seller/search_cloth.h"
#include "../../seller/restock_cloth.h"
#include "../../seller/inventory_report.h"

#include <string>
#include <iostream>
using namespace std;

void seller_menu(ClothList *seller){
    int seller_choice;

    do{
        cout<<"\n\tWelcome to the Seller's Page!\n\n";

        cout<<"==============================================="<<endl;
        cout<<"              SELLER MENU"<<endl;
        cout<<"==============================================="<<endl;

        cout<<endl;
        
        cout<<"1. Add Cloth"<<endl;
        cout<<"2. Display Clothes"<<endl;
        cout<<"3. Update Cloth"<<endl;
        cout<<"4. Delete Cloth"<<endl;
        cout<<"5. Search Cloth"<<endl;
        cout<<"6. Restock Cloth"<<endl;
        cout<<"7. Inventory Report"<<endl;
        cout<<"0. Back to Main Menu"<<endl;
        cout<<"\nEnter your choice: "; cin>>seller_choice;
        
        switch(seller_choice){
            case 1: add_cloth(seller); break;
            case 2: display_clothes(seller); break;
            case 3: update_cloth(seller); break;
            case 4: delete_cloth(seller); break;
            case 5: search_cloth(seller); break;
            case 6: restock_cloth(seller); break;
            case 7: inventory_report(seller, "data/inventory_report.txt"); break;
            case 0: cout<<"\tReturning to Main Menu..."<<endl; break;
            default: cout<<"\tInvalid choice. Please try again."<<endl;
        }
    }while(seller_choice != 0);
}
#endif
