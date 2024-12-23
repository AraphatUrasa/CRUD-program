#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Item {
    int id;
    int name;
    double price;
    void display() const {
        cout << "ID: " << id << ", Name :" << name << ", price: $" << price << endl;
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

    }
}

}
}