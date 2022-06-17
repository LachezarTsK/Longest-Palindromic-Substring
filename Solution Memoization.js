
/**
 * @param {string} input
 * @return {string}
 */
var longestPalindrome = function (input) {
    const sizeInput = input.length;
    const memo = Array.from(new Array(sizeInput), () => new Array(sizeInput).fill(false));
    const indexRangeForLongestPalindrome = [0, 0];
    let range = 0;

    while (range < sizeInput) {
        for (let i = 0; i + range < sizeInput; ++i) {
            if (input.charAt(i + range) === input.charAt(i) && (range < 3 || memo[i + 1][i + range - 1])) {
                memo[i][i + range] = true;
                indexRangeForLongestPalindrome[0] = i;
                indexRangeForLongestPalindrome[1] = i + range;
            }
        }
        ++range;
    }
    return input.substring(indexRangeForLongestPalindrome[0], indexRangeForLongestPalindrome[1] + 1);
};
