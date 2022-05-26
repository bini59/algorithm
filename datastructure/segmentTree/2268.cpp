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

void modify(ll *tree, int start, int end, int node, ll diff, int index){
    if(index < start || index > end) return;

    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;
    modify(tree, start, mid, node * 2, diff, index);
    modify(tree, mid + 1, end, node * 2 + 1, diff, index);
}

ll sum(ll *tree, int start, int end, int l, int r, int index){
    if(l <= start && r >= end) return tree[index];
    if(l > end || r < start) return 0;
    int mid = (start + end) / 2;

    return sum(tree, start, mid, l, r, index * 2) + sum(tree, mid + 1, end, l, r, index * 2 + 1);
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);


    int n, m;
    cin >> n >> m;
    ll *arr = new ll[n];
    ll *tree = new ll[n * 5 + 100];
    for (int i = 0; i < n; i++) arr[i] = 0;
    for (int i = 0; i < n*2+100; i++) tree[i] = 0;

    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a == 1){
            ll temp = c - arr[b-1];
            arr[b-1] = c;
            modify(tree, 0, n, 1, temp, b-1);
        }   
        else if (a==0){
            if(b < c)
                printf("%lld\n", sum(tree, 0, n, b - 1, c - 1, 1));
            else
                printf("%lld\n", sum(tree, 0, n, c - 1, b - 1, 1));
        }
    }
}