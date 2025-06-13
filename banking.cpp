#include <iostream>
#include <iomanip>
#include "banking.hpp"

void showBalance(double balance) {
    std::cout << "Your balance is : €" << std::setprecision(2) << std::fixed << balance << std::endl;
}

double deposit() {
    double amount = 0;
    std::cout << "Enter the amount to be deposited: ";
    std::cin >> amount;
    if (amount > 0) return amount;
    std::cout << "That's not a valid amount\n";
    return 0;
}

double withdraw(double balance) {
    double amount = 0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;
    if (amount > balance) {
        std::cout << "Insufficient funds\n";
        return 0;
    } else if (amount < 0) {
        std::cout << "That is not a valid amount\n";
        return 0;
    }
    return amount;
}
