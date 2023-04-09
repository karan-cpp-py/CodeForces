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
ll min3(ll a, ll b, ll c){return(min(min(a,b),c));}
ll max4(ll a, ll b, ll c, ll d){return(max(max(max(a,b),c),d));}
ll min4(ll a, ll b, ll c, ll d){return(min(min(min(a,b),c),d));}
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
void YES(){cout<<"YES"<<endl;}
void NO(){cout<<"NO"<<endl;}
const ll mod = 1e9 + 7;
ll binary_exp(ll a,ll b, ll m){
    ll result = 1;
    while(b){
        if(b&1){
            result = (result*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return result;
}

ll fact(ll num){
    if(num==0 || num==1) return 1;
    ll ans=1;
    forloop(i,2,num+1){
        ans = (ans*i)%mod;
    }
    return ans;
}
void solution(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vi arr(n+m+1); vi nums(m);
        forloop(i,0,m) cin>>nums[i];
        unordered_map<int,int> mapi;
        int val=1;
        for(int i=n-1; i>=0; i--){
            arr[i]=val;
            mapi[val]=i;
            val++;
        }
        vi idx(n+1,-1);
        int cnt=n,start=0;
        forloop(i,0,m){
            if(mapi.find(nums[i])!=mapi.end()){
                arr[cnt]=nums[i];
                arr[mapi[nums[i]]]=-1;
                mapi[nums[i]]=cnt;
                cnt++;
            }
            else{
                arr[cnt]=nums[i];
                while(arr[start]==-1) start++;
                if(arr[start]<=n && mapi.find(arr[start])!=mapi.end()){
                    idx[arr[start]]=i+1;
                }
                mapi[nums[i]]=cnt++;
                arr[start++]=-1;
            }
        }
        for(int i=1; i<idx.size(); i++){
            cout<<idx[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    solution();
}