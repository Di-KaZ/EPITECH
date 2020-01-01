#include "my_ls.h"

void disp_mon (struct stat *file_stat)
{
	char month[12][4] = {"Jan\0", "Fab\0", "Mar\0",
			     "Apr\0" ,"May\0" ,"Jun\0",
		             "Jul\0", "Aou\0", "Sep\0",
			     "Oct\0", "Nov\0", "Dec\0"};
	time_t time = file_stat->st_mtime;
	struct tm ltime;

	localtime_r(&time, &ltime);

	for (long int i = 0; i < 12; i += 1)
		if (ltime.tm_mon == i)
			my_putstr(month[i]);
	my_printf(" %d ", ltime.tm_mday);
	if (ltime.tm_hour < 10)
		my_putchar('0');
	my_printf("%d:%d", ltime.tm_hour, ltime.tm_min);
}

void print_auth2 (struct stat *file_stat)
{
	struct passwd uid;
	struct passwd *get_uid = NULL;
	char *bufferuid = malloc(256);
	char *buffergrpid = malloc(256);
	struct group *get_grpid;
	struct group grpid;

	getpwuid_r(file_stat->st_uid, &uid, bufferuid, 256 , &get_uid);
	getgrgid_r(file_stat->st_gid, &grpid,buffergrpid, 256 , &get_grpid); 
	my_printf(" %d %s %s %d ",
	file_stat->st_nlink, get_uid->pw_name, get_grpid->gr_name,
	file_stat->st_size);
	free(bufferuid);
	free(buffergrpid);
	disp_mon(file_stat);
}

void print_auth(char *path)
{
	struct stat file_stat;

	stat(path, &file_stat);
	my_putchar((S_ISDIR(file_stat.st_mode)) ? 'd' : '-');
	my_putchar((file_stat.st_mode & S_IRUSR) ? 'r' : '-');
	my_putchar((file_stat.st_mode & S_IWUSR) ? 'w' : '-');
	my_putchar((file_stat.st_mode & S_IXUSR) ? 'x' : '-');
	my_putchar((file_stat.st_mode & S_IRGRP) ? 'r' : '-');
	my_putchar((file_stat.st_mode & S_IWGRP) ? 'w' : '-');
	my_putchar((file_stat.st_mode & S_IXGRP) ? 'x' : '-');
	my_putchar((file_stat.st_mode & S_IROTH) ? 'r' : '-');
	my_putchar((file_stat.st_mode & S_IWOTH) ? 'w' : '-');
	my_putchar((file_stat.st_mode & S_IXOTH) ? 'x' : '-');
	my_putchar('.');
	print_auth2(&file_stat);

}
