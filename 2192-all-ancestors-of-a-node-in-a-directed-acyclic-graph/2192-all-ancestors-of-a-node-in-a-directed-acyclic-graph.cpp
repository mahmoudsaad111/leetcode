class Solution {
public:
    void dfs(vector<vector<int>>&g,vector<int>&visted,vector<vector<int>>&ans,int i,int p){
        for(int  j=0;j<g[i].size();j++){
            
            if(!visted[g[i][j]]){
                visted[g[i][j]]=1;
                dfs(g,visted,ans,g[i][j],p) ;
                ans[g[i][j]].push_back(p) ;
            }
        }
        
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n) ;
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]) ;
        }
       vector<vector<int>>ans(n) ;
        for(int i=0;i<n;i++){
            vector<int>visted(n) ;
            visted[i]=1;
            dfs(g,visted,ans,i,i); 
        }
      
     
        return ans; 
        
        
    }
};