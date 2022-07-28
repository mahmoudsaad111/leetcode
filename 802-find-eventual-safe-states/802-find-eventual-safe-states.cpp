class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&vec) {
        vector<int>d(vec.size()) ;
        vector<vector<int>>g(vec.size()); 
        for(int i=0;i<vec.size();i++)
            for(int j=0;j<vec[i].size();j++)
                g[vec[i][j]].push_back(i) ;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                d[g[i][j]]++ ;
            }
        }
        queue<int>q; 
        for(int i=0;i<vec.size();i++){
            if(vec[i].size()==0)q.push(i) ;
        }vector<int>ans ;
        while(q.size()){
            int x=q.front();q.pop();
            ans.push_back(x); 
            for(int i=0;i<g[x].size();i++){
                if(--d[g[x][i]]==0)q.push(g[x][i]) ;
            }
        }
        sort(ans.begin(),ans.end()) ;
        return ans; 
        
    }
};