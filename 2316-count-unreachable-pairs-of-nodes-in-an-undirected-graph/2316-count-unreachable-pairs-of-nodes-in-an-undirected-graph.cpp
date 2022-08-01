class Solution {
public:
    long long  dfs(vector<vector<int>>&g,vector<int>&visted,int node){
        visted[node]=1;
        long long  cnt=1;
        for(int i=0;i<g[node].size();i++){
            if(!visted[g[node][i]]){
                cnt+=dfs(g,visted,g[node][i]); 
            }
        }
        
        return cnt ;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n) ;
        for(int  i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]) ;
            g[edges[i][1]].push_back(edges[i][0]) ;
        }
        vector<int>visted(n) ;
        vector<long long>v ;
        long long ans=0; 
        for(int i=0;i<n;i++){
            if(!visted[i]){
                long long u=dfs(g,visted,i) ;
                v.push_back(u); 
            }
        } 
        for(int i=0;i<v.size();i++){
                ans+=v[i]*(n-v[i]); 
            n-=v[i];
        }
 
        return ans ;
    }
};