#include <stdio.h>
void main()
{
	int income, in;
	double tax = 0;
	printf("������ �Է��ϼ��� ==> ");
	scanf("%d", &income);
	in = income;

	if (income > 15000) {
		tax += (income - 15000)*0.38;
		income = 15000;
	}
	if (income > 8800) {
		tax += (income - 8800)*0.35;
		income = 8800;
	}
	if (income > 4600) {
		tax += (income - 4600)*0.24;
		income = 4600;
	}
	if (income > 1200) {
		tax += (income - 1200)*0.15;
		income = 1200;
	}
	tax += income*0.06;
	printf(" ��ü������ %7.1f�����Դϴ�.\n", tax);
	printf(" �����ҵ��� %7.1f�����Դϴ�.\n", in - tax);
}