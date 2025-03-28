#include "my.h"
#include "byte_struct_work.h"

int main()
{
    ANIMAL* arr = NULL;
    int count_struct = 0;
    while (1)
    {
        switch(menu())
        {
            case 1:
                puts("Input int number");
                printf("%d\n", remainder_of_4(check_int(INT_MIN, INT_MAX)));
                break;
            case 2:
                struct_work(&arr, &count_struct);
                break;
            case 0:
                free(arr);
                return 0;
            default:
                puts("Error");
        }
    }
}
