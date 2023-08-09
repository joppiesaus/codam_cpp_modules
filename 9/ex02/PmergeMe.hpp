#pragma once

#include <vector>

// threshold when the merge sort will use insertion sort
// with the optimization flags -O2 -mtune=native -march=native on the Codam Macs
// 40 is faster for larger sets
#define INSERTION_THRESHOLD (6)

void testSort();

template <typename T>
void insert(T& arr, int value, int leftIndex, int rightIndex)
{
    int i;
    for (i = rightIndex; i >= leftIndex && arr[i] > value; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = value;
}

template <typename T>
void insertionSort(T& arr, int leftIndex, int endIndex)
{
    for (int i = leftIndex + 1; i < endIndex + 1; i++)
    {
        insert(arr, arr[i], leftIndex, i - 1);
    }
}

// merges array
template <typename T>
void merge(T& arr, int p, int q, int r)
{
    const int lowHalfSize = q - p + 1;
    const int highHalfSize = r - q;

    T lowHalf = T(lowHalfSize);
    T highHalf = T(highHalfSize);

    std::copy(arr.begin() + p, arr.begin() + q + 1, lowHalf.begin());
    std::copy(arr.begin() + q + 1, arr.begin() + r + 1, highHalf.begin());

    int k = p;
    int i = 0;
    int j = 0;
    while (i < lowHalfSize && j < highHalfSize)
    {
        if (lowHalf[i] < highHalf[j])
        {
            arr[k] = lowHalf[i];
            i++;
        }
        else
        {
            arr[k] = highHalf[j];
            j++;
        }
        k++;
    }

    // copy remaining
    while (i < lowHalfSize)
    {
        arr[k] = lowHalf[i];
        i++;
        k++;
    }
    while (j < highHalfSize)
    {
        arr[k] = highHalf[j];
        j++;
        k++;
    }
}

// sorts the array using merge-insertion/Ford Johnson algorithm. p is starting point, r is ending point of array.
template <typename T>
void FordJohnsonSort(T& arr, int p, int r)
{
    if (p + (INSERTION_THRESHOLD - 1) < r)
    {
        const int q = (p + r) / 2;
        FordJohnsonSort(arr, p, q);
        FordJohnsonSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
    else
    {
        insertionSort(arr, p, r);
    }
}
