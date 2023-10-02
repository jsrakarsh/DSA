bool find(vector<int> arr,int cows,int value)
    {
        int no_of_cow=1;
        int last=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-last >= value)
            {
                no_of_cow++;
                last=arr[i];
            }
        }
        if(no_of_cow >= cows)
        {
            return true;
        }
        else
        {
            return false;
        }
    }   
int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
     int ans;
        sort(stalls.begin(),stalls.end() );
        int low=0;
        int high= stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid= (low+high)/2;
            int answer = find(stalls,k,mid);
            if(answer == true)
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high= mid-1;
            }
        }
        return ans;
}