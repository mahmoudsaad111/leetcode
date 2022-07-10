class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<int>f(1e5);
        for(int i=0;i<forbidden.size();i++)f[forbidden[i]]=1;
        queue<pair<int,bool>>q;q.push({0,true}) ;f[0]=1;
        for(int level=0,sz=1;q.size();level++,sz=q.size()){
            while(sz--){
                pair<int,bool>p=q.front();q.pop();
                int v=p.first ;bool c=p.second; 
                if(v==x)return level; 
                if((v+a)>=0&&(v+a)<1e5&&!f[v+a]){f[v+a]=1;q.push({v+a,true});}
                if(c&&(v-b)>=0&&!f[v-b]){
                    //f[v-b]=1;
                    q.push({v-b,false});
                }
            }
        }
        return -1;
    }
};