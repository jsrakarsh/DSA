
int first(vector<int>&arr,int n,int target)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid] == target) 
        {
          ans = mid;
          high = mid - 1;
        }
        else if(arr[mid] > target)
        {
            high=mid-1;
        }
        else // for searching in right
        {
            low=mid+1;
        }

    }
    return ans;
}
int last(vector<int>&arr,int n,int target)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid] == target) 
        {
          ans = mid;
          low= mid + 1;
        }
        else if(arr[mid] < target)
        {
            low= mid + 1;
        }
        else // for searching in left
        {
            high= mid - 1;
        }

    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
   int first_occurence= first(arr,n,k);
       if(first_occurence == -1)
       return {-1,-1};
    int last_occurence= last(arr,n,k);
    return {first_occurence,last_occurence};
}

