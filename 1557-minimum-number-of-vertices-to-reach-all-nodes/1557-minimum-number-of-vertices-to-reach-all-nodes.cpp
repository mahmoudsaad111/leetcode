class Solution {
public:
    map<int,int>mp ;
    void dfs(vector<vector<int>>&vec,vector<int>&visted,int ind){
        for(int i=0;i<vec[ind].size();i++){
            if(mp[vec[ind][i]]==1)mp[vec[ind][i]]=0;
            else if(!visted[vec[ind][i]]){visted[vec[ind][i]]=1;dfs(vec,visted,vec[ind][i]);}
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>vec(n,vector<int>());
        for(int i=0;i<edges.size();i++){
            vec[edges[i][0]].push_back(edges[i][1]) ;
        }
        vector<int>visted(n),res;
        for(int i=0;i<n;i++){
            if(!visted[i]){
                mp[i]=1;
                visted[i]=1;
                dfs(vec,visted,i); 
            }
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second)res.push_back(i->first);
        }
        return res;
    }
};