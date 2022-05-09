/* Link : https://www.codingninjas.com/codestudio/problems/count-inversions_615
   - Optimal approach using MERGE SORT :

*/


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