class Solution {
public:
  
    int dfs(vector<vector<int>>&vec,vector<int>&visted,vector<int>&time,int ind){
        int mx=0 ;
        for(int i=0;i<vec[ind].size();i++){
            if(!visted[vec[ind][i]]){
                visted[vec[ind][i]]=1;
               mx=max(mx,dfs(vec,visted,time,vec[ind][i]) );
            
            }
        }
     return time[ind]+mx;
    }
    int numOfMinutes(int n, int id, vector<int>& manager, vector<int>&time) {
        vector<vector<int>>vec(manager.size()+1) ;
        vector<int>visted(manager.size()+1) ;
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1){continue;}
            vec[i].push_back(manager[i]);
            vec[manager[i]].push_back(i) ;
        }
         visted[id]=1;
        return dfs(vec,visted,time,id) ;
       
    }
};