#include <stdio.h>
#include <string.h>

int myvalue = 47;

int main (int argc, char **argv){
    if (argc <= 1) {
        return -1;
    } 
    if (strcmp(argv[1], "FEEDBEEF") == 0) {
        printf("Correct\n");
        
        } else {
            printf("Incorrect; :( \n"); 
        }
}
