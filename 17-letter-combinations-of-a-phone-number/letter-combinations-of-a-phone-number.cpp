class Solution {
public:

    vector<string> result;

    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(string& digits, int index, string& current) {

        // We have processed all digits
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters for current digit
        string letters = mapping[digits[index] - '0'];

        // Try every possible letter
        for (char ch : letters) {

            // Choose
            current.push_back(ch);

            // Explore
            backtrack(digits, index + 1, current);

            // Undo choice
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        string current = "";

        backtrack(digits, 0, current);

        return result;
    }
};