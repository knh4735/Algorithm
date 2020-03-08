// 1991 트리순회 자료구조(트리)
#include <stdio.h>

struct NODE {
	char name;
	NODE *l, *r;
};
NODE node[27];

void preorder(NODE *node){
	printf("%c", node->name);
	if(node->l != NULL) preorder(node->l);
	if(node->r != NULL) preorder(node->r);
}

void inorder(NODE *node){
	if(node->l != NULL) inorder(node->l);
	printf("%c", node->name);
	if(node->r != NULL) inorder(node->r);
}

void postorder(NODE *node){
	if(node->l != NULL) postorder(node->l);
	if(node->r != NULL) postorder(node->r);
	printf("%c", node->name);
}

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		char name, l, r;
		scanf(" %c %c %c", &name, &l, &r);

		int idx = name-'A';
		node[idx].name = name;

		if(l == '.') node[idx].l = NULL;
		else node[idx].l = &node[l-'A'];

		if(r == '.') node[idx].r = NULL;
		else node[idx].r = &node[r-'A'];
	}
	
	preorder(&node[0]);
	printf("\n");
	inorder(&node[0]);
	printf("\n");
	postorder(&node[0]);
	printf("\n");

	return 0;
}
