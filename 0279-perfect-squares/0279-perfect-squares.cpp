class Solution {
public:
    int arr[10001] ;
    int dp(int n){
        if(!n)return 0; 
        int &ret=arr[n]; 
        if(ret!=-1)return ret; 
        ret=n;
        for(int i=1;i<=sqrt(n);i++){
            if(i*i<=n)ret=min(ret,dp(n-i*i)+1); 
        }
        return ret; 
        }
    int numSquares(int n) {
        memset(arr,-1,sizeof(arr)) ;
        return dp(n) ;
    }
};