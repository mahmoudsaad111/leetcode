class Solution {
public:
    void bfs(vector<vector<int>>&blue,vector<vector<int>>&red,queue<pair<int,bool>>&q,vector<int>&res,vector<int>&vistedr,vector<int>&vistedb){
        for(int level=0,sz=1;q.size();sz=q.size(),level++){
            while(sz--){
            pair<int,bool>p=q.front();q.pop();
            int a=p.first;bool flag=p.second; 
            res[a]=min(res[a],level); 
            if(flag)vistedr[a]=1 ;else vistedb[a]=1;
            if(!flag)
            for(int i=0;i<blue[a].size();i++){
                if(!vistedr[blue[a][i]]){
                    q.push({blue[a][i],!flag});
                }
            }
            else
           for(int i=0;i<red[a].size();i++){
                if(!vistedb[red[a][i]]){
                    q.push({red[a][i],!flag});
                }
            }
        }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>blue(n),red(n) ;
        for(int i=0;i<redEdges.size();i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]); 
        }
          for(int i=0;i<blueEdges.size();i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]); 
        }
        vector<int>res(n,1e9);
        queue<pair<int,bool>>q1,q2 ;q1.push({0,false});q2.push({0,true});
        vector<int>vistedr(n),vistedb(n),vistedr1(n),vistedb1(n);
        if(blue[0].size())
        bfs(blue,red,q1,res,vistedr,vistedb);
        if(red[0].size())
        bfs(blue,red,q2,res,vistedr1,vistedb1);
        for(int i=0;i<n;i++){
            if(res[i]==1e9)res[i]=-1 ;
        }
        res[0]=0 ;
        return res;
        
    }
};