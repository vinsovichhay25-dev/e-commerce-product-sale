#ifndef ADD_CLOTH_H
#define ADD_CLOTH_H 

#include "../include/cloth_info.h"
#include "../include/fileio.h"

#include <iostream>
using namespace std;

void add_cloth(ClothList *seller){
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
        cout<<"How many cloth do you want to add? : ";
        cin>>clothQuantity;

        cout<<endl;

        if(cin.fail() || clothQuantity < 0){
            cout<<"\tInvalid input value. Please try again!"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }else break;
    }
        if(clothQuantity == 0){
            cout<<"\tNo cloth is added."<<endl;
            return;
        }
        for(int i=0; i<clothQuantity; i++){
            ClothInfo *newCloth = new ClothInfo;

            cout<<"Enter cloth_id: "; cin>>cloth_id;
            cout<<"Enter cloth_name: "; cin>>cloth_name;
            cout<<"Enter cloth_brand: "; cin>>cloth_brand;
            cout<<"Enter cloth_category: "; cin>>cloth_category;
            cout<<"Enter cloth_size: "; cin>>cloth_size;
            cout<<"Enter cloth_color: "; cin>>cloth_color;
            cout<<"Enter cloth_material: "; cin>>cloth_material;
            
            while(true){
                cout<<"Enter cloth_price: "; 
                cin>>cloth_price;

                if(cin.fail() || cloth_price <= 0){
                    cout<<"\tInvalid input! Price must be an integer and positive."<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }else break;
            }

            while(true){
                cout<<"Enter cloth_stock_quantity: "; 
                cin>>cloth_stock_quantity;

                if(cin.fail() || cloth_stock_quantity <= 0){
                    cout<<"\tInvalid input! Stock must be a non-negative number and can't be string!"<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }else break;
            }

            while(true){
                cout<<"Enter cloth_rating: ";          
                cin>>cloth_rating;

                if(cin.fail() || cloth_rating <= 0 || cloth_rating > 5){
                    cout<<"\tInvalid input! Rate can't be string and has to be between 0.0 and 5.0 "<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }else break;
            }
            
            cout<<"Enter cloth_promotion: "; cin>>cloth_promotion;

            newCloth->cloth_id = cloth_id;
            newCloth->cloth_name = cloth_name;
            newCloth->cloth_brand = cloth_brand;
            newCloth->cloth_category = cloth_category;
            newCloth->cloth_size = cloth_size;
            newCloth->cloth_color = cloth_color;
            newCloth->cloth_material = cloth_material;
            newCloth->cloth_price = cloth_price;
            newCloth->cloth_stock_quantity = cloth_stock_quantity;
            newCloth->cloth_rating = cloth_rating;
            newCloth->cloth_promotion = cloth_promotion;

            newCloth->next = nullptr;
            newCloth->prev = seller->tail;

            if(seller->tail != nullptr){
                seller->tail->next = newCloth; 
            }else{
                seller->head = newCloth;
            }
            seller->tail = newCloth;
            seller->size++;
        }

    save_to_csv(seller, "data/clothes.csv");
}

#endif