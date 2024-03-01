#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
#define MAX_VERTEX 20001 // 최대 vertex
#define MAX_EDGE 300001 // 최대 edge


// 최소 비용 배열
int d[MAX_VERTEX];

vector<pair<int, int> > edge[MAX_EDGE];

void dijkstra(int start_node){

    d[start_node] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start_node));

    // pq 의 모든 경로들을 확인할 때까지 반복
    while(!pq.empty()){
      
        int current = pq.top().second;
        int start_to_current_distance = -pq.top().first;

        pq.pop();

        if (d[current] < start_to_current_distance){
            continue;
        }

        for (int i=0; i<edge[current].size(); ++i){
            int next = edge[current][i].second;
            int start_to_next_distance = start_to_current_distance + edge[current][i].first;

            if (d[next] > start_to_next_distance){
                d[next] = start_to_next_distance;

                pq.push(make_pair(-start_to_next_distance, next));
            }
        }
    }
}

int main(){

    // 노드의 개수와 간선의 개수 입력
    int v, e;
    cin >> v >> e;

    // 시작 노드 입력
    int k;
    cin >> k;

    // 최소 비용 배열 초기화
    for (int i=1; i<v+1; ++i){
        d[i] = INF;
    }

    for (int i=0; i<e; ++i){

        int u, v, w;
        cin >> u >> v >> w;

        edge[u].push_back(make_pair(w, v));
    }

    dijkstra(k);

    for (int i=1; i<v+1; ++i){
        if (d[i] == INF){
            cout << "INF" << " ";    
        }
        else{
            cout << d[i] << " ";
        }
    }

    return 0;

}
