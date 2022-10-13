class Solution {
public:
    int arr1[1006];
    int arr2[1006];
    int dpfirst(int ind,vector<int>&vec){
      if(ind==-1)return  0;
        int &ret=arr1[ind]; 
        if(ret!=-1)return ret; 
        ret=0 ;
        for(int i=ind-1;i>=0;i--){
            if(vec[i]<vec[ind])
            ret=max(ret,dpfirst(i,vec));
        }
        ret+=1;
        return ret; 
        
    }
    int dplast(int ind,vector<int>&vec){
          if(ind==vec.size())return 0;
        int &ret=arr2[ind]; 
        if(ret!=-1)return ret; 
        ret=0 ;
        for(int i=ind+1;i<vec.size();i++){
            if(vec[i]<vec[ind])
            ret=max(ret,dplast(i,vec));
        }
        ret+=1;
        return ret; 
    }
    int minimumMountainRemovals(vector<int>&vec) {
        memset(arr1,-1,sizeof(arr1)) ;
        memset(arr2,-1,sizeof(arr2)) ;
        int ans=0 ;
        for(int i=0;i<vec.size();i++){
            int a=dpfirst(i,vec),b=dplast(i,vec) ;
            if(a==1||b==1)continue; 
            ans=max(a+b-1,ans); 
            
        }
        
        return vec.size()-ans; 
    }
};