class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n) ;vector<int>d(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]) ;
            d[edges[i][1]]++ ;
        }
        vector<set<int>>vec(n) ;
        queue<pair<int,set<int>>>q ; 
        for(int i=0;i<n;i++){
            if(!d[i]){
                set<int>st;st.insert(i) ;
                q.push({i,st}) ;
            }
        }
  
            while(q.size()){
                int x=q.front().first;set<int>st=q.front().second ;q.pop() ;
                
                for(int i=0;i<g[x].size();i++){
                    for(auto j=st.begin();j!=st.end();j++)vec[g[x][i]].insert(*j) ;
                    vec[g[x][i]].insert(g[x][i]) ;
                    if(--d[g[x][i]]==0)q.push({g[x][i],vec[g[x][i]]}) ;
                }
            }
        vector<vector<int>>ans(n) ;
        for(int i=0;i<n;i++){
            for(auto j=vec[i].begin();j!=vec[i].end();j++){
                if(i!=*j)
                ans[i].push_back(*j) ;
            }
        }
        return ans; 
        
        
    }
};