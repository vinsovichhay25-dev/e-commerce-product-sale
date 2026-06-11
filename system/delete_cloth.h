#ifndef DELETE_CLOTH_H
#define DELETE_CLOTH_H

#include "../include/cloth_info.h"
#include "../include/fileio.h"

#include <iostream>
using namespace std;

bool deleteNode(ClothList *list,ClothInfo *current,bool &found_delete){
    if(current->prev != nullptr){
        current->prev->next = current->next;
    }else{
        list->head = current->next;
    }

    if(current->next != nullptr){
        current->next->prev = current->prev;
    }else{
        list->tail = current->prev;
    }

    delete current;

    list->size--;

    found_delete = true;

    return true;
}

void delete_cloth(ClothList *list){
    if(list == nullptr || list->head == nullptr){
        cout<<"No clothes available to delete."<<endl;
        return;
    }
    int seller_choice;

    cout<<"\n============================================== DELETE OPTIONS ==================================================================\n\n";
    
    cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"\t1. Delete by Cloth ID\n";
    cout<<"\t2. Delete Out-of-Stock Items\n";
    cout<<"\t3.. Delete by Brand\n";
    cout<<"0. Back to System Menu\n";

    cout<<"--------------------------------------------------------------------------------------------------------------------------------\n\n";

    while(true){
        cout<<"Enter your choice: "; cin>>seller_choice;

        if(cin.fail()){
            cout<<"\n\tInvalid input! Please enter a number between 0-3.\n\n";

            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if(seller_choice < 0 || seller_choice > 4){
            cout<<"\n\tInvalid input! Pleae enter a number betweeen 0-3.\n\n";
            continue;
        }else{  
            break;
        }
    }

    bool found_delete = false;

    switch(seller_choice){
        case 1:{
            string delete_id;
            cout<<"Enter cloth ID: ";
            cin>>delete_id;

            ClothInfo *current = list->head;

            while(current != nullptr){
                if(current->cloth_id == delete_id){
                    deleteNode(list, current, found_delete);
                    cout<<"\n\tCloth deleted successfully.\n\n";
                    save_to_csv(list, "data/clothes.csv");
                    return;
                }
                current = current->next;
            }
            cout<<"Cloth ID not found.\n";
            break;
        }
        case 2:{
            ClothInfo *current = list->head;

            while(current != nullptr){

                ClothInfo *nextNode = current->next;

                if(current->cloth_stock_quantity<=0){
                    deleteNode(list, current, found_delete);
                }
                current = nextNode;
            }

            if(found_delete){
                cout<<"\n\tOut-of-stock items deleted.\n\n";
                save_to_csv(list, "data/clothes.csv");
            }else{
                cout<<"\n\tNo out-of-stock items found.\n\n";
            }
            break;
        }

        case 3:{
            string brand;
            cout<<"Enter brand: ";
            cin>>brand;

            ClothInfo *current=list->head;

            while(current != nullptr){

                ClothInfo *nextNode = current->next; 

                if(current->cloth_brand == brand){
                    deleteNode(list, current, found_delete);
                }

                current = nextNode;
            }
            if(found_delete){
                cout<<"\n\tAll clothes from brand deleted.\n\n";
                save_to_csv(list,"data/clothes.csv");
            }else{
                cout<<"\n\tNo clothes found for brand.\n\n";
            }
            break;
        }

        case 0:{
            cout<<"\n\tReturning to Seller Menu...\n\n";
            return;
        }
    }
}

#endif