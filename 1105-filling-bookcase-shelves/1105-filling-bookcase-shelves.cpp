class Solution {
public:
    int arr[1001] ;
    int dp(int ind,vector<vector<int>>&vec,int width){
        if(ind==vec.size())return  0;
        int &ret=arr[ind] ;
        if(ret!=-1)return ret; 
         
        int w=0,mx=0;
        ret=1e9 ;
        for(int i=ind;i<vec.size();i++){
            mx=max(mx,vec[i][1]) ;
            if(w+vec[i][0]<=width){
                w+=vec[i][0];
               ret=min(ret,mx+dp(i+1,vec,width)) ;
            }else break ;
        }
        return ret; 
    }
    int minHeightShelves(vector<vector<int>>&vec, int width) {
        memset(arr,-1,sizeof(arr)); 
        return dp(0,vec,width) ;
        
    }
};