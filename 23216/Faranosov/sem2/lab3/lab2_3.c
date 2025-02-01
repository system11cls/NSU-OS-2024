#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

void* func(void *param) {
	int it = 0;
	char** strs = param;
	for (int i = 0; i < 4; i++) {
		printf("%s\n", strs[i]);
	}

	return NULL;
}



int main() {
	pthread_t thread1, thread2, thread3, thread4;
	int res;

	char strs1[4][3] = { "1", "2", "3", "4"};
	char strs2[4][10] = { "Hi", "to", "everyone", "here"};
	char strs3[4][4] = { "00", "01", "10", "11"};
	char strs4[4][2] = { "a", "b", "c", "d"};

	res = pthread_create(&thread1, NULL, func, (void*)strs1);
	if (res != 0) {
		perror("create 1 error");
		exit(1);
	}

	pthread_exit(NULL);
}