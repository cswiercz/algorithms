#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define T int

int arrays_equal(T* a, T* b, size_t n)
{
  for (size_t k=0; k<n; ++k)
    if (a[k] != b[k])
      return 0;
  return 1;
}

void merge(T* array, T* helper, size_t start, size_t mid, size_t end)
{
  // copy contents to same indices in helper array
  for (size_t i=start; i<=end; ++i)
    helper[i] = array[i];

  // left and right point to helper, i points to where to place in array
  size_t left = start;
  size_t right = mid + 1;
  size_t i = start;
  while ((left <= mid) && (right <= end))
    {
      // if the current left element is smaller than the current right element
      // then put it in the array and incrememnt left
      if (helper[left] < helper[right]) {
        array[i] = helper[left];
        left++;
      } else {
        // otherwise, put the current right element in the array and increment
        // right
        array[i] = helper[right];
        right++;
      }

      // we added an element. move to the next position
      i++;
    }

  // there may be remaining elements on the left and right sides. however, we
  // only need to copy over the left side elements because the right side
  // elements are already there
  size_t remaining = 0;
  if (mid >= left)
    {
      remaining = mid - left;
      for (size_t j=0; j<=remaining; ++j)
        {
          array[i+j] = helper[left + j];
        }
    }
}

void merge_sort_helper(T* array, T* helper, size_t start, size_t end)
{
  size_t mid;
  if (start < end)
    {
      mid = (start + end)/2;
      merge_sort_helper(array, helper, start, mid);
      merge_sort_helper(array, helper, mid+1, end);
      merge(array, helper, start, mid, end);
    }
}

void merge_sort(T* array, size_t length)
{
  T* helper = (T*) malloc(length * sizeof(T));
  merge_sort_helper(array, helper, 0, length-1);
  free(helper);
}


size_t partition(T* array, size_t left, size_t right)
{
  size_t sep = left;
  T pivot = array[right];
  T current, temp;

  for (size_t i=left; i<right; ++i)
    {
      current = array[i];
      if (current <= pivot) {
        // swap with sep pointer
        temp = array[sep];
        array[sep] = current;
        array[i] = temp;

        // move forward one
        sep++;
      }
    }

  // swap the pivot (last element) with the sep
  temp = array[sep];
  array[sep] = pivot;
  array[right] = temp;
  return sep;
}

void quick(T* array, size_t left, size_t right)
{
  size_t mid;
  if (left < right) {
    mid = partition(array, left, right);
    quick(array, left, mid-1);
    quick(array, mid+1, right);
  }
}
void quick_sort(T* array, size_t length)
{
  quick(array, 0, length-1);
}


int main(int argc, char** argv)
{
  printf("== Testing Sort ==\n");
  T array[10] = {6,5,3,1,8,7,2,4,10,9};
  T sorted[10] = {1,2,3,4,5,6,7,8,9,10};

  printf("sorting...\n");
  quick_sort(array, 10);

  printf("testing...\n");
  assert(arrays_equal(array, sorted, 10));
}
