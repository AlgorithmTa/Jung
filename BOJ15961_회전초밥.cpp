#include <bits/stdc++.h>
using namespace std;

// 접시의 수 N, 초밥의 가짓수 d,
// 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
int n, d, k, c;
int sushi[3000001];
int start, cnt, answer;
unordered_map<int, int> m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> d >> k >> c;

  for(int i=0; i<n; i++){
    cin >> sushi[i];
  }

  for (int i = 0; i < k - 1; i++) { 
    m[sushi[i]]++;
  } 

  int fin = k - 1;
    for(int i = 0 ; i < n ; i++){ 
      int del = sushi[start];
      int cur = sushi[fin%n];
      m[cur]++;
      int num = m.size();
      if (m.find(c) == m.end()) {
        answer = max(answer,num + 1);
      }
      else {
        answer = max(answer, num);
      }
      m[del]--;
      if (m[del] == 0) 
        m.erase(m.find(del));
      start++;
      fin++;
    }
    cout << answer;
  
  
  
  return 0;
}

