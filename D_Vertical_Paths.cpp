// Author : karan_cpp_py

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
void solution();
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vvpi vector<vector<pi>>
#define vpl vector<pl>
#define vvpl vector<vector<pl>>
#define pb push_back
#define mp make_pair
#define forloop(i, a, b) for (ll i = a; i < b; i++)
ll max3(ll a, ll b, ll c)
{
    return (max(max(a, b), c));
}
ll min3(ll a, ll b, ll c) { return (min(min(a, b), c)); }
ll max4(ll a, ll b, ll c, ll d) { return (max(max(max(a, b), c), d)); }
ll min4(ll a, ll b, ll c, ll d) { return (min(min(min(a, b), c), d)); }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
void YES() { cout << "YES" << endl; }
void NO() { cout << "NO" << endl; }
const ll mod = 1e9 + 7;
// int y = stoi(s);
//  find substring in string
//  (str.find(str2)!=std::string::npos)
ll binary_exp(ll a, ll b, ll m)
{
    ll result = 1;
    while (b)
    {
        if (b & 1)
        {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return result;
}

ll fact(ll num)
{
    if (num == 0 || num == 1)
        return 1;
    ll ans = 1;
    forloop(i, 2, num + 1)
    {
        ans = (ans * i) % mod;
    }
    return ans;
}
bool isPowerOfTwo(int n)
{
    return (n >= 0) ? (n && (!(n & (n - 1)))) : (n + 1 && (!(n & (n + 1))));
}
bool isPal(string &str)
{
    int start = 0, end = str.size() - 1;
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}
// ((num & (1<<i-1))!=0) will give ith bit of num. Here 0 indexing has been followed.
// (num | (1<<i-1)) will set ith bit of num. Here 0 indexing has been followed.
// (num & (1<<i-1)) will clear ith bit of num. Here 0 indexing has been followed.

void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi nums(n);
        unordered_map<int, int> mp;
        int root = -1;
        forloop(i, 0, n)
        {
            cin >> nums[i];
            if (nums[i] == i + 1)
                root = nums[i];
            mp[i + 1] = 0;
            // mp[nums[i]]++;
        }
        for (auto i : nums)
        {
            mp[i]++;
        }
        priority_queue<pi, vpi, greater<pi>> pq;
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        vvi final;
        vi ans;
        vi vis(n + 2, 0);
        // vis[root-1]=1;
        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            cout << nums[0] << endl;
        }
        else
        {
            while (!pq.empty())
            {
                auto i = pq.top();
                pq.pop();
                int node = i.second;
                // cout<<node<<endl;
                if (vis[node] == 0)
                {
                    ans.pb(node);
                    while (node != root)
                    {
                        vis[node] = 1;
                        if (vis[nums[node - 1]] == 0)
                            ans.pb(nums[node - 1]);
                        node = nums[node - 1];
                    }
                    reverse(ans.begin(), ans.end());
                    final.pb(ans);
                    ans.clear();
                    vis[root - 1] = 1;
                }
            }
            cout << final.size() - 1 << endl;
            if (final.size() == 2)
                cout << final[0].size() << endl;
            else
                cout << final[0].size() - 1 << endl;
            cout << root << " ";
            forloop(i, 1, final[0].size()) cout << final[0][i] << " ";
            cout << endl;
            forloop(i, 1, final.size() - 1)
            {
                cout << final[i].size() - 1 << endl;
                forloop(j, 1, final[i].size()) cout << final[i][j] << " ";
                cout << endl;
            }
        }
        cout<<endl;
    }
}

int main()
{
    solution();
}