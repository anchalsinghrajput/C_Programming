#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	char buff;
	int fd1,fd2;
	fd1 = open("one.txt", O_RDONLY);
	fd2 = open("two.txt", O_WRONLY|O_CREAT);
	
	while(read(fd1, &buff, 1))
	{
	    write(fd2, &buff, 1);
	}

    printf("The copy is successful\n");
    close(fd1);
    close(fd2);

    return(0);
}
