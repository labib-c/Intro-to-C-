using namespace std;
#include "account2.h"
#include <iostream>
#include <vector>

const double Interest = 0.025;
const string Date = "24/04/2016";
typedef vector <AccountClass> AccVector;

bool GiveInterest(AccountClass &Source, double Interest, string Date) {
    if (Source.GetBalance() > 0) {
        Source.Deposit(Source.GetBalance() * Interest, Date);
        return true;
    }
    else
        return false ;

}

void AddInterest(AccountVector &Bank, double Interest, string Date) {
    for (int x = 0; x < Bank.size(); x++)
        GiveInterest(Bank[x], Interest, Date);
    return;

 }

int main() {
    AccVector Bank(0);
    int NumAccounts = 0;
    string Name, Date;
    double InitialDeposit;
    bool check = true;
    string answer;
    while (check == true) {
        Bank.resize(Bank.size()+1);
        cout << "Enter name number" << (Bank.size()) << ": ";
        getline(cin, Name);
        cout << "Enter date number" << (Bank.size()) << ": ";
        getline(cin, Date);
        cout << "Enter initial deposit number" << (Bank.size()) << ": ";
        cin >> InitialDeposit;
        cout << "Would you like to add another account (y/n)? "<<endl;
        cin >> answer;
        cin.ignore(80,'\n');
        Bank[Bank.size()-1].SpecifyAccount(Name, Date);
        Bank[Bank.size()-1].Deposit(InitialDeposit, Date);
        if (answer == "n" || answer =="N")
            check = false;
    }
    AddInterest(Bank, Interest, Date);
    for (int i=0; i<Bank.size(); i++) {
        cout.width(25);
        cout.setf(ios::left);
        cout << Bank[i].GetName() << Bank[i].GetBalance() << endl;
    }
    return(0);
}
