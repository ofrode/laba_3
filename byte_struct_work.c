#include "byte_struct_work.h"
#include "my.h"

int remainder_of_4(int number)
{
    return number & 0x03;
}

int correct_name(char* name) {
    if (name == NULL || name[0] == '\0') {
        return 0;
    }

    if (!isalpha(name[0]) || !isupper(name[0])) {
        return 0;
    }

    for (int i = 1; name[i] != '\0'; i++) {
        if (!islower(name[i])) {
            return 0;
        }
    }

    return 1;
}

void input_char(char** name)
{
    char* last_name = malloc(1);
    if (last_name == NULL) exit(1);
    last_name[0] = '\0';
    int last_name_length = 0;
    do
    {
        char buf = _getch();
        if (buf == '\b' || buf == 127)
        {
            if (last_name_length > 0)
            {
                last_name_length--;
                char* new_ptr = (char*)realloc(last_name, (last_name_length + 1));
                if (new_ptr != NULL)
                {
                    last_name = new_ptr;
                }
                printf("\b \b");
            }
        }
        else
            if ((buf >= 'a' && buf <= 'z') || (buf >= 'A' && buf <= 'Z'))
            {
            char* new_ptr = (char*)realloc(last_name, (last_name_length + 2));
            if (new_ptr != NULL)
            {
                last_name = new_ptr;
                last_name[last_name_length++] = buf;
                last_name[last_name_length] = '\0';
                printf("%c", buf);
            }
        } else
            if (buf == '\n' || buf == '\r')
        {
            break;
        }
    } while (1);
    puts("");

    (*name) = last_name;
}

void input_char_num(char** data)
{
    char* string = malloc(1);
    if (string == NULL) exit(1);
    string[0] = '\0';
    int length = 0;
    do
    {
        char buf = _getch();
        if (buf == '\b' || buf == 127)
        {
            if (length > 0)
            {
                length--;
                char* new_ptr = (char*)realloc(string, (length + 1));
                if (new_ptr != NULL)
                {
                    string = new_ptr;
                }
                printf("\b \b");
            }
        } else
            if ((buf >= 'a' && buf <= 'z')  || (buf >= 'A' && buf <= 'Z')  || (buf >= '0' && buf <= '9') || buf == '.')
            {
            char* new_ptr = (char*)realloc(string, (length + 2));
            if (new_ptr != NULL)
            {
                string = new_ptr;
                string[length++] = buf;
                string[length] = '\0';
                printf("%c", buf);
            }
        } else if (buf == '\n' || buf == '\r')
        {
            break;
        }
    } while (1);
    puts("");

    (*data) = string;
}

int correct_data(char *date)
{
    int day, month, year;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (strlen(date) != 10)
    {
        return 0;
    }
    if (date[2] != '.' || date[5] != '.')
    {
        return 0;
    }
    if (sscanf_s(date, "%d.%d.%d", &day, &month, &year) != 3)
    {
        return 0;
    }
    if (year < 0 || year > 9999)
    {
        return 0;
    }
    if (month < 1 || month > 12)
    {
        return 0;
    }
    if (day < 1 || day > days_in_month[month - 1])
    {
        return 0;
    }
    return 1;
}

int menu()
{
    puts("-----------------------------------------------");
    puts("|                   Menu:                     |");
    puts("|                  Task 1-2                   |");
    puts("| End my mega super puper respect project - 0 |");
    puts("-----------------------------------------------");
    int task = check_int(0, 2);
    return task;
}

void struct_work(ANIMAL** arr, int* count)
{
    while(1)
    {
        puts("Write animal - 1");
        puts("Search animal - 2");
        puts("Delete animal - 3");
        puts("End task - 0");
        int choice = check_int(0, 3);
        switch(choice)
        {
            case 1:
                ANIMAL* temp = realloc(*arr, (*count + 1) * sizeof(ANIMAL));
                if (temp == NULL) {
                    puts("Error: Memory allocation failed");
                    return;
                }
                *arr = temp;
                (*count)++;
                add_struct(&(*arr)[*count - 1]);
                break;
            case 2:
                print_all_name(*arr, *count);
                puts("\nEntry name of struct");
                char * find_name;
                input_char(&find_name);
                if (correct_name(find_name) != 1)
                {
                    puts("Erorr");
                    return;
                }
                print_animal_in_line(find_animal_by_name(*arr, *count, find_name));
                break;
            case 3:
                *arr = remove_animals_by_lifetime(*arr, count);
                break;
            default:
                puts("Erorr");
        }
    }
}

void add_struct(ANIMAL *animal) {
    while (1) {
        puts("Enter Name:");
        input_char(&animal->name);

        if (correct_name(animal->name)) {
            break;
        }
        puts("Erorr");
    }
    puts("Enter count of animal:");
    animal->count = check_int(1, INT_MAX);




    while (1) {
        puts("Enter Data:");
        input_char_num(&animal->data_lifetime.data);
        if (correct_data(animal->data_lifetime.data))
        {
            break;
        }
        puts("Erorr");
    }
    puts("Enter Time of Life");
    animal->data_lifetime.life_time = check_float(0.0001, 100000);
}

ANIMAL* find_animal_by_name(ANIMAL* animals, int count,char* name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(animals[i].name, name) == 0)
        {
            return &animals[i];
        }
    }
    return NULL;
}

void print_all_name(ANIMAL* animals, int count)
{
    if (animals == NULL || count <= 0)
    {
        puts("Erorr");
        return;
    }
    puts("List of animal names:");
    for (int i = 0; i < count; i++)
    {
        printf("%s ", animals[i].name);
    }
}

void print_animal_in_line(ANIMAL *animal) {
    if (animal == NULL) {
        printf("Invalid animal (NULL pointer)\n");
        return;
    }

    printf("Count: %d | Name: %s | Data: %s | Life time: %.1f\n",
           animal->count,
           animal->name ? animal->name : "(NULL)",
           animal->data_lifetime.data,
           animal->data_lifetime.life_time
    );
}

ANIMAL* remove_animals_by_lifetime(ANIMAL* animals, int* count)
{
    if (animals == NULL || count == NULL || *count <= 0) {
        return animals;
    }

    puts("Enter trigger life time");
    double target_life = check_float(0, 10000);

    int new_count = 0;
    for (int i = 0; i < *count; i++) {
        if (animals[i].data_lifetime.life_time != target_life) {
            new_count++;
        }
    }

    if (new_count == *count) {
        return animals;
    }

    ANIMAL* new_animals = malloc(new_count * sizeof(ANIMAL));
    if (new_animals == NULL) {
        return NULL;
    }

    int new_index = 0;
    for (int i = 0; i < *count; i++) {
        if (animals[i].data_lifetime.life_time != target_life) {
            new_animals[new_index++] = animals[i];
        }
    }

    free(animals);

    *count = new_count;
    return new_animals;
}
