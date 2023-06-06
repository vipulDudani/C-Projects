#include <iostream>
#include <vector>

// Tour package structure
struct TourPackage {
    std::string destination;
    int duration;
    double price;
};

// Function to display available tour packages
void displayTourPackages(const std::vector<TourPackage>& packages) {
    std::cout << "Available Tour Packages:\n";
    for (const auto& package : packages) {
        std::cout << "Destination: " << package.destination << "\n";
        std::cout << "Duration: " << package.duration << " days\n";
        std::cout << "Price: $" << package.price << "\n";
        std::cout << "-----------------------------\n";
    }
}

// Function to book a tour package
void bookTourPackage(const TourPackage& package) {
    std::cout << "You have booked the following tour package:\n";
    std::cout << "Destination: " << package.destination << "\n";
    std::cout << "Duration: " << package.duration << " days\n";
    std::cout << "Price: $" << package.price << "\n";
    std::cout << "Enjoy your trip!\n";
}

int main() {
    // Sample tour packages
    std::vector<TourPackage> tourPackages = {
        {"Paris", 5, 1500.0},
        {"Rome", 7, 2000.0},
        {"Tokyo", 10, 3000.0},
        // Add more tour packages here
    };

    int choice;
    do {
        std::cout << "Tour and Travel Management System\n";
        std::cout << "1. View available tour packages\n";
        std::cout << "2. Book a tour package\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayTourPackages(tourPackages);
                break;
            case 2: {
                int packageChoice;
                std::cout << "Enter the package number you want to book: ";
                std::cin >> packageChoice;

                if (packageChoice >= 1 && packageChoice <= tourPackages.size()) {
                    const TourPackage& selectedPackage = tourPackages[packageChoice - 1];
                    bookTourPackage(selectedPackage);
                } else {
                    std::cout << "Invalid package number. Please try again.\n";
                }
                break;
            }
            case 3:
                std::cout << "Thank you for using the system!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}
