#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){

  int n;
  vector<int> t;
  
  cin >> n;
  for(int i=0; i< n; i++) {
    int a;
    cin >> a;
    t.push_back(a);
  }

  sort(t.begin(), t.end());

  long long total = 0;
  for(int i=0; i<n; i++){
    total += abs((i+1) - t[i]);
  }
  cout << total;
  
  return 0;
}
