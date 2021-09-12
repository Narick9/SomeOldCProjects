#include <stdio.h>
#include <math.h>

#define POPULSTART 490000000  // 500e6
#define POPULEND 1300000000   // 1400e6
#define YEARSTART 1945
#define YEAREND 2000
#define LIFETIME 50
#define CHILDBERINGAGE 20

/**
 * Расчёт населения Китая с 1945 года. Выходит, что
 * за 55 лет каждая детородная женщина рожала в среднем
 * по 4 ребёнка. Удивительно, но возможно. Вывести 
 * формулу коофициента детей на семью я таки не смог.
**/

int main()
{
    int population = POPULSTART,
        // всё население делим на его средний возраст, так получаем двадцатилетнего человка, 
        // делим ещё на 2 и получаем детородных девушек
        women = population/(LIFETIME*2);
    float birth_factor = 3.9;   // тот самый коофициент детей на семью
    for (int i = 0; i < (YEAREND - YEARSTART); i++) {
        population += women*birth_factor;   // рождение нового поколения
        population -= population/LIFETIME;  // вычет умерших
        women = population/(LIFETIME*2);    // новое кол-во женщин
    }
    printf("population: %.1fm\n", population*pow(10, -6));
    // population: 1322.8m

    return 0;
}