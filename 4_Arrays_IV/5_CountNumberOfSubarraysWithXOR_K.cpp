/*
Link : https://www.interviewbit.com/problems/subarray-with-given-xor/

Optimal Approach : Using map, 
T.C : O(n)
S.C : O(n)
*/
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    int xxor = 0;
    long long cnt = 0;
    for(int i=0; i<A.size(); i++){
        xxor ^= A[i];
        if(xxor == B)
            cnt++;
        int y = xxor^B;
        if(mp.find(y) != mp.end()){
            cnt += mp[y];
        }
        mp[xxor]++;
    }
    return cnt;
}


/*
1. BRUTE FORCE : Using 2 for loops, check for every subarray's xor.
T.C : O(n^2)
S.C : O(1)
*/
int Solution::solve(vector<int> &A, int B) {
    int cnt = 0;
    for(int i=0; i<A.size(); i++){
        int xxor = 0;
        for(int j=i; j<A.size(); j++){
            xxor ^= A[j];
            if(xxor == B)
            cnt++;
        }
    }    
    return cnt;
}