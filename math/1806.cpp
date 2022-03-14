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
vector<int> ary; // 1차원 배열
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


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
  
    int n, s;
    scanf("%d%d", &n, &s);

    int result = n+1;
    
    ary = vector<int>(n+1, 0);
    FOR(n) scanf("%d", &ary[i+1]);

    int j = 0;
    FOR(n){
        ary[i+1] += ary[i];
    }

    int x, y;
    x = 0; y = n;
    if(!(ary[y] < s)) {
        for(x = 0; x < n; x++){
            if(ary[y]-ary[x] < s) break;
        }
        x -= 1;
        result = y-x;
        // printf("%d %d\n", x, y);

        for(int i = n-1; i >= result; i--){
            for(int j = 1; j <= result; j++){
                if(i-result+j <= 0) continue;
                if(ary[i]-ary[i-result+j] < s){
                    // printf("%d %d %d\n", i, i-result+j, ary[i]-ary[i-result+j]);
                    result = result-j+1;
                    break;
                }
            }
        }
        for(int i = result; i > 0; i--){
            if(ary[i] >= s){
                result = i;
            }
        }
    }
    else{
        result = 0;
    }

    printf("%d", result);
    // printf(" %d %d\n", x, y);

	


}