#include <iostream>
using namespace std;
int main()
{
 unsigned long long int n,m,k,j,p;
 int flag;
 cin>>n;
 cin>>m;
 flag=0;
 int test[2];
 test[0]=1;
 test[1]=1;
 for(j=3;j<=n;j++)
 {
  if((test[0]==0)&&(test[1]==1))
   { 
     flag=1;
     break;
   }
  else 
  {
   p=(test[0]+test[1])%m;
   test[0]=test[1];
   test[1]=p;
   }
   
 }
 if (flag==1)
   k= n%(j-2);
 else 
   k=n;
 unsigned long int fibb[k+1];
 fibb[0]=0;
 fibb[1]=1;
 fibb[2]=1;
 for(j=3;j<=k;j++)
 {
  fibb[j]=(fibb[j-1]+fibb[j-2])%m;
  /*cout<<fibb[j]<<"\n";*/
  }
 /*cout<<k<<","<<(j-2)<<"\n";*/
 cout<<fibb[k];
 cout<<'\n'; 
 }
