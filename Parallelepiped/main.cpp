#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool contains(vector <int>& a, vector <int>& b) {
    int i = a.size();
    for (int j = 0; j < i; j++) {
        if (a[j] > b[j])
            return false;
    }
    return true;
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int n, m;
    cin >> m >> n;
    vector<vector<int>> paral(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paral[i][j];
        }
        sort(paral[i].begin(), paral[i].end());
    }
    sort(paral.begin(), paral.end());
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int maxim = 0;
        for (int j = 0; j < i; j++) {
            if (contains(paral[j], paral[i])) {
                maxim = max(dp[j], maxim);
            }
        }
        dp[i] = maxim + 1;
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
