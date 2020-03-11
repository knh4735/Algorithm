// 2252 줄세우기 그래프1(위상정렬)
#include <stdio.h>

struct NODE {
	int num = 0;
	NODE *next = nullptr;
};

struct Q {
	int arr[32001];
	int hd = 0;
	int tl = 0;
	
	void push(int n){
		arr[tl] = n;
		tl++;	
	}

	int pop(){
		int ret = arr[hd];
		hd++;
		return ret;
	}

	int empty(){
		return hd == tl;
	}
};

int main(){
	NODE student[32001];
	NODE node[100001];
	int node_cnt = 0;
	int inbound[32001] = {0, };
	Q q;

	int n, m;
	int s, t;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &s, &t);

		inbound[t]++;
	
		NODE *cur = &student[s];
		while(cur->next != nullptr) cur = cur->next;
		node[node_cnt].num = t;
		cur->next = &node[node_cnt];
		node_cnt++;
	}

	for(int i = 1; i <= n; i++){
		if(inbound[i] == 0) q.push(i);
	}

	// NODE *cur = student[1];
	// printf("%d ", cur->num);
	// while(cur != NULL){
	// 	int outbound = cur->num;
	// 	printf("%d ", outbound);
	// 	cur = cur->next;
	// }
	// 	printf("\n");

	for(int i = 0; i < n; i++){
		int std = q.pop();
		printf("%d ", std);

		NODE *cur = &student[std];
		while(cur->next != nullptr){
			cur = cur->next;
			int outbound = cur->num;
			
			inbound[outbound]--;
			if(inbound[outbound] == 0) q.push(outbound);
		}
	}

	return 0;
}
