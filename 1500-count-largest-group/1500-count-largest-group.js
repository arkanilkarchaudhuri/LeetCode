/**
 * @param {number} n
 * @return {number}
 */
var countLargestGroup = function(n) {
    const map = new Map();
    let maxSize = 0;

    for (let i = 1; i <= n; i++) {
        const sum = i.toString().split('').reduce((acc, d) => acc + Number(d), 0);
        const newCount = (map.get(sum) || 0) + 1;
        map.set(sum, newCount);
        maxSize = Math.max(maxSize, newCount);
    }

    let result = 0;
    for (let count of map.values()) {
        if (count === maxSize) result++;
    }
    return result;
};