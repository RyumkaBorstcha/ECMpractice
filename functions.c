#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "functions.h"
#include <math.h>
#include <string.h>
#include <time.h>
                                                          ///////�� �� ������, ��������� �.�. 17 ������///////

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
   double D = (b_ * b_) - (a_ * c_ * 4);   //������������
   if (D < 0)
      printf("D<0, no solutions\n");   //�������������� ������ ���
   else
   {
      if ((int)D > 0)
      {
         printf("%f\n", (-b_ + sqrt(D)) / (2 * a_));
         printf("%f\n", (-b_ - sqrt(D)) / (2 * a_));
      }
      else
         printf("%f\n", (-b_) / (2 * a_));  //���� ������������ = 0, ���� ������
   }
}

void t_4()
{
   
   int rate = 0;    //�����
   float time = 0;  //����� � ��������
   int code = 0;    //��� ������

   printf("Enter the code\n");
   scanf_s("%d", &code);

   printf("Enter the time\n");
   scanf_s("%f", &time);

   switch (code)    //������ ��� ������� ������
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
   printf("The total cost: %f\n", (rate * time / 60)); //����� � ��������, � ����� �� ������
}

void t_5()
{
   int sum = 0;       //����� n ���� �����, ���������� � n-��� �������
   int a = 0;         //��������������� ����������

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
   int i = 0;        //����� ��������
   int result = 0;
   int j = n_ - 1;   //��� �������� * �� ������� ������, j - ��� �������

   while (i < n_)
   {
      result += binary[i] * pow(2, j); //���������� ����� * ������� ������
      i++;                             //���������� ������
      j--;                             //���������� �������
   }
   return result;
}

void t_7(int I, int J)
{
   int** arr = (int**)malloc(I * sizeof(int**));
   //�������� ������������� ������
   if (!arr)
      exit(EXIT_FAILURE);

   for (int i = 0; i < I; ++i)
   {
      arr[i] = (int*)malloc(J * sizeof(int*));
      if (!arr[i])
         exit(EXIT_FAILURE);
   }

   for (int i = 0; i < J; ++i) //���������� �� �������
   {
      for (int j = 0; j < I; ++j) //���������� �� ��������
      {
         arr[i][j] = (rand() % 21) - 10;  //���������� � ���������� �� -10 �� 10
         printf("%4d", arr[i][j]);  //����� ������� �� �����
         arr[i][j] = (-3) * arr[i][j]; //������� �� -3 (�������� ����) ����� ��, ����� ������ �� ������ ����
      }
      printf("\n");
   }

   printf("\n\n");

   for (int i = 0; i < J; ++i)
   {
      for (int j = 0; j < I; ++j)
      {
         printf("%4d", arr[i][j]); //����� �������������� �������
      }
      printf("\n");
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////