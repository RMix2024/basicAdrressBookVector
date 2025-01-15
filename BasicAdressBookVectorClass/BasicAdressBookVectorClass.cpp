#include "Vector.h"   // Include the Vector class
#include "Record.h"   // Include the Record class
#include <iostream>
#include <string>

using namespace std;


// Function to display all records
void displayRecords(const Vector<Record>& records) {
    if (records.isEmpty()) {
        cout << "No records to display.\n";
        return;
    }

    cout << "\nAddress Book:\n";
    for (size_t i = 0; i < records.getSize(); ++i) {
        cout << i + 1 << ". Name: " << records[i].name
            << ", Phone: " << records[i].phone << '\n';
    }
}

// Function to delete a record by index
void deleteRecord(Vector<Record>& records) {
    if (records.getSize() == 0) {
        cout << "No records to delete.\n";
        return;
    }

    // Display all records to the user
    cout << "\nAddress Book:\n";
    for (size_t i = 0; i < records.getSize(); ++i) {
        cout << i + 1 << ". Name: " << records[i].name
            << ", Phone: " << records[i].phone << '\n';
    }

    // Prompt the user for the record number to delete
    size_t recordNumber;
    cout << "\nEnter the record number to delete: ";
    cin >> recordNumber;

    // Validate the record number
    if (recordNumber < 1 || recordNumber > records.getSize()) {
        cout << "Invalid record number. Please try again.\n";
        return;
    }

    // Adjust for zero-based indexing and shift records
    size_t index = recordNumber - 1;
    for (size_t i = index; i < records.getSize() - 1; ++i) {
        records[i] = records[i + 1];
    }

    // Reduce the size of the vector
    records.pop_back();
    cout << "Record deleted successfully.\n";
}


int main() {
    try {
        Vector<Record> records;

        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Add Record\n";
            cout << "2. View Records\n";
            cout << "3. Delete Record\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: { // Add Record
                Record newRecord;
                cout << "Enter name: ";
                cin >> newRecord.name;
                cout << "Enter phone number: ";
                cin >> newRecord.phone;

                records.push_back(newRecord);
                cout << "Record added successfully.\n";
                break;
            }
            case 2: // View Records
                displayRecords(records);
                break;

            case 3: { // Delete Record
                deleteRecord(records);
                break;
            }

            case 4: // Exit
                cout << "Exiting program. Goodbye!\n";
                break;

            default: // Invalid Choice
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        } while (choice != 4);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
