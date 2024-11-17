#include <stdio.h>

struct GameInfo {
    char *name;
    int year;
    int price;
    char *company;
};

int main(void) {
    //게임출시1
    //이름zz
    //제작년도
    //가격
    //제작사

    char *name = "얍얍";
    int year = 2024;
    int price = 43000;
    char *company = "스퀘어에닉스";

    //게임출시2
    //이름
    //제작년도
    //가격
    //제작사

    char *name2 = "얍얍2";
    int year2 = 2024;
    int price2 = 62000;
    char *company2 = "닌텐도";

    //위와 같이 비슷한 값들 관리를 해줄 수 있는 구조체 선언(여러 타입 관리 가능) 
    
    //구조체 사용
    struct GameInfo gameInfo1;

    gameInfo1.name = "구조체게임명";
    gameInfo1.year = 2024;
    gameInfo1.price = 55000;
    gameInfo1.company = "EA Sports";

    //구조체 출력
    printf("===게임출시정보1===\n");
    printf(" 게임명: %s\n", gameInfo1.name);
    printf(" 출시년도: %d\n", gameInfo1.year);
    printf(" 가격: %d\n", gameInfo1.price);
    printf(" 회사: %s\n\n", gameInfo1.company);
    
    //구조체를 배열처럼 초기화
    struct GameInfo gameInfo2 = {"배열처럼초기화111", 2024, 33000, "스퀘어"};
    
    //구조체(배열초기화) 출력
    printf("===게임출시정보2===\n");
    printf(" 게임명: %s\n", gameInfo2.name);
    printf(" 출시년도: %d\n", gameInfo2.year);
    printf(" 가격: %d\n", gameInfo2.price);
    printf(" 회사: %s\n\n", gameInfo2.company);

    //구조체 배열
    struct GameInfo gameInfoArr[] = {
        gameInfo1, gameInfo2
    };

    printf("gameInfoArr[0].name:%s\n", gameInfoArr[0].name);
    printf("gameInfoArr[1].name:%s\n\n", gameInfoArr[1].name);
    
    //구조체 포인터 사용법1
    struct GameInfo *gameInfoPointer = &gameInfo1;
    printf("===게임출시정보1(포인터 방식 출력1)===\n");
    printf(" 게임명: %s\n", (*gameInfoPointer).name);
    printf(" 출시년도: %d\n", (*gameInfoPointer).year);
    printf(" 가격: %d\n", (*gameInfoPointer).price);
    printf(" 회사: %s\n\n", (*gameInfoPointer).company);

    //구조체 포인터 사용법2
    printf("===게임출시정보1(포인터 방식 출력2)===\n");
    printf(" 게임명: %s\n", gameInfoPointer->name);
    printf(" 출시년도: %d\n", gameInfoPointer->year);
    printf(" 가격: %d\n", gameInfoPointer->price);
    printf(" 회사: %s\n\n", gameInfoPointer->company);

    return 0;
}