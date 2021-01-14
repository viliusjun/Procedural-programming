// Vilius Junevičius

// Enter a sequence of integers. The end of which is denoted by 0. Output the number of members whose sum of digits is an odd number.

#include <stdio.h> 

int main(){
    int number; 
    int count = 0;
    int sum = 0; 
    int temp;

    printf("Input a sequence of numbers which end with a 0: \n"); 

    // we repeat the cikle at least one time until the entered number is 0
    do {
        scanf("%d", &number);

        temp = number;

        sum = 0;

        while (temp > 0){
            sum = sum + (temp % 10); 
            temp = temp / 10; 
        }

        if (sum % 2 == 1){
            count++;
        }

    }while(number != 0);

    printf("There are %d numbers whose sum of digits is an odd number\n", count); 
    return 0;
}