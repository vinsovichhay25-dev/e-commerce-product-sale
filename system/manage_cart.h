#ifndef MANAGE_CART_H
#define MANAGE_CART_H

#include "../include/cloth_info.h"

#include <iostream>
using namespace std;

void manage_cart(ClothList *list, ClothList &cart){
    if(cart.head == nullptr){
        cout<<"\n\t>>> Cart is Empty!";
        return;
    }
    int choice;

    cout<<"\n============================================================\n";
    cout<<"\t1. Reduce Quantity\n";
    cout<<"\t2. Remove Cloth Permanantly\n";
    cout<<"\t0. Back to System's Menu\n";
    cout<<"============================================================\n";

    while(true){
        cout<<"Enter your choice: ";
        cin>>choice;

        if(cin.fail()){
            cout<<"\n\t>>> Invalid choice! Please enter a number between 0-2.";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }else if(choice < 0 || choice > 2){
            cout<<"\n\t>>> Invalid choice! Please enter a number between 0-2.";
            continue;
        }
        break;
    }
    
    ClothInfo *current = cart.head;

    switch(choice){
        case 1:{
            int removeQuantity;
            string findID;
            bool isFound = false;

            while(true){
                cout<<"Enter an ID to reduce Quantity: ";
                cin>>findID;

                current = cart.head;
                isFound = false;

                while(current != nullptr){
                    if(current->cloth_id == findID){
                        isFound = true;
                        break;
                    }
                    current = current->next;
                }
                if(isFound){
                    break;
                }

                cout<<"\n\t>>> Cloth ID not found! Try again.";
            }            
            while(true){
                cout<<"Enter quantity to reduce: ";
                cin>>removeQuantity;

                if(removeQuantity <= 0){
                    cout<<"\n\t>>> Invalid quantity!";
                    continue;
                }
                if(removeQuantity > current->cloth_quantity){
                    cout<<"\n\t>>> You can not reduce the quantity! You only have " <<current->cloth_quantity<< " in cart!\n\n";
                    continue;
                }
                break;
            }
            current->cloth_quantity = current->cloth_quantity - removeQuantity;
            
            ClothInfo *inventory = list->head;

            while(inventory != NULL){
                if(inventory->cloth_id == findID){
                    inventory->cloth_quantity += removeQuantity;
                    break;
                }
                inventory = inventory->next;
            }
            cout<<"\n\t>>> Removed " <<removeQuantity<< " item(s) from cart!";
            
            if(current->cloth_quantity == 0){
                if(current->prev){
                    current->prev->next = current->next;
                }else{
                    cart.head = current->next;
                }
                if(current->next){
                    current->next->prev = current->prev;
                }else{
                    cart.tail = current->prev;
                }
                delete current;
            }
            break;
        }
        case 2:{
            string id;
            cout<<"Enter Cloth ID to remove from cart: ";
            cin>>id;
            
            bool isFound = false;

            while(current != nullptr){
                if(current->cloth_id == id){
                    isFound = true;
                    break;
                }
                current = current->next;
            }
            if(!isFound){
                cout<<"\n\t>>> Item not found in cart!";
                return;
            }else{
                int quantity = current->cloth_quantity;

                // restore inventory stock
                ClothInfo *inventory = list->head;

                while(inventory != NULL){
                    if(inventory->cloth_id == id){
                        inventory->cloth_quantity += quantity;
                        break;
                    }
                    inventory = inventory->next;
                }

                if(current->prev != nullptr){
                    current->prev->next = current->next;
                }else{
                    cart.head = current->next; 
                }

                if(current->next != nullptr){
                    current->next->prev = current->prev;
                }else{
                    cart.tail = current->prev;
                }

                delete current;
                cart.size--;
                
                cout<<"\n\t>>> Item removed from cart successfully!";
                break;
            }
        }
        case 0:{
            cout<<"\n\tBack to System's Menu...";
            break;
        }
    }
}

#endif