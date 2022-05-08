//https://leetcode.com/problems/maximum-subarray/

/*
KADANE'S ALGORITHM : the problem can be solved in O(1) TC, using kadane's algorithm.
Approach is to traverse the array and storing the contiguous sum in curr_sum and max sum in max_sum, the moment curr_sum becomes -ve it will reduces the whole subarray max_sum thus, we will make curr_sum = 0 and will start new subarray linearly.
T.C : O(1)
S.c : O(1)
*/
int maxSubArray(vector<int>& nums) {
    int curr_sum = 0, max_sum = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        curr_sum += nums[i];
        max_sum = max(max_sum, curr_sum);
        if(curr_sum<0)
            curr_sum = 0;
    }
    return max_sum;
}

/*
2. NAIVE : Using 2 loops
T.C : O(n^2)
S.C : O(1)
*/
int maxSubArray(vector<int>& nums) {
    int max_sum = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        int curr_sum = 0;
        for(int j=i; j<nums.size(); j++){
            curr_sum += nums[j];
            max_sum = max(curr_sum, max_sum);
        }
    }
    return max_sum;
}

/*
1. NAIVE : Using 3 loops, we can get all possible subarrays using 2 loops and their sums using the 3rd loop
T.C : O(n^3)
S.C : O(1)
*/
 int maxSubArray(vector<int>& nums) {
    int max_sum = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            int curr_sum = 0;
            for(int k=i; k<=j; k++)
                curr_sum += nums[k];
            max_sum = max(curr_sum, max_sum);
        }
    }
    return max_sum;
}