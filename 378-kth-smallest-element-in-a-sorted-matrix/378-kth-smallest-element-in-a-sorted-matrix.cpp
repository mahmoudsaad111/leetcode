class Solution {
public:
    bool valid(vector<vector<int>>&matrix,int mid,int k){
       int cnt=0 ;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[i][j]<=mid){cnt++ ;}
                else continue ;
            }
        }  

        return cnt>=k ;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int s=matrix[0][0],e=matrix[n-1][n-1];int res= 1e9 ;
        while(e>=s){
            int mid=(s+e)/2 ;
            if(valid(matrix,mid,k)){
                res=min(mid,res) ;
                e=mid-1 ;
            }
            else{
                s=mid+1; 
            }
        }
        return res;
    }
};