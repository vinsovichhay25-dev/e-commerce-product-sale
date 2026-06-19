#ifndef INVENTORY_REPORT_H
#define INVENTORY_REPORT_H

#include "../include/cloth_info.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void inventory_report(ClothList *list, const string &filename) {
    ofstream file(filename);

    if (!file.is_open()){
        cout << "Error: Cannot open report file!"<<endl;
        return;
    }

    file <<"============================ INVENTORY REPORT ===========================\n\n";

    file << left
         << setw(10)<<"ID"
         << setw(20)<<"Name"
         << setw(15)<<"Brand"
         << setw(10)<<"Price"
         << setw(10)<<"Stock"
         << setw(10)<<"Rating"
         << endl;

    file<<"-----------------------------------------------------------------------\n";

    if (list->head == nullptr){
        file<<"\n\tNo inventory data available.\n";
        file.close();
        cout<<"\n\tReport generated (empty inventory).\n";
        return;
    }

    ClothInfo *temp = list->head;

    int totalItems = 0;
    int totalStock = 0;

    while (temp != nullptr){
        file << left
             << setw(10)<<temp->cloth_id
             << setw(20)<<temp->cloth_name
             << setw(15)<<temp->cloth_brand
             << setw(10)<<temp->cloth_price
             << setw(10)<<temp->cloth_quantity
             << setw(10)<<temp->cloth_rating
             << endl;

        totalItems++;
        totalStock += temp->cloth_quantity;

        temp = temp->next;
    }

    file<<"-----------------------------------------------------------------------\n";

    file<<"\nTotal Products: " <<totalItems<<endl;
    file<<"Total Stock: " <<totalStock <<endl;

    file<<"\n============================ END OF REPORT ==============================";

    file.close();

    cout<<"\n\tInventory report generated successfully!"<<endl;
}

#endif