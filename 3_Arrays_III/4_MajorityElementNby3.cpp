/*
Link : https://leetcode.com/problems/majority-element-ii/

Optimal Approach : Boyer-Moore Voting algorithm, using this algorithm we can find two candidates in the array which will have the highest freqencies, then we can again count, if their frequencies is greater than n/3.
T.C : O(n)
S.C : O(1)
*/
vector<int> majorityElement(vector<int>& nums) {
    int x(-1), y(-1), cntX(0), cntY(0);
    for(auto num : nums){
        if(num==x) cntX++;
        else if(num==y) cntY++;
        else if(cntX==0) x=num, cntX++;
        else if(cntY==0) y=num, cntY++;
        else cntX--, cntY--;
    }
    cntX=cntY=0;
    for(auto num : nums){
        if(num==x) cntX++;
        else if(num==y) cntY++;
    }
    vector<int> ans;
    if(cntX>nums.size()/3) ans.push_back(x);
    if(cntY>nums.size()/3) ans.push_back(y);
    return ans;
}

/*
Another approaches are same as that for the majority element (n/2), the brute force and hashmap mathod.
*/