/*This program was written by Labib Chowdhury on March 10th, 2016. This program uses pointers
to take user entered words and puts them into a list in alphabetical order*/
#include <iostream> //needed for input and output
using namespace std;

string UpperCase(string S)
/*Returns a copy of S with all lowercase characters converted to uppercase
characters. */
{
    for (int Letter=0; Letter< S.length(); Letter++)
        if ((S[Letter] >= 'a')&& (S[Letter] <= 'z'))
        S[Letter]=S[Letter]-'a'+'A';
    return(S);
}
struct Node
/* builds node structure*/
{
    string word;
    Node *next;//intializes next as a node
};
void DisplayList(Node *start)
/*Returns a list after it recieves a start if the list*/
{
    Node *current=start;    //initializes start of list as node
    while (current!=NULL){
        cout <<current->word <<endl;    //displays word and shifts to next one
        Node *previous=current; //variable for previous word
        current=current->next;
        delete previous;    //delets memory as it goes along

    }
    return;
}
void AddAtStart(Node *&start, Node *&newentry)
/*Uses the start of a list and a new word and adds the word to the beginning*/
{
    newentry->next=start;   //adds new word to start of list
    start=newentry;
    return;
}
Node *GetWord()
/*User enters a word and converts it into a node*/
{
    Node *newentry=new Node;    //initializes the new word
    cout<<"Please enter a word\n";
    cin >> newentry->word;  //user enters word
    return newentry;
}
Node *StartList(Node *newentry)
/*Used to initialize a list and returns the start of the list*/
{
    Node *start=newentry;   //only starts list then points to end
    start->next=NULL;
    return (start);
}
void AddItem(Node *start,Node *newentry)
/*Adds an item in the middle of the list*/
{
    Node *previous=start;   //intializes previous as start
    Node *current=start->next;  //initializes current
    while (current != NULL){    //loops while the list isnt at the end
            if (UpperCase(current->word)>UpperCase(newentry->word) && UpperCase(previous->word)<UpperCase(newentry->word)) //compares previous and new words
            {
                previous->next=newentry;    //adds word to list
                newentry->next=current;
                return;
            }
            else
            {
                current=current->next;  //adds word to list
                previous=previous->next;
            }
    }
    if (current==NULL) //if the word is added to end of list
    {
        previous->next=newentry;    //adds word to list
        newentry->next=NULL;
    }

    return;

}

main()
{
    Node *start = new Node; //initializes start of list

    Node *newentry=GetWord(); //initializes new user entered word
    if (UpperCase(newentry->word) !="DONE") //if user enters done first
{
        start=StartList(newentry);  //initializes list using StartList() function
        newentry=GetWord(); //user inputs a word
        while (UpperCase(newentry->word) !="DONE"){ //loops till user enters 'done'
            if (UpperCase(newentry->word)<UpperCase(start->word))   //if the word goes before everything
                AddAtStart(start,newentry);
            else
                AddItem(start,newentry);    //adding word to middle
            newentry=GetWord();


        }cout <<endl;
         DisplayList(start);//displays list
    }
    return(0);
}

