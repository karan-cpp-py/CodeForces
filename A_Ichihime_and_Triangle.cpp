#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
void solution();
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vvpi vector<vector<pi>>
#define vpl vector<pl>
#define vvpl vector<vector<pl>>
#define pb push_back
#define mp make_pair
#define forloop(i,a,b) for(int i=a; i<b; i++)
ll max3(ll a, ll b, ll c){return(max(max(a,b),c));}
ll max4(ll a, ll b, ll c, ll d){return(max(max(max(a,b),c),d));}
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
void YES(){cout<<"YES"<<endl;}
void NO(){cout<<"NO"<<endl;}
const ll mod = 1e9 + 7;


int main(){
    int t; cin>>t;
    while(t--){
        solution();
    }
}
void solution(){
    ll a,b,c,d; cin>>a>>b>>c>>d;
    if(b>=c) cout<<b<<" "<<b<<" "<<c<<endl;
    else cout<<b<<" "<<c<<" "<<c<<endl;

}