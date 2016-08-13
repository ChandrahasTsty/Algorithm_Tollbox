#include <iostream>
using namespace std;
int main()
{ 
  int length,k,l;
  cin>>length;
  int numbers[length];
  for (k=0; k< length;k++)
  cin >> numbers[k]; 

  long int buff[2];
  buff[0]=numbers[0];
  buff[1]=1;
  for(k=1;k<length;k++)
  {
   if(numbers[k]>buff[0])
   {
    buff[1]=buff[0];
    buff[0]=numbers[k];
   }
   else if(numbers[k]>buff[1])
   {
    buff[1]=numbers[k];
   }
  }
 cout<<buff[1]*buff[0];
  cout<<"\n";
}
