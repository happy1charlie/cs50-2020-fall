#include <cs50.h>
#include <stdio.h>

bool valid_Triangle (float x, float y, float z);

int main(void)
{
    float x = get_float("X?");
    float y = get_float("Y?");
    float z = get_float("Z?");

    bool num = valid_Triangle(x, y, z);

    printf("%i" , num);
    return 0;
}

bool valid_Triangle (float x, float y, float z)
{
    if (x <= 0 || y <= 0 || z <= 0){
        return false;
    } else if ((x + y >= z) || (x + z >= y) || (y + z >= x)){
        return true;
    } else{
        return false;
    }
}



