#include<iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> results;
		vector<string> board(n, string(n, '.'));
		vector<bool> cols(n, false);
		vector<bool> diag1(2 * n - 1, false);
		vector<bool> diag2(2 * n - 1, false);
		backtrack(0, n, board, results, cols, diag1, diag2);
		return results;
	}
private:
	void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& results,vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
		if (r == n) {
			results.push_back(board);
			return;
		}
		for (int c = 0; c < n; ++c) {
			if (cols[c] || diag1[r - c + n - 1] || diag2[r + c]) {
				continue;
			}
			board[r][c] = 'Q';
			cols[c] = diag1[r - c + n - 1] = diag2[r + c] = true;
			backtrack(r + 1, n, board, results, cols, diag1, diag2);
			board[r][c] = '.';
			cols[c] = diag1[r - c + n - 1] = diag2[r + c] = false;
		}
	}
};
int main() {
	Solution solver;
	int n;
	cin>>n;
	vector<vector<string>> results = solver.solveNQueens(n);
	for (int i = 0; i < results.size(); ++i) {
		for (const string& row : results[i]) {
			cout << row << endl;
		}
		cout << endl;
	}

	return 0;
}
