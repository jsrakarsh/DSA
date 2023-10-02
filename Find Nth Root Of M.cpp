int find(int mid,int n,int m)
{
  long long answer=1;              // if find==m return 1
  for(int i=1;i<=n;i++)           // if find<m return 0
  {                               //if find >m return 2
    answer=answer*mid;
    if(answer>m)
    {
      return 2;
    }
  }
  if (answer==m)
  {
    return 1;
  }
 return 0;
}
int NthRoot(int n, int m) {
int low=1;
int high=m;
while(low<=high)
{
  int mid=(low+high)/2;
  int answer=find(mid,n,m);
  if(answer==1)
  {
    return mid;
  }
  else if(answer==0)
  {
    low=mid+1;
  }
  else
  {
    high=mid-1;
  }
}
return -1;
}