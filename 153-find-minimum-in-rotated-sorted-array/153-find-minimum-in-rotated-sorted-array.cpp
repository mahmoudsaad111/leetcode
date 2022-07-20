class Solution {
public:
    int findMin(vector<int>& vec) {
        int s=0,e=vec.size()-1;int res=1e9;
        while(e>=s){
            int mid=(s+e)/2;
            res=min(res,vec[mid]) ;
            if(vec[mid]>vec[e])s=mid+1;
            else e=mid-1;
        }
        return res ;
    }
};