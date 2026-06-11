#ifndef INVENTORY_REPORT
#define INVENTORY_REPORT
#include <fstream>
#include <iostream>
#include <iomanip>
#include "../include/cloth_info.h"

using namespace std;

void inventory_report(ClothList *list, const string &filename){
    ofstream myfile(filename);

    if(!myfile.is_open()) {
        cout<<"Error: cannot open file " <<filename<<endl;
        return;
    }

    ClothInfo *current = list->head;

    myfile<<"============================== INVENTORY REPORT ===============================\n\n";

    myfile <<left 
           <<setw(8)<<"ID"
           <<setw(25)<<"Name"
           <<setw(16)<<"Brand"
           <<setw(6)<<"Size"
           <<setw(10)<<"Price"
           <<setw(8)<<"Stock"
           <<"Status\n";

    myfile<<"--------------------------------------------------------------------------------\n";

    int total = 0;
    int low_stock = 0;
    int out_stock = 0;

    while (current != nullptr) {

        string status;

        if(current->cloth_stock_quantity == 0) {
            status = "OUT";
            out_stock++;
        }else if(current->cloth_stock_quantity <= 5) {
            status = "LOW";
            low_stock++;
        }else{
            status = "OK";
        }
        myfile <<left                 
               <<setw(8)<<current->cloth_id
               <<setw(25)<<current->cloth_name
               <<setw(16)<<current->cloth_brand
               <<setw(6)<<current->cloth_size
               <<setw(10)<<current->cloth_price
               <<setw(8)<<current->cloth_stock_quantity
               <<status<<"\n";

        current = current->next;
        total++;
    }
    myfile<<"--------------------------------------------------------------------------------\n";
    myfile<<"================================================================================\n";

    myfile << "                                Total Items      : " << total << "\n";
    myfile << "                                Low Stock Items  : " << low_stock << "\n";
    myfile << "                                Out of Stock     : " << out_stock << "\n";

    myfile<<"================================================================================\n";

    myfile.close();

    cout<<"\n\tInventory report generated successfully: "<<filename<<endl;
}

#endif