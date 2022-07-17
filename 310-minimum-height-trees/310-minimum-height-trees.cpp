class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>&v) {
        vector<vector<int>>vec(n,vector<int>()) ;vector<int>d(n) ;
        for(int i=0;i<v.size();i++){
            vec[v[i][0]].push_back(v[i][1]) ;
            vec[v[i][1]].push_back(v[i][0]) ;
            d[v[i][0]]++ ;d[v[i][1]]++; 
        }
        queue<int>q;
        for(int i=0;i<n;i++)if(d[i]==1)q.push(i);
        int sz=q.size();
        while(n>2){
            sz=q.size();
            n-=sz ;
            while(sz--){
                int x=q.front();q.pop();
                for(int i=0;i<vec[x].size();i++){
                    if(--d[vec[x][i]]==1)q.push(vec[x][i]);
                }
            }
            
        }
        vector<int>res ;
        while(q.size()){
            res.push_back(q.front()) ;
            q.pop();
        }
        if(!res.size())res.push_back(0);
        return res;
    }
};