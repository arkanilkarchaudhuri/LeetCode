class Solution {

    /**
     * @param Integer[][] $points
     * @return Integer
     */
    function findMinArrowShots($points) {

        if (empty($points)) {
            return 0;
        }

        usort($points, function ($a, $b) {
            return $a[1] - $b[1];
        });

        $curr = $points[0][1];
        $arrows = 1;

        for ($i = 1; $i < count($points); $i++) {
            [$start, $end] = $points[$i];

            if ($start > $curr) {
                $curr = $end;
                $arrows++;
            }
        }

        return $arrows;
    }
}