class Solution {
public:
    int res=0;set<pair<int,int>>st;
    void dfs(vector<vector<int>>&vec,vector<int>&visted,int ind,int  p){
        visted[ind]=1;
        for(int i=0;i<vec[ind].size();i++){
            if(visted[vec[ind][i]]&&vec[ind][i]!=p){
                st.insert({min(ind,vec[ind][i]),max(ind,vec[ind][i])}) ;
                           }
            else if(!visted[vec[ind][i]]){
                visted[vec[ind][i]]=1;
                dfs(vec,visted,vec[ind][i],ind) ;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>vec(n+1);
        vector<int>visted(n+1) ;
        for(int i=0;i<connections.size();i++){
            vec[connections[i][0]].push_back(connections[i][1]) ;
            vec[connections[i][1]].push_back(connections[i][0]) ;
        }
        for(int  i=0;i<n;i++){
            if(!visted[i]){
                res++ ;
                dfs(vec,visted,i,i) ;
            }
        }
        int cnt=st.size();
        if(cnt>=res-1)return res-1;
        else return -1;
    }
};