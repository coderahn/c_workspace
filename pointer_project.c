#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int level;
int arrayFish[6];
int *cursor;

void initData();
void printfFishes();
void decreaseWater(long elpasedTime);
int checkFishArrive();

//물고기가 6마리가 있습니다.
//이들은 어항에 살고 있는데 사막이라 너무 더워서 물이 계속 증발합니다.
//물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요.
//물고기는 시간이 지날수록 점점 커져서 나중에는 냠냠..
int main_pointer_project(void) {
    long startTime = 0; //게임 시작시간
    long totalElapsedTime = 0; //게임 경과시간
    long prevElapsedTime = 0; //직전 경과시간(최근에 물을 준 시간 간격)

    int num; //몇번어항에 물을 줄 것인지
    initData();

    cursor = arrayFish; //cursor[0], cursor[1]..같이 사용 가능

    startTime = clock(); //현재 시간을 밀리세컨드 단위로 반환(1000분의 1초)
    while(1) {
        printfFishes();
        printf("몇 번 어항에 물을 주시겠어요?\n");
        scanf("%d", &num);

        if (num < 1 || num > 6) {
            printf("입력 값이 잘못 되었습니다.\n");
            continue;
        }

        //총 경과 시간
        printf("clock():%ld\n", clock());
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; //밀리초를 초로 변환
        printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

        //직전 물 준 시간으로부터 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

        //어항의 물을 감소(증발)
        decreaseWater(prevElapsedTime);

        //사용자가 입력한 어항에 물을 준다.
        //1. 어항의 물이 0이면? 물을 주지 않는다. 이미 꼬기.
        if (cursor[num - 1] <= 0) {
            printf("%d번 물고기가 이미 죽었습니다. 물을 주지 않습니다.\n", num);
        }

        //2. 어항의 물이 0이 아닌경우, 물을 준다. (100을 안 넘는지 체크)
        else if(cursor[num - 1] + 1 <= 100) {
            //물을 준다.
            printf("%d번 어항에 물을 줍니다\n", num);
            cursor[num - 1] += 1;
        }

        //레벨업 할 것인지 확인(20초마다 수행)
        if (totalElapsedTime / 20 > level - 1) {
            level++;
            printf("***축 레벨 업! 기존 레벨 %d에서 레벨 %d로 업그레이드\n", level-1, level);

            if (level == 5) {
                printf("축하합니다 만렙!n");
                exit(0);
            }
        }

        //모든 물고기가 죽었는지 확인
        if (checkFishArrive() == 0) {
            //물고기 모두 죽음
            printf("모든 물고기가 ...\n");
            exit(0);
        } else {
            printf("물고기가 살아 있어요\n");
        }
        prevElapsedTime = totalElapsedTime;
    }

    return 0;
}

void initData() {
    level = 1; //게임레벨 1~5
    for (int i=0; i<6; i++) {
        arrayFish[i] = 100; //어항의 물 높이(100) 
    }
}

void printfFishes() {
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
    for (int i=0; i<6; i++) {
        printf(" %4d ", arrayFish[i]);
    }

    printf("\n\n");
}

void decreaseWater(long elpasedTime) {
    for (int i=0; i<6; i++) {
        arrayFish[i] -= (level * 3 * (int)elpasedTime); //3은 난이도 조절을 위한 값
        if (arrayFish[i] < 0) {
            arrayFish[i] = 0;
        }
    }
}

int checkFishArrive() {
    for (int i=0; i < 6; i++) {
        if (arrayFish[i] > 0) {
            return 1; //참 true
        }
    }
    return 0;
}