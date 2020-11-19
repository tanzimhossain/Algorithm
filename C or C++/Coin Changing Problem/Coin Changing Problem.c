#include<stdio.h>

#define INFINITY 9999

int no_coins, amount;

void Coin_Change(int coin_arr[], int min_coin[], int coin_index[])
{
   int i, price, min, coin;
   min_coin[0] = 0;
   coin_index[0] = 0;

   for(price = 1; price <= amount; price++)
   {
       min = INFINITY;
       for(i = 1; i <= no_coins; i++)
       {
           if(coin_arr[i] <= price)
           {
               if((1+min_coin[price-coin_arr[i]]) < min)
               {
                   min = 1+min_coin[price-coin_arr[i]];
                   coin = i;
               }
           }
       }
       min_coin[price] = min;
       coin_index[price] = coin;
   }

}

void required_coin(int coin_arr[], int coin_index[])
{
    int temp = amount;
    while(temp > 0)
    {
        printf("\ncoin required :: %d", coin_arr[coin_index[temp]]);
        temp = temp - coin_arr[coin_index[temp]];
    }
}

int main ()
{
    printf("Enter the number of coins available :: ");
    scanf("%d",&no_coins);
    int coin_arr[no_coins+1];
    coin_arr[0]= 0;
    int i, temp;
    for(i=0; i<no_coins; i++)
    {
        printf("\nEnter available coins :: ");
        scanf("%d",&temp);
        coin_arr[i+1] = temp;
    }

    printf("\nEnter amount :: ");
    scanf("%d",&amount);

    int min_coin[amount+1];
    int coin_index[amount+1];

    Coin_Change(coin_arr, min_coin, coin_index);

    printf("\nMin no. of coins required to make change for %d is = %d", amount, min_coin[amount]);

    required_coin(coin_arr, coin_index);

    printf("\n\n");

    return 0;
}
