#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 8
#define ARRAY_SIZE 2

int array[ARRAY_SIZE];
pthread_mutex_t mutex;

void *thread_func(void *arg)
{
	int tid = *(int *)arg;

	// Her iki thread de farklı elemanlarda işlem yapacak
	int start = tid * ARRAY_SIZE / NUM_THREADS;
	int end = (tid + 1) * ARRAY_SIZE / NUM_THREADS;

	for (int i = start; i < end; i++)
	{
		pthread_mutex_lock(&mutex);	  // Mutex kilidini al
		array[i] += 1;				  // Kritik bölge
		pthread_mutex_unlock(&mutex); // Mutex kilidini serbest bırak
	}

	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int thread_args[NUM_THREADS];

	// Mutex nesnesini başlat
	pthread_mutex_init(&mutex, NULL);

	// Dizi elemanlarını sıfırla
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		array[i] = 0;
	}

	// Her thread için başlangıç dizini belirle
	for (int i = 0; i < NUM_THREADS; i++)
	{
		thread_args[i] = i;
		pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
	}

	// Thread'leri tamamla
	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}

	// Mutex nesnesini serbest bırak
	pthread_mutex_destroy(&mutex);

	// Dizi elemanlarını yazdır
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}