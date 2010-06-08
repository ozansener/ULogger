#include <time.h>
#include <string>
#include <pthread.h>
#include <fstream>
#include <iostream>
#include <string.h>
class Logger{
public:
    std::string fileName;
    bool isStarted;
public:
    static pthread_mutex_t mutexLogger;
    Logger();
    ~Logger();
    void InitLogger(char* fileName);
    int AddString(char* logMessage);
    };

