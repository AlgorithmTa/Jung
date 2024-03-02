#include <bits/stdc++.h>
using namespace std;

int num, result; // 100 이하의 자연수
vector<pair<int, int>> line;
int dp[100];

void solution() {
  // 왼쪽 정렬
  sort(line.begin(), line.end());


  // 젤 긴거를 하나씩 뺌
  for (int i = 0; i < num; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (line[j].second < line[i].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }

    result = max(result, dp[i]);
  }

  cout << num - result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> num;

  for(int i=0; i<num; i++){
    int a, b;
    cin >> a>> b;
    line.push_back({a,b});
  }

  solution();
  
  return 0;
  
}

