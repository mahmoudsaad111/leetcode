class Solution {
public:
    int arr[501] ;
    int dp(int ind,vector<int>&vec,int k){
        if(ind==vec.size())return  0;
        int &ret=arr[ind] ;
        if(ret!=-1)return ret ;
        int mx=0 ;
        for(int i=ind;i<min((int)vec.size(),ind+k);i++){
            mx=max(mx,vec[i]) ;
            ret=max(ret,dp(i+1,vec,k)+mx*(i-ind+1)); 
        }
            
        return ret; 
    }
    int maxSumAfterPartitioning(vector<int>&vec, int k) {
        memset(arr,-1,sizeof(arr)) ; 
        return dp(0,vec,k) ;
        
    }
};