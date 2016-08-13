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
  long int p[n][2];
  long int a[n];
  long int b[n];
  long int distance[100];
  int k,t,buff,s,buff_len,crp;
  long int coveredtill=0;
  long int result[100];
  long int buffer[100];
  int lr=0;
  for(k=0;k<n;k++)
  {
      cin>>p[k][0];
      cin>>p[k][1];   
  }
 
  for(k=0;k<n;k++)
  {
    a[k]=p[k][0];
  }
  sort(a,n);
  int copied[n];
  int flag=0;
 for(k=0;k<n;k++)
  copied[k]=0;
  
  for(k=0;k<n;k++)
  {
    flag=0;
    for(t=0;t<n;t++)
      if((p[t][0]==a[k])&&(copied[t]==0)&&(flag==0))
      {
        b[k]=p[t][1];
        copied[t]=1;
        flag=1;
      } 
    }
  for(k=0;k<n;k++)
  {
   p[k][0]=a[k];
   p[k][1]=b[k];
   //cout<<p[k][0]<<","<<p[k][1]<<"\n";
  }
  for(k=0;k<n;k++)
  {
   buffer[0]=p[k][1];
   buff_len=1;
   for(t=k+1;t<n;t++)
   {
     crp=k;
     if(p[t][0]>p[k][0])
      goto eol;
   
     else
     {
      buffer[buff_len]=p[t][1];
      buff_len=buff_len+1;
      if((p[t+1][0]>p[k][0])||((t+1)==n))
       {
        sort(buffer,buff_len);
        for(s=0;s<buff_len;s++)
         p[t-s][1]=buffer[buff_len-1-s];
       }
     }
   }
   eol:
      buff_len=1;
  }
   for(k=0;k<n;k++)
  {
   //cout<<p[k][0]<<","<<p[k][1]<<"\n";
  }
  lr=0;
  for(k=0;k<n;k++)
  {
   if((coveredtill<p[k][0])||((p[k][0]==0)&&(coveredtill==0)))
   {
    s=0;
    for(t=k;t<n;t++)
    {
       distance[s]=p[t][1]-coveredtill;
       s=s+1;
    }
    sort(distance,s);
    result[lr]=coveredtill+distance[0];
    coveredtill=coveredtill+distance[0];
    lr=lr+1;
   }
  }
  cout<<lr<<"\n";
  for(k=0;k<lr;k++)
   cout<<result[k]<<" ";
  cout<<"\n";
 return 0;   
 }
 
    
    
    
    
