#include <iostream>
#include <vector>
using namespace std;

void backtracking(int N, int row, int& cnt, vector<int>& colVisited, vector<int>& diagLVisited, vector<int>& diagRVisited) {
    if (N == row) {
        ++cnt;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (colVisited[col] || diagLVisited[row - col + N - 1] || diagRVisited[row + col]) {
            continue;
        }

        colVisited[col] = 1;
        diagLVisited[row - col + N - 1] = 1;
        diagRVisited[row + col] = 1;

        backtracking(N, row + 1, cnt, colVisited, diagLVisited, diagRVisited);

        colVisited[col] = 0;
        diagLVisited[row - col + N - 1] = 0;
        diagRVisited[row + col] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int cnt = 0;
    vector<int> colVisited(N, 0);
    vector<int> diagLVisited((N << 1) - 1, 0);
    vector<int> diagRVisited((N << 1) - 1, 0);

    
    backtracking(N, 0, cnt, colVisited, diagLVisited, diagRVisited);
    cout << cnt;
}