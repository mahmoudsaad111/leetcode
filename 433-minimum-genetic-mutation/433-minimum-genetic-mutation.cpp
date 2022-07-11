class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,int>mp;
        for(int i=0;i<bank.size();i++)mp[bank[i]]=0;
        queue<string>q;q.push(start);
        mp[start]=1;
       for(int level=0,sz=1;q.size();level++,sz=q.size()){
           while(sz--){
               string t=q.front();q.pop();
               if(t==end)return level; 
               for(int i=0;i<t.length();i++){
                   char c=t[i];
                   t[i]='A';if(mp.count(t)&&!mp[t]){q.push(t);mp[t]=1;}
                   t[i]='G';if(mp.count(t)&&!mp[t]){q.push(t);mp[t]=1;}
                   t[i]='C';if(mp.count(t)&&!mp[t]){q.push(t);mp[t]=1;}
                   t[i]='T';if(mp.count(t)&&!mp[t]){q.push(t);mp[t]=1;}
                   t[i]=c;
               }
           }
       }
        return -1;
    }
};