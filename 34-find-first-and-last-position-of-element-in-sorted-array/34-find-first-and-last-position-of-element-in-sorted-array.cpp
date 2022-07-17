class Solution {
public:
    vector<int> searchRange(vector<int>&vec, int t) {
        vector<int>res(2);if(!vec.size())return {-1,-1};
        res[0]=lower_bound(vec.begin(),vec.end(),t)-vec.begin();
        res[1]=upper_bound(vec.begin(),vec.end(),t)-vec.begin() ;
        res[1]-- ;
        if(res[0]>=vec.size()||vec[res[0]]!=t)res[0]=-1,res[1]=-1 ;
        return res;
    }
};