#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, pair<int, int>> piii;

const int INF = INT_MAX;
const int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

bool isValid(int x, int y, int n, int m, const vector<vector<int>>& board) {
    return x >= 1 && x <= n && y >= 1 && y <= m && board[x][y] != -1;
}

int minKnightMoves(int n, int m, const vector<vector<int>>& board, int x1, int y1, int x2, int y2) {
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
    priority_queue<piii, vector<piii>, greater<piii>> pq;

    dist[x1][y1] = 0;
    pq.push({ 0, {x1, y1} });

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == x2 && y == y2) {
            return currDist;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, n, m, board)) {
                int cost;
                if (board[nx][ny] == 1) {
                    cost = 2;
                }
                else {
                    cost = 1;
                }

                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;
                    pq.push({ dist[nx][ny], {nx, ny} });
                }
            }
        }
    }

    return -1;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (board[x1][y1] == -1 || board[x2][y2] == -1) {
        cout << "No";
        return 0;
    }
    int result = minKnightMoves(n, m, board, x1, y1, x2, y2);

    if (result == -1) {
        cout << "No";
    }
    else {
        cout << result;
    }

    return 0;
}
