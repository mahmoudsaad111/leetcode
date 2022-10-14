class Solution {
public:
    int arr[101][101];
    int dp(int i,int j,vector<vector<int>>&vec){
        if(i==vec.size()-1&&j==vec[0].size()-1)return 1; 
        int &ret=arr[i][j]; 
        if(ret!=-1)return ret; 
        ret=0 ;
        if(i+1<vec.size()&&!vec[i+1][j])ret+=dp(i+1,j,vec) ;
         if(j+1<vec[0].size()&&!vec[i][j+1])ret+=dp(i,j+1,vec) ;
        return ret; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>&vec) {
        memset(arr,-1,sizeof(arr)); 
        if(vec[0][0])return 0 ;
        return dp(0,0,vec) ;
        
    }
};