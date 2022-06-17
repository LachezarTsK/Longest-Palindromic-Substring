
public class Solution {

    public String longestPalindrome(String input) {
        final int sizeInput = input.length();
        boolean[][] memo = new boolean[sizeInput][sizeInput];
        int[] indexRangeForLongestPalindrome = new int[]{0, 0};
        int range = 0;

        while (range < sizeInput) {
            for (int i = 0; i + range < sizeInput; ++i) {
                if (input.charAt(i + range) == input.charAt(i) && (range < 3 || memo[i + 1][i + range - 1])) {
                    memo[i][i + range] = true;
                    indexRangeForLongestPalindrome[0] = i;
                    indexRangeForLongestPalindrome[1] = i + range;
                }
            }
            ++range;
        }
        return input.substring(indexRangeForLongestPalindrome[0], indexRangeForLongestPalindrome[1] + 1);
    }
}
