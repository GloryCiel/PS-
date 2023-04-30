#include<stdio.h>

int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int D = A / (C - B) + 1;
	if (B >= C)
		printf("-1");
	else
		printf("%d",D);
}