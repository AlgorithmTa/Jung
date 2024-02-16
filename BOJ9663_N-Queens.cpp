#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int col[15];
int n, total = 0;

bool check(int level)
{
    for(int i = 0; i < level; i++)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)// 대각 or 같은 라인
            return false;
    return true;
}

void nqueen(int x)
{
    if(x == n)
        total++;
    else
    {
        for(int i = 0; i < n; i++)
        {
            col[x] = i; // 해당 위치에 퀸을 배치
            if(check(x)) // 유효하면 퀸 배치
                nqueen(x+1);
        }
    }
}

int main(void){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  nqueen(0);
  cout << total;
}
