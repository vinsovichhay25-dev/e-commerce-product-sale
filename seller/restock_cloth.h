#ifndef RESTOCK_CLOTH_H
#define RESTOCK_CLOTH_H

#include "../include/cloth_info.h"

#include <iostream>
using namespace std;

void restock_cloth(ClothList *seller){
    

    save_to_csv(seller, "data/clothes.csv");
}

#endif
