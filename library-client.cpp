using namespace std;
#include <iostream>
#include "date.h"
#include "library.h"
#include <vector>
typedef vector <LibraryClass> LibraryItemClass;

int main()
{
    const int MAXSIZE=3;
    LibraryClass LibraryItemClass(MAXSIZE);
    DateClass tdate;

    DateClass ddate1 (12,26,15);
    DateClass ddate2 (12,26,16);
    DateClass ddate3 (6,29,16);
    LibraryItemClass[0].SetDate(ddate1);
    LibraryItemClass[1].SetDate(ddate2);
    LibraryItemClass[2].SetDate(ddate3);
    LibraryItemClass[0].SetTitle("1984");
    LibraryItemClass[1].SetTitle("Jane Eyre");
    LibraryItemClass[2].SetTitle("The Da Vinci Code");

    cout <<"Enter todays date "<<endl;
    cin >>tdate;
    cout<<"Overdue: ";
    cout << "Title"<< "\t"<<"\t"<<"\t"<<"Due Date"<< endl;
    for (int i=0;i<3;i++)
    {
        if (LibraryItemClass[i].IsOverDue(tdate)==true){
            cout << LibraryClass[i].GetTitle()<<"\t";
            cout<< LibraryItemClass[i].GetDate();
            cout<<endl;
        }
    }
}
