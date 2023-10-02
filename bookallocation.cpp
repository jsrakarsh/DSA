int no_of_students(vector<int>arr,int value)
{   
    // value means the no.of pages for which we have to check;
    int students=1; 
    int current=0;  // this variable to show the current page holded by student 1
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]+current <= value)
        {
            current+= arr[i];
        }
        else{
            students++ ; //when limit exceeds to hold page..shift to next student
                        // and update the current to 0;
            current = arr[i];
        }

    }
    return students;
}
int findPages(vector<int>& arr, int n, int m) {
    //if no. of students exceeds than no. of books in array
    if(m>n)
    {
        return -1;
    }
    int ans;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(), 0 );
    while(low<=high)
    {
        int mid=(low+high)/2;
        int students= no_of_students(arr,mid);
        if(students > m)
        {   
            low = mid+1;
        }
        else
        {
            ans = mid;
            high =mid -1;
        }
    }
    return ans;
}