//https://leetcode.com/problems/rotate-image/

/*
2. SPACE OPTIMIZED INPLACE SOLUTION : We can observe that the rotated matrix is the transpose of the reverse of given matrix.
    first reverse up to down, then transpose it
    1 2 3     7 8 9     7 4 1
    4 5 6  => 4 5 6  => 8 5 2
    7 8 9     1 2 3     9 6 3
T.C : O(n*n)
S.C : O(1)
*/
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    //reverse matrix upto down
    reverse(matrix.begin(), matrix.end());
    //transpose the matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    } 
}

/*
1. USING DUMMY MATRIX : We can use a dummy matrix and can put the 1st row of the given matrix into last col of dummy matrix, 2nd row of given matrix to 2nd last col of dummy matrix.
T.C : O(n*n)
S.C : O(n*n)
*/
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int> (n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rotated[j][n-i-1] = matrix[i][j];
        }
    }
}