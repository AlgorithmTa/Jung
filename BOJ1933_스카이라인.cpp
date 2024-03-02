#include <bits/stdc++.h>
using namespace std;

// n개의 직사각형 모형 건물
// 전체 윤곽 구하기

typedef pair<int, int> pii;

int n;
vector<pair<pii, pii> > vc;
map<pii, int, greater<> > st;

map<int, int> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i=0; i<n; i++){
    int l, h, r; // 왼쪽 x좌표, 높이, 오른쪽 x좌표
    cin >> l >> h >> r;

    vc.push_back({ {l, h}, { r, 0 } });
    vc.push_back({ {r, h}, { l, 1 } });
  }
  
  // x좌표에 대해 정렬
  sort(vc.begin(), vc.end());

  // 이전의 최고 높이
  int prev = -1;
  st[{0, 0}] = 0;

  for (int i = 0; i < vc.size(); i++)
  {
      int here = vc[i].first.first;
      int other = vc[i].second.first;
      int height = vc[i].first.second;
      int pos = vc[i].second.second;

      // 만약 현재 점이 시작이라면 맵에 그대로 넣는다.
      if (pos == 0)
          st[{height, here}] = other;

      // 시작점이 아닌 끝점이라면 시작점을 찾아 삭제한다.
      else {
          auto it = st.find({ height, other });
          st.erase(it);
      }

      // 지금 맵에 남아있는 높이 최대를 찾는다.
      auto it = st.begin();
      int maxH = it->first.first;

      // 내가 알고있던 이전 최대 높이와 다르다면
      if (maxH != prev)
      {
          // 최대 높이 갱신
          prev = maxH;

          // 만약 시작점이라면 최대 갱신
          if (pos == 0)
              mp[here] = max(mp[here], maxH);

          // 만약 끝점이라면
          else {
              // 아직 표시된 적이없다면 최대값으로 갱신
              if (mp.count(here) == 0)
                  mp[here] = maxH;
              // 표시된 적이 있다면 최솟값으로 갱신
              else
                  mp[here] = min(mp[here], maxH);
          }
      }
  }

  prev = -1;
  for (auto it = mp.begin(); it != mp.end(); it++) {
      if (it->second != prev)
          printf("%d %d ", it->first, it->second);
      prev = it->second;
  }
  
  return 0;
  
}

