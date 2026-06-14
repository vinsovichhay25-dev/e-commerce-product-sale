#ifndef DISPLAY_CLOTHES_H
#define DISPLAY_CLOTHES_H

#include "../include/cloth_info.h"
#include <iostream>
#include <iomanip>

using namespace std;

void display_clothes(ClothList *list) {

    if(list == nullptr || list->head == nullptr){
        cout<<"\n\tNo clothes available!";
        return;
    }else{
        cout<<"\n\t"<<list->size<<" cloth(s) in inventory.\n";
    }

    cout << "\n================================================================================================================================\n";
    cout << "                                                 CLOTHING INVENTORY\n";
    cout << "================================================================================================================================\n";

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

    while (current != nullptr) {

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
}

#endif