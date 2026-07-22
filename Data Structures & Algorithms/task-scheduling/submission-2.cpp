class Solution {
public: // Optimal simulation approach using max heap
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        // Count the frequency of every task
        for (char task : tasks) {
            mp[task]++;
        }

        priority_queue<int> pq;

        // Push all task frequencies into the max heap
        // The highest frequency will always remain at the top
        for (auto it : mp) {
            pq.push(it.second);
        }

        int time = 0;

        while (!pq.empty()) {

            // One cycle contains at most n + 1 different tasks
            int cycle = n + 1;

            // Temporarily store unfinished task frequencies
            // We push them back only after the current cycle ends
            vector<int> temp;

            // Execute at most n + 1 different tasks in the current cycle
            while (cycle > 0 && !pq.empty()) {
                int top = pq.top();
                pq.pop();

                // Execute this task once
                top--;

                // If this task still has remaining occurrences,
                // store it temporarily
                if (top > 0) {
                    temp.push_back(top);
                }

                cycle--;
                time++;
            }

            // Push unfinished tasks back into the heap
            // after the current cycle is completed
            for (int frequency : temp) {
                pq.push(frequency);
            }

            // If tasks are still remaining, the unused positions
            // in the current cycle will be idle intervals
            if (!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};