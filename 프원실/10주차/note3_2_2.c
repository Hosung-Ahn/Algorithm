#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int size_bin(char *name) {
	FILE *fp = NULL;
	fp = fopen(name, "rb");
	assert(fp);
	int x = 0, cnt = 0;
	while(fread(&x, sizeof(int), 1, fp)) cnt++;
	fclose(fp);
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
	char x, last = 0;
	while ((x = fgetc(fp)) != EOF) {
        last = x;
		if (x == ',' || x == '\n') cnt++;
	}
	fclose(fp);
    if (last == '\n' || last == 0) cnt--;
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
void save_numbers_binary(int *pn, char *filename) {
	FILE *fd = fopen(filename, "wb");
	int *pcur = pn;
	
	if (fd) {
		while (*pcur >= 0) pcur++;
		fwrite(pn, sizeof(int), pcur-pn, fd);
		fclose(fd);
	}
}

void save_numbers_csv(int *pn, char *filename) {
	FILE *fd = fopen(filename, "wt");
	int *pcur = pn;
	
	if (fd) {
		while (*pcur >= 0) {
			fprintf(fd, "%d", *pcur++);	
			while (*pcur >= 0) {
				fprintf(fd, ",%d", *pcur++);
				if ( (pcur-pn) % 8 == 0) {
					fprintf(fd, "\n");
					break;
				}
			}
		}
		fclose(fd);
	}
}

int get_max(int *values) {
	int nmax = 0;
	
	if (values) {
		while (*values >= 0) {
			if (*values > nmax)
				nmax = *values;
			values++;
		}
	}
	return nmax;
}



int main(){
    char *bin = "2bin.bin", *csv = "2csv.txt";
    // int nvals[] = {1,2,3,-1};
    int nvals2[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,0,2,2,1,-1}
    save_numbers_binary(nvals2, bin);
    save_numbers_csv(nvals2, csv);

    int *nums, *nums2;
    nums = read_numbers_binary(bin);
    nums2 = read_numbers_csv(csv);

    printf("MAX : %d\n", get_max(nums));
    printf("MAX : %d\n", get_max(nums2));
    
}