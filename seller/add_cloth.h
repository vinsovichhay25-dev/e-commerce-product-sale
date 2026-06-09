#ifndef ADD_CLOTH_H
#define ADD_CLOTH_H 

#include "../include/cloth_info.h"

#include <iostream>
using namespace std;

void add_cloth(ClothList *seller){
    

    save_to_csv(seller, "data/clothes.csv");
}

#endif