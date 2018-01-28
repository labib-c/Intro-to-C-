using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------------------------
AccountClass::AccountClass():Balance(0),TransDates(0),TransKinds(0),TransAmts(0),IsOpen(false)
{
}
//--------------------------------------------------------------
void AccountClass::SpecifyAccount(string AcctName,string AcctOpenDate){
    if (!IsOpen){
        Name=AcctName;
        OpenDate=AcctOpenDate;
        IsOpen=true;
    }
}
//--------------------------------------------------------------
void AccountClass::Deposit(double Amt, string Date)
{
    Balance+=Amt;
    TransDates.resize(TransDates.size()+1);
    TransDates[TransDates.size()-1] = Date;

    TransKinds.resize(TransKinds.size()+1);
    TransKinds[TransKinds.size()-1] = "Deposit";

    TransAmts.resize(TransAmts.size()+1);
    TransAmts[TransAmts.size()-1] = Amt;
}
//--------------------------------------------------------------
bool AccountClass::Withdrawal(double Amt,string Date)
{
    TransDates.resize(TransDates.size()+1);
    TransDates[TransDates.size()-1]=Date;
    TransKinds.resize(TransKinds.size()+1);
    TransAmts.resize(TransAmts.size()+1);
    TransAmts[TransAmts.size()-1]=Amt;
    if(Amt<=Balance){
        Balance-=Amt;
        TransKinds[TransKinds.size()-1]="Withdrawal";
        return(true);
    }
    else{
        TransKinds[TransKinds.size()-1]="Withdrawal/Failed";
        return(false);
    }
}
//--------------------------------------------------------------
double AccountClass::GetBalance()const
{
    return(Balance);

}
//--------------------------------------------------------------
void AccountClass::WriteTransactions(ostream & OutFile) const
{
    OutFile.setf(ios::fixed);
    OutFile.precision(2);
    OutFile<<Name<<endl;
    OutFile<<"Acct opened on "<<OpenDate<<" Balance:"<<Balance<<endl;
    OutFile<<"Transactions"<<endl;
    for (int i=0;i<TransDates.size();i++){
        OutFile.width(12);OutFile<<TransDates[i];
        OutFile.width(22);OutFile<<TransKinds[i];
        OutFile.width(12);OutFile<<TransAmts[i]<<endl;
    }
}
//--------------------------------------------------------------























