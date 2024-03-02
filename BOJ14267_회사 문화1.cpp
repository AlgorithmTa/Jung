#include <bits/stdc++.h>
using namespace std;

int n =0, m =0;
int x, y;
int score[100001] = {0,};
vector<int> vec[100001];

void addScore(int a) {
  for (int i = 0; i < vec[a].size(); i++) {
    score[vec[a][i]] += score[a];
    addScore(vec[a][i]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for(int i=1; i<=n; i++){
    int a;
    cin >> a;
    if (i == 1) continue;
    vec[a].push_back(i);
  }

  for(int i=1; i<=m; i++){
    cin >> x >> y;
    score[x] += y;
  }

  addScore(1);
  
  for(int i=1; i<=n; i++){
    cout << score[i];
    if (i == n) break;
    cout << ' ';
  }

  cout << ' ';
  
  return 0;
  
}

