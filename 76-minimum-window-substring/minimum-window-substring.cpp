class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);

        // Store frequency of characters in t
        for(char c : t)
            freq[c]++;

        int left = 0;
        int right = 0;

        int count = t.length();

        int minLen = INT_MAX;
        int start = 0;

        while(right < s.length()) {

            // If current character is needed
            if(freq[s[right]] > 0)
                count--;

            // Include current character in window
            freq[s[right]]--;

            right++;

            // Window is valid
            while(count == 0) {

                // Update minimum window
                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Remove left character
                freq[s[left]]++;

                // Required character removed
                if(freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};