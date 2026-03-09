#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char phone[20];
} Contact;

int main() {
    int count = 0;
    Contact *list = NULL;
    char *fileName = "contacts.txt";
    char choice;

    // 1. 파일에서 기존 데이터 불러오기
    FILE *fp = fopen(fileName, "r");
    if (fp != NULL) {
        if (fscanf(fp, "%d", &count) != EOF) {
            list = (Contact *)malloc(sizeof(Contact) * count);
            for (int i = 0; i < count; i++) {
                fscanf(fp, "%s %s", list[i].name, list[i].phone);
            }
        }
        fclose(fp);
        printf("=> 기존 데이터를 불러왔습니다. (현재: %d명)\n", count);
    }

    // 2. 추가 입력 여부 묻기
    printf("새로운 연락처를 추가하시겠습니까? (y/n): ");
    scanf(" %c", &choice); // %c 앞의 공백은 버퍼 비우기용입니다.

    if (choice == 'y' || choice == 'Y') {
        count++; // 인원수 증가
        
        // [Ch.16 동적 할당 응용] realloc으로 메모리 크기 확장하기
        list = (Contact *)realloc(list, sizeof(Contact) * count);
        
        if (list == NULL) {
            printf("메모리 할당 실패!\n");
            return 1;
        }

        printf("[%d번째 사람] 이름: ", count);
        scanf("%s", list[count - 1].name);
        printf("[%d번째 사람] 번호: ", count);
        scanf("%s", list[count - 1].phone);
    }

    // 3. 전체 목록 확인
    printf("\n--- 현재 주소록 목록 (총 %d명) ---\n", count);
    for (int i = 0; i < count; i++) {
        printf("성함: %-10s | 연락처: %s\n", list[i].name, list[i].phone);
    }

    // 4. 파일에 다시 저장 (갱신된 인원수와 데이터 기록)
    fp = fopen(fileName, "w");
    if (fp != NULL) {
        fprintf(fp, "%d\n", count);
        for (int i = 0; i < count; i++) {
            fprintf(fp, "%s %s\n", list[i].name, list[i].phone);
        }
        fclose(fp);
        printf("\n=> 데이터가 '%s'에 안전하게 갱신되었습니다.\n", fileName);
    }

    if (list != NULL) free(list);
    return 0;
}