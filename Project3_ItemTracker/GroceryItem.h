//Diego Caputi
#pragma once
#include <string>

using namespace std;

class GroceryItem {
public:
    // Constructor to initialize an item with a name
    //@param name - Name of the grocery item
    GroceryItem(const string& name);

    // Constructor to initialize an item with a name and quantity
    //@param name - Name of the grocery item
    //@param quantity - Quantity of the grocery item
    GroceryItem(const string& name, int quantity);

    // Getter for the name of the grocery item
    //@returns - Name of the grocery item
    string getName() const;

    // Getter for the quantity of the grocery item
    //@returns - Quantity of the grocery item
    int getQuantity() const;

    // Increment the quantity of the grocery item
    void addItem();

    // Decrement the quantity of the grocery item
    void removeItem();

    // Comparison operator for sorting GroceryItem in a set
    //@param other - Another GroceryItem object
    //@returns - True if this item is less than the other item
    bool operator<(const GroceryItem& other) const;

private:
    string name;
    int quantity;
};
