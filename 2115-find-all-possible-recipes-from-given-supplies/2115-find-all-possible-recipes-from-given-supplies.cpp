class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
 map<string,vector<string>>mp;map<string,int>d,ready;
        for(int i=0;i<recipes.size();i++){
          for(int j=0;j<ingredients[i].size();j++){
              mp[ingredients[i][j]].push_back(recipes[i]) ;
              d[recipes[i]]++ ;
          }
        }
        queue<string>q ;vector<string>ans ;
        for(int i=0;i<supplies.size();i++)q.push(supplies[i]) ;
        for(int level=0,sz=q.size();q.size();level++,sz=q.size()){
        while(sz--){
            string x=q.front();q.pop();
            if(level)ans.push_back(x) ;
            for(int j=0;j<mp[x].size();j++){
                if(--d[mp[x][j]]==0){
                    q.push(mp[x][j]); 
                }
            }
        }
        }
        return ans; 
    }
};