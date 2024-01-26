#include<iostream>
#include<algorithm>
using namespace std;

int map[11][11];
bool visited[11];
int arr[11];
int n,k;
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int ans = 987654321;

void dfs(int start){
   if(start == n){
       if(arr[0] != k){
           return;
       }
       int sum = 0;
       for(int i = 0;i<n-1;i++){
           sum += map[arr[i]][arr[i+1]];
       }
       ans = min(ans,sum);
       return;
   }
    for(int i = 0;i<n;i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[start] = i;
            dfs(start+1);
            visited[i] = false;
        }
    }
}
int main(void){
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }

    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
            }
        }
    }

    dfs(0);

    cout << ans;
}
