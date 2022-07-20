class Solution {
public:
    int lengthOfLIS(vector<int>& vec) {
        vector<int>res;
        res.push_back(vec[0]);
        for(int i=1;i<vec.size();i++){
            int u=lower_bound(res.begin(),res.end(),vec[i])-res.begin();
            if(u<res.size())
                res[u]=vec[i];
            else
                res.push_back(vec[i]);
        }
        return res.size();
    }
};