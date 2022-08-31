#include <stdio.h>
#include <string.h>


int soma(int* nums, int tam) {
    int total = 0;
    for(int i = 0; i < tam; i++) {
        total = total + nums[i];
    }

    return total;
}


int main(void){
    int nums[3];
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;

    int total = soma(nums, 3);
    printf("total é %d\n", total);


}

