#ifndef DELETE_CLOTH_H
#define DELETE_CLOTH_H

#include "../include/cloth_info.h"
#include "../include/fileio.h"

#include <iostream>
using namespace std;

void delete_cloth(ClothList *seller){
    

    save_to_csv(seller, "data/clothes.csv");

}

#endif

