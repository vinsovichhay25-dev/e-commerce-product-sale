#ifndef LOAD_FROM_CSV_H
#define LOAD_FROM_CSV_H

#include "../include/cloth_info.h"
#include <fstream>
#include <string.h>
#include <sstream>
#include <iostream>

void load_from_csv(ClothList *list, const string &filename) {
    ifstream file(filename);

    if(!file.is_open()){
        cout<<"\n\tError opening file: "<<filename<<"\n\n";
        return;
    }

    string line;

    while(getline(file, line)){

        if(line == ""){
            continue;
        }
        stringstream ss(line);

        ClothInfo *newCloth = new ClothInfo;

        getline(ss, newCloth->cloth_id, ',');
        getline(ss, newCloth->cloth_name, ',');
        getline(ss, newCloth->cloth_brand, ',');
        getline(ss, newCloth->cloth_category, ',');
        getline(ss, newCloth->cloth_size, ',');
        getline(ss, newCloth->cloth_color, ',');
        getline(ss, newCloth->cloth_material, ',');

        string price_str;
        string stock_str;
        string rating_str;

        getline(ss, price_str, ',');
        getline(ss, stock_str, ',');
        getline(ss, rating_str, ',');

        if(price_str == "" || stock_str == "" || rating_str == "") {
            delete newCloth;
            continue;
        }

        newCloth->cloth_price = stof(price_str);
        newCloth->cloth_quantity = stoi(stock_str);
        newCloth->cloth_rating = stof(rating_str);

        getline(ss, newCloth->cloth_promotion);

        newCloth->next = nullptr;
        newCloth->prev = list->tail;

        if(list->tail != nullptr) {
            list->tail->next = newCloth;
        }else{
            list->head = newCloth;
        }

        list->tail = newCloth;
        list->size++;
    }
    file.close();
}

#endif

