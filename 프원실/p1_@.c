#include <stdio.h>
#include <stdlib.h>

#define END_MARK	-1
#define MAX_SIZE	10000

void swap(int *left, int *right) {
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

int get_kth_largest(int *nums, int k) {
	
}

int main() {
    int nums[] = {9383,886,2777,6915,7793,
                  8335,5386,492,6649,1421,-1};
    // printf("%d\n",  get_kth_largest(nums,4) );
    for (int i = 1; i <= 14; i++) {
        printf("%d\n",  get_kth_largest(nums,i) );
        for (int j = 0; j<=9; j++) {
            printf("%d ", nums[j]);
        }
        printf("\n");
    }
    printf("%d\n",  get_kth_largest(nums,5) );
}