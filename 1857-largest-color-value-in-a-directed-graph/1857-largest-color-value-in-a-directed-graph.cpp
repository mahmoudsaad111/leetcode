class Solution {
public:
    int largestPathValue(string c, vector<vector<int>>& edges) {
        int n=c.length();
        vector<vector<int>>vec(n) ;vector<int>d(n); 
        for(int i=0;i<edges.size();i++){
            vec[edges[i][0]].push_back(edges[i][1]) ;
            d[edges[i][1]]++ ;
        }queue<int> q;
        for(int  i=0;i<n;i++){
            if(!d[i])q.push(i) ; 
        }
        int p=0,a=0; 
        vector<vector<int>>res(n,vector<int>(26)) ;
        while(q.size()){
          int i=q.front();q.pop();
            res[i][c[i]-'a']++;
            ++p;
            a=max(a,res[i][c[i]-'a']) ;
            for(int  j=0;j<vec[i].size();j++){
                if(--d[vec[i][j]]==0){
                    q.push(vec[i][j]); 
                }
                for(int k=0;k<26;k++){
                    res[vec[i][j]][k]=max(res[vec[i][j]][k],res[i][k]);
                }
            }
        }
        if(p!=n)return -1;
        
        
        return a;
    }
};