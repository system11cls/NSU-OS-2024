#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "string.h"

typedef struct data {
	char strs[4][20];
	int cnt;
} data;

data d1;

void* func(void *param) {
	
	data* d = param;
	printf("%s\n", d->strs[0]);

	return NULL;
}


const char* strs1[4] = { "1", "2", "3", "4" };

int main() {
	pthread_t thread1;
	int res;

	strcpy(d1.strs[0], "a");
	d1.cnt = 4;


	res = pthread_create(&thread1, NULL, func, &d1);
	if (res != 0) {
		perror("create 1 error");
		exit(1);
	}

	pthread_exit(NULL);
}