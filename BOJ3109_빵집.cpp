#include<iostream>
#include<algorithm>
using namespace std;

int r, c, answer;
char MAP[10001][500];
bool visit[10001][500];
bool ans;

int dx[] = {-1,0,1};
int dy[] = {1,1,1,};


void DFS(int x ,int y){
  visit[x][y] = true;
  if(y == c-1){
    ans = true;
    answer++;
    return;
  }
    
  for(int i = 0; i < 3; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx >= 0 && ny >= 0 && nx < r && ny < c){
      if(MAP[nx][ny] == '.' && visit[nx][ny] == false){
        DFS(nx, ny);
        if(ans == true) return;
      }
    }
  }
}

  
int main(void) {

  cin >> r >> c;
  for(int i = 0; i < r; i++){
    for(int j =0; j < c; j++){
      cin >> MAP[i][j];
    }
  }

    for(int i = 0; i < r; i++){
      ans = false;
      DFS(i, 0);
    }
    cout << answer << endl;
   
  return 0;
}
