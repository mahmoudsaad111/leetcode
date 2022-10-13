class Solution {
public:
    int arr[1000] ;
    int dp(int ind ,vector<int>&vec){
        if(ind>=vec.size())return 0;
        int &ret=arr[ind]; 
        if(ret!=-1)return ret; 
        ret=min(dp(ind+1,vec),dp(ind+2,vec))+vec[ind] ;
        return ret; 
    }
    int minCostClimbingStairs(vector<int>& vec) {
        memset(arr,-1,sizeof(arr)) ;
        return min(dp(0,vec),dp(1,vec)) ;
        
    }
};