/*
Link : https://leetcode.com/problems/reverse-pairs/

Optimal Approach : Using Ordered Set
T.C : O(nlogn)

*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set oset;
        int cnt = 0;
        for(int i=nums.size()-1; i>=0; i--){
            cnt += oset.order_of_key(nums[i]);
            oset.insert(1ll*nums[i]*2);
        }
        return cnt;
    }
};

/*
1. Brute force solution can be to traverse the array using 2 loops and check every pair where i<j and arr[i]>2*arr[j].
T.C : O(n^2)
*/