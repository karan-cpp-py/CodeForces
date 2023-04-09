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
#define forloop(i, a, b) for (int i = a; i < b; i++)
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

void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        ll sum = 0;
        ll alice = 0, bob = 0;
        if (a1 == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            ll sum=0;
            sum = a1 + min(a2,a3)*2 + min(a1+1,abs(a2-a3)+a4);
            cout<<sum<<endl;
        }
    }
}

int main()
{
    solution();
}