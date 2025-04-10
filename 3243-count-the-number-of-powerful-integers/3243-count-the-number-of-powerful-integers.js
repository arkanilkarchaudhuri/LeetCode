/**
 * @param {number} start
 * @param {number} finish
 * @param {number} limit
 * @param {string} s
 * @return {number}
 */
var numberOfPowerfulInt = function (start, finish, limit, s) {
    const sAsNumber = +s
    const numberOfPowerfulToStart = DP(start - 1, limit, sAsNumber, s.length)
    const numberOfPowerfulToFinish = DP(finish, limit, sAsNumber, s.length)
    return numberOfPowerfulToFinish - numberOfPowerfulToStart
};

function DP(max, maxDigit, sAsNumber, sLength) {
    const maxLength = orderOfMagnitude(max) + 1
    if (maxLength <= sLength) {
        if (max >= sAsNumber) return 1
        return 0
    }

    const divisor = Math.pow(10, maxLength - 1)
    const leftMostDigitOfMax = Math.floor(max / divisor)
    const numberOfDigitOfPrefix = maxLength - sLength

    if (leftMostDigitOfMax > maxDigit) {
        return Math.pow(maxDigit + 1, numberOfDigitOfPrefix)
    }
    return (leftMostDigitOfMax) * Math.pow(maxDigit + 1, numberOfDigitOfPrefix - 1)
        + DP(max % divisor, maxDigit, sAsNumber, sLength)
}

function orderOfMagnitude(number) {
    return Math.floor(Math.log10(number))
}