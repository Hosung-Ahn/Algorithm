#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int size_bin(char *name) {
	FILE *fp = NULL;
	fp = fopen(name, "rb");
	assert(fp);
	int x = 0, cnt = 0;
	while(fread(&x, sizeof(int), 1, fp)){
		cnt++;
	}
	fclose(fp);
    printf("cnt = %d\n", cnt);
	return cnt;
}

int * read_numbers_binary(char *filename) {
	int size = size_bin(filename);
	FILE *fp = NULL;
	fp = fopen(filename, "rb");
	assert(fp);
	int *ret = malloc(sizeof(int)*(size+1));
	fread(ret, sizeof(int), size, fp);
	ret[size] = -1;
	fclose(fp);
    printf("size = %d\n", size);
    for (int i = 0; i<=size; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
	return ret;
}

int size_csv(char *filename) {
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	assert(fp);
	int cnt = 1;
	char x;
	while ((x = fgetc(fp)) != EOF) {
		if (x == ',' || x == '\n') cnt++;
	}
	fclose(fp);
    if ((cnt-1) % 5 == 0) cnt--;
	return cnt ;
}
int * read_numbers_csv(char *filename) {
	int size = size_csv(filename);
	FILE *fp;
	fp = fopen(filename, "r"); 
	assert(fp);
	int *ret = malloc(sizeof(int)*(size+1));
	int num = 0, index = 0;
	char x;
	while ((x = fgetc(fp)) != EOF) {
		if (x == ',' || x == '\n') {
			ret[index++] = num;
			num = 0;
		}
		else {
			num = num*10 + x - '0';
		}
	}
	fclose(fp);
	ret[index] = num;
	ret[size] = -1;
    printf("size = %d\n", size);
	for (int i = 0; i<=size; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
	return ret;
}

int main(){
    char *bin = "bin.bin", *csv = "csv.txt";
    FILE *fp;
    int nvals[10] = {1,19385,23,3256,477,796601,33456,12345678,99,100};
    int nvals2[10]= {1, 9, 178, 15, 2345, 2, 2, 34, 12,5};
    fp = fopen("bin.bin", "wb");
    assert(fp);
    fwrite(nvals2, sizeof(int), 10, fp);
    fclose(fp);

    char buf[100], *fsf = NULL;
    fp = fopen(csv, "w");
    assert(fp);
    for (int i = 0; i< 10; i++) {
        if ((i+1)%5) fsf = "%d,";
        else fsf = "%d\n";
        fprintf(fp, fsf, nvals2[i]);
    }
    fclose(fp);

    int *nums, nums2;
    nums = read_numbers_binary(bin);
    nums = read_numbers_csv(csv);
    
}