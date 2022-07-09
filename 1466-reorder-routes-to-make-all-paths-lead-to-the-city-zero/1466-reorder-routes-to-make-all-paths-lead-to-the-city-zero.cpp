class Solution {
public:
    int res=0;
    void dfs(vector<vector<pair<int,bool>>>&vec,vector<int>&visted,int ind){
      
        for(int i=0;i<vec[ind].size();i++){
            if(!visted[vec[ind][i].first]){
                if(!vec[ind][i].second)res++ ;
                visted[vec[ind][i].first]=1;
                dfs(vec,visted,vec[ind][i].first) ;
            }
        }
    }
    int minReorder(int n, vector<vector<int>>&v) {
        vector<vector<pair<int,bool>>>vec(n) ;
        for(int i=0;i<v.size();i++){
            vec[v[i][0]].push_back({v[i][1],false});
                vec[v[i][1]].push_back({v[i][0],true});
        }
        vector<int>visted(n) ;
        visted[0]=1;
        dfs(vec,visted,0);
        return res;
    }
};