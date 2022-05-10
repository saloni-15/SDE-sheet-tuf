/*
Link : https://leetcode.com/problems/search-a-2d-matrix/

Optimal Approach: (Using Binary Search) We can start from first row, last col and can see if the element==key, if(ele>key) move back to previous col (j-1) or if (ele<key) move to next row (i+1).

T.C : O(log(m*n))
S.C : O(1)

*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i=0, j=matrix[0].size()-1;
    while(i<matrix.size() and j>=0){
        if(matrix[i][j]==target)
            return true;
        else if(matrix[i][j]>target)
            j--;
        else
            i++;
    }
    return false;
}


// 1.A naive approach can be to search the number by traversing the whole matrix, which will take O(m*n) runtime.
