#ifndef THREAD_OSX
#define THREAD_OSX


#include <assert.h>
#include <pthread.h>
#include <stdio.h>

// Some of this code was adapted from:
// https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/Multithreading/CreatingThreads/CreatingThreads.html

typedef void* (*Worker)(void*);

int spawn(Worker worker)
{
    // pthread_attr_t  attr;
    pthread_t posixThreadID;

    // returnVal = pthread_attr_init(&attr);
    // assert(!returnVal);

    // returnVal = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    // assert(!returnVal);

    return pthread_create(&posixThreadID, NULL, worker, NULL);
}


#endif
