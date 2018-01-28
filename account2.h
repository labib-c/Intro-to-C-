#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED





using namespace std;
#include <iostream>
#include <vector>

class AccountClass{
public:
    AccountClass();
    AccountClass(string AcctName,string AcctOpenDate);
    void Deposit(double Amt, string Date);
    bool Withdrawal(double Amt,string Date);
    double GetBalance()const;
    void WriteTransactions(ostream & OutFile) const;
    void SpecifyAccount(string AcctName, string AcctOpenDate);
    string GetName() const;
private:
    string Name;
    string OpenDate;
    double Balance;
    vector <string> TransDates, TransKinds;
    vector <double> TransAmts;
    bool IsOpen;
};
#endif // ACCOUNT_H_INCLUDED
#include "account2.cpp"

