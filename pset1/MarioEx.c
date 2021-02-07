# include<cs50.h>
# include<stdio.h>

  //    # inputnumber - 1 i+1
  //   ## inputnumber - 2 i+2
  //  ### inputnumber - 3 i+3
  // #### inputnumber - 4 i+4

  // 觀察上面的空格規律 先把空格印出來

int main(void)
{
  int inputNumber;

  do
  {
    inputNumber = get_int("How many stair do you want? ");
  }
  while (inputNumber > 8 || inputNumber < 1);

  int i = 0, l = 0, m = 0, j = 0, k = 0; 
  for (i = 0; i < inputNumber; i++)
  {
    
    for (l = 0; l < 4 - i; l++)
    {
      printf(" ");
    }

    for (m = 0; m <= i; m++)
    {
      printf("#");
    }

    for (k = 0; k < 2; k++)
    {
      printf(" ");
    }

    for (j = 0; j <= i; j++)
    {
      printf("#");
    }
    printf("\n");
    
  }
  

    printf("i:%d l:%d , m:%d , k:%d , j:%d ", i , l , m , k, j);
  
  
  return 0;
}