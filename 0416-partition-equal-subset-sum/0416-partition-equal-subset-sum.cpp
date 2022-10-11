class Solution {
public:
    int arr[201][20001]; 
    int dp(int ind,int sum1,int sum2,vector<int>&vec){
        if(ind==vec.size())return sum1==sum2;
        int &ret=arr[ind][sum1] ;
        if(ret!=-1)return ret; 
        ret=max(dp(ind+1,sum1+vec[ind],sum2,vec),dp(ind+1,sum1,sum2+vec[ind],vec)); 
    return ret;         
    }
    bool canPartition(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        return dp(0,0,0,nums) ;
        
    }
};