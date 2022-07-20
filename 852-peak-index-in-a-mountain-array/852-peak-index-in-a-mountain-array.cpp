class Solution {
public:
    int peakIndexInMountainArray(vector<int>& vec) {
        int res=0;
     int e=vec.size()-2,s=1 ;
        while(e>=s){
            int mid=(s+e)/2 ;
            if(vec[mid]>vec[mid-1]&&vec[mid]>vec[mid+1])return mid;
            else if(vec[mid]>vec[mid-1]) s=mid+1;
            else e=mid-1;
        }
        return res;
    }
};