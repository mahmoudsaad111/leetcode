class Solution {
public:
    int arr[101][101] ;
    int dp(int i,int  j,vector<vector<int>>&vec){
        if(i==vec.size()-1)return 0 ;
        int &ret=arr[i][j] ;
        if(ret!=1e9)return ret; 
        ret=dp(i+1,j,vec)+vec[i+1][j]; 
        if(j+1<vec[0].size())ret=min(ret,dp(i+1,j+1,vec)+vec[i+1][j+1]) ;
        if(j-1>=0)ret=min(ret,dp(i+1,j-1,vec)+vec[i+1][j-1]) ;
        return ret; 
    }
    int minFallingPathSum(vector<vector<int>>&vec) {
     for(int i=0;i<101;i++)
         for(int j=0;j<101;j++)arr[i][j]=1e9; 
        int ans=1e9 ;
        for(int i=0;i<vec[0].size();i++){
            ans=min(ans,dp(0,i,vec)+vec[0][i]); 
        }
        return ans; 
    }
};