#ifndef ADD_TO_CART_H
#define ADD_TO_CART_H

#include "../include/cloth_info.h"
#include "display_clothes.h"
#include <iostream>
using namespace std;

ClothInfo *find_cloth_by_id(ClothList *list, const string &id){
    if(list == NULL) return NULL;

    ClothInfo *temp = list->head;

    while (temp != NULL){
        if (temp->cloth_id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void insert_cart(ClothList &cart, ClothInfo *item, int quantity){
    ClothInfo *current = cart.head;

    while(current != NULL){
        if(current->cloth_id == item->cloth_id){
            current->cloth_quantity += quantity;
            return;
        }
        current = current->next;
    }

    ClothInfo *newNode = new ClothInfo;

    *newNode = *item; // copy product data

    newNode->cloth_quantity = quantity; 
    newNode->next = NULL;
    newNode->prev = cart.tail;

    if (cart.tail != NULL)
        cart.tail->next = newNode;
    else{
        cart.head = newNode;
    }
    cart.tail = newNode;
    cart.size++;
}

void add_to_cart(ClothList *list, ClothList &cart){
    string id;
    int quantity;
    
    if(list == nullptr || list->head == nullptr){
        cout<<"\n\tNo clothes available!";
        return;
    }
    display_clothes(list);

    cout<<"\nEnter Cloth ID: ";
    cin>>id;

    ClothInfo *item = find_cloth_by_id(list, id);

    if(item == NULL){
        cout<<"\n\t>>> Cloth not found!\n\n";
        cout<<"\n\t>>> Back to System's Menu...";
        return;
    }
    while(true){
        cout<<"Enter quantity: ";
        cin>>quantity;

        if(quantity <= 0){
            cout<<"\n\t>>> Invalid quantity!\n";
            continue;
        }
        if(quantity > item->cloth_quantity){
            cout<<"\n\tNot enough stock! There is only "<<item->cloth_quantity<< " items in the inventory.\n\n";
            continue;
        }
        break;
    }

    item->cloth_quantity -= quantity;

    insert_cart(cart, item, quantity);

    cout<<"\n\tAdded " <<quantity<< " item(s) of " <<item->cloth_name<< " to cart!";

}

#endif
