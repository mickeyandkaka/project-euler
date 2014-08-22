#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a,b)    (memset(a,b,sizeof(a)))
#define rep(i,a)    for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

const LL mod = 1000000000ll;

LL f(LL n){
    LL a = n, b = n + 1, c = 2 * n + 1;

    if(a % 2 == 0) a /= 2;
    else b /= 2;

    if(a % 3 == 0) a /= 3;
    else if(b % 3 == 0) b /= 3;
    else  c /= 3;

    a %= mod;
    b %= mod;
    c %= mod;

    return (a * b % mod) * c % mod;
}

LL g(LL st, LL ed){
    LL vst = f(st - 1);
    LL ved = f(ed);
    return (ved - vst + mod) % mod;
}

int main()
{
    LL ans = 0;
    LL n = 1000000000000000ll;
//    LL n = 7;
    for(LL i=1; i<=n; )
    {
        LL v = n / i;
        LL cur = n / v;
        ans = (ans + g(i, cur) * (v % mod) % mod) % mod;
        i = cur + 1;
    }
    cout<<ans<<endl;

	return 0;
}

