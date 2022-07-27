class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
           n++ ;
        vector<vector<pair<int,int>>>vec(n);
        for(int i=0;i<times.size();i++){
            vec[times[i][0]].push_back({times[i][1],times[i][2]}) ;
        }
        vector<int>cost(n,1e9);cost[k]=0;
        queue<int>q ;int res=0 ;
        q.push(k) ;
        while(q.size()){
            int x=q.front();q.pop();
            for(int i=0;i<vec[x].size();i++){
                if(cost[x]+vec[x][i].second<cost[vec[x][i].first]){
                    q.push(vec[x][i].first) ;
                cost[vec[x][i].first]=min(cost[vec[x][i].first],cost[x]+vec[x][i].second); 
            }
            }
        }
        for(int i=1;i<n;i++){if(cost[i]==1e9)return -1 ;res=max(res,cost[i]);} 
        return res;
        
    }
};