#ifndef RESTOCK_CLOTH_H
#define RESTOCK_CLOTH_H

#include "../include/cloth_info.h"
#include "../include/fileio.h"

#include <iostream>
using namespace std;

void restock_cloth(ClothList *seller){
    
    string id;
    int quantity;
    bool isFound = false;

    cout<<"Enter ClothID to restock: "; cin>>id;

    while(true){
        cout<<"Enter quantity to add: "; cin>>quantity;

        if(quantity<=0 || cin.fail()){
            cout<<"\n\tInvalid quantity.\n\n";

            cin.clear();
            cin.ignore(1000, '\n');
        }else break;
    }

    ClothInfo *current = seller->head;

    while(current != nullptr){
        if(current->cloth_id == id){
            current->cloth_stock_quantity += quantity;

            cout<<"\n\tCloth Restock Successfully.\n\n";

            isFound = true;
            break;
        }
        current = current->next;
    }
    if(!isFound){
        cout<<"\n\tCloth ID is not found.\n";
    }
    
    save_to_csv(seller, "data/clothes.csv");
}

#endif
