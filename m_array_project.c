#include <stdio.h>
#include <time.h>

//10마리의 서로 다른 동물(각 카드 2장씩)
//사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
//모든 동물 쌍을 찾으면 게임 종료
//총 실패 횟수 알려주기

//2차원 배열로 선언
//({0,0}{0,1}{0,2}{0,3}
//({1,0}{1,1}{1,2}{1,3}
//({2,0}{2,1}{2,2}{2,3}
//({3,0}{3,1}{3,2}{3,3}

//각배열 마지막에 동물 값을 넣음. 동물 배열 선언
//animal[i][j] = 
//{토끼,닭...}
//animal에 들어가는 동물은 랜덤함수 통해서 넣기.

//2차원 배열 선언한거 scanf_s로 선택을 함.
//선택한 아이의 i,j를 갖고 animal에서 찾음.
//다시 누름. 그 i,j로 animal에서 찾음.
//열린게 2개면 ==비교로 횟수 체크

int arrayAnimal[4][5]; //카드 지도(20장))
int checkAnimal[4][5]; //뒤집혔는지 여부 확인 
char *strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();

int main(void) {
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal();

    int failCount = 0; //실패 횟수

    while(1) {
        int select1 = 0; //사용자가 선택한 처음 수
        int select2 = 0; //사용자가 선택한 두번째 수

        printAnimals(); //동물 위치 출력
        printQuestion(); //문제 출력 (카드 지도)
        printf("뒤집을 카드를 2개 고르세요 : ");
        scanf_s("%d %d", &select1, &select2);

        if (select1 == select2) { //같은 카드 선택시 무효
            continue;
        }
    }

    return 0;
}

void initAnimalArray() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            arrayAnimal[i][j] = -1;
        }
    }

}

void initAnimalName() {
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";
    
    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이"; 
    
}

void shuffleAnimal() {
    for (int i=0; i < 10; i++) {
        for (int j=0; j<2; j++) {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

//좌표에서 빈 공간 찾기
int getEmptyPosition() {
    while(1) {
        int randPos = rand() % 20; //0~19
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if (arrayAnimal[x][y] == -1) {
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x) {
    //19 -> (3,4)
    return x / 5;
}

int conv_pos_y(int y) {
    //19 -> (3,4)
    return y % 5;
}

void printAnimals() {
    printf("\n================몰래보여줍니다요==============\n\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n\n");

}

void printQuestion() {
    printf("\n\n(문제\n)");
    int seq = 0;

    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            //카드를 뒤집어서 정답을 맞혔으면 '동물 이름'
            if(checkAnimal[i][j] != 0) {
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            }
            //아직 뒤집지 못했으면 (정답을 못맞췄으면) 뒷면 -> 위치를 나타내는 숫자
            else {
                printf("%8d", seq);
            }
        }
    }

}