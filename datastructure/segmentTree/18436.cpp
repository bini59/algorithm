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
// typedef long long ll;


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
void printArray(pair<int, int> *arr, int size){
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", arr[i].first, arr[i].second);
    }
    printf("\n");
}
pair<int, int> init(pair<int, int> *tree, int *arr, int start, int end, int index){
    if(start == end) return tree[index] = (arr[start+1] % 2) ? make_pair(0, 1) : make_pair(1, 0);

    int mid = (start + end) / 2;

    pair<int, int> t1 = init(tree, arr, start, mid, index * 2);
    pair<int, int> t2 = init(tree, arr, mid+1, end, index * 2 + 1);

    return tree[index] = make_pair(t1.first + t2.first, t1.second + t2.second);
}

void modify(pair<int, int> *tree, int start, int end, int node, pair<int, int> diff, int index){
    if(index < start || index > end) return;

    tree[node].first += diff.first;
    tree[node].second += diff.second;

    if(start == end) return;
    int mid = (start + end) / 2;

    modify(tree, start, mid, node * 2, diff, index);
    modify(tree, mid + 1, end, node * 2 + 1, diff, index);
}

pair<int, int> getpair(pair<int, int> *tree, int start, int end, int l, int r, int index){
    if(l <= start && r >= end) return tree[index];
    if(l > end || r < start) return {0, 0};
    int mid = (start + end) / 2;

    pair<int, int> t1 = getpair(tree, start, mid, l, r, index * 2);
    pair<int, int> t2 = getpair(tree, mid + 1, end, l, r, index * 2 + 1);

    return make_pair(t1.first + t2.first, t1.second + t2.second);
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);


    int n, m;
    cin >> n;
    int *arr = new int[n+1];
    pair<int, int> *tree = new pair<int, int>[n * 4 + 100];
    for (int i = 0; i < n; i++) cin >> arr[i+1];
    for (int i = 0; i < n * 4 + 100; i++) tree[i] = {0, 0};
    init(tree, arr, 0, n-1, 1);


    cin >> m;

    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;;
        if(a == 1){
            if(!((arr[b] % 2) == (c % 2))){
                if(arr[b] % 2) modify(tree, 1, n, 1, make_pair(1, -1), b);
                else modify(tree, 1, n, 1, make_pair(-1, 1), b);
            }
            arr[b] = c;
        }   
        else{
            pair<int, int> temp = getpair(tree, 1, n, b, c, 1);
            if(a == 2) printf("%d\n", temp.first);
            else if(a == 3) printf("%d\n", temp.second);
        }
    }
}