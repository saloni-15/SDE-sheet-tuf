/*
Link : https://leetcode.com/problems/two-sum/

Optimal Approach : Using Hashmap
T.C : O(n)
S.C : O(n)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for(int i=0; i<nums.size() ;i++){
        if(mp.find(target-nums[i]) != mp.end())
            return {i, mp[target-nums[i]]};
        mp[nums[i]] = i;
    }   
    return {};
}

/*
1. BRUTE FORCE : To run two loops and check every pair for the target.
T.C : O(n^2)
S.C : O(1)
*/
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size(); j++){
            if(i!=j and nums[i]+nums[j]==target)
                return {i, j};
        }
    }    
    return {};
}
