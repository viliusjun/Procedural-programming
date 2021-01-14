// Vilius Junevičius

// Enter an integer N. Enter N integers a1, a2, ... aN. If all numbers between them are even or all odd - output a message.
// Otherwise, calculate the expression: Sum = x1 * y1 + x2 * y2 + ... + xp * yp,
//  where xi are even consecutive members of the sequence, yi are odd consecutive members of the sequence, 
//  p = min(n, t), where n is the number of even sequence members and t is the number of odd sequence members.

#include <stdio.h>

int calculations(int N, int a[], int *Sum);

int main() {
    int N, Sum = 0;

    printf("Input a number N:\n");
    scanf("%d", &N);


    int a[N];

    printf("Input %d numbers:\n", N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", a+i);
    }


    int S = calculations(N, a, &Sum);

    if (S == -1){
        printf("All of the numbers are odd.\n");
    }
    else if (S == -2){
        printf("All of the numbers are even.\n");
    }
    else {
        printf("Sum = %d\n", Sum);
    }

    return 0;
}

int calculations(int N, int a[], int *Sum) {
    int number_of_even_numbers = 0, number_of_odd_numbers = 0;

    for (int i = 0; i < N; ++i){
        if (a[i] % 2 == 0) {
            number_of_even_numbers++;
        }
        if (a[i] % 2 == 1) {
            number_of_odd_numbers++;
        }
    }
    
    if (N == number_of_odd_numbers) {
        return -1;
    }
    else if (N == number_of_even_numbers) {
        return -2;
    }
    else{
        int temp; 

        // We sort all the numbers using the Bubble sort algorithm
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }


        int even[number_of_even_numbers], odd[number_of_odd_numbers];
        int count1 = 0, count2 = 0; 

        // we seperate the even and odd numbers to two seperate arrays
        for (int i = 0; i < N; i++) {
            if (a[i] % 2 == 0) {
                // even[count1] = a[i]; 
                *(even + count1) = *(a + i);
                count1++;
            }
            if (a[i] % 2 == 1) {
                odd[count2] = a[i];
                count2++;
            }
        }

        // p = min(the number of even numbers, the number of odd numbers)
        int p;
        if (number_of_odd_numbers > number_of_even_numbers) {
            p = number_of_even_numbers;
        }
        else {
            p = number_of_odd_numbers;
        }
        
        // expression Sum = x1*y1 + x2*y2 + ... + xp*yp
        for (int i = 0; i < p; i++) {
            *Sum += (even[i] * odd[i]);
        }

        return 0;
    }
}