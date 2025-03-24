#include <stdio.h>
#define ARR_SIZE 4

int main(void)
{
	// Создадим массив длиной 4
	char arr[ARR_SIZE] = {1, 2, 3, 4};
	// Итерируемся по массиву
	for(int i = 0; i < ARR_SIZE; i++)
	{
		// Если дошли до конца, то выводим последний элемент с пробельным символом и выходим из цикла
		if(i == ARR_SIZE -1) 
		{
			printf("%d\n", arr[i]);
			break;
		}
		// Печатаем в stdout каждый жлемент массива(не включая последний)
		printf("%d ", arr[i]);
	
	}
	return 0;
}
