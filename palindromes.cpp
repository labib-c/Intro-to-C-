#include <iostream>
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

string Reverse(string x)
/*Returns a string of in reverse order*/
{
    string justlet= JustLetters(x);
    string rev;
    for (int i = justlet.length()-1;i>=0;i--){
        rev=rev+justlet[i];
    }return(rev);

}
string JustLetters(string y)
/* Returns string with only letters. */
{
    string palin;
    for (int Letter=0; Letter < y.length(); Letter++){
        if (((y[Letter])>='A'||(y[Letter])>='a')&& ((y[Letter])<='Z'|| (y[Letter])<='z'))
            palin=palin+(y[Letter]);
  }return(palin);
}
bool IsPalin(string i)
/*Returns a Boolean variable if string is/isn't a palindrome. */
{
    string letstring=JustLetters(i);
    string reversestring= Reverse(i);
    bool done=true
    for (int x = 0; x <= upperstring.length(); x ++ ){
        if (letstring[x] == reversestring[x]){
            return(true);
        else
            return(false);
        }
    }

}
int main()
{

}
