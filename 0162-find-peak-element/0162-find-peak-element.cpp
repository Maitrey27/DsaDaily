class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n =arr.size();

        int left = 1;
        int right = n-2; //bcz first and last element are always lower than all others

        while(left<=right)
        {
            int mid = left + (right-left)/2;

            if(arr[mid-1]<arr[mid]  && arr[mid]>arr[mid+1])
            {
                //first peak elemnt found
                return mid;
            }
            else if(arr[mid-1]>arr[mid])
            {
                //left nbr has value greater so possiblity that peak can exist on left
                right  = mid-1; //move left
            }
            else{
                //right nbr has value greater (arr[mid]<arr[mid+1]) peak on right side
                left = mid+1; //move right
            }
        }

        return 0; //not found
    }
};