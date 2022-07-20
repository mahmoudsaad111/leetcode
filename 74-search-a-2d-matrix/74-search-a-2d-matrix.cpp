class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int s=0,e=(n)*(m)-1 ;
        while(e>=s){
            int mid=(s+e)/2; 
            int a=mid/(m),b=mid%(m) ;
            if(matrix[a][b]==target)return true ;
            else if(matrix[a][b]<target)s=mid+1; 
            else e=mid-1; 
        }
        return false;
    }
};