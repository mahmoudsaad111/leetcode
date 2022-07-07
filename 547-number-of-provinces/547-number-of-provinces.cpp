class Solution {
public:
    void dfs(vector<vector<int>>&vec,vector<int>&visted,int ind){
        visted[ind]=1 ;
        for(int i=0;i<vec[ind].size();i++){
            if(vec[ind][i]&&!visted[i]){
                visted[i]=1;
                dfs(vec,visted,i) ;    
            }
        }
    }
    int findCircleNum(vector<vector<int>>&vec) {
        vector<int>visted(vec.size()+1) ;int res=0;
        for(int i=0;i<vec.size();i++){
            if(!visted[i]){
                res++ ;
                dfs(vec,visted,i) ;
            }
        }
        return res;
    }
};