#include <stdio.h>
#include <time.h>

//10������ ���� �ٸ� ����(�� ī�� 2�徿)
//����ڷκ��� 2���� �Է°��� �޾Ƽ� -> ���� ���� ã���� ī�� ������
//��� ���� ���� ã���� ���� ����
//�� ���� Ƚ�� �˷��ֱ�

//2���� �迭�� ����
//({0,0}{0,1}{0,2}{0,3}
//({1,0}{1,1}{1,2}{1,3}
//({2,0}{2,1}{2,2}{2,3}
//({3,0}{3,1}{3,2}{3,3}

//���迭 �������� ���� ���� ����. ���� �迭 ����
//animal[i][j] = 
//{�䳢,��...}
//animal�� ���� ������ �����Լ� ���ؼ� �ֱ�.

//2���� �迭 �����Ѱ� scanf_s�� ������ ��.
//������ ������ i,j�� ���� animal���� ã��.
//�ٽ� ����. �� i,j�� animal���� ã��.
//������ 2���� ==�񱳷� Ƚ�� üũ

int arrayAnimal[4][5]; //ī�� ����(20��))
int checkAnimal[4][5]; //���������� ���� Ȯ�� 
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

    int failCount = 0; //���� Ƚ��

    while(1) {
        int select1 = 0; //����ڰ� ������ ó�� ��
        int select2 = 0; //����ڰ� ������ �ι�° ��

        printAnimals(); //���� ��ġ ���
        printQuestion(); //���� ��� (ī�� ����)
        printf("������ ī�带 2�� ������ : ");
        scanf_s("%d %d", &select1, &select2);

        if (select1 == select2) { //���� ī�� ���ý� ��ȿ
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
    strAnimal[0] = "������";
    strAnimal[1] = "�ϸ�";
    strAnimal[2] = "������";
    strAnimal[3] = "�����";
    strAnimal[4] = "����";
    
    strAnimal[5] = "�ڳ���";
    strAnimal[6] = "�⸰";
    strAnimal[7] = "��Ÿ";
    strAnimal[8] = "Ÿ��";
    strAnimal[9] = "ȣ����"; 
    
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

//��ǥ���� �� ���� ã��
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
    printf("\n================���������ݴϴٿ�==============\n\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n\n");

}

void printQuestion() {
    printf("\n\n(����\n)");
    int seq = 0;

    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            //ī�带 ����� ������ �������� '���� �̸�'
            if(checkAnimal[i][j] != 0) {
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            }
            //���� ������ �������� (������ ����������) �޸� -> ��ġ�� ��Ÿ���� ����
            else {
                printf("%8d", seq);
            }
        }
    }

}