class Solution {
public:
    bool isPrintable(vector<vector<int>>&vec) {
    
    vector<int>mxr(61,-1);vector<int>mxc(61,-1);vector<int>mnr(61,100);vector<int>mnc(61,100) ;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                int c=vec[i][j]; 
              mxr[c]=max(mxr[c],i) ;
              mxc[c]=max(mxc[c],j) ;
              mnr[c]=min(mnr[c],i) ;
              mnc[c]=min(mnc[c],j) ;
                }  
        }
        vector<vector<int>>g(61,vector<int>()) ;vector<int>d(61) ;
        for(int i=0;i<61;i++){
            for(int j=mnr[i];j<=mxr[i];j++){
                for(int k=mnc[i];k<=mxc[i];k++){
                  if(vec[j][k]!=i)
                  {
                      g[vec[j][k]].push_back(i) ;
                  }
                }
            }
        }
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++)
                d[g[i][j]]++ ;
        }
        queue<int>q;
        int cnt=0 ;
        for(int i=0;i<d.size();i++){
            if(!d[i]){q.push(i) ;}
        }
        while(!q.empty()){
            int x=q.front();q.pop();//cout<<x<<endl;
            cnt++ ;
            for(int i=0;i<g[x].size();i++){

                if(--d[g[x][i]]==0){q.push(g[x][i]);}
                
            }
        }
        if(cnt<g.size())return false ;
        else return true;
    }
};