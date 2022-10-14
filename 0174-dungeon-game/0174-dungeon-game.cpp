class Solution {
public:
    int arr[201][201] ;
    int dp(int i,int j,vector<vector<int>>&vec){
        if(i>=vec.size()||j>=vec[0].size())return 1e9; 
        if(i==vec.size()-1&&j==vec[0].size()-1){
            if(vec[i][j]<0)return 1-vec[i][j] ;
            return  1;
        }
        int &ret=arr[i][j] ;
        if(ret!=1e9)return ret; 
       ret=min(dp(i+1,j,vec),dp(i,j+1,vec)); 
        if(vec[i][j]>=ret)return ret=1; 
        return ret=ret-vec[i][j]; 
    }
    int calculateMinimumHP(vector<vector<int>>&vec) {
        for(int i=0;i<201;i++)
            for(int j=0;j<201;j++)arr[i][j]=1e9; 
        return dp(0,0,vec); 
    }
};