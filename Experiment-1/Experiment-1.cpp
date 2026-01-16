#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

long long operations = 0;
int currDepth = 0;
int maxDepth = 0;

void complexRec(int n) {
    operations++;
    currDepth++;
    maxDepth = max(maxDepth, currDepth);

    if (n <= 2) {
        currDepth--;
        return;
    }

    int p = n;
    while (p > 0) {
        operations++;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        p >>= 1;
        operations++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }

    reverse(small.begin(), small.end());
    operations += n;

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);

    currDepth--;
}

int main() {
    vector<int> inputs = {8, 16, 32};

    for (int n : inputs) {
        operations = 0;
        currDepth = 0;
        maxDepth = 0;

        auto start = high_resolution_clock::now();
        complexRec(n);
        auto end = high_resolution_clock::now();

        auto timeTaken = duration_cast<milliseconds>(end - start);

        cout << "n = " << n << endl;
        cout << "Operations = " << operations << endl;
        cout << "Max Recursion Depth = " << maxDepth << endl;
        cout << "Time Taken = " << timeTaken.count() << " ms" << endl;
        cout << "----------------------------\n";
    }
    return 0;
}
