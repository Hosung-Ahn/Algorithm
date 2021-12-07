#include <stdio.h>
#include <stdlib.h>

#define END_MARK	-1
#define MAX_SIZE	10000

void swap(int *left, int *right) {
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

int partition(int *nums, int left, int right) {
    int x = nums[right], i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] <= x) {
            swap(nums + i, nums + j);
            i++;
        }
    }
    swap(nums + i, nums + right);
    return i; 
}


int quick_select(int *nums, int left, int right, int k) {
    int index = partition(nums, left, right);
    if (k > 0 && k <= right - left + 1) { 
        if (index + 1 == k) return nums[index];

        if (index + 1 > k) 
            return quick_select(nums, left, index - 1, k);

        return quick_select(nums, index + 1, right, k - index - 1);
    }
    return -1;
}

int get_kth_largest(int *nums, int k) {
    int *pn = nums;
    while (*pn != -1) {
        pn++;
    }
    int last = pn-nums-1;
    if (last < 0 || k < 1 || k > last + 1) return -1;
    return quick_select(nums, 0, last, k);
}

int main() {
    int nums[] = {9383,886,2777,6915,7793,8335,5386,492,6649,1421,-1};
    printf("%d\n",  get_kth_largest(nums,4) );
//     for (int i = 0; i <= 14; i++) {
//         printf("%d\n",  get_kth_largest(nums,i) );
//     }
//     printf("%d\n",  get_kth_largest(nums,5) );
}