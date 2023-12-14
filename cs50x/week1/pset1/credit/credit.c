#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long ccNo;
    long ccNoDuplicate;
    int sum = 0;
    int otherDigitSum;
    int firstDigit;
    int secondDigit;
    int totalDigits = 0;
    long ccNoCopy;

    // * let's get a prompt from the user for a credit card number
    do/-
    {
        ccNo = get_long("Input: ");
    }
    while (ccNo < 1);

    ccNoCopy = ccNo;

    while (ccNoCopy >= 100)
    {
        ccNoCopy /= 10;
    }
    secondDigit = ccNoCopy % 10;
    ccNoCopy /= 10;
    firstDigit = ccNoCopy;

    // * modulo to get the last digit of ccNo
    otherDigitSum = ccNo % 10;
    ccNo /= 10;
    // * add 1 to total digits
    totalDigits++;

    // * check if the product of this digit by 2 has 2 digits, and if so, add the 2 digits to sum
    // * ccNo % 10 * 2 % 10 will get the first digit, as it gets the remainder of the product divided by 10 e.g if the original
    // * number is 8, 2x8 = 16, 16 modulo 10 = 6
    // * ccNo % 10 / 5 % 10 will get the second digit as it first divides the product by 10, then gets the remainder divided by 10
    // * e.g. 2x8 = 16, 16 / 10 = 1.6, 1.6 as int = 1
    if (((ccNo % 10) * 2) > 9)
    {
        sum += ((ccNo % 10) * 2) % 10;
        sum += ((ccNo % 10) / 5) % 10;
    }
    else
    {
        sum += ((ccNo % 10) * 2);
    }

    // * skip to the 3rd last digit of ccNo
    ccNo /= 10;
    // * add 1 to total digits
    totalDigits++;

    // * for loop to increment every other digits
    // * example cc number - 4003600000000014
    for (int i = 0; ccNo > 0; i++)
    {
        int ccNoLastDigitNow = ccNo % 10;
        otherDigitSum += ccNoLastDigitNow;
        if (ccNo > 9)
        {
            // * add 1 to total digits
            totalDigits++;
        }
        ccNo /= 10;

        ccNoLastDigitNow = ccNo % 10;
        if ((ccNoLastDigitNow * 2) > 9)
        {
            sum += (ccNoLastDigitNow * 2) % 10;

            ccNoLastDigitNow /= 5;

            sum += ccNoLastDigitNow % 10;
            // * add 1 to total digits
            totalDigits++;
        }
        else
        {
            sum += ((ccNoLastDigitNow) *2);
            // * add 1 to total digits
            totalDigits++;
        }
        ccNo /= 10;
    }

    // * tabulate the total sum
    sum += otherDigitSum;
    //  printf("totalDigits: %d\n", totalDigits);
    //  printf("firstDigit: %d\n", firstDigit);
    //  printf("secondDigit: %d\n", secondDigit);
    //  printf("sum: %d\n", sum);

    if (sum % 10 == 0)
    {
        if (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7) && totalDigits == 15)
        {
            printf("AMEX\n");
        }
        else if ((totalDigits == 13 || totalDigits == 16) && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else if (firstDigit == 5 && secondDigit > 0 && secondDigit < 6 && totalDigits == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    // * first, multiply every other digit by 2
    // * then, add those products digits together
    // * then, add that sum to the sum of the digits that were not multiplied by 2
    // * if the last digit in that sum is 0, it is a valid number - aka modulo 10
}
