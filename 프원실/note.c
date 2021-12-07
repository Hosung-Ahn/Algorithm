#include <stdio.h>
#include <time.h>
void print_local_time_after_kdays(time_t t, int k) {
	struct tm *time = localtime(&t);

	return;
}

int main(void) {
	int k=0;
	time_t now = time(NULL);
	char d[2][10] = {"abc","def"};
	printf("now = %ld", now);
	

	return 0;
}