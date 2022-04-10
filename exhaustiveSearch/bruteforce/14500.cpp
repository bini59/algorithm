// 14500 테트로미노,
// 주어진 plane에 테트로미노 하나를 놓았을 때,
// 그 놓은 구역의 숫자들의 합이 최대가 되게 하라.



//쓸거같은 STL 목록
#include <iostream>
#include <vector>
//#include <queue>
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
vector<vector<int>> pln; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)


// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


// range : mininum Size for mino
int sol(vector<vector<int>> mino, int n, int m){
    int res = 0;
    // i,f 는 범위를 지정해주고
    for(int i = 0; i <= n-(int)mino.size(); i++){
        for(int j = 0; j <= m-(int)mino[0].size(); j++){
            // 여기부턴 미노 하나에 대한 동작
            int temp = 0;
            for(int k = 0; k < (int)mino.size(); k++){
                for(int l = 0; l < (int)mino[0].size(); l++){
                    if(mino[k][l]){
                        temp += pln[i+k][j+l];
                    }
                }
            }
            res = max(res, temp);
        }
    }

    return res;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int result = 0;
    
    int n, m;
    scanf("%d%d", &n, &m);
    pln = vector<vector<int>>(n, vector<int>(m, 0));
    // 입력
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) scanf("%d", &pln[i][j]);

    
    // 각각 회전할 때, 왼쪽 위부터 차례대로 내려온다.

    // 일자 미노 가로형
    result = max(result, sol({{1, 1, 1, 1}}, n, m));
    // 일자 미노 세로형
    result = max(result, sol({{1}, {1}, {1}, {1}}, n, m));

    // 정사각형 미노
    result = max(result, sol({{1, 1}, {1, 1}}, n, m));

    // ㄴ 자 미노 형태 1
    result = max(result, sol({{1, 0}, {1, 0}, {1, 1}}, n, m));
    // ㄴ 자 미노 형태 2
    result = max(result, sol({{1, 1}, {0, 1}, {0, 1}}, n, m));
    // ㄴ 자 미노 형태 3
    result = max(result, sol({{1, 1}, {1, 0}, {1, 0}}, n, m));
    // ㄴ 자 미노 형태 4
    result = max(result, sol({{0, 1}, {0, 1}, {1, 1}}, n, m));

    // ㄴ 자 미노 형태 5
    result = max(result, sol({{0, 0, 1}, {1, 1, 1}}, n, m));
    // ㄴ 자 미노 형태 6
    result = max(result, sol({{1, 1, 1}, {1, 0, 0}}, n, m));
    // ㄴ 자 미노 형태 7
    result = max(result, sol({{1, 0, 0}, {1, 1, 1}}, n, m));
    // ㄴ 자 미노 형태 8
    result = max(result, sol({{1, 1, 1}, {0, 0, 1}}, n, m));

    // ㅗ 자 미노 형태 1
    result = max(result, sol({{1, 0}, {1, 1}, {1, 0}}, n, m));
    // ㅗ 자 미노 형태 2
    result = max(result, sol({{0, 1}, {1, 1}, {0, 1}}, n, m));
    // ㅗ 자 미노 형태 3
    result = max(result, sol({{0, 1, 0}, {1, 1, 1}}, n, m));
    // ㅗ 자 미노 형태 4
    result = max(result, sol({{1, 1, 1}, {0, 1, 0}}, n, m));

    // 지그재그 자 미노 형태 1
    result = max(result, sol({{1, 0}, {1, 1}, {0, 1}}, n, m));
    // 지그재그 자 미노 형태 2
    result = max(result, sol({{0, 1, 1}, {1, 1, 0}}, n, m));
    // 지그재그 자 미노 형태 3
    result = max(result, sol({{0, 1}, {1, 1}, {1, 0}}, n, m));
    // 지그재그 자 미노 형태 4
    result = max(result, sol({{1, 1, 0}, {0, 1, 1}}, n, m));

    printf("%d", result);

}