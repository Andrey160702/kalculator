// Блок 1: подключаем библиотеки ("math" необходима для возведения в степень и извлечения корня)
#include <stdio.h>
#include <math.h>
//
int main(int argc, char *agrv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
// Блок 2: объявляем переменные
	float a,b,res,step;
	char oper,k;
	long int fak=1;
//
	do
	{
// Блок 3: вводим первое число и арифметическую операцию. Так же вводим второе число/степень, если того требует операция
		printf("Введите первое число: ");
		scanf("%f",&a);
		printf("Введите одну из доступных операций (+,-,*,/,!,#(корень),^): ");
		scanf(" %c",&oper);
		if (oper == '+'|| oper == '-'||oper == '*'||oper == '/')
		{
			printf("Введите второе число: ");
			scanf("%f",&b);
		}
		else if (oper =='^')
		{
			printf("Введите степень, в которую хотите возвести число: ");
			scanf("%f",&step);
		}
//
//Блок 4: вычисления
		switch(oper)
		{
		case '+':
			res=a+b;
			printf("%f + %f = %f\n",a,b,res);
		break;
		case '-':
			res=a-b;
			printf("%f - %f = %f\n",a,b,res);
		break;
		case '*':
			res=a*b;
			printf("%f * %f = %f\n",a,b,res);
		break;
		case '/':
			if (b == 0)
			{
				printf("Делить на 0 нельзя, введите второе число еще раз: ");
				scanf("%f",&b);
				res=a/b;
				printf("%f / %f = %f\n",a,b,res);
			}
			else
			{
				res=a/b;
				printf("%f / %f = %f\n",a,b,res);
			}
		break;
		case '!':
			if (a == 0) printf("Факториал числа %f = 1\n",a);
			else if (a == 1) printf("Факториал числа %f = 1\n",a);
			else
			{
				for (float i=1; i<=a; i++)
				{
					fak=fak*i;
				}
				printf("Факториал числа %f = %li\n",a,fak);
			}
		break;
		case '^':
		if (step == 0) printf("1\n");
		else
		{
			printf("%0.5f\n",pow(a,step));
		}
		break;
		case '#':
			if (a<0) printf("корень из отрицательного числа извлекать нельзя\n");
			else printf("%.5f\n",sqrt(a));
		break;
		default:
			printf("Неизвестная операция\n");
		}
//
// Блок 5: тут если мы вводим "y", программа стартует сначала, если "n", то программа прекращает работу
		printf("Желаете продолжить? (y/n): ");
		scanf("%s",&k);
	}
	while (k == 'y');
//
	return 0;
}
