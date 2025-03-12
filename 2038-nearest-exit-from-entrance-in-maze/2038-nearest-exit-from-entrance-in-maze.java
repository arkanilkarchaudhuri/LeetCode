class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {

        int m = maze.length;
        int n = maze[0].length;

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        Deque<int[]> queue = new ArrayDeque<>();

        queue.add(new int[] {entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';

        while(! queue.isEmpty()) {
            int[] curr = queue.pollFirst();
            int r = curr[0];
            int c = curr[1];
            int dist = curr[2];

            for(int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];

                if(x == -1 || y == -1 || x == m || y == n) continue;
                if(maze[x][y] == '+') continue;
                if(x == 0 || y == 0 || x == m - 1 || y == n - 1) return dist + 1;
                maze[x][y] = '+';
                queue.add(new int[] {x, y, dist + 1});
            }
        }
        return -1;
    }
}