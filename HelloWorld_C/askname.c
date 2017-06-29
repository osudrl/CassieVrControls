#include <stdio.h>

int main() {
    char name[50];
    printf("Your name: ");
    scanf("%s", name);
    printf("Welcome, %s \n \n", name);

    int bottles =7;
    printf("How many bottles of beer? ");
    scanf("%d", &bottles);

    for (int i= 0; i < bottles; i++)
    {
        printf("%d bottles of beer on the wall. \n",(bottles-i));
    }

}


