#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DSU parent array
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();

        // Store jobs as {profit, deadline}
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs by profit descending
        sort(jobs.begin(), jobs.end(), greater<>());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());

        // Initialize DSU
        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int jobCount = 0, totalProfit = 0;

        // Schedule jobs
        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int availableSlot = find(d);
            if (availableSlot > 0) {
                // Assign job
                jobCount++;
                totalProfit += p;

                // Mark slot as occupied
                parent[availableSlot] = find(availableSlot - 1);
            }
        }

        return {jobCount, totalProfit};
    }
};
