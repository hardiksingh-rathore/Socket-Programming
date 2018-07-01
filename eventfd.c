#include <stdio.h>
#include <unistd.h>
#include <sys/eventfd.h>

void main()
{

	int efd;
	uint64_t i=0;
	int j=0;
	efd = eventfd(0, 0);
	//read(efd, &i, 1);
//	printf("parent(outside) i=%d\n", i);
	perror("eventfd");
	if(fork()==0) {

//		while(1) {
//			sleep(5);
	//		int i;
			for(i=0; i < 5; i++)
			{
                        //i=2;
			j=78;
			write(efd, &i, sizeof(uint64_t));
			printf("child j=%d\n", j);
			}
	//		printf("child i=%d\n", i);
//			sleep(1);
//		}
	} else {
//		while(1) {
			sleep(2);
			printf("in pareant\n");
			//scanf("%d", &i);
			read(efd, &i, sizeof(uint64_t));
	//		read(efd, &i, 1);
			printf("parent i=%d\n", i);
			printf("parent j=%d\n", j);
		//	sleep(1);
//		}

	}
}
