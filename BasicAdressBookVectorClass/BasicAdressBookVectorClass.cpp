#include "Vector.h"   // Include the Vector class
#include "Record.h"   // Include the Record class
#include <iostream>
#include <string>

// Function to display all records
void displayRecords(const Vector<Record>& records) {
    if (records.isEmpty()) {
        std::cout << "No records to display.\n";
        return;
    }

    std::cout << "\nAddress Book:\n";
    for (size_t i = 0; i < records.getSize(); ++i) {
        std::cout << i + 1 << ". Name: " << records[i].name
            << ", Phone: " << records[i].phone << '\n';
    }
}

// Function to delete a record by index
void deleteRecord(Vector<Record>& records, size_t index) {
    if (index >= records.getSize()) {
        std::cout << "Invalid record number. Please try again.\n";
        return;
    }

    // Shift all records after the specified index up by one position
    for (size_t i = index; i < records.getSize() - 1; ++i) {
        records[i] = records[i + 1];
    }

    records.pop_back(); // Remove the last element
    std::cout << "Record deleted successfully.\n";
}

int main() {
    try {
        Vector<Record> records;

        int choice;
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Add Record\n";
            std::cout << "2. View Records\n";
            std::cout << "3. Delete Record\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: { // Add Record
                Record newRecord;
                std::cout << "Enter name: ";
                std::cin >> newRecord.name;
                std::cout << "Enter phone number: ";
                std::cin >> newRecord.phone;

                records.push_back(newRecord);
                std::cout << "Record added successfully.\n";
                break;
            }
            case 2: // View Records
                displayRecords(records);
                break;

            case 3: { // Delete Record
                if (records.isEmpty()) {
                    std::cout << "No records to delete.\n";
                    break;
                }

                size_t recordNumber;
                std::cout << "Enter the record number to delete: ";
                std::cin >> recordNumber;

                // Adjust for zero-based index
                deleteRecord(records, recordNumber - 1);
                break;
            }
            case 4: // Exit
                std::cout << "Exiting program. Goodbye!\n";
                break;

            default: // Invalid Choice
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        } while (choice != 4);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
