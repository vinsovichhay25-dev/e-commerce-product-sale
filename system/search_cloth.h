#ifndef SEARCH_CLOTH_H
#define SEARCH_CLOTH_H

#include "../include/cloth_info.h"

#include <iomanip>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

void print_header(){

    cout<<"\n================================================================================================================================\n";
    cout<<"                                                 CLOTH DISPLAY BY SEARCH\n";
    cout<<"================================================================================================================================\n";

    cout<<left
        <<setw(10)<<"ID"
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

    cout<<string(128,'-')<<endl;
}

void display_cloth(ClothInfo *cloth){
    cout <<left
         <<setw(10)<<cloth->cloth_id
         <<setw(20)<<cloth->cloth_name
         <<setw(15)<<cloth->cloth_brand
         <<setw(15)<<cloth->cloth_category
         <<setw(8)<<cloth->cloth_size
         <<setw(12)<<cloth->cloth_color
         <<setw(15)<<cloth->cloth_material
         <<setw(10)<<fixed<<setprecision(2)<<cloth->cloth_price
         <<setw(8)<<cloth->cloth_quantity
         <<setw(8)<<cloth->cloth_rating
         <<setw(15)<<cloth->cloth_promotion
         <<endl;
}
void search_cloth(ClothList *list){
    
    int choice;
    bool isFound = false;

    if(list == nullptr || list->head == nullptr){
        cout<<"\n\tNo clothes available!";
        return;
    }

    cout<<"\n================================================ SEARCH OPTIONS ==========================================================\n\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"\t1. Search by Cloth ID \n";
    cout<<"\t2. Search by Brand \n";
    cout<<"\t3. Search by Price range\n";
    cout<<"\t0. Back to System's Menu\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";

    while(true){

        cout<<"Enter your choice: "; 
        cin>>choice;

        if(cin.fail()){
            cout<<"\n\tInvalid input! Please enter a number between 0-3.\n\n";
            
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if(choice < 0 || choice > 3){
            cout<<"\n\tInvalid input! Please enter a number between 0-3.\n\n";
            continue;
        }else{
            break;
        }
    }
    switch(choice){
        case 1: {
            string id;
            bool idFound = false;
            cout<<"Enter a Cloth's ID to search: "; cin>>id;

            ClothInfo *current = list->head;

            while(current != nullptr){
                if(current->cloth_id == id){
                    cout<<"\n\tCloth's ID is found!";
                    idFound = true;
                    break;
                }
                current = current->next;
            }
            if(!idFound){
                cout<<"\n\tCloth's ID is not found!";
                return;
            }

            print_header();

            while(current != nullptr){
                if(current->cloth_id == id){
                    display_cloth(current);
                    break;
                }
                current = current->next;
            }
            
            cout<<string(128,'-')<<endl<<endl<<endl;
            break;
        }
        case 2: {
            string brand;
            bool brandFound = false;
            cout<<"Enter a Cloth's Brand to search: "; cin>>brand;

            ClothInfo *current = list->head;

            while(current != nullptr){
                if(current->cloth_brand == brand){
                    cout<<"\n\tCloth's Brand is found!";
                    brandFound = true;
                    break;
                }
                current = current->next;
            }
            if(!brandFound){
                cout<<"\n\tCloth's Brand is not found!";
                return;
            }

            print_header();

            current = list->head;
            while(current != nullptr){
                if(current->cloth_brand == brand){
                    display_cloth(current);
                }
                current = current->next;
            }
            cout<<string(128,'-')<<endl<<endl<<endl;
            break;
        }
        case 3: {
            float minPrice, maxPrice;
            bool priceFound = false;

            while(true){
                cout<<"Enter minimum price: ";
                cin>>minPrice;

                if(cin.fail()){
                    cout<<"\n\tInvalid input! Please enter an integer number.";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                if(minPrice<0){
                    cout<<"\n\tPrice cannot be negative!";
                    continue;
                }else{
                    break;
                }
            }
            while(true){
                cout<<"Enter maximum price: ";
                cin>>maxPrice;

                if(cin.fail()){
                    cout<<"\n\tInvalid input! Enter a number.\n\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                if(maxPrice<0){
                    cout<<"\n\tPrice cannot be negative!";
                    continue;
                }else{
                    break;
                }
            }

            if(minPrice > maxPrice){
                cout<<"\n\tInvalid range! Minimum price cannot be greater than maximum price.";
                break;
            }

            ClothInfo *current = list->head;

            cout<<"\n\tClothes between "<<minPrice<< " and " <<maxPrice<< ":";

            while(current != nullptr){
                if(current->cloth_price >= minPrice && current->cloth_price <= maxPrice){
                    priceFound = true;
                    break;
                }
                current = current->next;
            }
            if (!priceFound) {
                cout<<"\n\tNo clothes found in this price range.";
                return;
            }            
            
            print_header();

            while(current != nullptr){
                if(current->cloth_price >= minPrice && current->cloth_price <= maxPrice){

                    display_cloth(current);
                    priceFound = true;
                }
                current = current->next;
            }
            cout << string(128, '-')<<endl<<endl<<endl;
            break;
        }
        case 0: {
            cout<<"\t\nReturning to the Seller's Menu...";
            break;
        }   
    }
}
#endif
