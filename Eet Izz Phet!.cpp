//      Bismillah-ir-Rahman-ir-Rahim


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return (a % m - b % m) % m; }
ll mod_mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll mod_div(ll a, ll b, ll m) { return (a % m * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod1 = 1e9 + 7 ;
const ll mod2 = 1e9 + 9 ; 
const int mx = 1e5 + 123 ;
const double eps = 1e-7 ;


ll prime[mx] ; 
ll P = 257 ; 
set<ll>st1 , st2  ; 
ll n , m ; 



ll Hash1(string s)
{
        ll ret = 0 ; 
        for(int i=0;i<s.size();i++)
        {
                ret = mod_add(ret*P,s[i],mod1) ; 
        }
        return ret ; 
}

ll Hash2(string s)
{
        ll ret = 0 ; 
        for(int i=0;i<s.size();i++)
        {
                ret = mod_add(ret*P,s[i],mod2) ; 
        }
        return ret ; 
}




void solution()
{
        cin >> n  ; 
        for(int i=0;i<n;i++)
        {
                string s ; 
                cin >> s; 
                st1.insert(Hash1(s)) ; 
                st2.insert(Hash2(s)) ; 
        }
        cin >> m ; 
        for(int i=0;i<m;i++)
        {
                string s ; 
                cin >> s; 
                bool b1 = (st1.find(Hash1(s))!=st1.end()) ; 
                bool b2 = (st2.find(Hash2(s))!=st2.end()) ; 
                if(b1 and b2) cout << "yes\n" ; 
                else cout << "no\n" ;  
        }
}


int main()
{
        fastIO;
        // file() ;
        int _ = 1; //cin >> _;
        while (_--) solution();
        return 0;
}
