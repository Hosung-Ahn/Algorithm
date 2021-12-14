# include <stdio.h>
# include <string.h>

typedef struct student {
	int id;
	char *name;
	double points;
} STUD;


int main() { 
    STUD s; 
    int id = 3;
    char name[12] = "Hosoung";
    float points = 1.234;

    s.id = id;
    // memcpy(s.name, name, 12);
    s.name = name; 
    s.points = points;
    printf("name : %s\n", name);
    printf("%d, %s, %f\n", s.id, s.name, s.points);

    char *greet = "hosung";
    greet = "Hello";
    printf("%s\n", greet);
}