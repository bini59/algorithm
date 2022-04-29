//쓸거같은 STL 목록
#include <iostream>
#include <vector>
#include <cstdlib>
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

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}node;


void tree_postorder(node* root){
    if(root == NULL) return;
    tree_postorder(root->left);
    tree_postorder(root->right);
    printf("%d\n", root->data);
}


node* create_tree(node *temp, int item){
    if(temp == NULL){
        temp = (node*)malloc(sizeof(node));
        temp->data = item;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(item < temp->data){
        temp->left = create_tree(temp->left, item);
    }
    else{
        temp->right = create_tree(temp->right, item);
    }

    return temp;
}

int main(){
	// 혹시나 cin, cout을 쓰게 딘다면...
	//cin.tie(NULL); 
	//ios::sync_with_stdio(false);
    int cur = 0;
    int preorder[10001];
    while(scanf("%d", &preorder[cur++]) != EOF){
    }

    node* root = nullptr;
    for(int i = 0; i < cur-1; i++){
        root = create_tree(root, preorder[i]);
    }
    tree_postorder(root);

	int result = 0;
	
}