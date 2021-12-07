#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define	DEF_RATE	1.8 // default rate (%)
#define	DEF_TERM 	1 // default term (yr)

int inter_calc(int dep, double rate, int yrs) {
	
	return 0;
}
int main(int argc, char *argv[]) {
	int myargc = 1, i;
	char my_cmd_line[1000]; 
	char *myargv[20]={"./Main.out", NULL};
	char *token = NULL;

	gets(my_cmd_line);
	
	token = strtok(my_cmd_line, " ");
	
	while (token) {
		myargv[myargc++] = token;
		token = strtok(NULL, " ");
	}

	return mymain(myargc, myargv);
}

int mymain(int argc, char *argv[]) {

	int deposit;
	double rate = DEF_RATE/100;
	int term = DEF_TERM;



	printf("Total Interest = KRW %d\n", inter_calc(deposit, rate, term));

	return 0;
}