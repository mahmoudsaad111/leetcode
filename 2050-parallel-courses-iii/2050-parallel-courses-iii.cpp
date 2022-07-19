class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>d(n),visted(n);vector<vector<int>>vec(n,vector<int>()) ;
        for(int i=0;i<relations.size();i++){
            int a=relations[i][0]-1,b=relations[i][1]-1;
            vec[a].push_back(b) ;
            d[b]++ ;
        }
        queue<int>q;int res=0;
        for(int i=0;i<n;i++){
            if(!d[i]){visted[i]=1;q.push(i);}
        }
        vector<int>c(n) ;
        while(q.size()){
            int sz=q.size();
            while(sz--){
                int x=q.front();q.pop();
                 c[x]+=time[x];
               
                for(int i=0;i<vec[x].size();i++){
                    int j=vec[x][i];
                    if(--d[j]==0){
                        q.push(j) ;
                        visted[j]=1;  
                    }
                  c[j]=max(c[j],c[x]);
                }
            }
        }
    res=*max_element(c.begin(),c.end());
        return res ;
    }
};