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
// ((num & (1<<i-1))!=0) will give ith bit of num. Here 0 indexing has been followed.
// (num | (1<<i-1)) will set ith bit of num. Here 0 indexing has been followed.
// (num & (1<<i-1)) will clear ith bit of num. Here 0 indexing has been followed.

void solution(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int m = 1<<n;
        vi nums;
        forloop(i,0,m){
            int s; cin>>s;
            nums.pb(s);
        }
        sort(nums.begin(),nums.end());
        int mid = m/2;
        ll sum=0;
        forloop(i,0,mid){
            sum+=nums[i];
        }
        forloop(i,mid,m){
            sum-=nums[i-mid];
            ll tmp = sum-nums[i];
            int size = nums.size();
            vector<vector<int>> dp(size,vector<int>(size,0x3f));
            dp[0][0]=0;
            forloop(j,1,mid+1){
                for(int k=1; k<=i-mid+1 && k<=j; k++){
                    int t1 = dp[j-1][k-1]+abs(nums[i-k+1]-tmp);
                    dp[j][k]=min(dp[j][k],t1);
                    dp[j][k-1]=min(dp[j][k-1],dp[j-1][k-1]);
                }
            }
            sum+=nums[i];
            int maxi = 1e9;
            forloop(j,0,mid+1){
                maxi = min(maxi,dp[mid][j]);
            }
            cout<<maxi<<" ";
        }
        cout<<endl;
    }
}

int main(){
    solution();
}