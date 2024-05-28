#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

class Transaction {
public:
    string type;
    double amount;
    time_t date;

    Transaction(const string& type, double amount) : type(type), amount(amount) {
        date = time(0);
    }

    void print() const {
        tm *ltm = localtime(&date);
        cout << type << ": " << amount << " on " << 1900 + ltm->tm_year << "-" 
             << 1 + ltm->tm_mon << "-" << ltm->tm_mday << endl;
    }
};

class Loan {
public:
    double amount;
    time_t date;

    Loan(double amount) : amount(amount) {
        date = time(0);
    }

    void print() const {
        tm *ltm = localtime(&date);
        cout << "Loan: " << amount << " on " << 1900 + ltm->tm_year << "-" 
             << 1 + ltm->tm_mon << "-" << ltm->tm_mday << endl;
    }
};

class Account {
protected:
    string accountNum;
    string accountHolder;
    string addr;
    string acctType;
    double balance;
    vector<Transaction> transactions;
    vector<Loan> loans;

public:
    Account(const string& accountNum, const string& accountHolder, const string& addr, const string& acctType, double initialFunds = 0)
        : accountNum(accountNum), accountHolder(accountHolder), addr(addr), acctType(acctType), balance(initialFunds) {}

    virtual ~Account() {}

    void deposit(double amount) {
        balance += amount;
        transactions.emplace_back("Deposit", amount);
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;
            transactions.emplace_back("Withdrawal", amount);
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        }
    }

    void update_info(const string& new_holder_name, const string& new_addr) {
        if (!new_holder_name.empty()) {
            accountHolder = new_holder_name;
        }
        if (!new_addr.empty()) {
            addr = new_addr;
        }
        cout << "Account information updated" << endl;
    }

    void view_passbook() const {
        for (const auto& transaction : transactions) {
            transaction.print();
        }
    }

    void search_transaction_history(time_t date = 0, double amount = 0) const {
        for (const auto& transaction : transactions) {
            bool match = true;
            if (date != 0) {
                tm *ltm = localtime(&transaction.date);
                tm *ltm_date = localtime(&date);
                match &= (ltm->tm_year == ltm_date->tm_year && ltm->tm_mon == ltm_date->tm_mon && ltm->tm_mday == ltm_date->tm_mday);
            }
            if (amount != 0) {
                match &= (transaction.amount == amount);
            }
            if (match) {
                transaction.print();
            }
        }
    }

    void take_loan(double amount) {
        loans.emplace_back(amount);
        balance += amount;
        cout << "Loan of " << amount << " approved. New balance: " << balance << endl;
    }

    void transfer_funds(Account& targetAccount, double amount) {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            withdraw(amount);
            targetAccount.deposit(amount);
            cout << "Transferred " << amount << " to account " << targetAccount.accountNum << endl;
        }
    }
};

class JointAccount : public Account {
private:
    vector<string> accountHolders;

public:
    JointAccount(const string& accountNum, const vector<string>& accountHolders, const string& addr, const string& acctType, double initialFunds = 0)
        : Account(accountNum, accountHolders[0], addr, acctType, initialFunds), accountHolders(accountHolders) {}

    void update_info(const vector<string>& new_holders, const string& new_addr) {
        if (!new_holders.empty()) {
            accountHolders = new_holders;
            accountHolder = accountHolders[0];
        }
        if (!new_addr.empty()) {
            addr = new_addr;
        }
        cout << "Joint account information updated" << endl;
    }
};
