#include "system/add_cloth.h"
#include "system/add_to_cart.h"
#include "system/checkout.h"
#include "system/delete_cloth.h"
#include "system/display_clothes.h"
#include "system/load_from_csv.h"
#include "system/manage_cart.h"
#include "system/save_to_csv.h"
#include "system/search_cloth.h"
#include "system/sort_clothes.h"
#include "system/update_cloth.h"
#include "system/view_cart.h"
#include "system/inventory_report.h"

#include "include/cloth_info.h"

#include <iostream>
using namespace std;

int main(){
    ClothList *list = createClothList();


   int user_choice;
    
    ClothList cart;
    cart.head = NULL;
    cart.tail = NULL;
    cart.size = 0;

    do{

        cout<<"\n\n================================================================================================================================\n";
        cout<<"                                                 WELCOME TO E-COMMERCE CLOTHING SYSTEM MENU\n";
        cout<<"================================================================================================================================\n";

        cout<<"\n--------------------------------------------------------------------------------------------------------------------------------\n";

        cout<<"1. Add Cloth"<<endl;
        cout<<"2. Display Clothes"<<endl;
        cout<<"3. Update Cloth"<<endl;
        cout<<"4. Delete Cloth"<<endl;
        cout<<"5. Search Cloth"<<endl;
        cout<<"6. Sorting Cloth"<<endl;
        cout<<"7. Add Cloth to Cart"<<endl;
        cout<<"8. View Cart"<<endl;
        cout<<"9. Manage Cart Cloth"<<endl;
        cout<<"10. Check out"<<endl;
        cout<<"11. Load Clothes from CSV"<<endl;
        cout<<"12. Save Clothes to CSV"<<endl;
        cout<<"13. Inventory Report"<<endl;
        cout<<"0. Exit program"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";

        while(true){
            cout<<">>>Enter your choice: "; 
            cin>>user_choice;

            if(cin.fail()){
                cout<<"\n\tInvalid input! Please enter a number between 0-13.\n\n";

                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            if(user_choice < 0 || user_choice > 13){
                cout<<"\n\tInvalid input! Please enter a number between 0-13.\n\n";
                continue;
            }else{
                break;
            }
        }
        switch(user_choice){
            case 1: add_cloth(list); break;
            case 2: display_clothes(list); break;
            case 3: update_cloth(list); break;
            case 4: delete_cloth(list); break;
            case 5: search_cloth(list); break;
            case 6: sort_clothes(list); break;
            case 7: add_to_cart(list, cart); break;
            case 8: view_cart(cart); break;
            case 9: manage_cart(list, cart); break;
            case 10: checkout(list, cart); break;
            case 11: load_from_csv(list, "data/clothes.csv"); break;
            case 12: save_to_csv(list, "data/clothes.csv"); break;
            case 13: inventory_report(list, "data/report_clothes.txt"); break;
            case 0: cout<<"\n\tExit Program!\n\n"; break;
        }
    }while(user_choice != 0);
    
    return 0;
}