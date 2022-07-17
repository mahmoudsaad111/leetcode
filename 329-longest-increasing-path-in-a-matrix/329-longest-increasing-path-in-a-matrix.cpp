class Solution {
public:
    int dx[4]={0,0,1,-1} ;
    int dy[4]={1,-1,0,0};
    bool valid(int i,int j,int n,int m){
        if(i<0||j<0||i>=n||j>=m)return false;
        return true;
    }
    int longestIncreasingPath(vector<vector<int>>&vec) {
        int n=vec.size(),m=vec[0].size();
        vector<vector<int>>d(n,vector<int>(m));
        queue<pair<int,int>>q;  vector<vector<int>>visted(300,vector<int>(300)) ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int r=dx[k]+i,c=dy[k]+j ;
                    if(valid(r,c,n,m)&&vec[r][c]>vec[i][j])d[i][j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!d[i][j]){q.push({i,j});visted[i][j]=1;}
            }
        }int res=1;
        for(int level=0,sz=q.size();q.size();sz=q.size(),level++){
            res=max(res,level+1);
            while(sz--){
         
             int i=q.front().first,j=q.front().second;q.pop();
                for(int k=0;k<4;k++){ 
                    int r=i+dx[k],c=dy[k]+j; 
                    if(valid(r,c,n,m)&&vec[i][j]>vec[r][c]&&--d[r][c]==0&&!visted[r][c]){ 
                        visted[r][c]=1;
                        q.push({r,c}) ;
                    }
                }
            }
        }
        return res;
    }
};
