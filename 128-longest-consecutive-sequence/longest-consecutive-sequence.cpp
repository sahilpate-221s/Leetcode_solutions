class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it : nums) {
            pq.push(it);
        }

        int prev = pq.top();
        pq.pop();

        int count = 1;   // first element starts a streak
        int maxi = 1;

        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (curr == prev) {
                // skip duplicates
                continue;
            } 
            else if (curr == prev + 1) {
                // extend streak
                count++;
            } 
            else {
                // streak breaks
                count = 1;
            }

            maxi = max(maxi, count);
            prev = curr;
        }
        return maxi;
    }
};
