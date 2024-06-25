//Diego Caputi
#include "ItemTracker.h"

void ItemTracker::loadItems(const string& filename) {
    items.clear(); // Clear existing items to prevent accumulation

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string itemName;
    while (inputFile >> itemName) {
        GroceryItem* newItem = new GroceryItem(itemName);
        auto existingItem = items.find(*newItem);

        if (existingItem != items.end()) {
            GroceryItem updatedItem = *existingItem;
            updatedItem.addItem();
            items.erase(existingItem);
            items.insert(updatedItem);
            delete newItem;
        }
        else {
            items.insert(*newItem);
            delete newItem;
        }
    }

    inputFile.close();
}

int ItemTracker::getItemFrequency(const string& itemName) const {
    GroceryItem searchItem(itemName);
    auto existingItem = items.find(searchItem);

    if (existingItem != items.end()) {
        return existingItem->getQuantity();
    }
    return 0;
}

void ItemTracker::printAllItems() const {
    for (const auto& item : items) {
        cout << item.getName() << " " << item.getQuantity() << endl;
    }
}

void ItemTracker::printHistogram() const {
    for (const auto& item : items) {
        cout << item.getName() << " ";
        for (int i = 0; i < item.getQuantity(); ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

void ItemTracker::saveFrequencies(const string& filename) const {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& item : items) {
        outputFile << item.getName() << " " << item.getQuantity() << endl;
    }

    outputFile.close();
}
