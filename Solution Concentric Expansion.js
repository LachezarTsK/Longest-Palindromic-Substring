
/**
 * @param {string} input
 * @return {string}
 */
var longestPalindrome = function (input) {

    const indexRangeForLongestPalindrome = [0, 0];

    for (let i = 0; i < input.length; ++i) {
        let oddLength = checkForPalindromeStaringFromTheMiddle(input, i, i);
        let evenLength = checkForPalindromeStaringFromTheMiddle(input, i, i + 1);
        let currentMaxLength = Math.max(oddLength, evenLength);

        if (currentMaxLength > indexRangeForLongestPalindrome[1] - indexRangeForLongestPalindrome[0] + 1) {
            indexRangeForLongestPalindrome[0] = i - Math.floor((currentMaxLength - 1) / 2);
            indexRangeForLongestPalindrome[1] = i + Math.floor(currentMaxLength / 2);
        }
    }
    return input.substring(indexRangeForLongestPalindrome[0], indexRangeForLongestPalindrome[1] + 1);
};

/**
 * @param {string} input
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
function checkForPalindromeStaringFromTheMiddle(input, left, right) {
    while (left >= 0 && right < input.length && input.charAt(left) === input.charAt(right)) {
        --left;
        ++right;
    }
    return right - left - 1;
}
