#ifndef DELETE_CLOTH_H
#define DELETE_CLOTH_H

#include "../include/cloth_info.h"

#include <string>
#include <cctype>
#include <iostream>
using namespace std;

void lwr(string &s){
    for(char &c : s){
        c = tolower(c);
    }
}

bool deleteNode(ClothList *list, ClothInfo *current, bool &found_delete){
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
        cout<<"\n\tNo clothes available to delete!";
        return;
    }

    int choice;

    cout<<"\n============================================== DELETE OPTIONS ==================================================================\n\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";

    cout<<"\t1. Delete by Cloth ID\n";
    cout<<"\t2. Delete Out-of-Stock Items\n";
    cout<<"\t3. Delete by Brand\n";
    cout<<"\t0. Back to System Menu\n";

    cout << "--------------------------------------------------------------------------------------------------------------------------------\n\n";

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
        }

        break;
    }

    bool found_delete = false;

    switch(choice){

        case 1:{
            string delete_id;

            cout<<"Enter cloth ID: ";
            cin>>delete_id;

            ClothInfo *current = list->head;

            while(current != nullptr){

                if(current->cloth_id == delete_id){

                    string confirm;

                    cout<<"Are you sure you want to delete this cloth? (yes/no): ";
                    cin>>confirm;

                    lwr(confirm);

                    if(confirm == "yes"){
                        deleteNode(list, current, found_delete);
                        cout<<"\n\tCloth deleted successfully.\n";
                    }
                    else{
                        cout<<"\n\tDeletion cancelled.\n";
                    }

                    return;
                }

                current = current->next;
            }

            cout<<"\n\tCloth ID not found.\n\n";
            break;
        }

        case 2:{
            string confirm;

            cout<<"Are you sure you want to delete ALL out-of-stock items? (yes/no): ";
            cin>>confirm;

            lwr(confirm);

            if(confirm != "yes"){
                cout<<"\n\tDeletion cancelled.\n";
                break;
            }

            ClothInfo *current = list->head;

            while(current != nullptr){

                ClothInfo *nextNode = current->next;

                if(current->cloth_quantity <= 0){
                    deleteNode(list, current, found_delete);
                }

                current = nextNode;
            }

            if(found_delete){
                cout<<"\n\tOut-of-stock items deleted successfully.\n";
            }
            else{
                cout<<"\n\tNo out-of-stock items found.\n";
            }

            break;
        }

        case 3:{
            string brand;

            cout<<"Enter brand: ";
            cin>>brand;

            string confirm;

            cout<<"Are you sure you want to delete all clothes from brand \"" 
                <<brand<< "\"? (yes/no): ";
            cin >> confirm;

            lwr(confirm);

            if(confirm != "yes"){
                cout<<"\n\tDeletion cancelled.\n";
                break;
            }

            ClothInfo *current = list->head;

            while(current != nullptr){

                ClothInfo *nextNode = current->next;

                if(current->cloth_brand == brand){
                    deleteNode(list, current, found_delete);
                }

                current = nextNode;
            }

            if(found_delete){
                cout<<"\n\tAll clothes from brand deleted successfully.\n";
            }
            else{
                cout<<"\n\tNo clothes found for brand \"" <<brand<< "\".\n";
            }

            break;
        }

        case 0:{
            cout<<"\n\tReturning to System Menu...\n\n";
            return;
        }
    }
}

#endif