// 5639 이진검색트리 자료구조(이진탐색트리)
#include <iostream>
using namespace std;

struct NODE {
	NODE(): key(-1), l(NULL), r(NULL) {}
	int key;
	NODE *l;
	NODE *r;
};

int node_cnt = 1;	// 0은 루트노드

void insert(NODE tree[], int k, NODE *node){
	if(node->key == -1){
		node->key = k;
		return;
	}

	if(k < node->key){
		if(node->l == NULL) node->l = &tree[node_cnt++];
		insert(tree, k, node->l);
	}
	else if(k > node->key){
		if(node->r == NULL) node->r = &tree[node_cnt++];
		insert(tree, k, node->r);
	}
}

void postorder(NODE *node){
	if(node->l != NULL) postorder(node->l);
	if(node->r != NULL) postorder(node->r);

	cout << node->key << endl;
}

int main(){
	NODE tree[10001];

	int tmp;
	while(cin >> tmp){
		insert(tree, tmp, &tree[0]);
	}

	postorder(&tree[0]);
	
	return 0;
}
