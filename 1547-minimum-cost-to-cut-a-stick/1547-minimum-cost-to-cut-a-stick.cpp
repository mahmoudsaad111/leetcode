class Solution {
public:
    long long arr[105][105] ;
    long long dp(int i,int j,vector<int>&vec){
        if(i>j)return 0 ;
        long long &ret=arr[i][j]; 
        if(ret!=-1)return ret ;
        ret=1e7;
        for(int k=i;k<=j;k++){
            if(i)
            ret=min(ret,vec[j+1]-vec[i-1]+dp(i,k-1,vec)+dp(k+1,j,vec)) ;
            else 
            ret=min(ret,vec[j+1]+dp(i,k-1,vec)+dp(k+1,j,vec)) ;
        }
        return ret; 
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n) ;
        memset(arr,-1,sizeof(arr)) ;
        sort(cuts.begin(),cuts.end()) ;
        return dp(0,cuts.size()-2,cuts) ;
        
    }
};