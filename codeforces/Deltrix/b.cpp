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
bool isPossible(vector<char> ch, int curr, char c){
    int offset = c - 'a';
    int i = curr - offset, j = curr -offset + 1, k = curr -offset + 2;
    if(i>=0 and ch[i] == 'a' and ch[j] == 'b' and ch[k] == 'c') {
        debug() << imie(ch[i]) imie(ch[j]) imie(ch[k]);
        return true;
    } 
    return false;
}
bool isValid(vector<char> s, int i)
{
    return (s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'c');
}
int change(vector<char> ch, int pos, char c){
    debug() << imie(ch[pos]) imie(c);

    if (ch[pos] == c) return 0;
    debug() << imie("is possible called");

    //debug() << imie(isPossible(ch,pos,ch[pos]));

    if (isPossible(ch,pos,ch[pos]) ) {
        return -1;
    } else if (isPossible(ch,pos,c)){
        return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    clock_t z = clock();
#endif

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> ch(all(s));
    debug() << imie(ch);

    int cnt=0;
    REP(i, n - 2)
    {
        if (isValid(ch, i))
        {
            cnt++;
        }
    }
    //debug() << imie(cnt);

    REP(i, q)
    {
        
        int pos;
        char c;
        cin >> pos;
        cin >> c;
        pos--;
        //debug() << imie(pos) imie(c);
        int delta = change(ch,pos,c);
        debug() << imie(delta);
        cnt += delta;
        ch[pos] = c;
        cout << cnt << endl;
    }

#ifdef LOCAL
    double Total_Execution_time = (double)(clock() - z) / CLOCKS_PER_SEC;
    debug() << imie(Total_Execution_time);
#endif
}
