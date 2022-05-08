//https://leetcode.com/problems/sort-colors/

/*
DUTCH NATIONAL FLAG ALGORITHM : using 3 pointers named low, mid, and high. We will be using these 3 pointers to move around the values. The primary goal here is to move 0s to the left and 2s to the right of the array and at the same time all the 1s shall be in the middle region of the array and hence the array will be sorted.
T.C : o(n)
S.C : O(1)
*/
void sortColors(vector<int>& nums) {
    int beg = 0, mid = 0, end = nums.size()-1;
    //considering mid
    while(mid<=end){
        if(nums[mid] == 0)
            swap(nums[mid++], nums[beg++]);
        else if(nums[mid] == 1)
            mid++;
        else if(nums[mid] == 2)
            swap(nums[mid++], nums[end--]);
    }
}

/*
Naive approaches can be to simply sort the array which will take O(nlogn) runtime and the second approach can be counting the 0s, 1s and 2s and updating the array accordingly which will be a two pass solution.
*/