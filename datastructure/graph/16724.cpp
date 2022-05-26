//쓸거같은 STL 목록
#include <iostream>
#include <vector>
//#include <queue>
#include <stack>
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


// print Vector<int>
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

// print Array<int>
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int map[1001][1001];
int visit[1001][1001];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int i, int j, int n, int m, int t){



        int res = 0;

    stack<int> s;
    s.push(i * 10000 + j);
    visit[i][j] = t;

    int temp[1001] = {0};
    int tsize = 0;

    while(!s.empty()){
        int tmp = s.top();
        s.pop();
        int x = tmp / 10000;
        int y = tmp % 10000;

        temp[tsize++] = tmp;

        int nx = dx[map[x][y]] + x;
        int ny = dy[map[x][y]] + y;

        if(!(nx < 0 || nx >= n || ny < 0 || ny >= m)){
            if(visit[nx][ny] == t){
                temp[tsize++] = nx * 10000 + ny;
                res = 1;
                break;
            }
            else if(!(visit[nx][ny])){
                visit[nx][ny] = t;
                s.push(nx * 10000 + ny);
            }
        }
    }
    if (res){
        int x = t;
        for (int i = 0; i < tsize; i++){
            if(temp[i] == temp[tsize-1])
                x = -1;
            visit[temp[i] / 10000][temp[i] % 10000] = x;
        }
    }

    return res;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        char temp[1001];
        cin >> temp;
        for (int j = 0; j < m; j++){
            switch (temp[j])
            {
            case 'D':
                map[i][j] = 0;
                break;
            case 'U':
                map[i][j] = 1;
                break;
            case 'R':
                map[i][j] = 2;
                break;
            case 'L':
                map[i][j] = 3;
                break;
            default:
                break;
            }
        }
    }

    int result = 0;
    int cur = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(visit[i][j] != cur){
                result += dfs(i, j, n, m, cur++);
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     printArray(visit[i], m);
    // }

    cout << result;
}