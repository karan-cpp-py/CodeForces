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
int equalize(vector<int> nums){
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]!=nums[i+1]){
            return 0;
        }
    }
    return 1;
}
void solution(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi nums(n);
        forloop(i,0,n) cin>>nums[i];
        bool flag = true;
        ll q=0;
        forloop(i,0,n-1){
            if(nums[i]!=nums[i+1]){
                flag=false;
                break;
            }
        }
        if(flag==true){
            cout<<0<<endl;
        }
        else{
            vvi arr1;vi arr2=nums;
            //arr2=nums;
            while(!equalize(nums)){
                int tmp1 = INT_MAX,idx=-1;
                forloop(i,0,n){
                    if(nums[i]<tmp1){
                        tmp1=nums[i]; idx=i;
                    }
                }
                int f = 0;
                forloop(i,0,n){
                    if(nums[i]>tmp1){
                        int tmp2 = (nums[i]/tmp1);
                        if(nums[i]%tmp1) tmp2+=1;
                        arr1.pb({i,idx});
                        nums[i]=tmp2;
                        f=1;
                    }
                }
                if(nums==arr2){
                    q=-1;
                    break;
                }
                arr2=nums;
            }
            if(q==-1){
                cout<<q<<endl;
            }
            else{
                cout<<arr1.size()<<endl;
                forloop(i,0,arr1.size()){
                    cout<<(arr1[i][0])+1<<" "<<(arr1[i][1])+1<<endl;
                }
            }
        }
    }
}

int main(){
    solution();
}