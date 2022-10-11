class Solution {
public:
    int arr[1001][1001]; 
    int dp(int  i,int  j,string &s1,string &s2){
        if(i==s1.length()||j==s2.length())return 0 ;
        int &ret=arr[i][j]; 
        if(ret!=-1)return ret; 
        if(s1[i]==s2[j])return ret=dp(i+1,j+1,s1,s2)+1 ;
        ret=max(dp(i+1,j,s1,s2),dp(i,j+1,s1,s2)); 
        return ret; 
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(arr,-1,sizeof(arr)); 
    return dp(0,0,text1,text2); 
        
    }
};