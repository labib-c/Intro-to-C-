#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

using namespace std;
#include <iostream>
#include "date.h"

class LibraryClass : public DateClass{
public:
    LibraryClass();
    LibraryClass(string title);
    bool IsOverDue(int tdate);
    string GetTitle()const;
    DateClass GetDate()const;
    void SetTitle(string title);
    void SetDate(DateClass ddate);
protected:
    DateClass DueDate;
    string Title;
};


#endif // LIBRARY_H_INCLUDED
#include "library.cpp"
