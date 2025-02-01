#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

void* func(void *param) {
	int it = 0;
	char** strs = (char**)param;
	while (strs[it] != NULL) {
		printf("%s\n", strs[it]);
	}

	return NULL;
}

char strs1[5][3] = { "1", "2", "3", "4", NULL };
char strs2[5][10] = { "Hi", "to", "everyone", "here", NULL };
char strs3[5][4] = { "00", "01", "10", "11", NULL };
char strs4[5][2] = { "a", "b", "c", "d", NULL };

int main() {
	pthread_t thread1, thread2, thread3, thread4;
	int res;

	

	res = pthread_create(&thread1, NULL, func, strs1);
	if (res != 0) {
		perror("create 1 error");
		exit(1);
	}

	pthread_exit(NULL);
}