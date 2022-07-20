class Solution {
public:
    bool valid(vector<int>&vec,int mid,int k){
        int l=0 ;
    for(int r=0;r<vec.size();r++){
            if(!vec[r])k-- ;
            while(l<=r&&k<0){
                 k+=!vec[l++];
            }
            if((r-l+1)>=mid)return true; 
        
    }
        return false;
    }
    int longestOnes(vector<int>& vec, int k) {
        int s=0,e=vec.size(),res=0;
        while(e>=s){
            int mid=(e+s)/2 ;
            if(valid(vec,mid,k)){res=max(res,mid) ;s=mid+1 ;}
            else e=mid-1 ;
        }
        return res; 
    }
};