#include <iostream>
using namespace std;

typedef struct me_ret
{
  long long int maj_el;
  int present;
}me_ret;

me_ret major_element(long long int* a,long int start_index,long int end_index);

int main(void)
{
  long int n,p;
  cin>>n;
  long long int a[n];
  for(p=0;p<n;p++)
  {
    cin>>a[p];
  }
  me_ret result;
  result=major_element(a,0,n-1);
  cout/*<<result.maj_el<<" "*/<<result.present<<"\n";
  return 0;
}
me_ret major_element(long long int* a,long int start_index,long int end_index)
{
  long int j,h;
  me_ret ret,half1,half2;
  long int l,count,mj;
  long int f=(start_index+end_index+1)/2;

  if(end_index-start_index<=1)
  {
    if(*(a+start_index)==*(a+end_index))
    {
      ret.maj_el=*(a+start_index);
      ret.present=1;
    }
    else
    {
      ret.maj_el=0;
      ret.present=0;
    }
    return ret;
  }
  else
  {
    half1=major_element(a,start_index,f);
    half2=major_element(a,f+1,end_index);

    mj=0;
    if(half1.present==1)
      {
        count=0;
        mj=half1.maj_el;
        for(j=start_index;j<=end_index;j++)
          count=count+(*(a+j)==mj);
        if(count<=(((end_index-start_index+1)/2)))
        {
          half1.present=0;
        }
      }
    if(half2.present==1)
      {
        count=0;
        mj=half2.maj_el;
        for(j=start_index;j<=end_index;j++)
          count=count+(*(a+j)==mj);
        if(count<=(((end_index-start_index+1)/2)))
        {
          half2.present=0;
        }
      }
      if(half1.present==1)
      {
        ret.present=1;
        ret.maj_el=half1.maj_el;
      }
      else if(half2.present==1)
      {
        ret.present=1;
        ret.maj_el=half2.maj_el;
      }
      else
      {
        ret.present=0;
        ret.maj_el=0;
      }
      return ret;
    }
  /*  else
    {
      ret.present=0;
      ret.maj_el=0;
      return ret;
    } */
  }
