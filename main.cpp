#include "include/menu/seller_menu.h"
#include "include/menu/customer_menu.h"
#include "include/cloth_info.h"
#include "include/fileio.h"
#include <iostream>
using namespace std;

int main() {
    ClothList *seller = createClothList();
    ClothList *customer = createClothList();

    int user_choice;
    load_from_csv(seller, "data/clothes.csv");

    do{
        cout<<"================================================"<<endl;
        cout<<"        ONLINE SHOPPING CLOTHES"<<endl;
        cout<<"================================================"<<endl;
        cout<<"1. Seller Mode \n2. Customer Mode \n0. Exit"<<endl;
        
        cout<<"Enter your choice: "; cin>>user_choice;

        switch(user_choice){
            case 1: seller_menu(seller); break;
            case 2: customer_menu(customer); break;
            case 0: cout<<"Exiting the program. Goodbye!"<<endl; break;
            default: cout<<"\tInvalid choice. Please try again."<<endl;
        }
    }while(user_choice != 0);

    save_to_csv(seller, "data/clothes.csv");

    return 0;
}