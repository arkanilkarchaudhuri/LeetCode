class Solution {
    fun countSymmetricIntegers(low: Int, high: Int):Int{
        var num = low
        var count = 0
        while(num<=high) {
            val str = num.toString()
            val len = str.length
            if(len%2==1){
                num = Math.pow(10.0,len.toDouble()).toInt()
                continue
            }
            val mid = len/2
            var s = 0
            for(i in 0..<mid){
                s += Character.digit(str.get(i), 10)
                s -= Character.digit(str.get(i+mid),10)
            }
            if(s==0)count++
            num++
        }   
        return count
    }
}