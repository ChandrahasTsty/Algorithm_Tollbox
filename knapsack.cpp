#include <iostream>
using namespace std;

typedef struct max_ret{
double max_val;
int index;
}max_ret; 

/* Defnition of the maximum function */  
max_ret maximum(double* start,int size)
{
 
 max_ret ret;
 ret.max_val=*(start);
 ret.index=0;
 int i;
  for(i=0;i<size;i++)
   if(*(start+i)>ret.max_val)
    {
     ret.max_val=*(start+i);
     ret.index=i;
    }
 return ret;
}
int main(void)
{
  long int n,tw;
  cin>>n;
  cin>>tw;
  long int v[n],w[n];
  double vw[n];
  double result=0;
  int k;
  for(k=0;k<n;k++)
  {
    cin>>v[k];
    cin>>w[k];
    vw[k]=(double)v[k]/(double)w[k];
  }
  max_ret s;
  for(k=0;(k<n)&&(tw>0);k++)
  {
   s=maximum(vw,n);
   if(tw>=w[s.index])
   {
     result=result+v[s.index];
     tw=tw-w[s.index];
   }
   else 
   {
    result=result+(v[s.index]*((double)tw/(double)w[s.index]));
    //cout<<v[s.index]<<","<<tw<<","<<w[s.index]<<"\n";
    tw=0;
   }
   vw[s.index]=0;
   /*for(int p=0;p<n;p++)
    cout<<vw[p];
   cout<<"\n";*/
   }
  cout.precision(4);
  cout << fixed << result<< endl;
   return 0;
 }
