class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin() ,nums.end());
        int maxs =0;
        for(int num:st){
            if(st.find(num - 1)== st.end()){
                int currentN = num;
                int currentS = 1;
                while(st.count(currentN+1)){
                    currentN++;
                    currentS++;
                }
                maxs = max(maxs , currentS);
            }
        }
        return maxs;
    }
};