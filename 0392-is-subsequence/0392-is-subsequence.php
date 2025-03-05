class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isSubsequence($s, $t) {
        if ($s === "") { return true; }
        $i = 0;
        $j = 0;
        $sLen = strlen($s);
        $tLen = strlen($t);
        
        while ($i < $sLen && $j < $tLen) {
            if ($s[$i] === $t[$j]) { $i++; }
            $j++;
        }
        return $i === $sLen;  
    }
}