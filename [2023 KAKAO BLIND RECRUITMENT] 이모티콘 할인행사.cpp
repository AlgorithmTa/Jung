#include <string>
#include <vector>

// 코드 참고해서 풀었음여
using namespace std;

int dis[4] = {40,30,20,10};
vector<pair<int,int>> price(7,{0,0}); //할인된 가격, 할인율 저장
vector<int> answer(2,0); // 결과 저장

void    dfs(int cnt, int n, vector<vector<int>> users, vector<int> emoticons)
{
    // 이모티콘에 대한 할인가격 할인율을 다 기입했을 때
    if(cnt == n){
        int plus = 0, sum = 0;
        for(int i=0;i<users.size();i++) {
            int tmp = 0;
            for(int j=0;j<n;j++)
                if (users[i][0] <= price[j].second) tmp += price[j].first;//원하는 할인율이상이면 구매값++
            if(tmp >= users[i][1]) plus++;//구매값이 정해진 값 이상이면
            else sum += tmp;//이윤++
        }
        if (plus > answer[0]){
            //임티플 가입자수가 더 많으면 
            answer[0] = plus;
            answer[1] = sum;
        }
        else if(plus == answer[0] && sum >= answer[1]) 
            answer[1] = sum; // 가입자수가 같고 이윤이 크면
        return ;
    }
    for(int i=0;i<4;i++) {
        price[cnt].first = (100 - dis[i]) * emoticons[cnt] / 100;
        price[cnt].second = dis[i];
        dfs(cnt+1, n, users, emoticons);
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    dfs(0, emoticons.size(), users, emoticons);
    return answer;
}
