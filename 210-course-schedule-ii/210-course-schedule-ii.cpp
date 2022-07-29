class Solution {
public:
 vector<int>res ;
    bool dfs(int node,vector<vector<int>>&vec,vector<int>&s,vector<int>&f,int &t){
        s[node]=t++ ;
        for(int i=0;i<vec[node].size();i++){
           if(s[vec[node][i]]==-1){

               if(dfs(vec[node][i],vec,s,f,t))return true; 
           }
            else if(f[vec[node][i]]==-1)return true ;
        
        }
       f[node]=t++ ;
        res.push_back(node) ;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>&p) {
        vector<vector<int>>vec(n) ;vector<int>s(n,-1),f(n,-1);
        for(int i=0;i<p.size();i++){
           vec[p[i][1]].push_back(p[i][0]);         } 
        int t=1;
        for(int i=0;i<n;i++){
            if(s[i]==-1){
               if( dfs(i,vec,s,f,t) )return vector<int>();
            }
        }
        reverse(res.begin(),res.end()) ;
        return res;
    }
};