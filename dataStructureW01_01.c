#include <stdio.h>
#include <stdlib.h>

int size;
int numbers[100];

void print_list()
{
  for (int i = 0; i < size; ++i)
  {
    printf(" %3d", numbers[i]);
    if (i % 8 == 7)
      printf("\n");
  }
}
void input_list()
{
  for (int i = 0; i < size; i++)
  {
    numbers[i] = rand() % 100;
  }
}

void add_list(int val)
{
  printf("값 %d를 리스트 맨 끝에 추가합니다.\n", val);
  numbers[size++] = val;
}

void insert_list(int pos, int val)
{
  printf("값 %d를 %d 번째에 삽입합니다.\n", val, pos + 1);
  for (int k = size - 1; k >= pos; k--)
    numbers[k + 1] = numbers[k];
  numbers[pos] = val;
  size++;
}

int delete_list(int pos)
{
  int result = numbers[pos];
  for (int k = pos; k < size - 1; k++)
    numbers[k] = numbers[k + 1];
  printf("%d 번째 값을 삭제합니다. 값 = %d\n", pos + 1, result);
  size--;
  return result;
}

int update_list(int pos, int val)
{
  int result = numbers[pos];
  numbers[pos] = val;
  printf("%d 번째 값을 %d로 변경합니다. 이전값 = %d\n", pos + 1, val, result);
  return result;
}

void run_menu()
{
  int pos, val;
  int menu;
  while (1)
  {
    printf("\n(1) 끝에 값 추가 \n(2) pos번째에 값 추가\n");
    printf("(3) pos번째 삭제 \n(4) pos번째 값 변경 \n(5) 종료 ");
    printf(" 메뉴선택 => ");
    scanf("%d", &menu);
    if (menu >= 5)
      break;
    switch (menu)
    {
    case 1:
      scanf("%d", &val);
      add_list(val);
      break;
    case 2:
      scanf("%d %d", &pos, &val);
      insert_list(--pos, val);
      break;
    case 3:
      scanf("%d", &pos);
      delete_list(--pos);
      break;
    case 4:
      scanf("%d %d", &pos, &val);
      update_list(--pos, val);
      break;
    default:
      break;
      // printf("다시 입력해주세요.");
    }
    print_list();
  }
  print_list();
}

int main()
{
  printf("숫자의 개수를 입력하세요 : ");
  scanf(" %d", &size);
  input_list();
  print_list();
  run_menu();
}