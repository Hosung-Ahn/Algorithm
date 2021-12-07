#include <stdio.h>
#include <time.h>
void print_local_time_after_kdays(time_t t, int k) {
    t = 18573*24*60*60 + 12404;
    t += k*60*60*24;

	struct tm *pt = localtime(&t);
    char days[7][10] = {"Sunday", "Monday","Tuesday","Wednesday",
    "Thursday","Friday","Saturday"};

    printf("%d/%d/%d, %02d:%02d:%02d, %s\n", pt->tm_year+1900, pt->tm_mon+1, pt->tm_mday,
    pt->tm_hour, pt->tm_min, pt->tm_sec, days[pt->tm_wday]);

	return;
}

int main(void) {
	int k=0;
	time_t now = time(NULL);
	
	scanf("%d", &k);
	print_local_time_after_kdays(now,k);

	return 0;
}