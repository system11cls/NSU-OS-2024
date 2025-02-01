#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

typedef struct data {
	char** strs;
	int cnt;
} data;

data d1;

void* func(void *param) {
	
	char (*st)[3] = param;
	printf("%s\n", st[0]);

	return NULL;
}

char st[2][5] = {"abcd", "abc"};

int main() {
	pthread_t thread1;
	int res;

	const char *strs1[3] = { "1", "2", "3", "4"};


	res = pthread_create(&thread1, NULL, func, strs1);
	if (res != 0) {
		perror("create 1 error");
		exit(1);
	}

	pthread_exit(NULL);
}