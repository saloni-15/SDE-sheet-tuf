// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
2. OPTIMAL SOLUTION : We can maintain two variables minCost and maxProfit and we can minimize the minCost and maximize the maxProfit in single traversal.
T.C : O(n)
S.C :O(1)
*/
int maxProfit(vector<int>& prices) {
    int maxPro = 0, minCost = INT_MAX;
    for(auto it : prices){
        minCost = min(minCost, it);
        maxPro = max(maxPro, it-minCost);
    }
    return maxPro;
}

/*
1. BRUTE FORCE : Using two loops we can check the all possible transactions and maintain a max profit among all
T.C : O(n^2)
S.C : O(1)
*/
int maxProfit(vector<int>& prices) {
    int maxPro = 0;
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j]>prices[i])
                maxPro = max(maxPro, prices[j]-prices[i]);
        }
    }
    return maxPro;
}