class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0 ;
        int r = heights.size()-1;
        int mw = 0;

        while(l < r){
            int w = r -l;
            int h = min(heights[l] , heights[r]);
            int a =  w  * h ;
            mw = max(mw , a);
            if(heights[l] < heights[r]){
                l++;
            }else{
                    r--;
            }
            
        }
    return mw;
    }
};
