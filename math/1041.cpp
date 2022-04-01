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

// 벡터 표시기(int)
void printVector(vector<int> arr){
	FOR((int)arr.size()){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


/*
    1041 주사위

    (i) 3개를 택했을때 제일 작은것 3개를 고른다.



*/

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);

    ll n;
    scanf("%lld", &n);

    vector<int> dice = vector<int>(7, 0);
    FOR(6){
        scanf("%d ", &dice[i+1]);
    }
    ll tmp[3] = {0, 0, 0};
    for(int i = 1; i <= 3; i++)
        tmp[i-1] = (dice[i] < dice[7-i] ? dice[i] : dice[7-i]);


    ll result = 0;
    // n = 1일 경우 예외처리
    if(n == 1){
        int max = 0;
        FOR(6){
            if(dice[i+1] > max) max = dice[i+1];
            result += dice[i+1];
        }
        printf("%lld", result - max);
        return 0;
    }

    ll max = 0;
    int min = 2147483647;
    FOR(3) max = (tmp[i] > max ? tmp[i] : max);
    FOR(3) min = (tmp[i] < min ? tmp[i] : min);
    result += (tmp[0]+tmp[1]+tmp[2])*4;
    result += (tmp[0]+tmp[1]+tmp[2]-max)*4*(n-1);
    result += (tmp[0]+tmp[1]+tmp[2]-max)*4*(n-2);
    result += (min)*4*(n-2)*(n-1);
    result += (min)*(n-2)*(n-2);

    printf("%lld", result);


	
}