class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int res=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1])res=i;
            else return res;
        }
        return res;
    }
};