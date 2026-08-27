class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Frequency of each task
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // Max heap
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            // One cycle has n + 1 slots
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int f = pq.top();
                    pq.pop();
                    f--;
                    if (f > 0) {
                        temp.push_back(f);
                   }
                }
               time++;
               // No tasks left
                if (pq.empty() && temp.empty()) {
                    break;
                }
            }
            // Put remaining tasks back
            for (int f : temp) {
                pq.push(f);
            }
        }
        return time;
    }
};