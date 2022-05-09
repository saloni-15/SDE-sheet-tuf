/*
Link: https://leetcode.com/problems/find-the-duplicate-number/

- Optimal approach will be to use Linked list cycle method. Since there is a duplicate number, there will be a cycle.

T.C : O(n)
S.C : O(1)
*/
int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    slow = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

/*
- One approach can be to sort the array and linearly traverse it, the duplicate number will come in adjacent. (nlogn)
- Second can be to use frequency array, which will take linear time but O(n) extra space.
*/