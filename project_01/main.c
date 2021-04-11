//   Инструкция по применению (работаем с файлом input.txt):
// 1)Вводим режим работы калькулятора (c/v)
// 2)Если мы выбрали режим работы с числами (c), то сначала вводим первое число, затем через пробел вводим операцию
//   Если операция подразумевает работу с двумя числами, то через пробел вводим второе число, затем запускаем программу и заходим в output.txt
//   Если операция подразумевает работу с одним числом, то после того, как ввели операцию, запускаем программ и заходим в output.txt
//   Пример ввода: "c 2 + 2" либо "c 3 !"
// 3)Если мы выбрали режим работы с векторами (v), то сначала вводим размер вектора, затем через пробел вводим первый вектор,
//   далее через пробел вводим второй вектор,а затем через пробел вводим операцию и запускаем программу. Далее заходим в output.txt
//   Пример ввода: "v 2 1 1 2 2 +"
//
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
	char oper, choose, operv;
	long int fak = 1;
	int size;
//
	FILE *input, *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");

//Блок 3: выбираем режим работы калькулятора
	printf(
			"Выберите режим калькулятора (c - работа с числами, v - работа с векторами)\n");
	fscanf(input, "%s", &choose);
//
	switch (choose) {
	case 'c':
		printf("Активирован режим работы с числами\n");
// Блок 4: вводим первое число и арифметическую операцию. Так же вводим второе число/степень, если того требует операция
		printf("Введите первое число\n");
		fscanf(input, "%f", &a);
		printf("Введите одну из доступных операций (+,-,*,/,!,#(корень),^)\n");
		fscanf(input, " %c", &oper);
		if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
			printf("Введите второе число\n");
			fscanf(input, "%f", &b);
		} else if (oper == '^') {
			printf("Введите степень, в которую хотите возвести число\n");
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
		break;
//
	case 'v':
		printf("Активирован режим работы с векторами\n");
// Блок 6: Вводим размер векторов, сами вектора и доступную операцию
		printf("Введите размер векторов\n");
		fscanf(input, "%i", &size);
		x = malloc(size * sizeof(float));
		y = malloc(size * sizeof(float));
		printf("Введите вектор x\n");
		for (int i = 0; i < size; i++)
			fscanf(input, "%f", &x[i]);
		printf("Введите вектор y\n");
		for (int i = 0; i < size; i++)
			fscanf(input, "%f", &y[i]);
		printf(
				"Введите одну из доступных операций (+,-,*(скалярное произведение))");
		fscanf(input, "%s", &operv);
//
		switch (operv)
// Блок 7: вычисления в режиме работы с векторами
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
			fprintf(output, "Неизвестная операция\n");
		}
//
	}
	fclose(input);
	fclose(output);
	return 0;
}
