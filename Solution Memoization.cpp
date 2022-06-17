
#include <array>
#include <string>
using namespace std;

class Solution {
    
public:
    string longestPalindrome(string input) {
        const size_t sizeInput = input.length();
        vector < vector<bool>> memo(sizeInput, vector<bool>(sizeInput));
        array<int, 2> indexRangeForLongestPalindrome{};
        int range = 0;

        while (range < sizeInput) {
            for (int i = 0; i + range < sizeInput; ++i) {
                if (input[i + range] == input[i] && (range < 3 || memo[i + 1][i + range - 1])) {
                    memo[i][i + range] = true;
                    indexRangeForLongestPalindrome[0] = i;
                    indexRangeForLongestPalindrome[1] = i + range;
                }
            }
            ++range;
        }
        return input.substr(indexRangeForLongestPalindrome[0], indexRangeForLongestPalindrome[1] - indexRangeForLongestPalindrome[0] + 1);
    }
};
