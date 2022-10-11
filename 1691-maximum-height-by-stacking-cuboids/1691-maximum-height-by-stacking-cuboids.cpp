class Solution {
public:
    int arr[102][102]; 
    int dp(int ind,int last,vector<vector<int>>&vec){
        if(ind==vec.size())return  0;
        int &ret=arr[ind][last];
        if(ret!=-1)return ret;
        ret=dp(ind+1,last,vec) ;
    if(last==101||vec[ind][0]<=vec[last][0]&&vec[ind][1]<=vec[last][1]&&vec[ind][2]<=vec[last][2])
        ret=max(ret,dp(ind+1,ind,vec)+vec[ind][2]);
        
        
        return ret; 
    }
    int maxHeight(vector<vector<int>>&vec) {
        memset(arr,-1,sizeof(arr)); 
        for(int i=0;i<vec.size();i++)sort(vec[i].begin(),vec[i].end());
        sort(vec.begin(),vec.end()) ; 
        reverse(vec.begin(),vec.end()); 
     
        return dp(0,101,vec);
    }
};