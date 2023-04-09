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
// ((num & (1<<i-1))!=0) will give ith bit of num. Here 0 indexing has been followed.
// (num | (1<<i-1)) will set ith bit of num. Here 0 indexing has been followed.
// (num & (1<<i-1)) will clear ith bit of num. Here 0 indexing has been followed.

void solution(){
        ll n;
        cin>>n;
        int maxi=-1;
        string str = to_string(n);
        int len=str.size();
        if(len==1) cout<<n<<endl;
        else{
            forloop(i,1,n){
                if(str[i]-'0'>str[i-1]-'0'){
                    maxi=(str[i-1]-'0')+1;
                    break;
                }
                else if(str[i-1]-'0'>str[i]-'0'){
                    maxi=str[i-1]-'0';
                    break;
                }
            }
            if(maxi==-1) maxi=str[0]-'0';
            ll ans=0;
            forloop(i,0,len){
                ans = (ans*10)+maxi;
            }
            cout<<ans<<endl;
        }
        
}

int main(){
    solution();
}