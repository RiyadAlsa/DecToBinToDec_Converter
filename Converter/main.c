#include <stdio.h>
#include <math.h>
#include "method.h"

int main() {

    int choice = 0;
    while (choice == 0) {
        printf("Enter 1 for decimal to binary\n");
        printf("Enter 2 for binary to decimal\n");
        printf("Enter 3 to exit the program\n");
        scanf("%d", &choice);

        if (choice == 1) {

            int decNum;
            printf("Enter a decimal number to convert to binary\n");
            scanf("%d", &decNum);

            decToBin(decNum);
            choice = 0;

        } else if (choice == 2) {

            int biNum;
            printf("Enter a binary number to convert to decimal\n");
            scanf("%d", &biNum);

            int decNum = binToDec(biNum);

            printf("Binary equivalent of %d is : %d\n", biNum, decNum);
            choice = 0;

        } else if (choice == 3) {

            return 0;

        } else {
            printf("The only valid numeral values are '1' or '2'\n");
            choice = 0;
        }
    }

return 0;
}

/**
 * This method is meant to convert a decimal value to binary
 * @return
 */
int decToBin(int decNum){

    //BEGINNING OF DECIMAL TO BINARY
    int biNum[10];
    int counter = 0;
    int remainder = 0;

    printf("Binary equivalent of %d is : ", decNum);
    while(decNum > 0)
    {
        remainder = decNum % 2;
        biNum[counter] = remainder;
        decNum /= 2;
        counter++;
    }

    for(int j = counter - 1; j >= 0; j--){
        printf("%d", biNum[j]);
    }
    //END
}

/**
 * This method is meant to convert a binary value to decimal
 * @return
 */
int binToDec(int biNum){

    //BEGINNING OF BINARY TO DECIMAL
    int decNum = 0;
    int base = 1;
    int rem = 1;

    int num = biNum;

    while(biNum != 0){
        rem = biNum % 10;
        decNum = decNum + rem * base;
        biNum /= 10;
        base *= 2;
    }

    return decNum;
}
