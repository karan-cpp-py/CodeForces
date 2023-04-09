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
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int x1=-1,y1=-1,x2=-1,y2=-1,x3=-1,y3=-1;
        cout<<"? "<<n/2<<" "<<m/2<<endl;
        //cin>>x1>>y1;
        fflush(stdout);
        if(n%2==0){
            cout<<"? "<<n/2+1<<" "<<m/2<<endl<<flush;
            //cin>>x2>>y2;
            fflush(stdout);
        }
        else{
            cout<<"? "<<n/2+1<<" "<<m/2<<endl;
            //cin>>x2>>y2;
            fflush(stdout);
            cout<<"? "<<n/2<<" "<<m/2+1<<endl;
            //cin>>x3>>y3;
            fflush(stdout);
        }
        int x,y;
        if(x1+x2+x3<=2*(n+m)-2-x1-x2-x3){
            cin>>x1>>y1;
            fflush(stdout);
            x=n-x1;
            y=m-y1;
        }
        else if(n%2==0 && (x1+x2+x3)>=(2*(n+m)-2-x1-x2-x3+2)){
             cin>>x2>>y2;
            fflush(stdout);
            x=n-x2;
            y=m-y2;
        }
        else if(n%2==1 && (x1+x2+x3)>=(2*(n+m)-2-x1-x2-x3+1)){
             cin>>x2>>y2;
            fflush(stdout);
            x=n-x2;
            y=m-y2;
        }
        else{
             cin>>x3>>y3;
            fflush(stdout);
            x=n-x3;
            y=m-y3;
        }
        cout<<"! "<<x<<" "<<y<<endl<<flush;
        fflush(stdout);
    }
}

int main(){
    solution();
}