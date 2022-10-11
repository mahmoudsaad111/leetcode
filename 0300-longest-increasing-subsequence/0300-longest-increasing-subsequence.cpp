class Solution {
public:
    vector<int>vec; 
     int arr[2502][2502]; 
    int dp(int ind,int last,vector<int>&vec){
        if(ind==vec.size()-1)return 0;
        int &ret=arr[ind][last];
        if(ret!=-1)return ret; 
        
        ret=dp(ind+1,last,vec); 
        if(vec[ind]>vec[last])ret=max(ret,dp(ind+1,ind,vec)+1); 
        return ret; 
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(arr,-1,sizeof(arr)); 
        nums.push_back(-1e6); 
     return dp(0,nums.size()-1,nums) ;
    }
};