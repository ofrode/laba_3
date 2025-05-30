#include "my.h"
#include "byte_struct_work.h"

//1. Найти и вывести остаток от деления целого числа на 4, не выполняя деления
//и не используя операцию взятия остатка от деления.
//2. Структура содержит информацию о животных зоопарка: количество особей
//(число), название (указатель), вложенную структуру – дату поступления в
//зоопарк (строка фиксированной длины) и среднюю продолжительность
//жизни. Найти животных с заданным названием. Удалить животных с
//заданным количеством особей.
//ЗАйцев Дмитрий Сергеевич 28.03.2025 11.43

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
