#ifndef UPDATE_CLOTH_H
#define UPDATE_CLOTH_H

#include "../include/cloth_info.h"
#include <iomanip>
#include <iostream>
using namespace std;

void currentCloth(ClothList *list){
    if(list == nullptr || list->head == nullptr){
        cout<<"\n\tNo clothes available!";
        return;
    }
    cout<<"\n================================================================================================================================\n";
    cout<<"                                                 CURRENT INFORMATION\n";
    cout<<"================================================================================================================================\n\n";
    
    cout<<left
        <<setw(8)<<"ID"
        <<setw(20)<<"Name"
        <<setw(15)<<"Brand"
        <<setw(15)<<"Category"
        <<setw(8)<<"Size"
        <<setw(12)<<"Color"
        <<setw(15)<<"Material"
        <<setw(10)<<"Price"
        <<setw(8)<<"Stock"
        <<setw(8)<<"Rating"
        <<setw(15)<<"Promotion"
        <<endl;

    cout<<string(128, '-')<<endl;

    ClothInfo *current = list->head;

    while (current != nullptr){
        cout<<left
            <<setw(8)<<current->cloth_id
            <<setw(20)<<current->cloth_name
            <<setw(15)<<current->cloth_brand
            <<setw(15)<<current->cloth_category
            <<setw(8)<<current->cloth_size
            <<setw(12)<<current->cloth_color
            <<setw(15)<<current->cloth_material
            <<setw(10)<<fixed<<setprecision(2)<<current->cloth_price
            <<setw(8)<<current->cloth_quantity
            <<setw(8)<<current->cloth_rating
            <<setw(15)<<current->cloth_promotion
            <<endl;

        current = current->next;
    }

    cout<<string(128, '-');
    cout<<"\n\n";
}

void update_cloth(ClothList *list){
    string updateId;
    bool updateFound = false;

    currentCloth(list);

    if(list == nullptr || list->head == nullptr){
        return;
    }

    cout<<"Enter Cloth ID to update: ";
    cin>>updateId;

    ClothInfo *current = list->head;

    while(current != nullptr){
        if(current->cloth_id == updateId){
            updateFound = true;
            break;
        }
        current = current->next;
    }

    if(!updateFound){
        cout<<"\n\tCloth ID is not found!";
        return ;
    }

    int updateChoice;

    cout<<"\n============================================== UPDATE OPTIONS ==================================================================\n\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";
    
    cout<<"\t1. Update Price\n";
    cout<<"\t2. Update Stock Quantity\n";
    cout<<"\t3. Update Promotion\n";
    cout<<"\t0. Back to System's Menu\n";

    cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";
    
    while(true){
        cout<<"Enter your choice: "; 
        cin>>updateChoice;

        if(cin.fail()){
            cout<<"\n\tInvalid choice! Please enter a number between 0-3.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }else if(updateChoice < 0 || updateChoice > 10){
            cout<<"\n\tInvalid choice! Please enter a number between 0-3.\n";
            continue;
        }
        break;
    }
    switch(updateChoice){
        case 1: {
            while(true){
                cout<<"Enter new Price: "; 
                cin>>current->cloth_price;

                if(cin.fail()){
                    cout<<"\n\tInvalid price! Price must be a float number.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }else if(current->cloth_price < 0){
                    cout<<"\n\tInvalid price! Price is a non-negative value.\n";
                    continue;
                }
                break;
            }
            break;
        }
        case 2: {
            while(true){
                cout<<"Enter new Stock Quantity: "; 
                cin>>current->cloth_quantity;
            
                if(cin.fail()){
                    cout<<"\n\tInvalid Stock Quantity! Stock Quantity must be an integer number.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }else if(current->cloth_quantity < 0){
                    cout<<"\n\tInvalid Stock Quantity! Stock Quantity is a non-negative value.\n";
                    continue;
                }
                break;
            }
            break;
        }
        case 3: {
            while(true){
                cout<<"Enter new Promotion : ";                
                cin>>current->cloth_promotion;

                if(cin.fail()) {
                    cout<<"\n\tInvalid input! Please enter a number (e.g. 10%, 15%, 20%).\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                if(current->cloth_promotion == "None"){
                    break;
                }
                if(current->cloth_promotion.back() != '%') {
                    cout<<"\n\tInvalid format! Use % symbol.\n";
                    continue;
                }
                break;
            }
            break;  
        }
        case 0:{
            cout<<"\n\tReturning back to the Seller's Menu....";
            break;
        }
    }

    cout<<"\n\tCloth updated successfully!";
}

#endif