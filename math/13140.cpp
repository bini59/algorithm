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
int N;

pair<int, int> result = {0, 0};

// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int sol(vector<int> res, vector<int> n, int k){
    if(k == 7){
        int hello = res[0]*10000 + res[1]*1000 + res[2] * 100 + res[2] *10 + res[3];
        int world = res[4]*10000 + res[3]*1000 + res[5] * 100 + res[2] *10 + res[6];
        if(N == hello+world){
            result.first = hello; result.second = world;
            return 1;
        }
        return 0;
    }
    for(int i = 0; i < 10; i++){
        if(i == 0 && (k == 0 || k == 4)) continue;
        if(!n[i]){
            n[i] = 1;
            res[k] = i;
            sol(res, n, k+1);
            
            n[i] = 0;
        } 
        if(result.first) return 0;
    }
    return 0;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);;l

    scanf("%d", &N);
    vector<int> res = vector<int>(7, 0);
    if (N < 190000){
        sol(res, vector<int>(10, 0), 0);
    }

    // vector<int> n = vector<int>(10, 0);
    // for(int k = 0; k < 7; k++){
    //     for(int i = 0; i < 10; i++){
    //         if(i == 0 && (k == 0 || k == 4)) continue;
    //         if(!n[i]){
    //             n[i] = 1;
    //             res[k] = i;
    //         }
    //     }
    // }

    if(result.first){
        printf("%7d\n+%6d\n-------\n%7d", result.first, result.second, N);
    }
    else{
        printf("No Answer");
    }

	int result = 0;
	
}



 