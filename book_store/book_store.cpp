// book_store.cpp : Book Store Application
//
#include <iostream>
#include <vector>
//#include "main.h"
using namespace std;

class Item {
public:
	int id;//Item ID
	string name;//Item name
	float price; //Item price
	int quantity; //Quantity in stock

	Item(int id, string name, float price, int quantity)
		: id(id), name(name), price(price), quantity(quantity) {};
};

class Inventory {
	vector <Item> items;//Create a vector of "Item" object 
public:
	//Inventory();
	void add_item(int id, string name, float price, int quantity);
	int remove_item(int id);
	int update_item_price(int id, float price);
	void display_items();
};

void Inventory::add_item(int id, string name, float price, int quantity) {
	items.push_back(Item(id, name, price, quantity));
	cout << "Add new items:" << endl;
	cout << "  ID:" << id << endl;
	cout << "  Name: " << name << endl;
	cout << "  Price: " << price << endl;
	cout << "  Items added: " << quantity << endl;
}

int Inventory::remove_item(int id) {
	bool is_found = false;
	for (auto it = items.begin(); it != items.end(); it++) {
		if (it->id == id) {
			items.erase(it);
			is_found = true;
			break;
		}
	}
	cout << endl;
	cout << "Remove item:" << endl;
	if (is_found == true) {
		cout << "item with an ID of " << id << " was removed from stock!\n";
		return 0;
	}
	else {
		cout << "item with an ID of " << id << " was not found!\n";
		return -1;
	}
}

int Inventory::update_item_price(int id, float price) {
	bool is_found = false;
	cout << endl;
	for (auto it = items.begin(); it < items.end(); it++) {
		if (it->id == id) {
			it->price = price;
			is_found = true;
			break;
		}
	}
	cout << "Update item" << endl;
	if (is_found == true) {
		cout << "item ID " << id << " price was changed to " << price << " Dollars.\n";
		return 0;
	}
	else {
		cout << "item ID " << id << " was not found!\n";
		return -1;
	}
}
void Inventory::display_items() {
	cout << endl;
	cout << "Display items list:" << endl;
	for (auto it = items.begin(); it < items.end(); it++) {
		cout << "Item ID " << it->id << ", Name " << it->name << ", Price " << it->price << ", Quantity " << it->quantity << endl;
	};
	
}


/**********************************************************/
int main()
{
	cout << endl;
    cout << "--- Book store Application ---\n";
    Inventory inventoy;

	cout << endl;
	inventoy.add_item(100001, "SQL Quick Start", 49.99, 3);
	inventoy.add_item(100002, "SQL Intermediate", 79.99, 2);
	inventoy.add_item(100003, "SQL Advanced", 79.99, 2);
	inventoy.display_items();

	inventoy.update_item_price(100004, 154.5);
	inventoy.update_item_price(100002, 45.99);
	inventoy.display_items();

	inventoy.remove_item(100002);
	inventoy.display_items();

	cout << endl;
	cout << endl;


	return 0;
}

