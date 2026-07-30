class Solution {
public:
    int minimumPushes(string word) {
        // count frequency of each letter
        vector<int> freq(26, 0);
        for (char c : word)
            freq[c - 'a']++;

        // sort descending
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;       // no more letters
            int pushCost = (i / 8) + 1;    // which "round" of keys
            ans += freq[i] * pushCost;
        }
        return ans;
    }
};