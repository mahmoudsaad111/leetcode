class Solution {
public:
    bool dfs(vector<vector<int>>&vec,vector<int>&visted,int ind,int color){
        if(!visted[ind])visted[ind]=color ;
        else if(visted[ind]!=color)return false;
        else return true;
        for(int i=0;i<vec[ind].size();i++)
            if(!dfs(vec,visted,vec[ind][i],3-color))return false;
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>visted(n+1);
        vector<vector<int>>vec(n+1) ;
        for(int i=0;i<dislikes.size();i++){
            vec[dislikes[i][0]].push_back(dislikes[i][1]);
            vec[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(!visted[i]){
                if(!dfs(vec,visted,i,1))return false;
            }
        }
        return true;
    }
};