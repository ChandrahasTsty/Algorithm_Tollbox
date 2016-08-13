#include <iostream>
using namespace std;
long int gcd(long int *n1,long int *n2);
void swap(long int* a1,long int *a2);
int main()
{
  long int num1,num2;
  cin>>(num1);
  cin>>(num2);
  long int ans=num1*num2/gcd(&num1,&num2);
  cout<<ans;
  cout<<'\n';
  }
void swap(long int* a1,long int *a2)
{
  *a1= *a1+*a2;
  *a2= *a1-*a2;
  *a1= *a1-*a2;
}
long int gcd(long int* n1,long int* n2)
{
  if(*n2>*n1)
    swap(n1,n2);
    
  if(*n2==0)
    return *(n1);
  else 
  {
   *n1=(*n1)%(*n2);
   gcd(n1,n2);
  }
}
