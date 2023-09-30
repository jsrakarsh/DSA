
int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans=10000;
    int index=-1;

    while (low <= high)
    {
        int mid=(low+high)/2;
        if(arr[low]<=arr[high])
        {
            ans=arr[low];
            index=low;
        }
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<ans)
            {
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        } 
        else 
        {
            if(arr[mid]<ans)
            {
                ans=arr[mid];
                index=mid;
            }
            high = mid - 1;
        }
    }
    return ans ;
}