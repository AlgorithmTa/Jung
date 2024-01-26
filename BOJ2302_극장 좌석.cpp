#include <bits/stdc++.h>
using namespace std;

int fibo[50];
int vip[50];

void fibonacci(){
  fibo[0] = 1;
  fibo[1] = 1;
  fibo[2] = 2;
  
  for(int i = 3; i < 50; i++) fibo[i] = fibo[i-1]+ fibo[i-2];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  fibonacci();
  
  for(int i = 0; i < m; i++)  cin >> vip[i];

  int answer = 1;
  int start = 0;

  for(int i = 0; i < m; i++){
    int end = vip[i];
    answer = answer * fibo[end-start-1];
    start = end;
  }
  answer = answer * fibo[n-start];
  
  cout << answer;
  return 0;
}

