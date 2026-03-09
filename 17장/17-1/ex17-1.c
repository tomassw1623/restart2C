#include <stdio.h>

struct student        // 구조체 선언
{
  int num;            // int 형 맴버
  double grade;       // double형 맴버
};

int main(void) {
  struct student s1;  // struct student형의 변수 선언

  s1.num = 2;         // s1의 num 맴버에 2 저장
  s1.grade = 2.7;     // s1의 grade 맴버에 2.7 저장
  printf("학번 : %d\n", s1.num);      // num 맴버 출력
  printf("학점: %.1lf\n", s1.grade);  // grade 맴버 출력

  return 0;  
}