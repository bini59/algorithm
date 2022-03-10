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


// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


/*

    6588 골드바흐의 추측

    100만까지의 수까지만

    4보다 큰 짝수 = (소수 홀수) + (소수 홀수)
    임을 증명하라



*/


// 에라토스테네스의 체 

vector<int> plane = vector<int>(1000001, 1);

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    for(int i = 2; i < 1000; i++){
        if(plane[i] == 1){
            for(int j = i*i; j < 1000001; j= j+i){
                plane[j] = 0;
            }
        }
    }
    //printVector(plane);
    plane[0] = plane[1] = plane[2] = 0;

    int n;
    int a , b;
    a = b= 0;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = n; i >2; i--){
            if(plane[i]){
                if(plane[n-i]){
                    a = i; b = n-i;
                    break;
                }
            }
        }
        if(!a){
            printf("Goldbach's conjecture is wrong.\n");
            continue;
        }
        printf("%d = %d + %d\n", n, b, a);
        a = 0; b= 0;
    }
	
}