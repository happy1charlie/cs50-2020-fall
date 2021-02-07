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
    inputNumber = get_int("How many stair do you want?\n");
  }
  while (inputNumber > 8 || inputNumber < 1);

  int i;
  for (i = 0; i < inputNumber; i++)
  {
    for (int l = 0; l < inputNumber - i - 1; l++)
    {
      printf(" ");
    }

    for (int m = 0; m <= i; m++)
    {
      printf("#");
    }

    for (int k = 0; k < 2; k++)
    {
      printf(" ");
    }

    for (int j = 0; j <= i; j++)
    {
      printf("#");
    }
    printf("\n");

  }

  return 0;
}