#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n;
vector<int> tree[MAXN];
int dist[MAXN], cnt[MAXN];

void dfs(int u, int p, int d) {
    dist[u] = d;
    cnt[u] = 1;
    for (int v : tree[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            cnt[u] += cnt[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u) {
        dfs(u, 0, 0);
        for (int k = 1; k <= n; ++k) {
            if (dist[u] >= k) {
                cout << cnt[u] - cnt[u - k] << " ";
            } else {
                cout << n << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
