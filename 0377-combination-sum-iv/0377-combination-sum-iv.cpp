class Solution {
public:
    int arr[1001][201]; 
    int dp(int ind,int m,vector<int>&vec){
        if(!m)return 1; 
        if(ind>=vec.size())return 0 ;
        int &ret=arr[m][ind]; 
        if(ret!=-1)return ret; 
        ret=0 ;
       for(int i=0;i<vec.size();i++){
           if(vec[i]<=m){
               ret+=dp(i,m-vec[i],vec) ; 
           }
       }
        return ret; 
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(arr,-1,sizeof(arr)) ;
        return dp(0,target,nums); 
    }
};