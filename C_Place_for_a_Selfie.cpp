// Author : karan_cpp_py

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
#define forloop(i,a,b) for(ll i=a; i<b; i++)
ll max3(ll a, ll b, ll c){return(max(max(a,b),c));}
ll min3(ll a, ll b, ll c){return(min(min(a,b),c));}
ll max4(ll a, ll b, ll c, ll d){return(max(max(max(a,b),c),d));}
ll min4(ll a, ll b, ll c, ll d){return(min(min(min(a,b),c),d));}
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
void YES(){cout<<"YES"<<endl;}
void NO(){cout<<"NO"<<endl;}
const ll mod = 1e9 + 7;
//int y = stoi(s);
// find substring in string 
// (str.find(str2)!=std::string::npos)
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
bool isPowerOfTwo(int n) {
    return (n>=0) ? (n && (!(n & (n-1)))) : (n+1 && (!(n & (n+1))));
}
bool isPal(string& str){
    int start=0,end=str.size()-1;
    while(start<=end){
        if(str[start++]!=str[end--]) return false;
    }
    return true;
}
bool flag=true;
// ((num & (1<<i-1))!=0) will give ith bit of num. Here 0 indexing has been followed.
// (num | (1<<i-1)) will set ith bit of num. Here 0 indexing has been followed.
// (num & (1<<i-1)) will clear ith bit of num. Here 0 indexing has been followed.
ll id=0;
int bs(long long b, vector<ll>& k, long long success, int l, int r){
    if(l>r) return l;
    int m = l+(r-l)/2;
    if((1LL*(b-k[m])*(b-k[m]))<success){
        flag=false;
        id=m;
        return bs(b,k,success,r+1,r);
    }
    else if(b<=0 && k[m]>=0) return bs(b,k,success,l,m-1);
    else if(b<=0 && k[m]<=0 && b>=k[m]) return bs(b,k,success,m+1,r);
    else if(b<=0 && k[m]<=0 && b<=k[m]) return bs(b,k,success,l,m-1);
    else if(b>=0 && k[m]>=0 && b>=k[m]) return bs(b,k,success,m+1,r);
    else if(b>=0 && k[m]>=0 && b<=k[m]) return bs(b,k,success,l,m-1);
    return bs(b,k,success,m+1,r);
}
void solution(){
    int t; cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> k(n);
        forloop(i,0,n) cin>>k[i];
        sort(k.begin(),k.end());
        forloop(i,0,m){
            ll a,b,c; cin>>a>>b>>c;
            if(c<0) NO();
            else{
                ll ac4=(1LL*4*a*c);
                //bool flag=true;
                ll idx = bs(b,k,ac4,0,n-1);
                if(flag) NO();
                else{
                    YES();
                    cout<<k[id]<<endl;
                    flag=true;
                }
            }
        }
        cout<<endl;
    }
}

int main(){
    solution();
}