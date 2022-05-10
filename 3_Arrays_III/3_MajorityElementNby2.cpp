/*
Link : https://leetcode.com/problems/majority-element/

Optimal Approach : Boyer-Moore Voting Algorithm
If we had some way of counting instances of the majority element as +1+1 and instances of any other element as -1−1, summing them would make it obvious that the majority element is indeed the majority element.
T.C : O(n) 
S.C : O(1)

*/
int majorityElement(vector<int>& nums) {
    int candidate;
    int cnt = 0;
    for(int i=0; i<nums.size(); i++){
        if(cnt == 0)
            candidate = nums[i];
        (candidate==nums[i]) ? cnt++ : cnt--;
    }
    return candidate;
}


/*
1. Brute force method will be to check if each element is majority element. Using 2 loops we can count the occurence of each element.
T.C : O(n^2) S.C : O(1)

2. An efficient approach can be to check frequency of all the elements using a hashmap and the element with frequency >= n/2 will be the answer.
T.C : O(n) S.C : O(n)

3. Another approach can be to sort the array and as the majority element will appear more than n/2 times the middle element of the sorted array will always be a majority element.
T.C : O(nlogn) S.C : O(1)
*/