#include <stdio.h>
#include <stdlib.h>

//The addition function takes two numbers as parameters that we will add between them and the result will be returned in a local variable
float addition(float elt1,float elt2){
    float total;
    total=elt1+elt2;
    return total;
}

//The subtraction function takes two numbers as parameters that we will subtract between them and the result will be returned in a local variable
float subtraction(float elt1, float elt2){
    float total;
    total=elt1-elt2;
    return total;
}

//The multiplication function takes two numbers as parameters that we will multiply between them and the result will be returned in a local variable
float multiplication(float elt1, float elt2){
    float total;
    total=elt1*elt2;
    return total;
}

//The division function takes two numbers as parameters which we will divide between them and the result will be returned in a local variable
float division(float elt1,float elt2){
    float total;
    total=elt1/elt2;
    return total;
}

//The power function takes two numbers as parameters where we calculate the first number to the power of the second number and the result will be returned in a local variable
float power(float elt1,float elt2){
    float total;
    int i;
    total=1;
    if (elt2<0){
        elt2=elt2*(-1);
        for (i=0;i<elt2;i++){
            total*=elt1;
        }
        total=1/total;
    }
    else{
        for (i=0;i<elt2;i++){
            total*=elt1;
        }
    }
    return total;
}

int main(void){
    // Program allowing the user to carry out operations with the 4 basic operators and to use power numbers

    // Variables
    float data1;       // First operand
    float data2;       // Second operand
    float result;      // Result of the operation
    char operator;     // Operator entered by the user
    int S;             // Flag to control the loop (1 = exit)

    // Beginning
    S = 0; // Initialize the loop control variable

    do {
        // Display instructions for the user
        printf("\nPour faire une addition, utilisez le + entre les deux nombres \n");
        printf("Pour faire une soustraction, utilisez le - entre les deux nombres \n");
        printf("Pour faire une multiplication, utilisez le * entre les deux nombres \n");
        printf("Pour faire une division, utilisez le / entre les deux nombres \n");
        printf("Pour calculer une puissance, utilisez le ^ entre les deux nombres \n");
        printf("Pour arrêter le programme, utilisez le symbole S ou s \n");
        printf("__________________________\n");
        printf("|                        |\n");
        printf("| ? ");

        // Read the input: two numbers and an operator
        if (scanf(" %f %c %f", &data1, &operator, &data2) != 3) {
            // If input is invalid, check if the user wants to exit
            char exitChar;
            scanf(" %c", &exitChar); // Read the character to check for 'S' or 's'
            if (exitChar == 'S' || exitChar == 's') {
                printf("|     End of the programm|");
                S = 1; // Set the flag to exit the loop
                break;
            } else {
                // Invalid input, prompt the user again
                printf("|         Invalid input! |\n");
                continue; // Restart the loop
            }
        }

        // Perform the calculation based on the operator
        switch (operator) {
            case '+': // Addition
                result = addition(data1, data2);
                printf("|                      =%g|", result);
                break;

            case '-': // Subtraction
                result = subtraction(data1, data2);
                printf("|                      =%g|", result);
                break;

            case '*': // Multiplication
                result = multiplication(data1, data2);
                printf("|                      =%g|", result);
                break;

            case '/': // Division
                if (data2 == 0) {
                    // Handle division by zero
                    printf("|                   Error|");
                } else {
                    result = division(data1, data2);
                    printf("|                      =%g|", result);
                }
                break;

            case '^': // Power
                result = power(data1, data2);
                printf("|                      =%g|", result);
                break;

            default:
                // Handle invalid operator
                printf("\nYou have not included a valid operator to calculate");
                break;
        }

        // Display the calculator interface
        printf("\n__________________________\n");
        printf("|   7  |  8  |  9  |  /  |\n");
        printf("|   4  |  5  |  6  |  *  |\n");
        printf("|   1  |  2  |  3  |  -  |\n");
        printf("|   0  |  ,  |  =  |  +  |\n");
        printf("__________________________\n");

    } while (S < 1); // Repeat until the user decides to exit

    return 0; // End of the program
}