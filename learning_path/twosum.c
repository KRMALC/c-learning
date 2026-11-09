#include <stdio.h>

int main (void){
    int numbers[] = {2, 7, 11, 15, 3};
    int number_size = 5;
    int target = 9;

    for (int i = 0; i < number_size; i ++){
        for (int j = i + 1; j < number_size; j++){
            if (numbers[i] + numbers[j]==target){
                printf("[%d,%d]",i,j);
                return 0;
            }
        }
    }
}