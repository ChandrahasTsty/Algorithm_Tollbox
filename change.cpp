#include <iostream>
using namespace std;
int main()
{
 int input;
 cin>>input;
 int change=0;
 change=change+(input/10);
 input=input%10;
 change=change+(input/5);
 input=input%5;
 change=change+input;
 cout<<change<<"\n";
 }
