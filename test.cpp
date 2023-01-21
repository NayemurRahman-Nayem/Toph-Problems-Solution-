#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 + 123 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e18  ;
const int mx = 2e5 + 123 ;
const double eps = 1e-7 ;


// forever-striver 


ll a[mx] , n , m ;
ll tc = 0  ;
vector<ll>segindex ; 

struct info {
    ll prop, sum;
} segtree[mx * 3];


void build(int node, int b, int e)
{
        if (b == e)
        {
                segtree[node].prop = 1 ;
                segindex.pb(node) ;
                return ;
        }
        int Leftnode = node * 2 ;
        int Rightnode = node * 2 + 1 ;
        int midInd = (b + e) / 2 ;
        build(Leftnode, b, midInd) ;
        build(Rightnode, midInd + 1, e) ;
        segtree[node].prop = 1 ;
}


void update(int node, int b, int e, int i, int j, ll m)
{
        if (i>e || j<b)
                return;
        if (b>=i && e<=j)
        {
                if (segtree[node].prop <= mod / m && segtree[node].prop != infLL)
                {
                        segtree[node].prop *= m ; 
                }
                else
                        segtree[node].prop = infLL ;

                return ;
        }
        int Leftnode = node * 2 ;
        int Rightnode = Leftnode + 1 ;
        int mid_ind = (b + e) / 2 ;
        update(Leftnode, b, mid_ind, i, j, m) ;
        update(Rightnode, mid_ind + 1, e, i, j, m) ;
}



void solution()
{
        segindex.clear() ; 
        cin >> n >> m ;
        for(int i=1;i<=n;i++)
        {
                cin >> a[i] ;
        }
        build(1,1,n) ; 
        for(ll i=1;i<=m;i++) {
                ll l , r , m ;
                cin >> l >> r >> m ; 
                update(1,1,n,l,r,m) ; 
        }
        cout << "Case " << ++tc << ": " ; 
        for(ll i=0;i<n;i++) {
                ll index = segindex[i] ; 
                while(index) {
                        a[i+1]/=segtree[index].prop ; 
                        index/=2 ; 
                }
                cout << a[i+1] << " " ; 
        }
        cout el ; 
}


int main()
{
        fastIO;
        // file() ;
        int _ = 1; cin >> _;
        while (_--) solution();
        return 0;
}