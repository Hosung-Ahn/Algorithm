#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int count_words(char *txt) {
    char *ptr = strtok(txt, " \n\r");
    int cnt = 0;
    while (ptr != NULL) {
        printf("%d : %s\n", cnt++, ptr); 
        // cnt++;
        ptr = strtok(NULL, " \n\r");
    }

    return cnt;
}

int main(void) {
	char * filename = "text.txt";
	FILE *fd = NULL;
	int test_case = 1;
	
	scanf("%d", &test_case);
	
	switch (test_case) {
		case 2:
			filename = "data/internet.txt";
			break;
		case 3:
			filename = "data/ce.txt";
			break;
		default :
			break;
	}
	
	fd = fopen(filename, "rt");
	if (fd) {
		int nsize;
		char * buffer = NULL;

		fseek(fd, 0, SEEK_END);
		nsize = ftell(fd);
		rewind(fd);	
			
		buffer = (char *)malloc(nsize+1);
		assert(buffer);
		
		nsize = fread(buffer, sizeof(char), nsize, fd);
		buffer[nsize] = '\0';
        printf("buffer : %s\n", buffer);
		printf("# of words in %s is %d\n",filename,count_words(buffer));
		fclose(fd);
	} 
	else puts("File Open Error\n");
	
	return 0;	
}
/*
// ai.txt
Artificial intelligence (AI), is intelligence demonstrated by machines, unlike the natural intelligence displayed by humans and animals. 

// internet.txt
The Internet is the global system of interconnected computer networks that uses the Internet protocol suite to communicate between networks and devices. 
It is a network of networks of local to global scope, linked by a broad array of electronic, wireless, and optical networking technologies.
*/