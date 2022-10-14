class Solution {
public:
    int arr[1001]; 
    int dp(int m,vector<int>&vec){
        if(!m)return 1; 
        int &ret=arr[m]; 
        if(ret!=-1)return ret; 
        ret=0 ;
       for(int i=0;i<vec.size();i++){
           if(vec[i]<=m){
               ret+=dp(m-vec[i],vec) ; 
           }
       }
        return ret; 
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(arr,-1,sizeof(arr)) ;
        return dp(target,nums); 
    }
};