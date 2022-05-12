/* Link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

Optimal Approach : Using Hashing, we can store the sum and index till current element in the map and whenever we get a sum at current index (i) which is already present in the map at index (idx) we can say that sum from index i to index idx will be Zero.
T.C : O(n)
S.C : O(n)

*/
int maxLen(vector<int>&A, int n){   
    int maxlen(0), sum(0);
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        sum += A[i];
        if(sum==0)
            maxlen = i+1;
        else{
            if(mp.find(sum) != mp.end())
                maxlen = max(maxlen, i-mp[sum]);
            else
                mp.insert({sum, i});
        }
        
    }
    return maxlen;
    
}

/*
1. BRUTE FORCE : Check for the sum of all possible subarrays using 2 nested loops and return the length of largest subarray.
T.C : O(n^2)
S.C : O(1)
*/
int maxLen(vector<int>&A, int n){   
    int maxlen = 0;
    for(int i=0; i<n; i++){
        int sum = A[i];
        for(int j=i+1; j<n; j++){
            sum += A[j];
            if(sum==0)
            maxlen = max(j-i+1, maxlen);
        }
    }
    return maxlen;
    
}