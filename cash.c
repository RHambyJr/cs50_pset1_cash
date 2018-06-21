//Calculates the least amount of coins necessary to make change

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int getChange(float amount);

int main(void)
{
    //holds user response
    float amount;

    //continuously asks user while amount is less than 0
    do
    {
        amount = get_float("Change: ");
    }
    while (amount < 0);

    int coinsNeeded = getChange(amount);
    printf("%i \n", coinsNeeded);
}

//Calculates the least number of coins needed with argument amount
//Returns int number of coins
int getChange(float amount)
{
    const float QTR = 25;
    const float DIME = 10;
    const float NKL = 5;
    const float PNY = 1;

    int coins = 0
    //Converts the float to an int, after rounding
    float change = roundf(amount * 100);
    int changeLeft = change;

    //Checks if the change remaining is greater than each coin piece
    //If it is, subtracts that coin's total from the remaining amount
    //and adds a coin
    //Continues until change left is 0
    do
    {
        while (changeLeft >= QTR)
        {
            changeLeft -= QTR;
            coins++;
        }
        while (changeLeft >= DIME)
        {
            changeLeft -= DIME;
            coins++;
        }
        while (changeLeft >= NKL)
        {
            changeLeft -= NKL;
            coins++;
        }
        while (changeLeft >= PNY)
        {
            changeLeft -= PNY;
            coins++;
        }
    }
    while (changeLeft != 0);

    return coins;
}