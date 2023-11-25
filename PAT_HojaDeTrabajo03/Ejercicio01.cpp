#include "Ejercicio01.h"

int Ejercicio01::findMin(int nums[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

 
        if (nums[mid] < nums[high])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return nums[low];
}
