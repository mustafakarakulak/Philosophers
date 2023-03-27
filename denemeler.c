#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*thread function definition*/
void	*threadFunction(void *args)
{
	while (1)
	{
		sleep(1);
		printf("I am threadFunction.\n");
	}
}
int main()
{
	/*creating thread id*/
	pthread_t *id;
	int ret;

	/*creating thread*/
	ret = pthread_create(id, NULL, threadFunction, NULL);
	if (ret == 0)
	{
		printf("Thread created successfully.\n");
	}
	else
	{
		printf("Thread not created.\n");
		return 0; /*return from main*/
	}
	while (1)
	{
		sleep(1);
		printf("I am main function.\n");
	}

	return 0;
}
