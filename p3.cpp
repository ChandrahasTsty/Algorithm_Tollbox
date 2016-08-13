#include <iostream>
using namespace std;
int gcd(int *n1,int *n2);
void swap(int* a1,int *a2);
int main()
{
  int num1,num2;
  cin>>(num1);
  cin>>(num2);
  int ans=gcd(&num1,&num2);
  cout<<ans;
  cout<<'\n';
  }
void swap(int* a1,int *a2)
{
  *a1= *a1+*a2;
  *a2= *a1-*a2;
  *a1= *a1-*a2;
}
int gcd(int* n1,int* n2)
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
