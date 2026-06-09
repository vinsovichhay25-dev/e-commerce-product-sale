#ifndef CUSTOMER_MENU_H
#define CUSTOMER_MENU_H

#include "../cloth_info.h"
    
#include "../../customer/view_clothes.h"
#include "../../customer/add_to_cart.h"
#include "../../customer/remove_from_cart.h"
#include "../../customer/search_clothes.h"
#include "../../customer/filter_clothes.h"
#include "../../customer/sort_clothes.h"
#include "../../customer/view_cart.h"
#include "../../customer/checkout.h"

#include <iostream>
using namespace std;

void customer_menu(ClothList *list){
    int customer_choice;

    do{
        cout<<"\n\tWelcome to the Customer's Page!"<<endl;
            
        cout<<"==============================================="<<endl;
        cout<<"              CUSTOMER MENU"<<endl;
        cout<<"==============================================="<<endl;

        cout<<"1. View Clothes"<<endl;
        cout<<"2. Search Clothes"<<endl;
        cout<<"3. Filter Clothes"<<endl;
        cout<<"4. Sort Clothes"<<endl;
        cout<<"5. Add to Cart"<<endl;
        cout<<"6. Remove from Cart"<<endl;
        cout<<"7. View Cart"<<endl;
        cout<<"8. Checkout"<<endl;
        cout<<"0. Back to Main Menu"<<endl;

        cout<<"\nEnter your choice: ";   cin>>customer_choice;
    
        switch(customer_choice){
            case 1: view_clothes(list); break;
            case 2: search_clothes(list); break;
            case 3: filter_clothes(list); break;
            case 4: sort_clothes(list); break;
            case 5: add_to_cart(list); break;
            case 6: remove_from_cart(list); break;
            case 7: view_cart(list); break;
            case 8: checkout(list); break;
            case 0: cout<<"\tReturning to Main Menu..."<<endl; break;
            default: cout<<"\tInvalid choice. Please try again."<<endl;
        }
    }while(customer_choice != 0);
}

#endif