#include <bits/stdc++.h>

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Free_Palestine  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int             long long
#define ld              long double
#define dd              double
#define ef              else if
#define vi              vector<int>
#define vl              vector<long long>
#define vs              vector<string>
#define vpi             vector<pair<int,int>>
#define si              set<int>
#define all(v) (v).begin(), (v).end()
#define Rall(v) (v).rbegin(), (v).rend()
#define loop(n)  for(int i = 0 ; i < n ; ++i)
#define endl     '\n'
#define YES             cout<<"YES"
#define NO              cout<<"NO"
#define Yes             cout<<"Yes"
#define No              cout<<"No"
#define yes             cout<<"yes"
#define no              cout<<"no"
#define pb              push_back
#define sp              " "
#define fi              first
#define se              second
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

bool Is_Prime(int p)
{
    if(p < 2)
        return false;
    if(p == 2)
        return true;
    if(p % 2 == 0)
        return false;

    int limit = sqrt(p);
    for(int i = 3; i <= limit; i += 2)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

// Debugging
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for(const auto& i : v) os << i << ' ';
    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for(auto& i : v) is >> i;
    return is;
}

//  وَلَسَوْفَ يُعْطِيكَ رَبُّكَ فَتَرْضَى

//const int dx[] = {0,0,1,-1};
//const int dy[] = {1,-1,0,0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void _3n_1(int n)
{
    // base case
    if(n <= 1)
    {
        cout << 1 << endl;
        return;
    }
    // transition
    cout << n << sp;
    (n & 1 ? _3n_1(n * 3 + 1) : _3n_1(n / 2));
}

void solve() {
    int n;cin >> n;
    _3n_1(n);
}

signed main()
{
    Free_Palestine
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}