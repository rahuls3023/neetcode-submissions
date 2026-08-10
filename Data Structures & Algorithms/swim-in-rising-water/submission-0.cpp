class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int n;

    // check if we can reach (n-1, n-1) when water level is t
    bool possibleToReach(int i, int j, vector<vector<int>>& grid,
                         vector<vector<bool>>& visited, int t) {

        // out of bounds, already visited, or cell elevation is greater than t
        if(i < 0 || j < 0 || i >= n || j >= n ||
           grid[i][j] > t || visited[i][j] == true) {
            return false;
        }

        visited[i][j] = true;

        // destination reached
        if(i == n-1 && j == n-1) return true;

        // explore all 4 directions
        for(auto &dir : directions) {
            int newr = i + dir[0];
            int newc = j + dir[1];

            if(possibleToReach(newr, newc, grid, visited, t)) {
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        // minimum possible time is the elevation of starting cell
        int l = grid[0][0];

        // maximum elevation in the grid can be n^2 - 1
        int r = n*n - 1;

        int result = 0;

        // binary search on minimum required time
        while(l <= r) {
            int mid = l + (r-l)/2;

            // fresh visited array for every binary search check
            vector<vector<bool>> visited(n, vector<bool>(n, false));

            // if destination is reachable at time mid, try a smaller time
            if(possibleToReach(0, 0, grid, visited, mid)) {
                result = mid;
                r = mid - 1;
            }
            // otherwise more time is required
            else {
                l = mid + 1;
            }
        }

        return result;
    }
};