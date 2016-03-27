#define LINUX

#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif


void sleep(int sleepMs)
{
#ifdef LINUX
    usleep(sleepMs*1000000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
#ifdef WINDOWS
    Sleep(sleepMs*1000);
#endif
}