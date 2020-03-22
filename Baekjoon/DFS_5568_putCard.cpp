// 5568 카드놓기 조합론(DFS)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, k;
string a[11];
set<string> combi;
vector<int> card;

void make_num(vector<int> card){
	string s = "";
	for(auto idx: card){
		s += a[idx];
	}

	combi.insert(s);
}

void select_card(int v[], int cur){
	if(card.size() == k){
		make_num(card);
		return;
	}

	for(int i = 0; i < n; i++){
		if(v[i] == 1) continue; 

		card.push_back(i);
		v[i] = 1;
		select_card(v, i);
		v[i] = 0;
		card.pop_back();
	}
}

int main(){
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int v[4] = {0,};
	for(int i = 0; i < n; i++){
		card.push_back(i);
		v[i] = 1;
		select_card(v, i);
		v[i] = 0;
		card.pop_back();
	}

	printf("%d\n", combi.size());
	// for(auto num: combi) cout << num << " ";

	return 0;
}
