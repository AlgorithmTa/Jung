#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, m;
string s;
int a, b;
bool node[26][26];

int main(void){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  
  for(int i=0; i< n; i++) {
    cin >> s;
    a = s[0] - 'a';
    cin >> s; 
    cin >> s;
    b = s[0] - 'a';

    node[a][b] = true;
  }

// 그냥 풀었다가 실패해서 플로이드 와샬 내용 찾아보고 추가..
  for (int k = 0; k < 26; k++) // 거쳐가는 노드
    for (int i = 0; i < 26; i++) // 출발 노드
      for (int j = 0; j < 26; j++) // 도착 노드
        if (node[i][k] == true && node[k][j] == true)
          node[i][j] = true;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> s;
    a = s[0] - 'a';
    cin >> s;
    cin >> s;
    b = s[0] - 'a';

    cout << (node[a][b] ? "T" : "F") << '\n';
  }
}
