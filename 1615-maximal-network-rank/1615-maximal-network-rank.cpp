class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       vector<vector<int>>vec(n) ;
        map<pair<int,int>,int>mp ; 
        for(int i=0;i<roads.size();i++){
            int a=roads[i][0],b=roads[i][1];
            vec[a].push_back(b);
            vec[b].push_back(a);
            mp[{min(a,b),max(a,b)}]=1 ;
        }
        int ans=0,cnt=0 ;
        for(int i=0;i<n;i++){
          
            for(int j=i+1;j<n;j++){
                cnt=0 ;
                cnt+=vec[i].size() ;
                cnt+=vec[j].size();
                if(mp.count({min(i,j),max(i,j)}))cnt-- ;
                ans=max(ans,cnt) ;
            }
        }
        return ans; 
    }
};