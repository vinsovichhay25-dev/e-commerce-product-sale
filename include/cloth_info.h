#ifndef CLOTH_INFO_H
#define CLOTH_INFO_H

#include <iostream>
#include <string>
using namespace std;

struct ClothInfo {
    string cloth_id;
    string cloth_name;
    string cloth_brand;
    string cloth_category;
    string cloth_size;
    string cloth_color;
    string cloth_material;
    float cloth_price;
    int cloth_stock_quantity;
    float cloth_rating;
    string cloth_promotion;
    ClothInfo *next;
    ClothInfo *prev;
};

struct ClothList{
    int size;
    ClothInfo *head;
    ClothInfo *tail;
};

ClothList *createClothList(){
    ClothList *list = new ClothList;
    
    list->size = 0;
    list->head = nullptr;
    list->tail = nullptr;
    return list;
};

#endif