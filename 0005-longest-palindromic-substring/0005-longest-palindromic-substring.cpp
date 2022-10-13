class Solution {
public:
    int arr[1001][1001] ;
    bool check(string &s,int i,int j){
      if(i>=j)return 1;
        int &ret=arr[i][j] ;
        if(ret!=-1)return ret; 
        if(s[i]==s[j])return ret=check(s,i+1,j-1); 
        return ret=0 ;
    }
    string longestPalindrome(string s) {
        memset(arr,-1,sizeof(arr)); 
        int res=0;string t;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(check(s,i,j)&&(j-i+1)>res){
                res=j-i+1 ;t.clear() ;
                    for(int k=i;k<=j;k++)t+=s[k];
                }
            }
        }
        return t;
    }
};