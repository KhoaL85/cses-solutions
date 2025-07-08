#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool c[1002][1002];
pair<int,int> p;
map<int,int> d;
queue<pair<int,int>> q;
int n, m, a[1002][1002], dx[]={-1,0,1,0}, dy[]={0,1,0,-1}, res;

void bfs(int x, int y) {
    q.push({x, y});
    c[x][y] = 1;
    int dem = 1;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int u = p.first + dx[i], v = p.second + dy[i];
            if (u >= 1 && u <= n && v >= 1 && v <= m && !c[u][v] && a[u][v]) {
                c[u][v] = 1;
                q.push({u, v});
                dem++;
            }
        }
    }
    d[dem]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> ch;
            if (ch == '.') {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!c[i][j] && a[i][j]) {
                res++;
                bfs(i, j);
            }
        }
    }
    cout << res;
    return 0;
}
