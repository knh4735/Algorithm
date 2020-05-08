// 5052 전화번호목록 문자열(TRIE)
#include <stdio.h>
#include <string.h>

struct TRIE_NODE {
  TRIE_NODE *next[10] = {nullptr, };  // 0~9
  int end = 0;
  int has_child = 0;
};

TRIE_NODE trie_node[100001];
int trie_cnt = 0;

int check(TRIE_NODE *root, char *str){
  TRIE_NODE *trie = root;
  while(*str != '\0'){
    if(trie->end == 1) return 1;
    if(trie->next[*str - '0'] == nullptr) return 0;

    trie = trie->next[*str - '0'];
    str++;
  }

  if(trie->has_child == 1) return 1;

  return 0;
}

void insert(TRIE_NODE *root, char *str){
  TRIE_NODE *trie = root;
  while(*str != '\0'){
    if(trie->next[*str - '0'] == nullptr){
      for(int i = 0; i < 10; i++) trie_node[trie_cnt].next[i] = nullptr;
      trie_node[trie_cnt].has_child = 0;
      trie_node[trie_cnt].end = 0;

      trie->next[*str - '0'] = &trie_node[trie_cnt];
      trie->has_child = 1;
      trie_cnt++;
    }

    trie = trie->next[*str - '0'];
    str++;
  }

  trie->end = 1;
}

int main(){
  int tc;
  scanf("%d", &tc);

  for(int T = 0; T < tc; T++){
    TRIE_NODE root;
    trie_cnt = 0;

    int n, flag = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
      char s[11];
      scanf("%s", s);
      if(flag == 1) continue;

      int has_prefix = check(&root, s);
      // printf("CHECK %d\n", has_prefix);
      if(has_prefix == 1){
        flag = 1;
      }

      insert(&root, s);
    }

    if(flag == 1) printf("NO\n");
    else printf("YES\n");
  }


  return 0;
}
