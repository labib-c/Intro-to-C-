/* This program was written by Labib Chowdhury on April 13th, 2016. It is used to create
a grid of cells and finds the amount of cells connected to each other*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef vector <char> onerow; //defines a row of characters
typedef vector <onerow> matrix;//defines a 2D grid filled with rows

void FillMatrix(matrix &nestlist)
/* Takes in an array and fills it randomnly with '*' */
{
    for (int i=0;i<nestlist.size();i++){
        for (int x=0;x<nestlist[0].size();x++){ //creates the 2D array
            int randnum=(rand()%2); //fills randomnly with 1 or 0
            if (randnum==1)
                nestlist[i][x]='*'; //replaces 1 with *

            else
                nestlist[i][x]=' '; //replaces 0 with a space
        }
    }
    return;
}
void DisplayMatrix(const matrix &nestlist)
/* Takes in a list and displays it */
{
    for (int i=(nestlist.size()-1);i>=0;i--){
        cout <<i;   //prints the row number
        for (int x=0;x<nestlist[0].size();x++){
                cout <<nestlist[i][x]<<" "; //prints the grid
                }
        cout<<endl;}
    for (int y=0;y<nestlist[0].size();y++){
        cout<<" "<<y;   //prints the column number
        }

    return;
}
int blob_check(matrix &nestlist,int row, int col)
/* Takes in an array and returns the blob number */
{
    int count=0; //initialize the counter
    if(row<=(nestlist.size()-1) && col<=(nestlist[0].size()-1) && row>=0 && col>=0){
        if (nestlist[row][col]==' ')   //checks if coordinate exists
            count=0;    //blob number is 0 if there is nothing there
        else{
            nestlist[row][col]=' '; //replaces an * with a space so it doesn't count twice
            count=1+(blob_check(nestlist,row,col-1))+  //checks cell on every side of it and goes through function
            (blob_check(nestlist,row-1,col))+
            (blob_check(nestlist,row-1,col-1))+
            (blob_check(nestlist,row,col+1))+
            (blob_check(nestlist,row+1,col+1))+
            (blob_check(nestlist,row+1,col))+
            (blob_check(nestlist,row+1,col-1))+
            (blob_check(nestlist,row-1,col+1));


        }

    }
    else    //returns 0 if there is no cell on coordinate
        count=0;



    return(count);//returns the number of total cells
}

int main()
{
    srand(time(NULL));//needed for random number
    int row,col,row2,col2; //initializes both rows and columns for user input
    cout << "Please enter the number of rows for the grid\n"<<endl;
    cin >>row; //user enters row
    cout <<"Please enter the number of columns for the grid\n"<<endl;
    cin >>col;//user enters column
    cout <<endl;
    matrix nestlist(row, onerow(col));//initializes the matrix
    bool done = false;//needed to exit while loop
    string ans;//initializes user input for the answer
    FillMatrix(nestlist);//fills matrix
    matrix check=nestlist;//creates backup matrix which goes through changes
    cout <<endl;
    while (not done){
        DisplayMatrix(nestlist);//displays the matrix
        cout <<"\nPlease enter a row number to check";
        cin>>row2;//user enters row
        cout <<"\nPlease enter a column number to check";
        cin>>col2;//user enters column
        cout<<"\nAt "<<row2<<" "<<col2<<" the blob size is "<<blob_check(check,row2,col2) ;//checks amount of cells connected
        cout <<"\nCheck another? (y/n)"<<endl;//asks if they want to continue
        cin >>ans;
        if (ans=="n")
            done=true;//exits loop if they enter 'n'
        matrix check=nestlist;//creates backup again as previous one is changed
    }
    return (0);
}

