#include <bits/stdc++.h>
using namespace std;

// V개의 마을와 E개의 도로로 구성되어 있는 도시
int v, e;
int arr[401][401];
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> v >> e;

  for(int i=1;i<=v;i++)
    for(int j=1;j<=v;j++)
      if(i!=j) arr[i][j] = INF;

  for(int i=0; i< e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    arr[a][b] = c;
  }

  //플로이드 와샬
  for(int k=1;k<=v;k++)
    for(int i=1;i<=v;i++)
        for(int j=1; j<=v;j++)
            if(arr[i][j] > arr[i][k] + arr[k][j])
                arr[i][j] = arr[i][k] + arr[k][j];


  int result = INF;
  for (int i = 1; i <= v; i++) {
    for (int j = 1; j <= v; j++) {
      if (i == j) continue;
      result = min(result, arr[i][j] + arr[j][i]);
    }
  }
  
  // 첫째 줄에 최소 사이클의 도로 길이의 합을 출력
  // 운동 경로를 찾는 것이 불가능한 경우에는 -1을 출력
  cout << ((result == INF) ? -1:result);
  
  return 0;
  
}

