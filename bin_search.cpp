#include <iostream>
using namespace std;

long int bin_search(long long int* a,long int start_index,long int end_index,long long int key);
int main(void)
{
    long int n,k,p;
    cin>>n;
    long long int a[n];
    for(p=0;p<n;p++)
    {
      cin>>a[p];
    }
    cin>>k;
    long long int keys[k];
    for(p=0;p<k;p++)
    {
      cin>>keys[p];
    }
    //cout<<"Reached Here !!"<<"\n";
    for(p=0;p<k;p++)
    {
      cout<<bin_search(a,0,n-1,keys[p])<<" ";
    }
    cout<<"\n";
    return 0;
}
long int bin_search(long long int* a,long int start_index,long int end_index,long long int key)
{
    long int f=((end_index+start_index)+1)/2;
    if(start_index==end_index)
    {
      if(*(a+start_index)==key)
      {
        return start_index;
      }
      else
      {
        return -1;
      }
    }
    else if(start_index>end_index)
    {
      return -1;
    }
    else
    {
      if(*(a+f)>key)
      {
        bin_search(a,start_index,f-1,key);
      }
      else if(*(a+f)==key)
      {
        return f;
      }
      else
      {
        bin_search(a,f+1,end_index,key);
      }
    }

}
