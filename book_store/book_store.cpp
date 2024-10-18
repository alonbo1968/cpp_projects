// book_store.cpp : Book Store Application
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream myfile_o;
ifstream myfile_i;


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
	//void add_item(int id, string name, float price, int quantity);
	void add_item();
	int remove_item(int id);
	int update_item_price(int id, float price);
	void display_items();
};

//void Inventory::add_item(int id, string name, float price, int quantity) {
//	items.push_back(Item(id, name, price, quantity));
//	cout << "Add new items:" << endl;
//	cout << "  ID:" << id << endl;
//	cout << "  Name: " << name << endl;
//	cout << "  Price: " << price << endl;
//	cout << "  Items added: " << quantity << endl;
//}
void Inventory::add_item() {
	int id;
	string name;
	float price;
	int quantity;
	cout << "Add new item:" << endl;
	cout << "  Enter ID: ";
	cin >> id;
	cout << "  Enter Name:";
	cin >> name;
	cout << "  Enter Price:";
	cin >> price;
	cout << "  Enter Quantity:";
	cin >> quantity;
	items.push_back(Item(id, name, price, quantity));
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
	myfile_o << endl;
	cout << "Display items list:" << endl;
	for (auto it = items.begin(); it < items.end(); it++) {
		cout << "Item ID " << it->id << ", Name " << it->name << ", Price " << it->price << ", Quantity " << it->quantity << endl;
		myfile_o << "Item ID " << it->id << ", Name " << it->name << ", Price " << it->price << ", Quantity " << it->quantity << endl;

	};
}


/**********************************************************/
int main()
{
	cout << endl;
    cout << "--- Book store Application ---\n";
    Inventory inventoy; //Create tnventory operations object

	myfile_o.open("output.csv", fstream::app);
	if (myfile_o.is_open()) {

	}
	else {
		cout << "Error openning the file for writing!" << endl;
		myfile_o.close();
		return -1;
	}

	cout << endl;
	int menu_option = 0;
	int item_id = 0;
	float item_price;
	bool exit = false;
	while (exit == false) {
		cout << "--- Menu: ---" << endl;
		cout << "1. Add an item." << endl;
		cout << "2. Remove one item." << endl;
		cout << "3. Update item price." << endl;
		cout << "4. Display items." << endl;
		cout << "5. Exit the program." << endl;

		cout << "Select your option: ";
		cin >> menu_option;

		switch (menu_option) {
		case 1:
			inventoy.add_item();
			break;
		case 2:
			cout << "Enter the item ID you want to remove: ";
			cin >> item_id;
			inventoy.remove_item(item_id);
			break;
		case 3:
			cout << "Enter the item ID: ";
			cin >> item_id;
			cout << endl << "Enter the new price: ";
			cin >> item_price;
			inventoy.remove_item(item_id);
			break;
		case 4:
			cout << "Enter the item ID: ";
			inventoy.display_items();
			break;
		case 5:
			cout << "Exiting the application!" << endl;
			exit = true;
			break;

		default:
			cout << "Invalid option entered. Try again!" << endl;
			break;
		}

		cout << endl;
	}

		//inventoy.add_item();
		//inventoy.display_items();

		//inventoy.update_item_price(100004, 154.5);
		//inventoy.update_item_price(100002, 45.99);
		//inventoy.display_items();

		//inventoy.remove_item(100002);
		//inventoy.display_items();

	myfile_o.close();
	return 0;
}

