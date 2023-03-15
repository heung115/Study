#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* elem_t;
int size;
elem_t numbers[100];

elem_t get_next() {
  char buf[20]; // temp buffer for malloc
  scanf("%s",buf);
  char* chptr = (char*)malloc((strlen(buf) + 1) * sizeof(char));
  //strcpy_s(chptr, (strlen(buf) + 1), buf);
  strncpy(chptr,buf,(strlen(buf) + 1));
  return chptr;
}

void print_list() {
  for(int i =0 ; i< size ;++i){
    printf(" %s",numbers[i]);
    if(i%8==7 )  printf("\n");
  }
}

void input_list(int size){
  printf("%d개의 문자열을 입력하시오 : ",size);
  for (int i = 0; i < size; i++){
    numbers[i] = get_next();
  }
}

void add_list(elem_t val) {
  printf("값 %s를 리스트 맨 끝에 추가합니다.\n", val);
  numbers[size++] = val;
}

void insert_list(int pos, elem_t val) {
  printf("값 %s를 %d 번째에 삽입합니다.\n", val, pos+1);
  for (int k = size - 1; k >= pos; k--)
    numbers[k + 1] = numbers[k];
  numbers[pos] = val;
  size++;
}

elem_t delete_list(int pos) {
  elem_t result = numbers[pos];
  for (int k = pos; k < size - 1; k++)
    numbers[k] = numbers[k + 1];
  printf("%d 번째 값을 삭제합니다. 값 = %s\n", pos+1, result);
  size--;
  return result;
}

elem_t update_list(int pos, char* val) {
  elem_t result = numbers[pos];
  numbers[pos] = val;
  printf("%d 번째 값을 %s로 변경합니다. 이전값 = %s\n", pos+1, val, result);
  return result;
}

void clear() {
  for (int i = 0; i < size; i++) {
    free(numbers[i]);
  }
  size = 0;
}
void free_list(){
  /*
  for ( int i =0; i<size ; i++){
    free(numbers[i]);
    numbers[i] = NULL;
  }*/
  clear();
}
//===================w02======================

void init_list(){
  size = 0;
}

int len() {
  return size;
}

elem_t get(int index) {
  return numbers[index];
}

int find(elem_t val) {
  for (int i = 0; i < size; i++) {
    if (strcmp(numbers[i], val) == 0)
      return i; // 찾으면 인덱스 반환 
    }
  return -1; // 못찾으면 -1
}


void run_menu() {
  int pos;
  elem_t val;
  int menu;
  while (1) {
    printf("\n(1) 끝에 값 추가 \n(2) pos번째에 값 추가\n");
    printf("(3) pos번째 삭제 \n(4) pos번째 값 변경 \n(5) 검색 \n(6) 종료 ");
    printf(" 메뉴선택 => ");
    scanf("%d", &menu);
    if (menu >= 6) break;
      switch (menu) {
      case 1:
        printf("끝에 추가 할 값 : ");
        add_list(get_next());
        break;
      case 2:
        printf("추가할 위치와 값 : ");
        scanf("%d",&pos);
        insert_list(--pos,get_next());
        break;
      case 3:
        printf("삭제할 위치");
        scanf("%d",&pos);
        free(delete_list(--pos));    //delete_list -> free return chrptr
        break;
      case 4:
        printf("변경할 위차와 값");
        scanf("%d",&pos);
        free(update_list(--pos,get_next()));     //update_list -> free return chrptr
        break;
      case 5:
        printf("찾으려는 값: ");
        val = get_next(); 
        pos = find(val);
        if (pos == -1)
          printf("%s는 없는 값입니다\n", val);
        else
          printf("%s는 %d번째인, [%d]에 있습니다\n", val, pos+1, pos);
        break;
      default:
        break; 
        //printf("다시 입력해주세요.");
      }
  print_list();
  }
  print_list();
  free_list();
  print_list();     //free check
}

int main(){
  printf("문자열의 개수를 입력하세요 : ");
  scanf(" %d", &size);
  input_list(size);
  print_list();
  run_menu();
}