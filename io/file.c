#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//상수
#define MAX 10000

int main_file(void) {
    //파일 입출력
    //파일에 어떤 데이터를 저장.
    //파일에 저장된 데이터를 불러오기.

    //[fputs, fgets 쌍] => 문자열 저장
    //char line[MAX]; //char line[10000]

    //1.파일쓰기
    // //읽어오기
    // //r:읽기전용 w:쓰기전용 a:이어쓰기 / t:텍스트, b:바이너리데이터
    // FILE *file = fopen("/Users/ash/Desktop/text.txt", "wb"); 

    // if (file == NULL) {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }

    // //파일에 쓰기
    // fputs("fputs를 이용해서 글을 적어볼게요\n", file);
    // fputs("잘 적히는지 확인해주세요\n", file);



    //2.파일읽기
    // FILE *file = fopen("/Users/ash/Desktop/text.txt", "rb");
    // if (file == NULL) {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }

    // while(fgets(line, MAX, file) != NULL) {
    //     printf("%s", line);
    // }

    // //파일 닫기
    // fclose(file);

    //[fprintf, fscanf 쌍]
    //fprintf => 정형화된(%d..) 방식으로 쓸 때
    //fscanf => 유사..

    int num[6] = {0,0,0,0,0,0}; //추첨번호

    int bonus = 0; //보너스번호
    char str1[MAX];
    char str2[MAX];

    //파일 쓰기
    // FILE *file = fopen("/Users/ash/Desktop/text2.txt", "wb");

    // if (file == NULL) {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }

    // //로또 추첨 번호 저장
    // fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호 ", 1,2,3,4,5,6);
    // fprintf(file, "%s %d\n", "보너스번호 ", 7);

    //파일 읽기

    FILE *file = fopen("/Users/ash/Desktop/text2.txt", "rb");

    if (file == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    //첫번째 줄(추첨번호) 읽어오기
    //읽어온 값을 num배열에 넣는다.
    fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0],  &num[1],  &num[2],  &num[3],  &num[4],  &num[5]);
    printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

    //두번째 줄(보너스) 읽어오기
    fscanf(file, "%s %d", str2, &bonus);
    printf("%s %d\n", str2, bonus);

    fclose(file);

    return 0;
}