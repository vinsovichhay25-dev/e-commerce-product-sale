#ifndef VIEW_CART_H
#define VIEW_CART_H

#include "../include/cloth_info.h"

#include <iostream>
#include <iomanip>
using namespace std;

void view_cart(ClothList &cart){
    if (cart.head == NULL){
        cout<<"\n\tCart is empty!";
        return;
    }
    cout<<"\n============================================================\n";
    cout<<"                         YOUR CART\n";
    cout<<"============================================================\n";

    cout <<left
         <<setw(10)<<"ID"
         <<setw(20)<<"Name"
         <<setw(10)<<"Quantity"
         <<setw(12)<<"Price"
         <<setw(15)<<"Subtotal"
         <<endl;

    cout<<"------------------------------------------------------------\n";

    ClothInfo *temp = cart.head;
    float total = 0;

    while (temp != NULL){
        float subtotal = temp->cloth_price * temp->cloth_quantity;
        total += subtotal;

        cout <<left
             <<setw(10)<<temp->cloth_id
             <<setw(20)<<temp->cloth_name
             <<setw(10)<<temp->cloth_quantity
             <<setw(12)<<temp->cloth_price
             <<setw(15)<<subtotal
             <<endl;
        temp = temp->next;
    }

    cout<<"------------------------------------------------------------\n";
    cout<<"                      TOTAL: " <<total<< endl;
    cout<<"============================================================\n\n";
}

#endif