//컨트롤+옵션+n
#include <stdio.h>
void changeArray();

int main_pointer(void) {
    //배열일 때 arr주소
    int arr[3] = { 10,20,30};
    // changeArray(arr); 
    changeArray(&arr[0]); 
    for (int i=0; i<3; i++) {
        printf("%d번째 배열값: %d\n", i, arr[i]);
        
    }
}

void changeArray(int *arr) {
    arr[2] = 50;
}