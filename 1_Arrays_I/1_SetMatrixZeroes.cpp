//https://leetcode.com/problems/set-matrix-zeroes/

/*
3. WITHOUT USING EXTRA VECTORS : instead of using extra vectors for rows and cols we can use the first row and first col of the matrix for the same to reduce space complexity. 
T.C : O(m*n)
S.c : O(1)
*/
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool col0 = false;
    for(int i=0; i<m; i++){
        if(matrix[i][0] == 0) //if 0th col has 0 or not (0,0 index handled seperately as it overlaps in first row and col)
            col0 = true;
        for(int j=1; j<n; j++){
            if(matrix[i][j] == 0)
                matrix[i][0] = 0, matrix[0][j] = 0;
        }
    }
    for(int i=m-1; i>=0; i--){ //traverse in reverse so that the first row and col is not computed first.
        for(int j=n-1; j>=1; j--){
            if(matrix[i][0]==0 or matrix[0][j]==0)
                matrix[i][j]=0;
        }
        if(col0 == true)
            matrix[i][0] = 0;
    }
}


/*
2. USING EXTRA VECTORS : use two vectors for row and col and traverse the matrix, whenever '0' is encountered, make row index in row vector and col index in col vector to '0'. Then again traverse the matrix and if that row is 0 or that col is 0, make matrix[i][j]=0
T.C : O(m*n)
S.C : O(m+n)
*/
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> row(m, 1), col(n, 1);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==0){
                row[i] = 0, col[j] = 0;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(row[i]==0 or col[j]==0)
                matrix[i][j] = 0;
        }
    }
}

/*
1. BRUTE FORCE : traverse the matrix and whenever '0' is encountered, traverse the same row and col and make all the elements zero.
T.C : O(m*n)*(m+n)
S.C: O(1)
*/
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==0){
                for(int k=0; k<n; k++)
                    if(matrix[i][k] != 0 or k==j)
                        matrix[i][k] = -1;
                for(int k=0; k<m; k++)
                    if(matrix[k][j] != 0 or k==i)
                        matrix[k][j] = -1;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==-1)
                matrix[i][j] = 0;
        }
    }
}