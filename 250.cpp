#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define pb push_back
#define mp make_pair
#define clr(a, b)	(memset(a,b,sizeof(a)))
#define rep(i, a)	for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

const LL mod = 10000000000000000ll;

LL power_mod(LL a, LL p, LL m){
	LL ret = 1;
	while(p){
		if(p & 1)	ret = ret * a % m;
		a = a * a % m;
		p >>= 1;
	}
	return ret;
}

LL val[250251];
LL dp[250251][250];

int main()
{
	// freopen("in","r",stdin);
	for(int i=1; i<=250250; i++)
	{
		val[i] = power_mod(i, i, 250);
		//cout<< val[i] << endl;
	}

	clr(dp, 0);
	dp[1][ val[1] ] = 1;
	dp[1][0] = 1;

	for(int i=2; i<=250250; i++)
	{
		for(int j=0; j<250; j++)
		{
			dp[i][j] = dp[i-1][j];
		}

		for(int j=0; j<250; j++)
		{
			dp[i][(j + val[i]) % 250] += dp[i-1][j];
			dp[i][(j + val[i]) % 250] %= mod;
			// cout<< dp[i][j] << endl;
		}
	}
	cout<<(dp[250250][0] - 1 + mod) % mod<<endl;

	return 0;
}