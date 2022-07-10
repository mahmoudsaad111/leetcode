class Solution {
public:
    bool canFinish(int n, vector<vector<int>>&vec) {
        vector<int>v(n),res ;
        vector<vector<int>>h(n) ;
        for(int i=0;i<vec.size();i++){
              h[vec[i][1]].push_back(vec[i][0]);
              v[vec[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)if(!v[i])q.push(i) ;
        while(q.size()){
            int x=q.front();q.pop();
          
            res.push_back(x) ;
            for(int i=0;i<h[x].size();i++){
                if(--v[h[x][i]]==0)
                    q.push(h[x][i]);
            }
        }
        if(res.size()==n)return true; 
        return false;
    }
};