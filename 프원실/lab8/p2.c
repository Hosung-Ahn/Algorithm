#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct student {
	int id;
	char name[12];
	double points;
} STUD;

int count(STUD *ps) {
    int cnt = 0;
    STUD *ptr = ps;
    while (ptr->id >= 0) {
        cnt++;
        ptr++;
    }
    return cnt;
}

int cmp(STUD left, STUD right) {
    return left.points < right.points;
}

void swap(STUD *a, STUD *b) {
    STUD tmp = *a;
    *a = *b;
    *b = tmp;
}

STUD * sort_students(STUD *ps) {
    int n = count(ps); 
    printf("n : %d\n", n);
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if ( cmp(ps[j], ps[j+1]) ) {
                swap(ps+j, ps+j+1); 
            }
        }
    }
    return ps;
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

int main(void) {
	STUD test_data[] = { {1, "Choi", 9.9}, {2, "Park", 0.1}, {3, "Kim", 5.0 }, 
	{4, "Lee", 9.9 }, {5, "Moon", 9.5 }, {6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, "", 0 } };
	STUD *students = test_data, *sorted_students = NULL;
	// int test_case = 1;
	
	// scanf("%d", &test_case);
	
	sorted_students = sort_students(students);	
	print_tops(sorted_students);
	
	return 0;	
}	