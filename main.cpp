#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);


int main()
{
    double balance = 0;
    int choice = 0;

    do
    {
        std::cout << "*******************" << std::endl;
        std::cout << "Enter you choice:\n";
        std::cout << "*******************" << std::endl;
        std::cout << "1. Show Balance" << std::endl;
        std::cout << "2. Deposit Monet" << std::endl;
        std::cout << "3. Withdraw Money" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cin >> choice;

        switch(choice) {
            case 1: showBalance(balance);
                    break;
            case 2: balance += deposit();
                    showBalance(balance);
                    break;
            case 3: balance -= withdraw(balance);
                    showBalance(balance);
                    break;
            case 4: std::cout << "Thanks for visiting! \n";
                    break;
            default: std::cout << "Invalid Choise" << std::endl;
        }

    } while (choice != 4);
    

    return 0;
}


void showBalance(double balance) {
    std::cout << "Your balance is : €" << std::setprecision(2) << std::fixed << balance << std::endl;
}

double deposit() {

    double amount = 0;
    std::cout << "Enter the amount to be deposited: ";
    std::cin >> amount;

    if (amount > 0) {
        return amount;
    } else {
        std::cout << "That's not a valid amount\n";
        return 0;
    }
}

double withdraw(double balance){

    double amount = 0;
    std::cout << "Enter amount to be withdraw: ";
    std::cin >> amount;

    if(amount > balance) {
        std::cout << "Insufficient funds\n";
        return 0;

    } else if (amount < 0) {
        std::cout << " That is not a valid amount\n";
        return 0;

    } else {
        return amount;
    }

}
