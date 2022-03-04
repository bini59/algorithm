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
//vector<vector<int>> pln; // 2차원 배열
//vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(n) for(int i = 0; i < (n); i++)

int n_house;
vector<vector<int>> house;


// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}



int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    scanf("%d", &n_house);

    house = vector<vector<int>>(n_house, vector<int>(3, 0));

    for(int i = 0; i < n_house; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &house[i][j]);
        }
    }

    vector<int> res = vector<int>(3, 0);
    res[0] = house[0][0]; res[1] = house[0][1]; res[2] = house[0][2];
    
    int R, G, B;

    for(int i = 1; i < n_house; i++){
        R = min(res[1], res[2])+house[i][0];
        G = min(res[0], res[2])+house[i][1];
        B = min(res[0], res[1])+house[i][2];
        res[0] = R; res[1] = G; res[2] = B;
    }

    printf("%d", min(B, min(R, G)));

    return 0;
	
}