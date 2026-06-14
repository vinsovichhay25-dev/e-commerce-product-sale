#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "../include/cloth_info.h"
#include <iostream>
#include <iomanip>
using namespace std;

void checkout(ClothList *list, ClothList &cart){
    if (cart.head == NULL){
        cout<<"\n\tCart is empty!";
        return;
    }

    float total = 0;

    cout<<"\n============================================================\n";
    cout<<"                      CHECKOUT BILL\n";
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
    cout<<"                      TOTAL: $" << total << endl;
    cout<<"\n----------------------- PAYMENT -----------------------------\n";

    float payment;
    while(true){
        cout<<"Enter payment amount $: ";
        cin>>payment;

        if(cin.fail() || payment <= 0){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"\n\t>>> Invalid payment!\n\n";
            continue;
        }
        if(payment < total){
            cout<<"\n\t>>> Insufficient payment! Checkout cancelled.\n\n";
            continue;
        }
        break;
    }

    float change = payment - total;

    cout<<"\n\t>>> Payment successful!\n";
    cout<<"\n\t>>> Change: $" <<change<<"";

    temp = cart.head;

    while (temp != NULL){
        ClothInfo *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    cart.head = NULL;
    cart.tail = NULL;
    cart.size = 0;

    cout<<"\n\t>>> Thank you for your purchase!";
}

#endif