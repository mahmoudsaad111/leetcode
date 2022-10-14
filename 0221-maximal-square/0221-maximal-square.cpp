class Solution {
public:
    int arr[301][301]; 
    int dp(int i,int j,vector<vector<char>>&vec){
       if(i<0||j<0||vec[i][j]=='0')return  0;
        int &ret=arr[i][j]; 
        if(ret!=-1)return ret; 
        ret=min({dp(i-1,j,vec),dp(i,j-1,vec),dp(i-1,j-1,vec)})+1; 
   return ret;         
    }
    int maximalSquare(vector<vector<char>>&vec) {
      memset(arr,-1,sizeof(arr)) ; 
        int ans=0 ;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[0].size();j++){
                ans=max(ans,dp(i,j,vec)) ;
            }
        }
        return ans*ans; 
    }
};