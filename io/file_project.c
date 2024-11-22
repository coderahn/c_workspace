#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 10000

//비밀번호 입력받기
//이후 비밀일기를 읽어와서 보여주고 작성하도록 합니다.
//틀린경우 경고메시지 표시 후 종료
int main(void) {

    //제일 처음 파일 존재 확인
    //파일이 없으면? 새로 비밀번호 설정(pass값 fput)
        //이후 새 파일 설정
        //입력값으로 저장
    //파일이 있으면?
        //패스워드 입력은 fscanf로 pass값 입력.
        //입력 후 pass값 if문처리
            //맞으면 fscanf로 파일 읽기
            //틀리면 경고문
    
    //fget, fput 활용
    char line[MAX]; //파일 불러와서 읽은 걸 담을 라인 변수
    char contents[MAX]; //입력할 일기 내용
    char password[20];
    char c; //비밀번호 입력시 키값확인용(마스킹)
    
    printf("비밀일기에 오신 것을 환영합니다\n");
    printf("비밀번호를 입력하세요\n");

    //getchar(), getch() 차이?
    //getchar():엔터를 입력받아야 동작을 합니다.
    //getch():키 입력시 바로바로 동작을 합니다.
    
    int i=0;
    while(1) {
        c = getch();
        if (c == 13){ //Enter -> 비밀번호 입력 종료
            password[i] = '\0';
            break;
        } else {
            printf("*");
            password[i] = c;
        }
        i++;
    }

    printf("\n\n====비밀번호 확인 중\n\n");
    
    //비밀번호: 1234
    if (strcmp(password, "1234") == 0) { //비밀번호 일치
        printf(" === 비밀번호 확인 완료 === \n\n");

        char *fileName = "/Users/ash/Desktop/secret_diary.txt";
        FILE *file = fopen(fileName, "a+b"); //a+b파일이 없으면 생성, 있으면 append를 한다. (뒤에서부터 내용을 추가한다)

        if (file == NULL) {
             printf("파일 열기 실패\n");
             return 1;
        }

        //file내용을 line에 입력
        while(fgets(line, MAX, file) != NULL) {
            printf("%s", line);
        }

        printf("\n\n 내용을 계속 작성하세요. 종료하시려면 exit를 입력하세요. \n\n");

        while(1) {
            scanf("%[^\n]", contents); //줄바꿈 나오기 전까지 읽어들이기
            getchar(); //ENTER입력(flush처리)

            if (strcmp(contents, "EXIT") == 0 ) {
                printf("비밀일기 입력을 종료합니다.");
                break;
            }
            //contents내용을 file에 쓰다.
            fputs(contents, file);
            fputs("\n", file); //getchar로 인해 enter가 씹혔으니 넣어줌
        }

        fclose(file);
    } else {
        printf("비밀번호 틀림 누구니");
        return 1;
    }

    return 0;
}
