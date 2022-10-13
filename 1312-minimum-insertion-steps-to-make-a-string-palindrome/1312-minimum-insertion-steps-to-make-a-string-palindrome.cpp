class Solution {
public:
    int arr[501][501] ;
    int dp(int  i,int j,string &s){
        if(i>=j)return 0 ;
        int &ret=arr[i][j]; 
        if(ret!=-1)return ret; 
        if(s[i]==s[j])return ret=dp(i+1,j-1,s); 
        ret=min(1+dp(i+1,j,s),1+dp(i,j-1,s)); 
return ret; 
        }
    int minInsertions(string s) {
        memset(arr,-1,sizeof(arr)) ;
        return dp(0,s.length()-1,s);
    }
};