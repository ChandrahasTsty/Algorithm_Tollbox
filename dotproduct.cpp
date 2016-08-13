#include <iostream>
using namespace std;
void sort(long int* input, int size)
{
 int  buffer[size];
 int k,i,h;
 for(k=0;k<size;k++)
  buffer[k]=0;
 int  enter;
 for(k=0;k<size;k++)
 {
  enter=1;
  for(i=k-1;i>=0;i--)
  {
   if((enter==1)&&(*(input+k)>buffer[i]))
    {
     if(i==k-1)
     {
      buffer[k]=*(input+k);
      enter=0;
     }
     else 
     {
     for(h=k-1;h>=(i+1);h--)
      buffer[h+1]=buffer[h];
     buffer[i+1]=*(input+k);
     enter=0;
     }
    }
  }
  if(enter==1)
  {
   for(h=k-1;h>=0;h--)
      buffer[h+1]=buffer[h];
   buffer[0]=*(input+k);
  }
 }
for(k=0;k<size;k++)
 *(input+k)=buffer[k];

} 
int main(void)
{
 int n;
 cin>>n;
 long int a[n];
 long int b[n];
 int k;
 long int result=0;
 for(k=0;k<n;k++)
  cin>>a[k];
 for(k=0;k<n;k++)
  cin>>b[k];
  
 sort(a,n);
 sort(b,n);
 for(k=0;k<n;k++)
  result=result+(a[k]*b[n-1-k]);
 cout<<result<<"\n";
 return 0;
 }
  
