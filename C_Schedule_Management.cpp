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
void dijkstra(ll source, vector<vector<pair<ll, ll>>> &adj, vector<ll> &distance)
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    distance[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        ll dist = pq.top().first;
        ll prev = pq.top().second;
        pq.pop();
        // vector<pair<int,int>>::iterator i;
        for (auto i : adj[prev])
        {
            ll next = i.first;
            ll distNext = i.second;
            if (distance[next] > dist + distNext)
            {
                distance[next] = distance[prev] + distNext;
                pq.push(make_pair(distance[next], next));
            }
        }
    }
}
struct trieNode{
    trieNode *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, trieNode* node){
        links[ch-'a'] = node;
    }
    trieNode *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

void solution(){
    int t; cin>>t;
    while(t--){
        ll n,m,maxi=0,cnt=0; cin>>n>>m;
        vl nums(n,0);
        forloop(i,0,m){
            ll a; cin>>a;
            nums[a-1]++;
            maxi=max(maxi,nums[a-1]);
        }
        for(auto i : nums){
            if(i==0) cnt++;
        }
        //cout<<maxi<<" ";
        ll sec=1;
        if(cnt==0) cnt=n-1;
        bool flag=false;
        if(maxi==2) cout<<2<<endl;
        else{
            while(maxi>2){
            maxi-=(2*cnt);
            sec+=2;
            if(maxi==1){
                flag=true; break;
            }
            else if(maxi<1){
                break;
            }
            cnt=n-1;
        }
        if(flag==true) cout<<sec+1<<endl;
        else if(maxi==2 && flag==true) cout<<sec+1<<endl;
        else cout<<sec<<endl;
        }
    }
}

int main(){
    solution();
}