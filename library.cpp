using namespace std;
#include <iostream>
#include "date.h"

//--------------------------------------------------------------
LibraryClass::LibraryClass(string title)
 :Title(title)
{
}

//--------------------------------------------------------------
string LibraryClass::GetTitle()const
{
    return(Title);
}

//--------------------------------------------------------------
DateClass LibraryClass::GetDate()const
{
    return(DueDate);
}

//--------------------------------------------------------------
void LibraryClass::SetTitle(string title)
{
    Title=title;
}

//--------------------------------------------------------------
void LibraryClass::SetDate(DateClass ddate)
{
    DueDate=ddate;
}

//--------------------------------------------------------------
bool LibraryClass::IsOverDue(DateClass tdate)
{
    if (DueDate<tdate)
        return true;
    else
        return false;
}
