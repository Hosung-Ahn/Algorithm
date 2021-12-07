#include <stdio.h>
typedef struct student {
	int id;
	char *pname;
	double points;
} STUD;

void stud_print(STUD *ps) {
    printf("%d, %s, %f\n", ps->id, ps->pname, ps->points);
}
void stud_swap(STUD *a, STUD *b) {
    STUD tmp = *a;
    *a = *b;
    *b = tmp;
}

STUD * stud_get_last(STUD *ps_array) {
    STUD *ret = ps_array;
    while (ret->id >= 0) {
        ret++;
    }
    return ret-1;
}
int stud_compare_points(STUD *ps1, STUD *ps2) {
    return ps1->points <= ps2->points;
}

void stud_bubble_sort(STUD * pnuecs) {
    STUD *last = stud_get_last(pnuecs);
    while (last != pnuecs) {
        STUD *first = pnuecs;
        while (first != last) {
            if (stud_compare_points(first, first+1)) stud_swap(first, first+1);
            first++;
        }
        last--;
    }
	return;
}


int main(void) {
    STUD pnuecs[] = { {1, "Choi", 9.9}, {2, "Park", 0.1},
		{3, "Kim", 5.0 }, {4, "Lee", 3.0 }, {5, "Moon", 9.5 },
		{6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, NULL, 0 } };
		
	STUD * ps_cur = pnuecs;
	// int test_id = 0;
	// scanf("%d",&test_id);
	// if (test_id) set_values_of_pnuecs(pnuecs, test_id); 
	
	stud_bubble_sort(pnuecs);
	
	while (ps_cur->id > 0)
		stud_print(ps_cur++);	

	return 0;
}