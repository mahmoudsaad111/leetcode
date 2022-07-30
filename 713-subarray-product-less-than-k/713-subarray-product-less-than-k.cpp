class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& vec, int k) {
        int l=0;long  long sum=1;int ans=0 ;
        for(int r=0;r<vec.size();r++){
            sum*=vec[r];
            while(l<vec.size()&&sum>=k){
                sum/=vec[l++] ;
            }
            ans+=r-l+1 ;
        }
        return max(ans,0); 
    }
};