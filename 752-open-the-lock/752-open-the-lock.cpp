class Solution {
public:
    bool help(string s,string target,queue<string>&q,unordered_map<string,int>&mp){
        if(s==target)return true;
        if(!mp.count(s)){mp[s]++;q.push(s) ;}
            return false;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int>mp ;
        for(int i=0;i<deadends.size();i++)mp[deadends[i]]++; 
        if(mp.count(target)||mp.count("0000"))return -1 ;
        if(target=="0000")return 0 ;
        queue<string>q;
        q.push("0000") ;
        for(int level=0,sz=1;!q.empty();level++,sz=q.size()){
            while(sz--){
                string t=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    string tmp=t;
                    if(tmp[i]=='9')tmp[i]='0' ;else tmp[i]++ ; 
                    if(help(tmp,target,q,mp))return level+1 ;
                     tmp=t;
                    if(tmp[i]=='0')tmp[i]='9';else tmp[i]-- ;
                          if(help(tmp,target,q,mp))return level+1 ;
                    
                }
            }
        }
        return -1; 
    }
};