#ifndef ADD_CLOTH_H
#define ADD_CLOTH_H 

#include "../include/cloth_info.h"

#include <string.h>
#include <iostream>
using namespace std;

void add_cloth(ClothList *list){
    string cloth_id;
    string cloth_name;
    string cloth_brand;
    string cloth_category;
    string cloth_size;
    string cloth_color;
    string cloth_material;
    float cloth_price;
    int cloth_stock_quantity;
    float cloth_rating;
    string cloth_promotion;

    int clothQuantity;

    while(true){
        cout<<"\tHow many cloth do you want to add? : ";
        cin>>clothQuantity;

        if(cin.fail() || clothQuantity < 0){
            cout<<"\n\tInvalid input! Please enter an integer number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }
    if(clothQuantity == 0){
        cout<<"\t\nNo cloth is added.";
        return;
    }
    for(int i=0; i<clothQuantity; i++){
        ClothInfo *newCloth = new ClothInfo;

        cout<<"------------------------------------------------ #" <<i+1<<  "Cloth added into inventory -------------------------------------------------\n\n";

        cin.ignore(1000, '\n');
        cout<<"Enter cloth_id: "; getline(cin,cloth_id);
        cout<<"Enter cloth_name: "; getline(cin,cloth_name);
        cout<<"Enter cloth_brand: "; getline(cin,cloth_brand);
        cout<<"Enter cloth_category: "; getline(cin,cloth_category);
        cout<<"Enter cloth_size: "; getline(cin,cloth_size);
        cout<<"Enter cloth_color: "; getline(cin,cloth_color);
        cout<<"Enter cloth_material: "; getline(cin,cloth_material);
        
        while(true){
            cout<<"Enter cloth_price: "; 
            cin>>cloth_price;

            if(cin.fail() || cloth_price <= 0){
                cout<<"\n\tInvalid input! Price must be an integer and positive.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } 
            break;
        }

        while(true){
            cout<<"Enter cloth_quantity: "; 
            cin>>cloth_stock_quantity;

            if(cin.fail() || cloth_stock_quantity <= 0){
                cout<<"\n\tInvalid input! Stock must be a non-negative number and can't be string!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } 
            break;
        }

        while(true){
            cout<<"Enter cloth_rating: ";          
            cin>>cloth_rating;

            if(cin.fail() || cloth_rating <= 0 || cloth_rating > 5){
                cout<<"\n\tInvalid input! Rate can't be string and has to be between 0.0 and 5.0\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            break;
        }

        while(true){
            cout<<"Enter cloth_promotion: "; 
            cin>>cloth_promotion;

            if(cin.fail()) {
                cout<<"\n\tInvalid input! Please enter a number (e.g. 10%, 15%, 20%).\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            if(cloth_promotion == "None"){
                break;
            }
            if(cloth_promotion.back() != '%') {
                cout<<"\n\tInvalid format! Use % symbol.\n";
                continue;
            }
            break;
        }

        newCloth->cloth_id = cloth_id;
        newCloth->cloth_name = cloth_name;
        newCloth->cloth_brand = cloth_brand;
        newCloth->cloth_category = cloth_category;
        newCloth->cloth_size = cloth_size;
        newCloth->cloth_color = cloth_color;
        newCloth->cloth_material = cloth_material;
        newCloth->cloth_price = cloth_price;
        newCloth->cloth_quantity = cloth_stock_quantity;
        newCloth->cloth_rating = cloth_rating;
        newCloth->cloth_promotion = cloth_promotion;

        cout<<"\t\nCloth added successfully!\n";

        newCloth->next = nullptr;
        newCloth->prev = list->tail;

        if(list->tail != nullptr){
            list->tail->next = newCloth; 
        }else{
            list->head = newCloth;
        }
        list->tail = newCloth;
        list->size++;
    }
}
#endif