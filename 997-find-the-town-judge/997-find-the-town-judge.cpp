class Solution {
public:
int findJudge(int n, vector<vector<int>>& trust) {
	if (n == 1)
		return 1; 
	vector<int>vec(n + 1); 
	for (int i = 0; i < trust.size(); i++){
		vec[trust[i][0]]--; 
		vec[trust[i][1]]++;

	}
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] == n - 1){
			return i;
		}	}
	return -1; 
}
};