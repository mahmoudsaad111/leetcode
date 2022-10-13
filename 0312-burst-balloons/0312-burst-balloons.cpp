class Solution {
public:
    int arr[301][301]; 
    int dp(int i,int j,vector<int>&vec){
        if(i>j)return 0 ;
        int &ret=arr[i][j] ;
        if(ret!=-1)return ret ;
        for(int k=i;k<=j;k++){
            ret=max(ret,vec[k]*vec[i-1]*vec[j+1]+dp(i,k-1,vec)+dp(k+1,j,vec));
        }
       
        return ret; 
        
    }
    int maxCoins(vector<int>&vec) {
        memset(arr,-1,sizeof(arr)) ;
        vector<int>v;
        v.push_back(1) ;
        for(int i=0;i<vec.size();i++)v.push_back(vec[i]); 
        v.push_back(1); 
        return dp(1,vec.size(),v) ;
    }
};