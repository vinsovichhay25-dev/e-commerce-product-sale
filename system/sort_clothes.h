#ifndef SORT_CLOTHES_H
#define SORT_CLOTHES_H

#include "../include/cloth_info.h"
#include <iostream>
using namespace std;

void swapClothData(ClothInfo *a, ClothInfo *b){
    swap(a->cloth_id, b->cloth_id);
    swap(a->cloth_name, b->cloth_name);
    swap(a->cloth_brand, b->cloth_brand);
    swap(a->cloth_category, b->cloth_category);
    swap(a->cloth_size, b->cloth_size);
    swap(a->cloth_color, b->cloth_color);
    swap(a->cloth_material, b->cloth_material);
    swap(a->cloth_price, b->cloth_price);
    swap(a->cloth_stock_quantity, b->cloth_stock_quantity);
    swap(a->cloth_rating, b->cloth_rating);
    swap(a->cloth_promotion, b->cloth_promotion);
}

void sort_clothes(ClothList *list){

    if(list == nullptr || list->head == nullptr){
        cout << "\nNo data available to sort!\n";
        return;
    }

    int choice;

    cout<<"\n============================================================ SORT CLOTH OPTIONS ==========================================================================================\n\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    
    cout << "\t1. Sort by ID (Ascending)\n";
    cout << "\t2. Sort by Name (A-Z)\n";
    cout << "\t3. Sort by Price (Low-High)\n";
    cout << "\t4. Sort by Rating (High-Low)\n";
    cout << "\t5. Sort by Stock Quantity (Low-High)\n";
    cout<<"\t0. Back to System's Menu\n";

    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
   
    while(true){
        cout<<"Enter your choice: ";
        cin>>choice;

        if(cin.fail()){
            cout<<"\n\tInvalid choice! Please enter a number between 0-5.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }else if(choice < 0 || choice > 5){
            cout<<"\n\tInvalid choice! Please enter a number between 0-5.\n";
            continue;
        }
        break;
    }

    bool swapped;

    do{
        swapped = false;

        ClothInfo *current = list->head;

        while(current->next != nullptr){

            bool needSwap = false;

            switch(choice){
                case 1: {
                    int id1 = stoi(current->cloth_id.substr(1));
                    int id2 = stoi(current->next->cloth_id.substr(1));

                    if(id1 > id2){
                        needSwap = true;
                    }
                    break;
                }
                case 2:
                    if(current->cloth_name > current->next->cloth_name){
                        needSwap = true;
                    }
                    break;
                case 3:
                    if(current->cloth_price > current->next->cloth_price){
                        needSwap = true;
                    }
                    break;
                case 4:
                    if(current->cloth_rating < current->next->cloth_rating){
                        needSwap = true;
                    }
                    break;

                case 5:
                    if(current->cloth_stock_quantity > current->next->cloth_stock_quantity){
                        needSwap = true;
                    }
                    break;
                default:
                    cout<<"\n\tInvalid choice!\n"<<endl;
                    return;
            }

            if(needSwap){
                swapClothData(current, current->next);
                swapped = true;
            }

            current = current->next;
        }

    }while(swapped);

    cout<<"\n\tSorting completed successfully!\n\n";
}

#endif