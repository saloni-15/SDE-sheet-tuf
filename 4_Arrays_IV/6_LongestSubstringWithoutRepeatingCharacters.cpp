/*
Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

Optimal Approach : Using set and sliding window, We can keep track of substring window with distinct characters.
T.C : O(n)
S.C : O(n)

*/
int lengthOfLongestSubstring(string s) {
    set<char> st;
    int i(0), j(0), maxlen(0);
    while(i<s.size() and j<s.size()){
        while(st.count(s[j])){
            st.erase(s[i]);
            i++;
        }
        st.insert(s[j]);
        maxlen = max(maxlen, j-i+1);
        j++;
    }
    return maxlen;
}