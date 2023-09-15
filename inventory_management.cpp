#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item{
    std::string name;
    int quantity;
    double price;
};
//function to add item in the inventory
void addItem(std::vector<Item> &inventory){
    Item newItem;
    std::cout<<"Enter item name: ";
    std::cin>>newItem.name;
    std::cout<<"\nEnter item quantity: ";
    std::cin>>newItem.quantity;
    std::cout<<"\nEnter item price: ";
    std::cin>>newItem.price;

    inventory.push_back(newItem);

    std::cout<<"Item added to the inventory."<<std::endl;

}
//function to update item in the inventory
void updateItem(std::vector<Item> &inventory){

    std::string searchName;
    std::cout<<"Enter the name of the item to update: ";
    std::cin>>searchName;
    Item item;
    for(Item item : inventory){
        if (item.name == searchName) {
            std::cout<<"Enter quantity: ";
            std::cin>>item.quantity;
            std::cout<<"Enter price: ";
            std::cin>>item.price;
            std::cout<<"Item Updated."<<std::endl;
            return;
        }
    }
    std::cout<<"Item not Found in Inventory."<<std::endl;
}

//function to remove the item from the inventory
void removeItem(std::vector<Item> &inventory){
    std::string searchName;
    std::cout<<"Enter the item name to be removed: ";
    std::cin>>searchName;

    for(auto it = inventory.begin(); it!=inventory.end(); ++it){
        if(it->name==searchName){
            it=inventory.erase(it);
            std::cout<<"Item removed for the inventory.";
            return;
        }
    }
    std::cout << "Item not found in inventory." << std::endl;
}

//function to display items in the inventory
void displayInventory(std::vector<Item> &inventory){
    std::cout << "Inventory:\n";
    for (const Item &item : inventory) {
        std::cout << "Name: " << item.name << "\n";
        std::cout << "Quantity: " << item.quantity << "\n";
        std::cout << "Price: $" << item.price << "\n\n";
    }

}
//function to display options to the user and take the choice of the user
int displayChoice(){
    int choice;
    std::cout << "Inventory Management System\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Update Item\n";
        std::cout << "3. Remove Item\n";
        std::cout << "4. Display Inventory\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        return choice;
}


int main(){
    std::vector<Item> inventory;
    int choice;

    do{
        choice = displayChoice();

        switch(choice){
            case 1:
                addItem(inventory);
                break;
            case 2:
                updateItem(inventory);
                break;
            case 3:
                removeItem(inventory);
                break;
            case 4:
                displayInventory(inventory);
                break;
            case 5:
                std::cout<<"Exitiing...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    }while(choice!=5);
    return 0;
}



