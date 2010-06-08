#include "CLogger.h"
#include <fstream>
#include <iostream>
using namespace std;
pthread_mutex_t Logger::mutexLogger;

class Params{
public:
    string fileName;
    char* logMessage;
    };

void* writeToFile(void* params){

    pthread_mutex_lock(&Logger::mutexLogger);
    Params* p=(Params*)params;
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    string timen(asctime(timeinfo));
    timen.replace(timen.size()-1,1,":");

    ofstream of;
    of.open(p->fileName.c_str(),ios_base::app);
    of<<timen<<p->logMessage<<endl;
    of.close();
    delete p;
    pthread_mutex_unlock(&Logger::mutexLogger);
    return NULL;
    }

Logger::Logger(){
    isStarted = false;
    }

Logger::~Logger(){
    isStarted = false;
    pthread_exit(NULL);
    }

void Logger::InitLogger(char* fileName){
    pthread_mutex_init(&Logger::mutexLogger,NULL);
    pthread_mutex_lock(&Logger::mutexLogger);
    if(isStarted)
        return;
    isStarted = true;
    this->fileName.insert(0,fileName);
    pthread_mutex_unlock(&mutexLogger);
    AddString("Logger Started");
    }

int Logger::AddString(char* logMessage){
    pthread_t threadLogger;
    Params *p;
    p=new Params;
    p->fileName = this->fileName;
    p->logMessage = logMessage;
    pthread_create(&threadLogger,NULL,writeToFile,(void*)p);
    }

