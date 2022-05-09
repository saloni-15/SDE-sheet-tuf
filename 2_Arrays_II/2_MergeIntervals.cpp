//https://leetcode.com/problems/merge-intervals/

/*
We can first sort the array so that the overlapping intervals are bound to be adjacent so we can linearly iterate over the array and taking the current element compare it with the next element. 
T.C : O(nlogn)
S.C : O(n)
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    for(auto it : intervals){
        if(temp[1]>=it[0]){
            temp[1] = max(temp[1], it[1]);
        }
        else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
        
}