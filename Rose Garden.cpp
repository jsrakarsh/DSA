 bool find(vector<int> &arr, int n, int m, int k, int value) {
        int total_bouquets = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= value) {
                count++;
            } else {
                total_bouquets += (count / k);
                count = 0;
            }
        }
        total_bouquets += (count / k);
        return total_bouquets >= m;
    }
int roseGarden(vector<int> bloomDay, int k, int m)
{
	  long long val = static_cast<long long>(m) * static_cast<long long>(k); // Calculate val as a long long to avoid overflow
        if (val > bloomDay.size()) 
		{
            return -1;
        }
        
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            minimum = min(minimum, bloomDay[i]);
            maximum = max(maximum, bloomDay[i]);
        }
        int low = minimum;
        int high = maximum;
        int result = -1; // Store the result to handle cases where no valid answer is found
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid integer overflow
            bool ans = find(bloomDay, n, m, k, mid);
            if (ans == true) {
                result = mid; // Update result when a valid answer is found
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result; // Return the result after the binary search is complete
}