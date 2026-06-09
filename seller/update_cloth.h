#ifndef UPDATE_CLOTH_H
#define UPDATE_CLOTH_H

#include "../include/cloth_info.h"

#include <iostream>
using namespace std;

void update_cloth(ClothList *seller){
 
    
    save_to_csv(seller, "data/clothes.csv");
}

#endif