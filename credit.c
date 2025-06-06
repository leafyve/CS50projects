#include <cs50.h>
#include <stdio.h>

int check_sum(long number);
int check_card_length(long number);

int main(void)
{
    // Prompt input
    long number = get_long("Number: ");

    // checksum for valid or invalid
     if (check_sum(number) == 0)
     {
        // check card length for which company
        check_card_length(number);
     }
     else
     {
        return 0;
     }
}

// calculate checksum
int check_sum(long number)
{
    // initializing arrays
    int total_sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int digit_count = 0;

    // TODO: sepearating and adding every starting with the number’s second-to-last digit then
    // mutipliy by 2 for every even number of the index [0], [2], [4]
    for (long temp = number; temp > 0; temp /= 10)
    {
        int digit = temp % 10;

        if (digit_count % 2 == 1)
        {
            int product = digit * 2;
            if (product > 9)
            {
                sum1 += (product - 9);
            }
            else
            {
                sum1 += product;
            }
        }
        else
        {
            sum2 += digit;
        }

        digit_count += 1;
    }

    total_sum = sum1 + sum2;

    // checking validity of credit card, return 0 and continue with the code to check card length
    if (total_sum % 10 == 0)
    return 0;

    // else return INVALID and end the code there by returning 1
    else
    {
        printf("INVALID\n");
        return 1;
    }
}

// check for card length and starting digits

int check_card_length(long number)
{
    // check if checksum produce valid answer first
    int card_length = 0;
    long original_number = number;
    while (number > 0)
    {
        number /= 10;
        card_length += 1;
    }
    while (original_number >= 100)
    {
        original_number /= 10;
    }

    if ((original_number == 34 || original_number == 37) && card_length == 15)
    {
        printf("AMEX\n");
    }

    else if ((original_number >= 51 && original_number <= 55) && card_length == 16)
    {
        printf("MASTERCARD\n");
    }

    else if (original_number / 10 == 4 && (card_length == 13 || card_length == 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}
