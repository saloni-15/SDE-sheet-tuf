/*
2. Using maths, 
*/

/*
1. To use frequency array of 1 to n elements.
T.C : O(n)
S.C : O(n)
*/

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	vector<int> vec(n+1, 0);
	for(auto it : arr)
		vec[it]++;
	pair<int, int> ans;
	for(int i=1; i<=n; i++){
		if(vec[i]==0)
			ans.first = i;
		if(vec[i]==2)
			ans.second = i;
	}
	return ans;
	
}