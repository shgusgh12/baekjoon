



#include <stdio.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#define SHOWHOST
void showtime(time_t);
void show_info(struct utmp*);
int utmp_open(char *filename);
struct utmp *utmp_next();
void utmp_close();
int main()
{
	struct utmp *utbufp;
	
	if(utmp_open(UTMP_FILE) == -1){
		perror(UTMP_FILE);
		exit(1);
	}
	while((utbufp = utmp_next())!=((struct utmp *)NULL))
		show_info(utbufp);
	utmp_close();
	return 0;
}
void show_info(struct utmp* utbufp)
{
	if( utbufp->ut_type != USER_PROCESS)
		return;
	printf("%-8.8s", utbufp->ut_name);
	printf(" ");
	printf("%-8.8s", utbufp->ut_line);
	printf(" ");
	printf("%10d", utbufp->ut_time);
	printf(" ");
	showtime(utbufp->ut_time);
#ifdef SHOWHOST
	printf("(%s)", utbufp->ut_host);
#endif
	printf("\n");
}
void showtime(long timeval)
{
	struct tm *t = localtime(&timeval);
	if(t->tm_mon+1 < 10)
	{
		printf("%d-0%d-%d ", 1900+t->tm_year, t->tm_mon+1, t->tm_mday);
	}
	else
		printf("%d-%d-%d ", 1900+t->tm_year, t->tm_mon+1, t->tm_mday);

	printf("%d:%d", t->tm_hour, t->tm_min);
}
