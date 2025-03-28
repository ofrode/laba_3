#ifndef LABA_3_BYTE_STRUCT_WORK_H
#define LABA_3_BYTE_STRUCT_WORK_H

typedef struct
{
    char *data;
    double life_time;
}DATA;

typedef struct
{
    int count;
    char *name;
    DATA data_lifetime;
}ANIMAL;

int remainder_of_4(int number);
int correct_name(char *name);
int correct_data(char *date);
void input_char(char** name);
void input_char_num(char** data);
void struct_work(ANIMAL** arr, int* count);
void add_struct(ANIMAL *animal);
int menu();
void print_all_name(ANIMAL* animals, int count);
ANIMAL* find_animal_by_name(ANIMAL* animals, int size,char* name);
void print_animal_in_line(ANIMAL *animal);
ANIMAL* remove_animals_by_lifetime(ANIMAL* animals, int* count);

#endif //LABA_3_BYTE_STRUCT_WORK_H
