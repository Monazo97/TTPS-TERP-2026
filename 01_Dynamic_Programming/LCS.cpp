#include <bits/stdc++.h>

using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main() {
    FIN;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector <vector<int>> dp(n+1,vector<int>(m+1,0));
    vector <vector<pair<int,int>>> prev(n+1,vector<pair<int,int>>(m+1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(dp[i-1][j] >= dp[i][j-1]) {
                prev[i][j] = {i-1,j};
            } else {
                prev[i][j] = {i,j-1};
            }
            if(a[i-1] == b[j-1]) {
                if(dp[i-1][j-1]+1 > dp[i][j]) {
                    prev[i][j] = {i-1,j-1};
                }
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    pair<int,int> pos = {n,m};
    vector <int> rta;
    while(pos.first > 0 and pos.second > 0) {
        pair<int,int> ant = prev[pos.first][pos.second];
        if(ant.first < pos.first and ant.second < pos.second) {
            rta.push_back(a[ant.first]);
        }
        pos = ant;
    }
    cout << dp[n][m] << "\n";
    reverse(rta.begin(),rta.end());
    for(int x : rta) cout << x << " ";
    cout << "\n";
    
    return 0;
}