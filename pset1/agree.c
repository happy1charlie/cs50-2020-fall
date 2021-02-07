# include<cs50.h>
# include<stdio.h>

int main(void)
{
    int i = 0;
    for (i = 0; i < 3 ; i++)
    {
        char a = get_char("Do you agree you are a loser? (Y or N) \n ");
            if (a == 'Y' || a == 'y')
            {
                printf("You are a loser\n ");
            }   
            else
            {
                printf("You are a loser\n ");
            }
    }
    
    return 0;
}