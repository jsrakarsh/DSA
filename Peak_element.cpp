
 int findPeakElement(vector<int>& arr) 
 {
        int n=arr.size();
        int i;
        //starting element seperate case
        if(i==0 && arr[0]>arr[1])
        {
            return 0;
        }
        //last element seperate case
        if(arr[n-1]>arr[n-2])
        {
            return n-1;
        }
        int low=1;
        int high=n-2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if((arr[mid]>arr[mid-1]) && (arr[mid]>arr[mid+1]))
            {
                return mid;
            }
            else if(arr[mid]>arr[mid-1])//peak element at right
            {
                low=mid+1;
            }
            else if(arr[mid]<arr[mid-1])//peak element at left
            {
                high=mid-1;
            }
            //FOR MULTIPLE PEAK QUESTION JUST ADD ONE else CASE IN THIS CODE
            //else
            //{
                low=mid+1;
           // }
        }
        return -1;
 }
