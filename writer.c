#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
int fd, result; size_t size; char resstring[14]; char name[]="";
(void)umask(0);

printf("Writing data to fifo\n");

if((fd = open(name, O_WRONLY)) < 0){
printf("Opening fifo for writing is failed\n");
exit(-1);
}
size = write(fd, "Hello, world!", 14);
printf("It was wrote to fifo\n");
if(size != 14) {
printf("Writing to fifo is failed\n");
exit(-1);
}
close(fd);
printf("Writer exit\n");
return 0;
}
