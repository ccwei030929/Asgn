#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Structure to represent a durian type
struct Durian {
    string name;
    double pricePerKg;
};

// Function to display country selection menu
int displayCountryMenu() {
    cout << "\n=====================================" << endl;
    cout << "     Welcome to Durian Selection     " << endl;
    cout << "=====================================" << endl;
    cout << "Please select a country:" << endl;
    cout << "1. Malaysia" << endl;
    cout << "2. Thailand" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;
    return choice;
}

// Function to display durian types for Malaysia
int displayMalaysiaDurianMenu() {
    cout << "\n--- Malaysia Durian Selection ---" << endl;
    cout << "1. Musang King - RM 55.00/kg" << endl;
    cout << "2. D24 - RM 35.00/kg" << endl;
    cout << "3. Red Prawn - RM 45.00/kg" << endl;
    cout << "0. Back to country selection" << endl;
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;
    return choice;
}

// Function to display durian types for Thailand
int displayThailandDurianMenu() {
    cout << "\n--- Thailand Durian Selection ---" << endl;
    cout << "1. Monthong - ฿175.00/kg" << endl;
    cout << "2. Kan Yao - ฿225.00/kg" << endl;
    cout << "3. Chanee - ฿125.00/kg" << endl;
    cout << "0. Back to country selection" << endl;
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;
    return choice;
}

// Function to get weight input with validation
double getWeight() {
    double weight;
    cout << "Enter weight (kg): ";
    
    while (!(cin >> weight) || weight <= 0) {
        cout << "Invalid input. Please enter a positive number for weight: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return weight;
}

// Function to ask if user wants to continue
bool askContinue() {
    char choice;
    cout << "\nDo you want to select more durians? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

// Function to process durian selection
void processDurianSelection(const vector<Durian>& durians, int choice, double& totalPrice) {
    if (choice >= 1 && choice <= static_cast<int>(durians.size())) {
        double weight = getWeight();
        double itemPrice = durians[choice - 1].pricePerKg * weight;
        totalPrice += itemPrice;
        
        cout << "\nSelected: " << durians[choice - 1].name << endl;
        cout << "Weight: " << fixed << setprecision(2) << weight << " kg" << endl;
        cout << "Price per kg: " << durians[choice - 1].pricePerKg << endl;
        cout << "Item total: " << itemPrice << endl;
        cout << "Current total: " << totalPrice << endl;
    } else if (choice != 0) {
        cout << "Invalid choice. Please try again." << endl;
    }
}

int main() {
    // Define durian types for each country
    vector<Durian> malaysiaDurians = {
        {"Musang King", 55.00},
        {"D24", 35.00},
        {"Red Prawn", 45.00}
    };
    
    vector<Durian> thailandDurians = {
        {"Monthong", 175.00},
        {"Kan Yao", 225.00},
        {"Chanee", 125.00}
    };
    
    double totalPrice = 0.0;
    int countryChoice, durianChoice;
    bool continueSelection = true;
    
    while (continueSelection) {
        countryChoice = displayCountryMenu();
        
        switch (countryChoice) {
            case 1: // Malaysia
                do {
                    durianChoice = displayMalaysiaDurianMenu();
                    if (durianChoice == 0) {
                        break; // Go back to country selection
                    }
                    processDurianSelection(malaysiaDurians, durianChoice, totalPrice);
                    if (durianChoice >= 1 && durianChoice <= static_cast<int>(malaysiaDurians.size())) {
                        if (!askContinue()) {
                            continueSelection = false;
                            break;
                        }
                    }
                } while (durianChoice != 0 && continueSelection);
                break;
                
            case 2: // Thailand
                do {
                    durianChoice = displayThailandDurianMenu();
                    if (durianChoice == 0) {
                        break; // Go back to country selection
                    }
                    processDurianSelection(thailandDurians, durianChoice, totalPrice);
                    if (durianChoice >= 1 && durianChoice <= static_cast<int>(thailandDurians.size())) {
                        if (!askContinue()) {
                            continueSelection = false;
                            break;
                        }
                    }
                } while (durianChoice != 0 && continueSelection);
                break;
                
            case 0: // Exit
                continueSelection = false;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    
    // Display final total
    cout << "\n=====================================" << endl;
    cout << "           ORDER SUMMARY             " << endl;
    cout << "=====================================" << endl;
    cout << "Total Price: " << fixed << setprecision(2) << totalPrice << endl;
    cout << "Thank you for your purchase!" << endl;
    cout << "=====================================" << endl;
    
    return 0;
}