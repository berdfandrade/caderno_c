#include <stdio.h>
#include <string.h>


/* int main() {
    int nums[3];
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
 
    int soma(char nums[3]){
    for(int i = 0; i < strlen(char nums[3]); i++){
        int soma_chars = (nums[i] + nums[i]);
    }

} 

}
*/

int soma(int* nums, int tam) {
    int total = 0;

    for(int i = 0; i < tam; i++) {
        total += nums[i];
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

