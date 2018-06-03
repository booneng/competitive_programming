#include <iostream>
#include <algorithm>
#include <cstring>

#define ll long long int
using namespace std;

const int MAXN = 52;

int n, k;
ll a[MAXN], s[MAXN];
bool dp[MAXN][MAXN];

bool dp_check(ll targ, ll mask) {
  memset(dp, false, sizeof dp);
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (((s[i] - s[j]) & mask & targ) == targ) {
	for (int k = 0; k < MAXN - 1; k++) {
	  if (dp[j][k]) dp[i][k + 1] = true;
	}
      }
    }
  }
  return dp[n][k];
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  s[0] = 0;
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
  ll ans = 0;
  for (int i = 56 - 1; i >= 0; i--) {
    if (dp_check(ans | (1LL << i), ~((1LL << i) - 1))) ans |= (1LL << i);
  }

  cout << ans;
  

}
