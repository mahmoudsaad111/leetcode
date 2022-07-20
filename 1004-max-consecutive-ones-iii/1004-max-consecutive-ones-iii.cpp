class Solution {
public:
    int valid(vector<int>&vec,int k){
        int l=0,res=0 ;
    for(int r=0;r<vec.size();r++){
            if(!vec[r])k-- ;
            while(l<=r&&k<0){
                 k+=!vec[l++];
            }
          res=max(res,r-l+1) ; 
        
    }
        return res;
    }
    int longestOnes(vector<int>& vec, int k) {
       return valid(vec,k);
    }
};