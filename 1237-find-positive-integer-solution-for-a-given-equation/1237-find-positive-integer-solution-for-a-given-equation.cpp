/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction&c, int z) {
        int x=1,y=1000;
        vector<vector<int>>res;
        while(y>0&&x<=1000){
            if(c.f(x,y)==z)
            { res.push_back({x,y}) ;x++;y--;}
            else if(c.f(x,y)<z)x++ ;
            else y-- ;
        }
        return res;
    }
};