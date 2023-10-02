int find(vector<int> arr, int value) {
        int d = 1;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) 
        {
            if (sum + arr[i] > value) {
                 d = d+1; // element will be loaded next day
                sum = arr[i]; // next day element will be start to load from index where limit was exceeded last day
            } 
            else 
            {
                sum = sum + arr[i];
            }
         }
        return d;
    }
int leastWeightCapacity(vector<int> &weights, int days)
{
    int ans = 0;
        int maximum = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int low = maximum;
        int high = sum;
        while (low <= high) {
            int mid = (low + high) / 2;
            int numberOfdays = find(weights, mid);
            if (numberOfdays <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
}