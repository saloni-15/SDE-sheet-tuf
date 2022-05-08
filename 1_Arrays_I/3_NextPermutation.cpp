// https://leetcode.com/problems/next-permutation/

/*
1) traverse from back and get index1 where a[i]<a[i+1]
2) again traverse from back and get first index2 where ele > arr[index1]
3) swap(arr[index1], arr[index2])
4) reverse(arr[index1+1], arr.end)
T.C : O(nums.size())
S.C : O(1)
*/

void nextPermutation(vector<int>& nums) {
    int idx1, idx2;  
    for(int i=nums.size()-2; i>=0; i--){
        if(nums[i]<nums[i+1]){ 
            idx1 = i; //break point of increasing sequence.
            break;
        }
    }
    //incase, the given combination is the last permutation, then next permutation will be the first combination
    if(idx1<0) 
        reverse(nums.begin(), nums.end());
    else{
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]>nums[idx1]){
                idx2 = i;
                break;
            }
        }
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin()+idx1+1, nums.end()); //to make rank as few as possible but greater than input array
    }
}