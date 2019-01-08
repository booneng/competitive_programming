#include <bits/stdc++.h>

using namespace std;

const int MAX_TIME = 1000005;
const int MAX_N = 100005;

int x[MAX_N];
int t[MAX_N];
int p[MAX_N];
int l[MAX_N];
long long f_cnt[MAX_TIME];
long long f_time[MAX_TIME];
long long f[MAX_N];
long long dp[MAX_N];

vector<int> adj[MAX_N];
long long remaining_time;

void add(int tpc, int cnt) {
  long long total_time = (long long)tpc * cnt;
  for (int i = tpc; i < MAX_TIME; i += (i&-i)) {
    f_time[i] += total_time;
    f_cnt[i] += cnt;
  }
}

long long sum(long long* arr, int time_bound) {
  long long s = 0;
  for (int i = time_bound; i > 0; i -= (i&-i)) {
    s += arr[i];
  }
  return s;
}

long long find(long long remaining_time) {
  int left = 1;
  int right = MAX_TIME - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    long long res = sum(f_time, mid);
    if (res < remaining_time) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  long long res_time = sum(f_time, left);
  long long cnt = sum(f_cnt, left);
  if (res_time > remaining_time) {
    cnt -= (res_time - remaining_time) / left;
    if ((res_time - remaining_time) % left) cnt--;
  }
  return cnt;
}

void dfs2(int i) {
  long long m1 = 0;
  long long m2 = 0;
  for (int child : adj[i]) {
    dfs2(child);
    if (dp[child] >= m1) {
      m2 = m1;
      m1 = dp[child];
    }
    else if (dp[child] > m2) {
      m2 = dp[child];
    }
  }
  if (i == 0) {
    dp[i] = max(f[i], m1);
  }
  else {
    dp[i] = max(f[i], m2);
  }
}

void dfs(int i) {
  remaining_time -= 2 * l[i];
  add(t[i], x[i]);
  f[i] = find(remaining_time);
  for (int child : adj[i]) {
    dfs(child);
  }
  add(t[i], -x[i]);
  remaining_time += 2 * l[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  long long T;
  cin >> n >> T;
  remaining_time = T;

  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 1; i < n; i++) {
    cin >> p[i] >> l[i];
    p[i]--;
    adj[p[i]].push_back(i);
  }

  dfs(0);
  dfs2(0);
  cout << dp[0];
}