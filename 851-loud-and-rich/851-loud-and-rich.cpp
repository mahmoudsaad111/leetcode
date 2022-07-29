class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>>g(quiet.size());
        vector<int>d(quiet.size()),ans(quiet.size(),-1);
        for(int i=0;i<richer.size();i++){
            g[richer[i][0]].push_back(richer[i][1]) ;
            d[richer[i][1]]++ ;
        }
        queue<int>q; 
        for(int i=0;i<quiet.size();i++){
         ans[i]=i;
            if(!d[i]){q.push(i);}
        }
        while(q.size()){
            int x=q.front();q.pop();
            for(int i=0;i<g[x].size();i++){
                if(ans[g[x][i]]==-1||quiet[ans[x]]<quiet[ans[g[x][i]]]){
                   ans[g[x][i]]=ans[x] ;
                }
                if(--d[g[x][i]]==0){
                    q.push(g[x][i]) ;
                }
            }
        }
        return ans; 
    }
};