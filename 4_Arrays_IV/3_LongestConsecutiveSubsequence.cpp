/* Link : https://leetcode.com/problems/longest-consecutive-sequence

Optimal Approach : Using set, we can insert all the elements into set and traverse the and for each element we can check if there consecutive elements are present in the set or not. 
T.C : O(n)
S.C : O(n)

*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxlen(0);
        for(auto it : nums) 
            st.insert(it);
        for(auto num : nums){
            if(!st.count(num-1)){ //if consecutively number not present
                int curr = num;
                int len = 1;
                while(st.count(curr+1)){ //check for consecutively greater numbers
                    curr++;
                    len++;
                }
                maxlen = max(len, maxlen);
            }
        }
        return maxlen;
    }
};

/*
2. Sorting : Sort the array and iterate in ascending order and check for the longest consecutive sequence.
T.C : O(nlogn)
S.C : O(1)
*/
int longestConsecutive(vector<int>& nums) {
    if(!nums.size()) return 0;
    sort(nums.begin(), nums.end());
    int maxlen(1), len(1), prev(nums[0]);
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==nums[i-1])
            continue;
        else if(nums[i]==prev+1)
            len++;
        else if(nums[i]!=prev+1)
            len = 1;
        prev = nums[i];
        maxlen = max(len, maxlen);
    }
    return maxlen;
}

/*
1. BRUTE FORCE : We can simply run 3 loops to check for consecutive elements for each element in array.
T.C : O(n^3)
S.C : O(1)
*/