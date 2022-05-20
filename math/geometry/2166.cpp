//쓸거같은 STL 목록
#include <iostream>
#include <vector>
//#include <queue>
//#include <stack>
#include <cmath>
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

// double triArea(pair<int, int> loc[3]){
//     // printf("(%d, %d), (%d, %d), (%d, %d)\n", loc[0].first, loc[0].second, loc[1].first, loc[1].second, loc[2].first, loc[2].second);
//     return abs((loc[2].second * (loc[0].second - loc[1].second)) - ((loc[0].first - loc[1].first) * loc[2].first) + (loc[1].first * (loc[0].first - loc[1].first)) - (loc[1].second * (loc[0].first - loc[1].first)));
// }

// double solution(pair<int, int> *loc, int size){
//     if(size == 2) return 0;
//     double res = 0;
//     for (int i = 0; i < size-2; i+=2){
//         pair<int, int> temp[3];
//         temp[0] = loc[i*2]; temp[1] = loc[i*2+1]; temp[2] = loc[i*2+2]; 
//         res += triArea(temp);
//         loc[i + 1] = loc[i + 2];
//     }
//     if(!(size % 2)){
//         pair<int, int> temp[3];
//         temp[0] = loc[0]; temp[1] = loc[size-1]; temp[2] = loc[size-2];
//         res += triArea(temp);
//         loc[size / 2] = loc[size - 1];
//     }

//     return res + solution(loc, size/2);
// }

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
    // cout.tie(NULL);
    cin.tie(NULL); 
	ios::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<ll, ll> locations[10001];
    for (int i = 0; i < n; i++){
        cin >> locations[i].first;
        cin >> locations[i].second;
    }
    locations[n] = locations[0];

    ll res = 0;
    for (int i = 0; i < n ; i++){
        res += locations[i].first * locations[i + 1].second;
        res -= locations[i + 1].first * locations[i].second;
    }
    if(res < 0) res = -res;
    if(res % 2){
        printf("%lld.5", res / 2);
    }
    else{
        printf("%lld.0", res / 2);
    }

    int result = 0;
	
}