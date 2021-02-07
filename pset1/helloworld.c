# include <stdio.h>
# include <cs50.h>
# include <unistd.h>

int main(void)
{
    int i = 0;
    
    while(i < 10)
    {
        sleep(0.5);
        printf("hello, world \n");
        i = i + 1;
        // or i++, ++i, i += 1
    }
    
    return 0;
}