#include <bits/stdc++.h>
using namespace std;

long long fibo[50] = {0,1,};

long long fibonacci(int a){
  if(a == 0 || a == 1) return fibo[a];
  else if(fibo[a] == 0) fibo[a] = fibonacci(a-1) + fibonacci(a-2);
  return fibo[a];
}

int main(void) {

  int t, a;
  cin >> t;

  for(int i=0; i < t; i++){
    cin >> a;
    if(a == 0) cout << "1 0" << '\n';
    else cout << fibonacci(a-1) << ' ' << fibonacci(a) << endl;
  }
  
  return 0;
}
