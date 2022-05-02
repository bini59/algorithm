//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
//#include <cmath>
//#include <algorithm>
//#include <string>

using namespace std;

/*
scanf, printf 쓰기.

cout 을 쓸때는 꼭 endl 말고 \n 쓰기.

아니면 밑에꺼 꼭 쓰기, 시간 개걸림.

*/



/*
범위 때문에 문제 안풀릴때는,

index 0은 무시하고 1부터 시작해보기.. 은근 저거때문에 화날때가 많은거같음...
*/



/*
꼭 데이터 범위 확인하기!!
long long 범위 잘 확인해서 풀기.
*/
//typedef long long ll;


//자주 쓸 데이터들
//vector<vector<int>> pln; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)


// 벡터 표시기(int)
void printVector(vector<int> arr) {
    FOR((int)arr.size()) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int map[1001][1001];

int bfs(int x, int y, int n, int m) {
    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    queue<vector<int>> q;
    q.push({ x, y, 1, 0 });

    vector<vector<pair<int, int>>> visited(n, vector<pair<int, int>>(m, { 0, 0 }));

    int result = 0;

    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        int cx = cur[0];
        int cy = cur[1];
        int cnt = cur[2];
        int dir = cur[3];

        if (cx == n - 1 && cy == m - 1) {
            result = cnt;
            break;
        }


        if ((visited[cx][cy].first == 0 && dir == 0) || (visited[cx][cy].second == 0 && dir == 1)) {
            dir == 0 ? visited[cx][cy].first = 1 : visited[cx][cy].second = 1;

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (map[nx][ny] == 1) {
                        if (dir == 0)
                            q.push({ nx, ny, cnt + 1, dir + 1 });
                        else
                            continue;
                    }
                    else {
                        q.push({ nx, ny, cnt + 1, dir});
                    }

                }
            }
        }
    }
    return result;
}


int main() {
    // 혹시나 cin, cout을 쓰게 딘다면...
    //cin.tie(NULL); 
    //ios::sync_with_stdio(false);

    int n, m;
    scanf("%d %d", &n, &m);
    char str[1001];
    FOR(n) {
        scanf("%s", str);
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    int ans = bfs(0, 0, n, m);
    ans = ans == 0 ? -1 : ans;
    printf("%d\n", ans);


    int result = 0;

}
