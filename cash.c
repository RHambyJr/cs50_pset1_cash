#include <cs50.h>
#include <stdio.h>
#include <math.h>

int getChange(float amount);

int main(void)
{
    float amount;

    do
    {
        amount = get_float("Change: ");
    }
    while (amount < 0);

    int coinsNeeded = getChange(amount);
    printf("%i \n", coinsNeeded);
}

int getChange(float amount)
{
    const float QTR = 25;
    const float DIME = 10;
    const float NKL = 5;
    const float PNY = 1;

    int coins = 0;
    float change = roundf(amount * 100);
    int changeLeft = change;

    printf("Initial change amount: %i\n", changeLeft);
    do
    {
        while (changeLeft >= QTR)
        {
            printf("Entering QTR...\n");
            printf("Amount left: %i\n", changeLeft);
            changeLeft -= QTR;
            coins++;
        }
        while (changeLeft >= DIME)
        {
            printf("Entering DIME...\n");
            printf("Amount left: %i\n", changeLeft);
            changeLeft -= DIME;
            coins++;
        }
        while (changeLeft >= NKL)
        {
            printf("Entering NKL...\n");
            printf("Amount left: %i\n", changeLeft);
            changeLeft -= NKL;
            coins++;
        }
        while (changeLeft >= PNY)
        {
            printf("Entering PNY...\n");
            printf("Amount left: %i\n", changeLeft);
            changeLeft -= PNY;
            coins++;
        }
    }
    while (changeLeft != 0);

    return coins;
}