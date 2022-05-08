// https://leetcode.com/problems/pascals-triangle/

/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
We can see every edge element is 1 and the inner elements are sum of two values of the above row, i.e matrix[i][j]=matrix[i-1][j]+matrix[i-1][j-1].
So we can build the matrix accordingly.
T.C : O(numRows*numRows)
S.C : O(numRows*numRows)
*/

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for(int i=0; i<numRows; i++){
        ans[i].resize(i+1);
        ans[i][0] = 1, ans[i][i] = 1;
        for(int j=1; j<i; j++)
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
    }
    return ans;
}