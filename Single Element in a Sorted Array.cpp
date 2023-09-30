/*int singleNonDuplicate(vector<int>& arr)
{   //BRUTE FORCE   O(n)
    int n = arr.size();
    int answer;

    if (n == 1)
    {
        return arr[0];
    }

    for (int i = 0; i < n - 1; i += 2)
    {
       if(i==0)//1st postion
       {
           if(arr[i]!=arr[i+1])
           {
               return arr[i];
           }
       }
       else if(i==n-1)//Last Position
       {
           if(arr[i]!=arr[i-1])
           {
               return arr[i];
           }
       }
       else //IN BETWEEN POSITION
       {
           if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1])
           {
               return arr[i];
           }
       }
    }
}
*/
int single_element(vector<int>&arr,int n)
{
    if(arr[0]!=arr[1])
    {
        return arr[0];
    }
      if(arr[n-1]!=arr[n-2])
      {
          return arr[n-1];
      }
      int low=1;
    int high=n-2;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])
        {
            return arr[mid];
        }

        if((mid % 2==0 && arr[mid]==arr[mid+1]) || (mid % 2==1 && arr[mid]==arr  [mid-1]))
        {
            //single element is on right because we found out that even and odd position element are equal
            low=mid+1;
        }
        else // single element is on left 
        {
            high=mid-1;
        }
    }
    return -1;
}
int singleNonDuplicate(vector<int>& nums)
{
    int n=nums.size();
       int ans= single_element(nums,n);
       return ans;
}
