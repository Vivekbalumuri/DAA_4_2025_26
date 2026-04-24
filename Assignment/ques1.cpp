#include <bits/stdc++.h>
using namespace std;

class NQueens {
public:
    int n;
    vector<vector<string>> solutions;
    int totalCount = 0;

    vector<int> col, diag1, diag2;

    void solve(int row, vector<string>& board) {
        if (row == n) {
            solutions.push_back(board);
            totalCount++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;
            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;

            solve(row + 1, board);
            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }

    void run(int size) {
        n = size;
        col.assign(n, 0);
        diag1.assign(2*n, 0);
        diag2.assign(2*n, 0);

        vector<string> board(n, string(n, '.'));
        solve(0, board);
        cout << "All Solutions:\n";
        for (auto &sol : solutions) {
            for (auto &row : sol) {
                cout << row << endl;
            }
            cout << "----------------\n";
        }
        cout << "Total Solutions: " << totalCount << endl;
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    NQueens obj;
    obj.run(n);
    return 0;
}
