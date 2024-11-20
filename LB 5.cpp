#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Структура для зберігання інформації про рахунок
struct BankAccount {
    string owner;
    double balance;
};

// Функція для створення нового рахунку
void createAccount(vector<BankAccount>& accounts, const string& owner, double initialBalance) {
    if (initialBalance < 0) {
        cout << "Баланс не може бути від’ємним!" << endl;
        return;
    }
    accounts.push_back({owner, initialBalance});
    cout << "Рахунок створено для " << owner << " з балансом " << initialBalance << " грн." << endl;
}

// Функція для поповнення балансу рахунку
void deposit(vector<BankAccount>& accounts, const string& owner, double amount) {
    for (auto& account : accounts) {
        if (account.owner == owner) {
            if (amount < 0) {
                cout << "Сума поповнення не може бути від’ємною!" << endl;
                return;
            }
            account.balance += amount;
            cout << "Баланс оновлено. Новий баланс: " << account.balance << " грн." << endl;
            return;
        }
    }
    cout << "Рахунок з ім'ям " << owner << " не знайдено." << endl;
}

// Функція для зняття коштів
void withdraw(vector<BankAccount>& accounts, const string& owner, double amount) {
    for (auto& account : accounts) {
        if (account.owner == owner) {
            if (amount < 0) {
                cout << "Сума зняття не може бути від’ємною!" << endl;
                return;
            }
            if (account.balance < amount) {
                cout << "Недостатньо коштів на рахунку." << endl;
                return;
            }
            account.balance -= amount;
            cout << "Гроші знято. Новий баланс: " << account.balance << " грн." << endl;
            return;
        }
    }
    cout << "Рахунок з ім'ям " << owner << " не знайдено." << endl;
}

// Функція для відображення інформації про всі рахунки
void displayAccounts(const vector<BankAccount>& accounts) {
    cout << "\nІнформація про всі рахунки:\n";
    for (const auto& account : accounts) {
        cout << "Власник: " << account.owner << ", Баланс: " << account.balance << " грн." << endl;
    }
    cout << endl;
}

// Головна функція
int main() {
    vector<BankAccount> accounts;
    int choice;
    do {
        cout << "Меню:\n";
        cout << "1. Створити рахунок\n";
        cout << "2. Поповнити рахунок\n";
        cout << "3. Зняти кошти\n";
        cout << "4. Відобразити всі рахунки\n";
        cout << "5. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string owner;
                double initialBalance;
                cout << "Введіть ім'я власника: ";
                cin.ignore(); // Очищення буфера
                getline(cin, owner);
                cout << "Введіть початковий баланс: ";
                cin >> initialBalance;
                createAccount(accounts, owner, initialBalance);
                break;
            }
            case 2: {
                string owner;
                double amount;
                cout << "Введіть ім'я власника рахунку: ";
                cin.ignore();
                getline(cin, owner);
                cout << "Введіть суму поповнення: ";
                cin >> amount;
                deposit(accounts, owner, amount);
                break;
            }
            case 3: {
                string owner;
                double amount;
                cout << "Введіть ім'я власника рахунку: ";
                cin.ignore();
                getline(cin, owner);
                cout << "Введіть суму зняття: ";
                cin >> amount;
                withdraw(accounts, owner, amount);
                break;
            }
            case 4:
                displayAccounts(accounts);
                break;
            case 5:
                cout << "Програма завершена. До побачення!" << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 5);

    return 0;
}
