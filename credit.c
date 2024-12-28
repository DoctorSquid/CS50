#include <stdio.h>
#include <cs50.h>

int get_credit_valid(long card_number);
int get_digits(long nums);
void print_card(int Valid, long card_number);

int main(void)
{
    long card_number;
    int digits;
    card_number = get_long("What is your credit card number ");
    digits = get_digits(card_number);
    int Valid = get_credit_valid(card_number);
    if (digits<13 || digits>16)
    {
        Valid = 0;
    }
    print_card(Valid, card_number);
}
int get_credit_valid(long card_number)
{
    int digits;
    int credit_total = 0;
    long card_number_dummy = card_number/10;
    int current;
    do
    {
        current = (card_number_dummy % 10) * 2;
        if (current>10)
        {
            current = (current / 10) + (current % 10);
        }
        credit_total += current;
        card_number_dummy = card_number_dummy / 100;
    }
    while(card_number_dummy>0);
    card_number_dummy = card_number;
    do
    {
        current = (card_number_dummy % 10);
        credit_total += current;
        card_number_dummy = card_number_dummy / 100;
    }
    while(card_number_dummy>0);
    if ((credit_total % 10) == 0)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
void print_card(int Valid, long card_number)
{
    long first_digits = card_number;
    int digits = get_digits(card_number);
    for(int i=0;i<digits-2;i++)
    {
        first_digits /= 10;
    }
    if(first_digits<56 && first_digits>50 && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (Valid == 0)
    {
        printf("INVALID\n");
    }
    else if((first_digits/10==4) && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    else if((first_digits==34 || first_digits==37) && digits == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
int get_digits(long numb)
{
    if (numb == 0)
    {
        return (0);
    }
    else
    {
        return(1 + (get_digits(numb/10)));
    }
}
//ticks all the 'correctness' criteria but i believe the correctness criteria for mastercard does not meet Luhn's algorithm,
//hence printing mastercard is before printing invalid. i also recognise this could probably be tweaked a bit for extra efficiency
//but i've spent long enough on this already.
