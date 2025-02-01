#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

typedef struct data {
	char** strs;
	int cnt;
} data;

data d1;

void* func(void *param) {
	
	char st[][] = param;
	printf("%s\n", st[0]);

	return NULL;
}

char st[][] = { "abcd", "abc"};

int main() {
	pthread_t thread1, thread2, thread3, thread4;
	int res;

	const char strs1[4][3] = { "1", "2", "3", "4"};
	

	d1.strs = strs1;
	d1.cnt = 4;

	res = pthread_create(&thread1, NULL, func, st);
	if (res != 0) {
		perror("create 1 error");
		exit(1);
	}

	pthread_exit(NULL);
}