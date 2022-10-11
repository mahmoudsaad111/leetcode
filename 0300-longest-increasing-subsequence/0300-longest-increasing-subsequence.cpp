class Solution {
public:
    vector<int>vec; 
     int arr[2502]; 
    int dp(int ind,vector<int>&vec){
        if(ind==vec.size())return 0;
        int &ret=arr[ind];
        if(ret!=-1)return ret; 
        ret=0 ;
          for(int i=ind+1;i<vec.size();i++){
              if(vec[i]>vec[ind])ret=max(ret,dp(i,vec)) ;
          }
        ret+=1;
        return ret; 
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(arr,-1,sizeof(arr)); 
        int ans=0; 
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dp(i,nums)) ;
        }
     return ans;
    }
};