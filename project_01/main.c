// Блок 1: подключаем библиотеки ("math" необходима для возведения в степень и извлечения корня)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//
int main(int argc, char *agrv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
// Блок 2: объявляем переменные
	float a, b, res, step, rez;
	float *x, *y;
	char oper, k, choose, operv;
	long int fak = 1;
	int size;
//
	do {
//Блок 3: выбираем режим работы калькулятора
		printf(
				"Выберите режим калькулятора (c - работа с числами, v - работа с векторами): ");
		scanf("%s", &choose);
//
		switch (choose) {
		case 'c':
			printf("Активирован режим работы с числами\n");
// Блок 4: вводим первое число и арифметическую операцию. Так же вводим второе число/степень, если того требует операция
			printf("Введите первое число: ");
			scanf("%f", &a);
			printf(
					"Введите одну из доступных операций (+,-,*,/,!,#(корень),^): ");
			scanf(" %c", &oper);
			if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
				printf("Введите второе число: ");
				scanf("%f", &b);
			} else if (oper == '^') {
				printf("Введите степень, в которую хотите возвести число: ");
				scanf("%f", &step);
			}
//
// Блок 5: вычисления в режиме работы с числами
			switch (oper) {
			case '+':
				res = a + b;
				printf("%f + %f = %f\n", a, b, res);
				break;
			case '-':
				res = a - b;
				printf("%f - %f = %f\n", a, b, res);
				break;
			case '*':
				res = a * b;
				printf("%f * %f = %f\n", a, b, res);
				break;
			case '/':
				if (b == 0) {
					printf(
							"Делить на 0 нельзя, введите второе число еще раз: ");
					scanf("%f", &b);
					res = a / b;
					printf("%f / %f = %f\n", a, b, res);
				} else {
					res = a / b;
					printf("%f / %f = %f\n", a, b, res);
				}
				break;
			case '!':
				if (a == 0)
					printf("Факториал числа %f = 1\n", a);
				else if (a == 1)
					printf("Факториал числа %f = 1\n", a);
				else {
					for (float i = 1; i <= a; i++) {
						fak = fak * i;
					}
					printf("Факториал числа %f = %li\n", a, fak);
				}
				break;
			case '^':
				if (step == 0)
					printf("1\n");
				else {
					printf("%0.5f\n", pow(a, step));
				}
				break;
			case '#':
				if (a < 0)
					printf("корень из отрицательного числа извлекать нельзя\n");
				else
					printf("%.5f\n", sqrt(a));
				break;
			default:
				printf("Неизвестная операция\n");
			}
//
		case 'v':
			printf("Активирован режим работы с векторами\n");
			printf("Введите размер векторов: ");
			scanf("%i", &size);
			x = malloc(size * sizeof(float));
			y = malloc(size * sizeof(float));
			printf("x:\n");
			for (int i = 0; i < size; i++)
				scanf("%f", &x[i]);
			printf("y:\n");
			for (int i = 0; i < size; i++)
				scanf("%f", &y[i]);
			printf(
					"Введите одну из доступных операций (+,-,*(скалярное произведение))");
			scanf("%s", &operv);
			switch (operv)
// Блок 6: вычисления в режиме работы с векторами
			{
			case '+':
				printf("( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", x[i]);
				printf(") + ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", y[i]);
				printf(") = ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", x[i] + y[i]);
				printf(")\n");
				break;

			case '-':
				printf("( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", x[i]);
				printf(") - ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", y[i]);
				printf(") = ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", x[i] - y[i]);
				printf(")\n");
				break;
			case '*':
				printf("( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", x[i]);
				printf(") * ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", y[i]);
				printf(") = ");
				for (int i = 0; i < size; i++)
					rez += x[i] * y[i];
				printf("%.2f \n", rez);
				break;
			default:
				printf("Неизвестная операция\n");
			}
//
// Блок 7: тут если мы вводим "y", программа стартует сначала, если "n", то программа прекращает работу
			printf("Желаете продолжить? (y/n): ");
			scanf("%s", &k);
		}
	} while (k == 'y');
//
	return 0;
}
