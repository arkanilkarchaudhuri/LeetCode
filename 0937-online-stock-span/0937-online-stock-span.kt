class StockSpanner() {

    private var index = -1
    private val stockSpanStack = Stack<Pair<Int, Int>>()

    fun next(price: Int): Int {
        index++
        while(stockSpanStack.isNotEmpty() && stockSpanStack.peek().first <= price) {
            stockSpanStack.pop()
        }
        val prevGreater = if (stockSpanStack.isEmpty()) Pair(-1, -1) else stockSpanStack.peek()
        stockSpanStack.push(price to index)
        return (index - prevGreater.second)
    }

}
