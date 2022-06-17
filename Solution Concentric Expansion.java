
public class Solution {

    public String longestPalindrome(String input) {

        int[] indexRangeForLongestPalindrome = new int[]{0, 0};

        for (int i = 0; i < input.length(); ++i) {
            int oddLength = checkForPalindromeStaringFromTheMiddle(input, i, i);
            int evenLength = checkForPalindromeStaringFromTheMiddle(input, i, i + 1);
            int currentMaxLength = Math.max(oddLength, evenLength);

            if (currentMaxLength > indexRangeForLongestPalindrome[1] - indexRangeForLongestPalindrome[0] + 1) {
                indexRangeForLongestPalindrome[0] = i - (currentMaxLength - 1) / 2;
                indexRangeForLongestPalindrome[1] = i + (currentMaxLength) / 2;
            }
        }
        return input.substring(indexRangeForLongestPalindrome[0], indexRangeForLongestPalindrome[1] + 1);
    }

    private int checkForPalindromeStaringFromTheMiddle(String input, int left, int right) {
        while (left >= 0 && right < input.length() && input.charAt(left) == input.charAt(right)) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
}
