//Diego Caputi
#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include "GroceryItem.h"

using namespace std;

class ItemTracker {
private:
    set<GroceryItem> items;

public:
    // Load items from a file and update their frequencies
    //@param filename - Name of the input file containing grocery items
    void loadItems(const string& filename);

    // Get the frequency of a specific item
    //@param itemName - Name of the item to look up
    //@returns - Frequency of the item in the inventory
    int getItemFrequency(const string& itemName) const;

    // Print all items and their frequencies
    void printAllItems() const;

    // Print a histogram of item frequencies
    void printHistogram() const;

    // Save the current item frequencies to a backup file
    //@param filename - Name of the output file for saving item frequencies
    void saveFrequencies(const string& filename) const;
};
