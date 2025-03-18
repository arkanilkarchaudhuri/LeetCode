class Solution {
    fun maxProfit(prices: IntArray, fee: Int): Int {
        var buy = Int.MIN_VALUE
        var sell = 0
        for (price in prices) {
            buy = maxOf(buy, sell - price)
            sell = maxOf(sell, price + buy - fee)
        }

        return sell
    }
}