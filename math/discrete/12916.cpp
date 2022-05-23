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
typedef long long ll;


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

#define MOD 1000000007

void multiMatrix(ll (&map)[][100], ll (&map2)[][100], ll n){
    ll **temp = new ll*[n];
    for (int i = 0; i < n; i++){
        temp[i] = new ll[n]();
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                temp[i][j] = (temp[i][j] + (map[i][k] * map2[k][j])) % MOD;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            map[i][j] = temp[i][j];
        }
    }
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

	int n, m;
    cin >> n >> m;
    ll map[100][100];
    ll res[100][100] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }
        res[i][i] = 1;
    }


    while(m > 0){
        if(m % 2){
            multiMatrix(res, map, n);
        }
        multiMatrix(map, map, n);
        m >>= 1;
    }
    ll result = 0;
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            result = (result + res[i][j]) % MOD;
        }
    }
    cout << result;
}