class Solution {
public:
    bool search(vector<int>&vec, int target) {
        int s=0,e=vec.size()-1;
        while(e>=s){
            int mid=(e+s)/2 ;
            if(vec[mid]==target)return true; 
            if(vec[s]==vec[mid]&&vec[e]==vec[mid]){s++;e--;}
            else if(vec[s]<=vec[mid]){
                if(target>=vec[s]&&target<=vec[mid])
                    e=mid-1 ;
                else s=mid+1;
               
            }
            else {
                if(target>vec[mid]&&target<=vec[e])
                    s=mid+1;
                else 
                    e=mid-1;
            }
        }
        return false; 
    }
};