class Solution {
public:  vector<string>ans;
    void dfs(map<string,vector<string>>&mp,string i){
       
     while(mp[i].size()){
            string h=mp[i][0]; 
              mp[i].erase(mp[i].begin(),mp[i].begin()+1);
                dfs(mp,h) ;
     } 
        ans.push_back(i);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>>mp;map<string,int>visted ;
        for(int i=0;i<tickets.size();i++){
            mp[tickets[i][0]].push_back(tickets[i][1]) ;
        }
        for(auto i=mp.begin();i!=mp.end();i++)sort(i->second.begin(),i->second.end());
      dfs(mp,"JFK") ;
        reverse(ans.begin(),ans.end());
       
        return ans;
    }
};