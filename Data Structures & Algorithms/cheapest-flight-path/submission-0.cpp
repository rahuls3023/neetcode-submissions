class Solution {
public://modified dijkstra with stops
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // build adjacency list
        // graph[u] stores {v, price}
        unordered_map<int, list<pair<int,int>>> graph;

        for(auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            graph[u].push_back({v, price});
        }

        // min heap to select the path with minimum cost
        // each element stores:
        // {cost so far, current city, stops so far}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // start from source with cost 0 and stops 0
        pq.push({0, src, 0});

        // visited[i] stores the minimum number of stops
        // used to process city i
        vector<int> visited(n, INT_MAX);
        visited[src] = 0;

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];   // total cost so far
            int city = curr[1];   // current city
            int stops = curr[2];  // stops used so far

            // since min heap gives minimum cost first,
            // reaching destination gives the cheapest valid cost
            if(city == dst) {
                return cost;
            }

            // do not explore further if stops exceed k
            if(stops > k) {
                continue;
            }

            // if this city has already been processed
            // using fewer stops, skip the current state
            if(visited[city] < stops) {
                continue;
            }

            // update minimum stops used to reach this city
            visited[city] = min(visited[city], stops);

            // explore all neighbouring cities
            for(auto &nbr : graph[city]) {

                int nextCity = nbr.first;
                int price = nbr.second;

                // move to next city and increase
                // both cost and number of stops
                pq.push({
                    cost + price,
                    nextCity,
                    stops + 1
                });
            }
        }

        // destination cannot be reached within k stops
        return -1;
    }
};