class Solution {
    public int countPaths(int n, int[][] roads) {


        List<int[]>[] graph = new LinkedList[n];

        for(int i = 0; i < n; i++) {
            graph[i] = new LinkedList<>();
        }

        for(int[] road : roads) {
            int x = road[0];
            int y = road[1];
            int cost = road[2];
            graph[x].add(new int[]{y, cost});
            graph[y].add(new int[]{x, cost});
        }

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        dist[0] = 0;

        pq.offer(new int[]{0, 0});
        int[] countWays = new int[n];
        countWays[0] = 1;
        while(!pq.isEmpty()) {
            int[] poll = pq.poll();
            int curr = poll[1];
            int cost = poll[0];
            if(curr == n-1) {
                return countWays[curr];
            }
            for(int[] next : graph[curr]) {
                int dest = next[0];
                int newCost = next[1];
                if(cost + newCost < dist[dest]) {
                    dist[dest] = cost + newCost;
                    pq.offer(new int[]{cost + newCost, dest});
                    countWays[dest] = countWays[curr];
                } else if(cost + newCost == dist[dest]) {
                    countWays[dest] = (countWays[dest] + countWays[curr])%1000000007;
                }
            }
        }
        
        return -1;
    }
}