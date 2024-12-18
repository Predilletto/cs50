#include <cs50.h>
#include <stdio.h>

void array_to_string(int arr[], int size);

void selection_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void merge_sort(int arr[], int size);
void merge(int arr[], int left[], int right[], int left_size, int right_size);

int main(void) {
  int tester[] = {2, 45, 62, 23, 4, 7, 16, 0, 0, 1};
  int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  merge_sort(tester, 10);
  array_to_string(tester, 10);
}

void array_to_string(int arr[], int size) {
  printf("[ ");

  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("]\n");
}

void selection_sort(int arr[], int size) {

  int start = 0;

  while (start < size - 1) {
    int min_index = start;
    for (int i = start + 1; i < size; i++) {
      if (arr[i] < arr[min_index]) {
        min_index = i;
      }
    }
    if (min_index != start) {
      int temp = arr[min_index];
      arr[min_index] = arr[start];
      arr[start] = temp;
    }

    start++;
  }
}

void bubble_sort(int arr[], int size) {
  int start = 0;
  int swapped;

  while (start < size - 1) {
    swapped = 0;
    for (int i = 0; i < size - 2; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = 1;
      }
    }
    if (!swapped) {
      break;
    }
    start++;
  }
}

void merge_sort(int arr[], int size) {
  int middle = size / 2;
  if (size <= 1) {
    return;
  }
  int left[middle];
  int right[size - middle];

  for (int i = 0; i < middle; i++) {
    left[i] = arr[i];
  }

  int i = 0;
  for (int j = middle; j < size; j++) {
    right[i++] = arr[j];
  }
  merge_sort(left, middle);
  merge_sort(right, size - middle);

  merge(arr, left, right, middle, size - middle);
}

void merge(int arr[], int left[], int right[], int left_size, int right_size) {

  int i = 0, j = 0, k = 0;

  while (i < left_size && j < right_size) {
    if (j < right_size && left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else if (i < left_size && right[j] <= left[i]) {
      arr[k++] = right[j++];
    }
  }
  if (i < left_size) {
    while (i < left_size) {
      arr[k++] = left[i++];
    }
  }
  if (j < right_size) {
    while (j < right_size) {
      arr[k++] = right[j++];
    }
  }
}
