/* Link : https://www.codingninjas.com/codestudio/problems/count-inversions_615
   - Optimal approach using MERGE SORT : 
*/
long long int merge(long long arr[], long long left_start, long long right_start, long long right_end){
    long long int count=0;
    long long i=left_start, j=right_start, k=0;
    long long temp[right_end - left_start +1];
    while(i<right_start && j<=right_end){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            count+=right_start-i;  
        } 
        
    }
    while(i<right_start) temp[k++]=arr[i++];
    while(j<=right_end) temp[k++]=arr[j++];
    
    for(long long i=left_start,k=0;i<=right_end;i++,k++) arr[i]=temp[k];
    return count;
}
    
long long int merge_sort(long long arr[], long long left, long long right){
    long long int count=0;
    while(right>left){
        long long mid = (left+right)/2;
        long long int leftCount = merge_sort(arr, left, mid);
        long long int rightCount = merge_sort(arr, mid+1, right);
        long long int mergeCount = merge(arr, left, mid+1, right);
        return leftCount+rightCount+mergeCount;
    }
    return count;
    
}
    
long long int inversionCount(long long arr[], long long N)
{
    long long int ans = merge_sort(arr, 0, N-1);
    return ans;
}



/*
2. Using ordered_set
T.C : O(nlogn)
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>

long long getInversions(long long *arr, int n){
       ordered_set oset;
       long long ans = 0;
       for(long long i = n-1; i>=0; i--){
           ans += oset.order_of_key(arr[i]);
           oset.insert(arr[i]);
       }
       return ans;
}


/*
1. BRUTE FORCE : Simply run two loops, i from 0 to n and j from i+1 to n, if there exists a pair where arr[i]>arr[j], increase count.
T.C : O(n*n) 
S.C : O(1)
*/
long long getInversions(long long *arr, int n){
	long long cnt = 0;
    for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[i])
				cnt++;
		}
	}
	return cnt;
}
int cnt 