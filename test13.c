#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>

// #include "common.h"

int main(int argc, char **argv)
{
    char name[] = "Man";
    mq_open(name , 1|0);
}