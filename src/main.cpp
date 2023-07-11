#include <iostream>
#include <time.h>

const int ARRAY_SIZE = 10;
const int MAX_NUM = 99;

void InitArray(int *array);
void SelectionSort(int *array);

int main()
{
    int array[ARRAY_SIZE];

    InitArray(array);
    SelectionSort(array);

    return 0;
}

void PrintArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << ", ";
    }

    std::cout << std::endl;
}

void InitArray(int *array)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % MAX_NUM + 1;
    }

    std::cout << "初期値" << std::endl;
    PrintArray(array);
}

void Swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void SelectionSort(int *array)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int min_index = i;

        for (int j = i; j < ARRAY_SIZE; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }

        Swap(&array[i], &array[min_index]);

        std::cout << i + 1 << "回目のソート" << std::endl;
        PrintArray(array);
    }
}