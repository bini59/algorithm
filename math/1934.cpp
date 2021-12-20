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


// 1934 최소공배수


/*

    최소공배수 => 두수를 곱한후 최대공약수로 나눈다.

    최대공약수 => 유클리드호제법

    a > b 이고,
    a%b => r이라고 할때

    gcd(a, b) = gcd(b, r)
    r = 0이면, 최대공약수가 b가 된다.


    재귀식, 반복식으로 내려가서 r = 0으로 만들어서 최대공약수를 구할 수 있다.

*/


int gcd(int a, int b){
    while(b != 0){
        int temp = a;
        a = b;
        b = temp%b;
    }

    return a;
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    int n = 0;
    scanf("%d", &n);

    int a, b;

    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        if(a < b){
            int temp = b;
            b = a;
            a = temp;
        }

        int gcdRes = gcd(a, b);
        printf("%d\n", a*b/gcdRes);
    }

	int result = 0;
	
}