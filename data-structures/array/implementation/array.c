#include <stdio.h>
#define ARR_SIZE 4

int main(void)
{
	// Создадим массив длиной 4
	int arr[ARR_SIZE] = {1, 2, 3, 4};
	// Итерируемся по массиву
	for(int i = 0; i < ARR_SIZE; i++)
	{
		// Печатаем в stdout каждый жлемент массива(не включая последний)
		printf(i == ARR_SIZE - 1 ? "%d\n" : "%d ", arr[i]);
	}
	return 0;
}
