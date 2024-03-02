#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  vector<double> num;
  
  cin >> n;

  for(int i=0; i< n; i++) {
    double a;
    cin >> a;
    num.push_back(a);
  }

  double dp[10001] = { 0.0, };
  
  double M = 0.0;
  dp[0] = num[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max(num[i], num[i] * dp[i - 1]);
    M = max(M, dp[i]);
  }

  printf("%.3f", M); //소수점 세자리
  
  return 0;
  
}

