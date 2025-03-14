/**
 * @param {number[]} candies
 * @param {number} k
 * @return {number}
 */
var maximumCandies = function (candies, k) {
    if (k === 0) return 0;

    let left = 1, right = Math.max(...candies), result = 0;

    const canDistribute = (mid) => {
        let count = 0;
        for (let c of candies) {
            count += Math.floor(c / mid);
        }
        return count >= k;
    };

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (canDistribute(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
};