
#include <array>
#include <string>
using namespace std;

class Solution {
    
public:
    string longestPalindrome(string input) {
        array<int, 2> indexRangeForLongestPalindrome{};

        for (int i = 0; i < input.length(); ++i) {
            int oddLength = checkForPalindromeStaringFromTheMiddle(input, i, i);
            int evenLength = checkForPalindromeStaringFromTheMiddle(input, i, i + 1);
            int currentMaxLength = max(oddLength, evenLength);

            if (currentMaxLength > indexRangeForLongestPalindrome[1] - indexRangeForLongestPalindrome[0] + 1) {
                indexRangeForLongestPalindrome[0] = i - (currentMaxLength - 1) / 2;
                indexRangeForLongestPalindrome[1] = i + (currentMaxLength) / 2;
            }
        }
        return input.substr(indexRangeForLongestPalindrome[0], indexRangeForLongestPalindrome[1] - indexRangeForLongestPalindrome[0] + 1);
    }

private:
    int checkForPalindromeStaringFromTheMiddle(const string& input, int left, int right) {
        while (left >= 0 && right < input.length() && input[left] == input[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};
