#include <stdio.h>

int main()
{
    int some_arr_hai[5000];
    int a, b, c;
    int flag;

    printf("kitna limit chaiye numbers ka ");
    scanf("%d", &flag);

    printf("dalo %d element dalo\n", flag);
    for (a = 0; a < flag; a++)
    {
        scanf("%d", &some_arr_hai[a]);
    }

    for (a = 0; a < flag; a++)
    {
        for (b = a + 1; b < flag; b++)
        {
            if (some_arr_hai[a] == some_arr_hai[b])
            {
                for ( c= b;  c< flag; c++)
                {
                    some_arr_hai[c] = some_arr_hai[c + 1];
                }
                flag--;
                b--;
            }
        }
    }

    printf("after removing all final result is \n");
    for (a = 0; a < flag; a++)
    {
        printf("%d\t", some_arr_hai[a]);
    }
    return 0;
}