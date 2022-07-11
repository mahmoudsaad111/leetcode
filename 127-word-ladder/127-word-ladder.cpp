class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>&d) {
        map<string,int>mp;
        for(int i=0;i<d.size();i++)mp[d[i]]=0 ;
        queue<string>q;q.push(beginWord) ;mp[beginWord]=1;
        for(int level=0,sz=1;q.size();level++,sz=q.size()){
            while(sz--){
                string t=q.front();q.pop();
                if(t==endWord)return level+1 ; 
                for(int i=0;i<t.length();i++){char c=t[i];
                    for(int j=0;j<26;j++){
                        t[i]=char(j+'a') ;
                        if(mp.count(t)&&!mp[t]){
                            mp[t]=1;
                            q.push(t);
                        }
                    }
                                              t[i]=c;
                }
            }
        }
        
        
        return 0 ;
    }
};