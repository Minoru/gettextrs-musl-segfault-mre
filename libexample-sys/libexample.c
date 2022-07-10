#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct libdata
{
    pthread_mutex_t mtx;
    uint64_t cnt;
};

struct libdata* libexample_init()
{
    printf("(libexample) Initializing... ");
    struct libdata* data = malloc(sizeof(struct libdata));
    pthread_mutex_init(&data->mtx, NULL);
    data->cnt = 0;
    printf("done\n");
    return data;
}

void libexample_inc(struct libdata* data)
{
    printf("(libexample) Incrementing... ");
    pthread_mutex_lock(&data->mtx);
    ++(data->cnt);
    pthread_mutex_unlock(&data->mtx);
    printf("done\n");
}

void libexample_deinit(struct libdata* data)
{
    printf("(libexample) Destroying... ");
    pthread_mutex_destroy(&data->mtx);
    printf("done\n");
}
