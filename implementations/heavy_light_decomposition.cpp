#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int parents[N];
int chain_heads[N];
int subtree_size[N];
int chain_numbers[N];
vector<int> adj[N];

int DFS(int i, int parent) {
  parents[i] = parent;
  subtree_size[i] = 1;
  for (int j : adj[i]) {
    if (j == parent) continue;
    subtree_size[i] += DFS(j, i);
  }
  return subtree_size[i];
}

void HLD(int i, int* chain_number) {
  chain_numbers[i] = *chain_number;
  if (chain_heads[*chain_number] == -1) chain_heads[*chain_number] = i;
  int special_child = -1;
  for (int j : adj[i]) {
    if (j == parents[i]) continue;
    if (special_child == -1 || subtree_size[j] > subtree_size[special_child]) {
      special_child = j;
    }
  }
  if (special_child != -1) {
    HLD(special_child, chain_number);
  }

  for (int j : adj[i]) {
    if (j == parents[i] || j == special_child) continue;
    (*chain_number)++;
    HLD(j, chain_number);
  }
}
int main() {
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[2].push_back(3);
  adj[2].push_back(4);
  adj[2].push_back(9);
  adj[3].push_back(5);
  adj[4].push_back(6);
  adj[5].push_back(7);
  adj[5].push_back(8);

  DFS(0, 0);
  memset(chain_heads, -1, sizeof(chain_heads));
  int chain_number = 0;
  HLD(0, &chain_number);
  for (int i = 0; i < N; i++) {
    cout << chain_numbers[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << chain_heads[i] << ' ';
  }
  cout << endl;
}