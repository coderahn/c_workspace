#include <stdio.h>

//선언
void p(int num);
int function_with_return();

//계산기 함수 선언
int add(int num1, int num2);
int min(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);


int main(void) {
    printf("---------------------\n");
    // int num = 2;
    // p(num);

    // num += 2;
    // p(num);

    // int ret = function_with_return();
    // p(ret);

    //계산기
    int num = 2;
    num = add(num, 2);
    p(num);

    num = min(num, 3);
    p(num);
    
    num = mul(num, 7);
    p(num);
    
    num = div(num, 2);
    p(num);
}

//정의
void p(int num) {
    printf("num은 %d입니다.\n", num);
}

int function_with_return() {
    printf("반환값 존재하는 함수입니다.\n");
    return 10;
}

//계산기 함수 정의
int add(int num1, int num2) {
    return num1 + num2;
}
int min(int num1, int num2) {
    return num1 - num2;
}
int mul(int num1, int num2) {
    return num1 * num2;
}
int div(int num1, int num2) {
    return num1 / num2;
}