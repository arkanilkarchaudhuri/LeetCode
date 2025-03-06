class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer[]
     */
    function findMissingAndRepeatedValues($grid) {
        $n = count($grid);
        $vector = array_fill_keys(range(1, $n ** 2), 0);
        
        foreach ($grid as $number) {
            foreach ($number as $num) {
                $vector[$num]++;
            }
        }
        
        [$duplicate, $missing] = [0, 0];
        foreach ($vector as $num => $freq) {
            if ($freq > 1) {
                $duplicate = $num;
            }
            if ($freq === 0) {
                $missing = $num;
            }
            if ($duplicate && $missing) {
                return [$duplicate, $missing];
            }
        }
        return [$duplicate, $missing];        
    }
}