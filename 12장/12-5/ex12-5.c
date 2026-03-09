#include <stdio.h>
// 나중에 입력할 공간입니다.
// #include <string.h>

int main(void) {
  char str[80];

  printf("공백이 포함된 문자열 입력 : ");
  fgets(str, sizeof(str), stdin);       // 문자열 입력
  // 나중에 입력할 공간입니다.
  // str[strlen(str) - 1] = '\0';
  printf("입력된 문자열은 %s입니다\n", str);  // 문자열 출력

  return 0;
}