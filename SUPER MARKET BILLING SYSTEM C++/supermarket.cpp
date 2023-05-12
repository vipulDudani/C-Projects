#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Class to represent a product
class Product {
public:
    string name;
    int quantity;
    float price;
};

// Function to display a menu with options
void displayMenu() {
    cout << "1. Add Product" << endl;
    cout << "2. Display Products" << endl;
    cout << "3. Calculate Total Bill" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to add a product to the supermarket
void addProduct(vector<Product>& products) {
    Product product;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, product.name);
    cout << "Enter quantity: ";
    cin >> product.quantity;
    cout << "Enter price: ";
    cin >> product.price;
    products.push_back(product);
    cout << "Product added successfully!" << endl;
}

// Function to display all products in the supermarket
void displayProducts(const vector<Product>& products) {
    if (products.empty()) {
        cout << "No products available." << endl;
    } else {
        cout << "Product Name\tQuantity\tPrice" << endl;
        cout << "----------------------------------------" << endl;
        for (const auto& product : products) {
            cout << setw(15) << left << product.name << "\t"
                 << setw(10) << left << product.quantity << "\t"
                 << setw(10) << left << product.price << endl;
        }
    }
}

// Function to calculate the total bill
float calculateTotalBill(const vector<Product>& products) {
    float totalBill = 0;
    for (const auto& product : products) {
        totalBill += product.quantity * product.price;
    }
    return totalBill;
}

int main() {
    vector<Product> products;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(products);
                break;
            case 2:
                displayProducts(products);
                break;
            case 3:
                cout << "Total Bill: $" << calculateTotalBill(products) << endl;
                break;
            case 4:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
