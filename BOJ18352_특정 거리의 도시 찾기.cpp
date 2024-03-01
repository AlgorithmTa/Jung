#include <bits/stdc++.h>
using namespace std;

int n, m, k, x;

vector<vector<int>> city;
vector<int> dist;
vector<int> result;


void bfs() {
  int start = x; // X번 도시로부터 시작
  dist[x] = 0;

  list<int> queue; 
  queue.push_back(x);

  while (!queue.empty()) {
    int now = queue.front(); 
    queue.pop_front();
    
    for (int i = 0; i < city[now].size(); i++) {
      int next = city[now][i]; 
      if (dist[next] == -1) {
        dist[next] = dist[now] + 1;
        queue.push_back(next);
      }
    }

  }
  for (int i = 1; i <= n; i++) {
    if (dist[i] == k)
      result.push_back(i);
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // 첫째 줄에 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X가 주어진다.
  cin >> n >> m >> k >> x;
  city = vector<vector<int>>(n + 1); 
  dist = vector<int>(n + 1, -1);

  for(int i=0; i < m; i++){
    int a, b;
    cin >> a >> b;
    city[a].push_back(b);
  }

  // X로부터 출발하여 도달할 수 있는 도시 중에서,
  // 최단 거리가 K인 모든 도시의 번호를 한 줄에 하나씩 오름차순으로 출력한다.

  bfs();
  if (result.size() == 0) cout << -1;
  else {
    for (int i = 0; i < result.size(); i++)
      cout << result[i] << endl;
  }
  
}

