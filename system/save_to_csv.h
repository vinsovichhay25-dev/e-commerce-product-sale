#ifndef SAVE_TO_CSV
#define SAVE_TO_CSV

#include "../include/cloth_info.h"
#include <fstream>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;

void save_to_csv(ClothList *list,const string &filename){
    ofstream file(filename);

    if(!file.is_open()){
        cout<<"Error opening file: "<<filename<<endl;
        return;
    }

    ClothInfo *current = list->head;

    while(current!=nullptr){
        file<<current->cloth_id<<","
            <<current->cloth_name<<","
            <<current->cloth_brand<<","
            <<current->cloth_category<<","
            <<current->cloth_size<<","
            <<current->cloth_color<<","
            <<current->cloth_material<<","
            <<current->cloth_price<<","
            <<current->cloth_quantity<<","
            <<current->cloth_rating<<","
            <<current->cloth_promotion
            <<endl;

        current=current->next;
    }
    file.close();
    cout<<"\n\t>>> All datas have just saved in csv file!.\n\n";

}
#endif
