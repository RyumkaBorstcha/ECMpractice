#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "functions.h"
#include <math.h>
#include <string.h>
#include <time.h>
                                                          ///////ДЗ на модуль, Игнатьева Е.С. 17 группа///////

double t_1(double x_, double a_, double  c_)
{
   return (sqrt(exp(x_) - pow(cos(pow(x_, 2) * pow(a_, 5)), 4)) + pow(atan(a_ - pow(x_, 5)), 4)) / (exp(1) * sqrt(abs(a_ + x_ * pow(c_, 4))));
}

double t_2(double t_)
{
   return 3 * pow(t_, 2) - 6 * t_;
}

void t_3(double a_, double b_, double c_)
{
   double D = (b_ * b_) - (a_ * c_ * 4);   //Дискриминант
   if (D < 0)
      printf("D<0, no solutions\n");   //Действительных корней нет
   else
   {
      if ((int)D > 0)
      {
         printf("%f\n", (-b_ + sqrt(D)) / (2 * a_));
         printf("%f\n", (-b_ - sqrt(D)) / (2 * a_));
      }
      else
         printf("%f\n", (-b_) / (2 * a_));  //Если Дискриминант = 0, один корень
   }
}

void t_4()
{
   
   int rate = 0;    //Тариф
   float time = 0;  //Время в секундах
   int code = 0;    //Код города

   printf("Enter the code\n");
   scanf_s("%d", &code);

   printf("Enter the time\n");
   scanf_s("%f", &time);

   switch (code)    //Тарифы для каждого города
   {
   case 48:
      rate = 15;
      break;
   case 44:
      rate = 18;
      break;
   case 46:
      rate = 13;
      break;
   case 45:
      rate = 11;
      break;
   default:
      break;
   }
   printf("The total cost: %f\n", (rate * time / 60)); //Время в секундах, а тариф за минуту
}

void t_5()
{
   int sum = 0;       //Сумма n цифр числа, возведённых в n-ную степень
   int a = 0;         //Вспомогательная переменная

   for (int i = 1000; i < 10000; i++)
   {
      a = i;
      sum = 0;
      for (int j = 0; j < 4; j++)
      {
         sum += pow(a % 10, 4);
         a /= 10;
      }
      if (sum == i) printf_s("%d ", i);
   }
}

int t_6(char* binary, int n_)
{
   int i = 0;        //Номер элемента
   int result = 0;
   int j = n_ - 1;   //При переводе * на степень двойки, j - это степень

   while (i < n_)
   {
      result += binary[i] * pow(2, j); //Прибавляем цифру * степень двойки
      i++;                             //Увеличение номера
      j--;                             //Уменьшение степени
   }
   return result;
}

void t_7(int I, int J)
{
   int** arr = (int**)malloc(I * sizeof(int**));
   //Проверка распределения памяти
   if (!arr)
      exit(EXIT_FAILURE);

   for (int i = 0; i < I; ++i)
   {
      arr[i] = (int*)malloc(J * sizeof(int*));
      if (!arr[i])
         exit(EXIT_FAILURE);
   }

   for (int i = 0; i < J; ++i) //Пробегаюсь по строкам
   {
      for (int j = 0; j < I; ++j) //Пробегаюсь по столбцам
      {
         arr[i][j] = (rand() % 21) - 10;  //Заполнение в промежутке от -10 до 10
         printf("%4d", arr[i][j]);  //Вывод таблицы на входе
         arr[i][j] = (-3) * arr[i][j]; //Умножаю на -3 (меняется знак) здесь же, чтобы заново не писать цикл
      }
      printf("\n");
   }

   printf("\n\n");

   for (int i = 0; i < J; ++i)
   {
      for (int j = 0; j < I; ++j)
      {
         printf("%4d", arr[i][j]); //Вывод сформированной таблицы
      }
      printf("\n");
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////