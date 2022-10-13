class Solution {
public:
    long long arr[60]; 
    long long dp(int n,int cnt){
        if(!n)return (cnt>=2);
        long long &ret=arr[n];
        if(ret)return ret; 
        for(int i=1;i<=n;i++){
            ret=max(ret,dp(n-i,cnt+1)*i) ;
        }
        return ret;
    }
    int integerBreak(int n) {
       memset(arr,0,sizeof(arr)) ;
        return dp(n,0); 
        
    }
};