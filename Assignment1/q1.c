#include <stdio.h>

void adder(int num1[], int num2[], int len, int resultArr[]) {
    int carryOver = 0;
    
    for (int i = len; i >= 0; i--) {
        int added = num1[i] + num2[i] + carryOver;

        if (added >= 10) {
            resultArr[i] = added - 10;
            carryOver = 1;
        } else {
            resultArr[i] = added;
            carryOver = 0;
        }
    }
}

void main() {

    int len;
    printf("Enter length of numbers: ");
    scanf("%d", &len);

    int num1[len+1];
    int num2[len+1];
    num1[0] = 0;
    num2[0] = 0;

    printf("NUMBER 1\n");
    for (int i = 1; i < len+1; i++) {
        printf("Enter digit %d: ", i);

        int digit;
        scanf("%d", &digit);

        if (digit < 10) {
            num1[i] = digit;
        } else {
            printf("Please enter a single digit. Exiting program...");
            return;
        }
    }

    printf("NUMBER 2\n");
    for (int i = 1; i < len+1; i++) {
        printf("Enter digit %d: ", i);

        int digit;
        scanf("%d", &digit);

        if (digit < 10) {
            num2[i] = digit;
        } else {
            printf("Please enter a single digit at a time. Exiting program...");
            return;
        }
    }

    int sum[len+1];
    adder(num1, num2, len, sum);

    printf("SUM: ");
    if (sum[0] != 0) printf("%d", sum[0]);
    for (int i = 1; i < len+1; i++) {
        printf("%d", sum[i]);    
    }

    int diff[len+1];
    int borrowed = 0;

    for (int i = len; i >= 0; i--) {
        int subtracted = num1[i] - num2[i] - borrowed;

        if (subtracted >= 0) {
            diff[i] = subtracted;
            borrowed = 0;
        } else {
            borrowed = 1;
            diff[i] = subtracted + 10;
        }
        
    }

    printf("\nDIFFERENCE: ");
    if (diff[0] != 0) printf("%d", diff[0]);
    for (int i = 1; i < len+1; i++) {
        printf("%d", diff[i]);
    }

    int product[len*2];
    int carried = 1;

    for (int i = len; i >= 0; i--) {
        
    }

}
