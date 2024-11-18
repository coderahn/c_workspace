#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//상수
#define MAX 10000

int main(void) {
    //파일 입출력
    //파일에 어떤 데이터를 저장.
    //파일에 저장된 데이터를 불러오기.

    //[fputs, fgets 쌍]
    char line[MAX]; //char line[10000]

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
    FILE *file = fopen("/Users/ash/Desktop/text.txt", "rb");
    if (file == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    while(fgets(line, MAX, file) != NULL) {
        printf("%s", line);
    }

    //파일 닫기
    fclose(file);

    //fprintf, fscanf 쌍


    
    return 0;
}