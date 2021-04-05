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
		FILE *input, *output;
		input = fopen("input.txt", "r");
		output = fopen("output.txt", "w");

//Блок 3: выбираем режим работы калькулятора
		printf(
				"Выберите режим калькулятора (c - работа с числами, v - работа с векторами): ");
		fscanf(input, "%s", &choose);
//
		switch (choose) {
		case 'c':
			printf("Активирован режим работы с числами\n");
// Блок 4: вводим первое число и арифметическую операцию. Так же вводим второе число/степень, если того требует операция
			printf("Введите первое число: ");
			fscanf(input, "%f", &a);
			printf(
					"Введите одну из доступных операций (+,-,*,/,!,#(корень),^): ");
			fscanf(input, " %c", &oper);
			if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
				printf("Введите второе число: ");
				fscanf(input, "%f", &b);
			} else if (oper == '^') {
				printf("Введите степень, в которую хотите возвести число: ");
				fscanf(input, "%f", &step);
			}
//
// Блок 5: вычисления в режиме работы с числами
			switch (oper) {
			case '+':
				res = a + b;
				fprintf(output, "%f + %f = %f\n", a, b, res);
				break;
			case '-':
				res = a - b;
				fprintf(output, "%f - %f = %f\n", a, b, res);
				break;
			case '*':
				res = a * b;
				fprintf(output, "%f * %f = %f\n", a, b, res);
				break;
			case '/':
				if (b == 0) {
					fprintf(output,
							"Делить на 0 нельзя, введите второе число еще раз: ");
					fscanf(input, "%f", &b);
					res = a / b;
					fprintf(output, "%f / %f = %f\n", a, b, res);
				} else {
					res = a / b;
					fprintf(output, "%f / %f = %f\n", a, b, res);
				}
				break;
			case '!':
				if (a == 0)
					fprintf(output, "Факториал числа %f = 1\n", a);
				else if (a == 1)
					fprintf(output, "Факториал числа %f = 1\n", a);
				else {
					for (float i = 1; i <= a; i++) {
						fak = fak * i;
					}
					fprintf(output, "Факториал числа %f = %li\n", a, fak);
				}
				break;
			case '^':
				if (step == 0)
					fprintf(output, "1\n");
				else {
					fprintf(output, "%0.5f\n", pow(a, step));
				}
				break;
			case '#':
				if (a < 0)
					fprintf(output,
							"корень из отрицательного числа извлекать нельзя\n");
				else
					fprintf(output, "%.5f\n", sqrt(a));
				break;
			default:
				fprintf(output, "Неизвестная операция\n");
			}
//
		case 'v':
			printf("Активирован режим работы с векторами\n");
			printf("Введите размер векторов: ");
			fscanf(input, "%i", &size);
			x = malloc(size * sizeof(float));
			y = malloc(size * sizeof(float));
			printf("x:\n");
			for (int i = 0; i < size; i++)
				fscanf(input, "%f", &x[i]);
			printf("y:\n");
			for (int i = 0; i < size; i++)
				fscanf(input, "%f", &y[i]);
			printf(
					"Введите одну из доступных операций (+,-,*(скалярное произведение)): ");
			fscanf(input, "%s", &operv);
			switch (operv)
// Блок 6: вычисления в режиме работы с векторами
			{
			case '+':
				fprintf(output, "( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", x[i]);
				fprintf(output, ") + ( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", y[i]);
				fprintf(output, ") = ( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", x[i] + y[i]);
				fprintf(output, ")\n");
				break;

			case '-':
				fprintf(output, "( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", x[i]);
				fprintf(output, ") - ( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", y[i]);
				fprintf(output, ") = ( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", x[i] - y[i]);
				fprintf(output, ")\n");
				break;
			case '*':
				fprintf(output, "( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", x[i]);
				fprintf(output, ") * ( ");
				for (int i = 0; i < size; i++)
					fprintf(output, "%.2f ", y[i]);
				fprintf(output, ") = ");
				for (int i = 0; i < size; i++)
					rez += x[i] * y[i];
				fprintf(output, "%.2f \n", rez);
				break;
			default:
				printf( "Неизвестная операция\n");
			}
//
// Блок 7: тут если мы вводим "y", программа стартует сначала, если "n", то программа прекращает работу
			printf("Желаете продолжить? (y/n): ");
			fscanf(input, "%s", &k);
		}
		fclose(input);
		fclose(output);
	} while (k == 'y');
//
	return 0;
}
