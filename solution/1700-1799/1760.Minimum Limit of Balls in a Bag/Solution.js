/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
var minimumSize = function (nums, maxOperations) {
    let [l, r] = [1, Math.max(...nums)];
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.map(x => ((x - 1) / mid) | 0).reduce((a, b) => a + b);
        if (s <= maxOperations) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
