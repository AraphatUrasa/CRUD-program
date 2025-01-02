#include <iostream>
#include <string>
#include <vector>

using namespace std;
//an object
struct Item {
    int id;
    string name;
    double price;
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", price: $" << price << endl;
    }
};

void createItem(vector<Item>& items);
void readItems(const vector<Item>& items);
void updateItem(vector<Item>& items);
void deleteItem(vector<Item>& items);

int main() {
    vector<Item> items;
    int choice;

    do {
        cout << "\n---CRUD operations Menu ---\n";
        cout << "1 Create Item\n";
        cout << "2 Read Items\n";
        cout << "3 Update Item\n";
        cout << "4 Delete Item\n";
        cout << "5 Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createItem(items);
                break;
            case 2:
                readItems(items);
                break;
            case 3:
                updateItem(items);
                break;
            case 4:
                deleteItem(items);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
//createItem function 
void createItem(vector<Item>& items) {
    Item newItem;

    cout << "\nEnter Item ID: ";
    cin >> newItem.id;
    cin.ignore();
    cout << "Enter Item Name: ";
    getline(cin, newItem.name);
    cout << "Enter Item price: ";
    cin >> newItem.price;

    items.push_back(newItem);
    cout << "Item created successfully!\n";
}
//readItems function
void readItems(const vector<Item>& items) {
    if (items.empty()) {
        cout << "\nNo items found.\n";
    } else {
        cout << "\n--- Item List ---\n";
        for (const auto& item : items) {
            item.display();
        }
    }
}
//updateItem function 
void updateItem(vector<Item>& items) {
    int id;
    cout << "\nEnter Item ID to update: ";
    cin >> id;

    for (auto& item : items) {
        if (item.id == id) {
            cin.ignore();
            cout << "\nEnter new Item Name: ";
            getline(cin, item.name);
            cout << "Enter new Item Price: ";
            cin >> item.price;
            cout << "Item updated successfully!\n";
            return;
        }
    }
    cout << "Item with ID " << id << " not found.\n";
}
//implementing the deleteItem function
void deleteItem(vector<Item>& items) {
    int id;
    cout << "\nEnter Item ID to delete: ";
    cin >> id;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->id == id) {
            items.erase(it);
            cout << "Item deleted successfully!\n";
            return;
        }
    }
    cout << "Item with ID " << id << " not found.\n";
}
