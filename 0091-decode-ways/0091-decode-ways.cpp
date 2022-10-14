class Solution {
public:
    int arr[101] ;
    int dp(int ind,string&s){
        if(ind==s.length())return 1; 
        if(s[ind]=='0')return 0 ;
        int &ret=arr[ind]; 
        if(ret)return ret; 
        ret=dp(ind+1,s); 
        if(ind<s.length()-1&&(s[ind]=='1'||(s[ind]=='2'&&s[ind+1]<'7')))
            ret+=dp(ind+2,s); 
        
        return ret;
    }
    int numDecodings(string s) {
        memset(arr,0,sizeof(arr));
        return dp(0,s) ;
        
    }
};