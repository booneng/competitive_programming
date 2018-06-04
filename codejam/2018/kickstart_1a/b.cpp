#include "bits/stdc++.h"
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
typedef long long ll;
typedef long double ld;
ld V[20005], par[20005];
int main() {
	int TC;
	scanf("%d", &TC);
	for (int cn = 1; cn <= TC; ++cn) {
		int N, K;
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; ++i) {
			scanf("%Lf", &V[i]);
		}
		sort(V, V + N);
		for (int i = 0; i < N; ++i) {
			par[i] = i ? V[i] + par[i - 1] : V[i];
		}
		ld avg = 0;
		for (int i = 0; i <= K; ++i) {
			int p = lower_bound(V, V + N, avg) - V;
			ld sum = par[N - 1];
			if (p) sum -= par[p - 1];
			sum += p * avg;
			avg = sum / N;
			cout << avg << endl;
		}
		printf("Case #%d: %.9Lf\n", cn, avg);
	}
}

