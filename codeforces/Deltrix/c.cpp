#include <bits/stdc++.h>

using namespace std;

#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                    \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
    {
sim > struct rge
{
    c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug
{
#ifdef LOCAL
    ~debug()
    {
        cerr << endl;
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c &)
    {
        ris;
    }
#endif
}
;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i >= k; i--)
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define all(a) a.begin(), a.end()
#define sz(a) int((a).size())
#define tr(c, i) for (typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c,x) != c.end())

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<vector<int>> vvi;

int INF = 1e9;
const int MAXN = 1e6+1;
bool is_composite[MAXN];

void sieve(int n)
{
    fill(is_composite, is_composite + n, false);
    for (int i = 2; i < n; ++i)
    {
        //if (!is_composite[i]) prime.push_back (i);
        for (int j = 2; i * j < n; ++j)
            is_composite[i * j] = true;
    }
}
bool isPrime(int n)
{
    if (n < 2)
        return false;
    return !is_composite[n];
}
void calculate(int T)
{
    int n, e;
    cin >> n >> e;
    vector<long long> a(n);
    REP(i, n)
    cin >> a[i];
    long long ans = 0LL;
    bool allOne = true;

    REP(i, n)
    {
        if (a[i] == 0)
            continue;

        int startIndex = i;
        bool found = false;
        int multiplier = 0;
        
        while (startIndex < n and a[startIndex] == 1)
        {
            found = true;
            a[startIndex] = 0;
            startIndex += e;
            ++multiplier;
        }

        if (startIndex >= n)
            continue;
        int cnt = 0;
        if (isPrime(a[startIndex]))
        {
            if (multiplier == 0) multiplier = 1;
            if (found) {
                ++cnt;
            }
                
            for (int j = startIndex + e; j < n; j += e)
            {
                if (a[j] == 1)
                {
                    //cout << "Found an answer: " << j << endl;
                    ++cnt;
                    continue;
                }
                break;
            }
        }
        debug() << imie(cnt) imie(startIndex) imie(i) imie(e) imie(a[startIndex]) imie(a[i]) imie(multiplier);

        ans += 1LL * cnt * multiplier;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    sieve(1000000);
#ifdef LOCAL
    int debugT = T;
    clock_t z = clock();
#endif
    while (T--)
    {
#ifdef LOCAL
        int Test_Case_Number = debugT - T;
        debug() << imie(Test_Case_Number);
#endif
        calculate(T);
#ifdef LOCAL
        debug() << ("----------------------------------------------------");
#endif
    }
#ifdef LOCAL
    double Total_Execution_time = (double)(clock() - z) / CLOCKS_PER_SEC;
    debug() << imie(Total_Execution_time);
#endif
}