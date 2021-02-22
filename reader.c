
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
int fd, result;
size_t size;
char resstring[14];
char name[] = "yerasyl.fifo";
(void)umask(0);

if (mknod(name, S_IFIFO | 0666, 0) < 0) {
printf("Creating fifo is failed\n");
exit(-1);
}
printf("File is created\n");
printf("Data has been read from fifo\n");

if ((fd = open(name, O_RDONLY)) < 0) {
printf("Opening fifo for reading is failed\n");
exit(-1);
}
size = read(fd, resstring, 14);
if (size < 0) {
printf("Can\'t read string\n");
exit(-1);
}
printf("Read from fifo: %s\n", resstring);
printf("Reader exit\n");
close(fd);
return 0;
}
