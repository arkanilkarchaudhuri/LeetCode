object Solution {
    def countGoodTriplets(arr: Array[Int], a: Int, b: Int, c: Int): Int = {
        (0 to arr.length - 2).flatMap(i => (1 to arr.length - 2).flatMap(j =>
          arr.drop(i + j + 1).map(Array(arr(i), arr(i + j), _)))
        ).count(trpl => (trpl(0) - trpl(1)).abs <= a && (trpl(1) - trpl(2)).abs <= b && (trpl(0) - trpl(2)).abs <= c)
    }
    
}