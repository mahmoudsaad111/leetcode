class Solution {
public:
    int dfs(int ind,vector<vector<int>>&vec,vector<int>&visted){
        visted[ind]=1; 
        int cnt=1;
        for(int i=0;i<vec[ind].size();i++){
            if(!visted[vec[ind][i]]){
                visted[vec[ind][i]]=1;
                cnt+=dfs(vec[ind][i],vec,visted) ;
            }
        }
            
            
            return cnt ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int a=0,b=0 ;
        for(int i=0;i<edges.size();i++){
          vector<int>visted(edges.size()+1);
            vector<vector<int>>vec(edges.size()+1) ;
            for(int j=0;j<edges.size();j++){
              if(i!=j){
                  vec[edges[j][0]].push_back(edges[j][1]) ;
                  vec[edges[j][1]].push_back(edges[j][0]) ;
              }  
            }
             int cnt=dfs(1,vec,visted) ; 
           if(cnt==edges.size())a=edges[i][0],b=edges[i][1] ;
           
        }
return {a,b} ;
    }
};