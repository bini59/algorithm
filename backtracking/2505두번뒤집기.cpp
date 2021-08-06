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
// vector<vector<bool>> pln; // 2차원 배열
vector<int> ary; // 1차원 배열
//queue<int> q; // 큐
//stack<int> s; // 스택

//for문 간단하게.
#define FOR(i, n) for(int i = 0; i < (n); i++)

vector<pair<int, int>> result = vector<pair<int, int>>(2, {0, 0});

void changeNum(int start, int end, vector<int>& array){
    int n;
    if((end-start)%2 == 0) n = (end-start)/2;
    else n = (end-start+1)/2;
    for(int i = 0; i < n; i++){
        int temp = array[start+i];
        array[start+i] = array[end-i];
        array[end-i] = temp;
    }
}

void sol(vector<int>& array, int idx, int n, bool reverse){
    int temp = -1;
    
    FOR(i, n){
        if(!reverse){
            if(array[i] != i+1 && temp == -1){
                temp = i;
            }
            if(array[i] == temp+1){
                changeNum(temp, i, array);
                result[idx] = {temp, i};
            }
        }
        else{
            if(array[n-i-1] != n-i && temp == -1){
                temp = n-i-1;
            }
            if(array[n-i-1] == temp+1){
                changeNum(n-i-1, temp,  array);
                result[idx] = {n-i-1, temp};
            }
        }
    }
}


int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ary = vector<int>(n, 0);
    

    FOR(i, n)
        cin >> ary[i];
        
    vector<int> ary2;
    ary2.assign( ary.begin(), ary.end() );

    sol(ary, 0, n, false);
    sol(ary, 1, n, false);
    
    bool check = true;
    FOR(i, n){
        if(ary[i] != i+1){
            check = false;
            break;
        }
    }
    
    if(!check){
        result[0].first = 0; result[1].first = 0; result[0].second = 0; result[1].second = 0;
        sol(ary2, 0, n, true);
        // FOR(i,n){
        //     cout << ary2[i] << endl;
        // }
        sol(ary2, 1, n, true);
    }
        

    FOR(i, 2){
        cout << result[i].first+1 << " " << result[i].second+1 << endl;
    }


}
