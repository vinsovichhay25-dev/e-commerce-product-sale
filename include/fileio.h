#ifndef FILE_IO_H
#define FILE_IO_H

#include "cloth_info.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void load_from_csv(ClothList *list, const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout<<"Error opening file: "<<filename<<endl;
        return;
    }
    string line;

    getline(file, line);
    stringstream ss(line);

    ClothInfo *newCloth = new ClothInfo;

    getline(ss, newCloth->cloth_id, ',');
    getline(ss, newCloth->cloth_name, ',');
    getline(ss, newCloth->cloth_brand, ',');
    getline(ss, newCloth->cloth_category, ',');
    getline(ss, newCloth->cloth_size, ',');
    getline(ss, newCloth->cloth_color, ',');
    getline(ss, newCloth->cloth_material, ',');

    string price_str, stock_str, rating_str;
    getline(ss, price_str, ',');
    getline(ss, stock_str, ',');
    getline(ss, rating_str, ',');

    newCloth->cloth_price = stof(price_str);
    newCloth->cloth_stock_quantity = stoi(stock_str);
    newCloth->cloth_rating = stof(rating_str);

    getline(ss, newCloth->cloth_promotion, ',');
    newCloth->next = nullptr;
    newCloth->prev = list->tail;

    if(list->tail != nullptr){
        list->tail->next = newCloth;
    }else{
        list->head = newCloth;
    }
    list->tail = newCloth;
    list->size++;

    file.close();
}

 void save_to_csv(ClothList *list, const string &filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    ClothInfo *tmp = list->head;

    while (tmp != nullptr) {
        file <<tmp->cloth_id<<","
             <<tmp->cloth_name<<","
             <<tmp->cloth_brand<< ","
             <<tmp->cloth_category<< ","
             <<tmp->cloth_size<<","
             <<tmp->cloth_color<<","
             <<tmp->cloth_material<<","
             <<tmp->cloth_price<<","
             <<tmp->cloth_stock_quantity<<","
             <<tmp->cloth_rating<<","
             <<tmp->cloth_promotion
             <<endl;
        tmp = tmp->next;   
    }
    file.close();
}
#endif