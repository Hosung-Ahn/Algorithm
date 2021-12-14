#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
typedef struct student {
	int id;
	char name[12];
	double points;
} STUD;

int count_text(char *filename) {
    FILE *fp;
    char * line = NULL;
    size_t len = 0;

    int cnt = 0;

    fp = fopen(filename, "r");
    assert(fp);

    while ( getline(&line, &len,  fp) != -1 ) {
        cnt++;
    }
    fclose(fp);
	return cnt;
}


STUD * read_students_text(char *filename) {
    int n = count_text(filename);
    STUD * ret = malloc(sizeof(STUD)*(n+1));

    FILE *fp;
    char * line = NULL;
    size_t len = 0;

    fp = fopen(filename, "r");
    assert(fp);

    for (int i = 0; i < n; i++) {
        STUD s;
        fscanf(fp, "%d %s %lf", &s.id, &s.name, &s.points);
        ret[i] = s;
    }
    fclose(fp);
    STUD end = {-1, "", 0};
    ret[n] = end;
	return ret;			
}
//end of one

int count_binary(char *filename) {
	FILE *fp = NULL;
	fp = fopen(filename, "rb");
	assert(fp);
    STUD s;
	int cnt = 0;
	while(fread(&s, sizeof(s), 1, fp)) cnt++;
	fclose(fp);
	return cnt;
}

STUD * read_students_binary(char *filename) {
    int n = count_binary(filename);
    STUD *ret = malloc(sizeof(STUD)*(n+1));
    FILE *fp = fopen(filename, "rb");
    assert(fp);
    STUD s;
    for (int i = 0; i < n; i++) {
        fread(&s, sizeof(s), 1, fp);
        ret[i] = s;
    }
    fclose(fp);
    STUD end = {-1, "", 0};
    ret[n] = end;

    return ret;
}

void save_students_text(STUD *ps, char *filename) {
	FILE *fd = fopen(filename, "wt");
	
	if (fd) {
		while (ps->id > 0) {
			fprintf(fd, "%d %s %lf\n", ps->id, ps->name, ps->points);
			ps++;
		}
		fclose(fd);
	}		
}

void save_students_binary(STUD *ps, char *filename) {
	FILE *fd = fopen(filename, "wb");
	STUD *pcur = ps;
	int nitem = 0;
	
	if (fd) {
		while (pcur->id > 0) pcur++;
		fwrite(ps, sizeof(STUD), pcur - ps, fd);
		fclose(fd);
	}		
}

void stud_print(STUD *ps) {
	printf("%03d %-12s %5.1lf\n", ps->id, ps->name, ps->points);
}

void print_students(STUD *ps) {
	while (ps->id > 0) stud_print(ps++);
}

void print_tops(STUD *sorted_ps) {
	double highest_points = sorted_ps->points;
	do {
		stud_print(sorted_ps++);
	} while (sorted_ps->points == highest_points);
}

STUD * sort_students(STUD *ps);

int main(void) {
	char *filename = "data";
	STUD test_data[] = { {1, "Choi", 9.9}, {2, "Park", 0.1}, {3, "Kim", 5.0 }, 
	{4, "Lee", 9.9 }, {5, "Moon", 9.5 }, {6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, "", 0 } };
	STUD *students = test_data, *readin_students = NULL, *sorted_students = NULL;
	int test_case = 1, bbinary = 0;
	
	// scanf("%d", &test_case);
		// if (bbinary) {
	// save_students_binary(students, filename);
	// readin_students = read_students_binary(filename);
	// }
	// else {
	// save_students_text(students, filename);
	// readin_students = read_students_text(filename);
    int cnt = 0;s
    while (readin_students->id >= 0 ) {
        printf("%d : %d, %s, %f\n", cnt++, readin_students->id, readin_students->name, 
                                                readin_students->points);
        readin_students++;
    }
	// }
	// if (readin_students) {
	// 	sorted_students = sort_students(readin_students);	
	// 	print_tops(sorted_students);
	// }	
	return 0;	
}