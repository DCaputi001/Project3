//Diego Caputi
#include <iostream>
#include <stdexcept>
#include "ItemTracker.h"

using namespace std;

// Constants for menu choices
const int LOOK_UP_FREQUENCY = 1;
const int PRINT_ALL_FREQUENCIES = 2;
const int PRINT_HISTOGRAM = 3;
const int EXIT = 4;

void displayMenu() {
    cout << LOOK_UP_FREQUENCY << ". Look up item frequency" << endl;
    cout << PRINT_ALL_FREQUENCIES << ". Print all item frequencies" << endl;
    cout << PRINT_HISTOGRAM << ". Print histogram of item frequencies" << endl;
    cout << EXIT << ". Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ItemTracker tracker;
    int choice = 0;

    while (choice != EXIT) {
        displayMenu();
        try {
            cin >> choice;
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                throw invalid_argument("Invalid input. Please enter a number.");
            }

            // Reload items for each operation
            tracker.loadItems("Inventory.txt");

            switch (choice) {
            case LOOK_UP_FREQUENCY: {
                string itemName;
                cout << "Enter item name: ";
                cin >> itemName;
                int frequency = tracker.getItemFrequency(itemName);
                if (frequency > 0) {
                    cout << itemName << " was purchased " << frequency << " times." << endl;
                }
                else {
                    cout << "Item not currently in inventory." << endl;
                }
                break;
            }
            case PRINT_ALL_FREQUENCIES:
                tracker.printAllItems();
                break;
            case PRINT_HISTOGRAM:
                tracker.printHistogram();
                break;
            case EXIT:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

            // Save frequencies after each operation
            tracker.saveFrequencies("frequency.dat");

        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
