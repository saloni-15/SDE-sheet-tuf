/*
Link : https://leetcode.com/problems/4sum/

Generalized for K sum problems
After sorting the array, we can use k-2 outer loops for k-2 variables and one inner loop for 2 sum using two pointers for remaining 2 variables.
T.C : O(n^(k-1)) and o(n^3) for 4sum
S.C : O(n)

*/
 vector<vector<int>> fourSum(vector<int>& nums, int target1) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0; i<n-3; i++){
        int target2 = target1-nums[i];
        for(int j=i+1; j<n-2; j++){
            int target3 = target2-nums[j];
            int beg = j+1, end = n-1;
            while(beg<end){
                int sum = nums[beg] + nums[end];
                if(sum==target3){
                    vector<int> quad = {nums[i], nums[j], nums[beg], nums[end]};
                    ans.push_back(quad);
                    while(beg<end and nums[beg]==quad[2]) beg++;
                    while(beg<end and nums[end]==quad[3]) end--;
                }
                else if(sum>target3) end--;
                else if(sum<target3) beg++;
            }
            while(j+1<n-2 and nums[j]==nums[j+1]) j++;
        }
        while(i+1<n-3 and nums[i]==nums[i+1]) i++;
    }
    return ans;
}