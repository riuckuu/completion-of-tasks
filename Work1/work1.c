#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_NAME 30 //самое длинное имя в снг 15 букв
//я не знаю какая система оценивания у спортсменов, поэтому взял их оценку от [0 до 20]
struct Athlete
{
    char name[MAX_LEN_NAME];
    int result;
};


void changeResult(struct Athlete* athletes, int newResult)
{
    athletes->result = newResult;
}


void printListAthletes(const struct Athlete* athletes, int n)
{
    for (int i = 0;i < n;i++)
        printf("%d. %s : %d\n", i + 1, (athletes + i)->name, (athletes + i)->result);
}


double avgResult(const struct Athlete* athletes, int n)
{   
    int sum = 0;
    for (int i = 0;i < n;i++)
        sum += (athletes + i)->result;
    return (double)sum / n;
}


int maxResult(const struct Athlete* athletes, int n)
{
    int k = 0;
    for (int i = 0;i < n;i++)
    {
        if ((athletes + i)->result > (athletes + k)->result)
            k = i;
    }
    return k;
}


int main()
{
    int n;
    printf("Введи количество спортсменов\n");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Спортсмены должны существовать\n");
        return 1;
    }
    struct Athlete* athletes = (struct Athlete*)malloc(n * sizeof(struct Athlete));
    if (athletes == NULL)
    {
        printf("Ошибка при выделении памяти\n");
        return 1;
    }

    for (int i = 0;i < n;i++)
    {   
        printf("Введи имя %d спортсмена\n", i + 1);
        if (scanf("%29s", (athletes + i)->name) != 1)
        {
            printf("Ошибка при вводе имени спортсмена\n");
            free(athletes);
            return 1;
        }
        printf("Введи результат %d спортсмена от 0 до 20\n", i + 1);
        if (scanf("%d", &(athletes + i)->result) != 1 || (athletes + i)->result < 0 || (athletes + i)->result > 20)
        {
            printf("Ошибка при вводе резкльтатов спортсмена\n");
            free(athletes);
            return 1;
        }
    }
    int index;
    int newResults;
    printf("Введи номер спортсмена для которого хочешь поменять результат (1 до %d)\n", n);
    if (scanf("%d", &index) != 1 || index <= 0 || index > n)
    {
        printf("Номер спортсмена должен быть положительным\n");
        free(athletes);
        return 1;
    }
    printf("Введи новый результат спорсмена %d от 0 до 20\n", index);
    if (scanf("%d", &newResults) != 1 || newResults < 0 || newResults > 20)
    {
        printf("Ошибка при вводе нового результата");
        free(athletes);
        return 1;
    }

    changeResult(athletes + index - 1, newResults);
    printf("\nСпортсмены и их результаты:\n");
    printListAthletes(athletes, n);
    printf("\nСредний результат %d спортсменов: %.2f\n", n, avgResult(athletes, n));
    int best = maxResult(athletes, n);
    printf("\nЛучший результат %d, принадлежит спортсмену %s, под номером %d\n",
        (athletes + best)->result, (athletes + best)->name, best + 1);

    free(athletes);
    return 0;
}