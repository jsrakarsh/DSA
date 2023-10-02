int find(vector<int> & arr,int target,int value)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum += ceil( (double) (arr[i]) / (double) (value) );
        }
        if (sum <= target) {
            return 1;
        }
        return -1;
}
int smallestDivisor(vector<int>& nums, int threshold)
{
	 int minimum=INT_MAX;
        int maximum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            minimum=min(minimum,nums[i]);
            maximum=max(maximum,nums[i]);
        }
        int low=minimum;
        int high=maximum;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int answer=find(nums,threshold,mid);
            if(answer==1)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
}