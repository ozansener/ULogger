#include "CLogger.h"
#include <pthread.h>
#include <iostream>
using namespace std;


int main (int argc, char *argv[])
{
    Logger logger;
    logger.InitLogger("log.txt");
    logger.AddString("Sample Log Message");
    return 0;
}
