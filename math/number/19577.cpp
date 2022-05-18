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
void printVector(vector<int> arr) {
    FOR((int)arr.size()) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// print Array<int>
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#define MAX_SIZE 1000001

int main() {
    // 혹시나 cin, cout을 쓰게 딘다면...
    //cin.tie(NULL); 
    //ios::sync_with_stdio(false);

    int x;
    scanf("%d", &x);
    ll R = 0;
    for (int Q = 1; Q <= (ll)ceil(pow(x, 0.5))*100; Q++){
        if(x % Q)
            continue;
        ll n = Q;
        ll j = 2;
        ll m = n;
        ll t = 0;
        ll result = 1;
        while (n != 1 && j < (ll)ceil(pow(m, 0.5))+1 && (result*Q <= x)) {
            if ((n % j == 0)) {
                if(t != j){
                    result *= (j - 1);
                    t = j;
                }
                else{
                    result *= j;
                }
                n /= (j);
                continue;
            }
            j++;
        }
        if(n > 1){
            result *= (n-1);
        }
        if(result*Q == x){
            cout << Q;
            return 0;
        }
    }
    cout << -1;
}