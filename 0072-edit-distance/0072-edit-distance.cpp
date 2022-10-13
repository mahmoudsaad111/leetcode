class Solution {
public:
    int arr[501][501]; 
    int dp(int  i,int j,string& s1,string& s2){
        if(i==s1.size())return s2.size()-j;
        if(j==s2.size())return s1.size()-i;
        int &ret=arr[i][j]; 
        if(ret!=-1)return ret; 
        if(s1[i]==s2[j])return ret=dp(i+1,j+1,s1,s2);
        ret=min({1+dp(i+1,j,s1,s2),dp(i,j+1,s1,s2)+1,1+dp(i+1,j+1,s1,s2)}); 
        return ret; 
    }
    int minDistance(string word1, string word2) {
        memset(arr,-1,sizeof(arr));
        return dp(0,0,word1,word2) ;
    }
};