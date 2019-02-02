#include<iostream>
#include<time.h>
//#include<conio.h>
#include<cstdlib>
#include<pthread.h>
#include <unistd.h>
#include <emscripten/emscripten.h>
#include <emscripten/threading.h>
#define NUM 100
using namespace std;
extern "C"
{
void EMSCRIPTEN_KEEPALIVE *show_time(void*)
{
    time_t t, val =1;

    struct tm* ist;

    t = time(NULL);

    ist = localtime(&t);

    cout<<ist->tm_hour;
    cout<<":";
    cout<<ist->tm_min;
    cout<<":";
    cout<<ist->tm_sec;
    cout<<":\n";


}
}
int EMSCRIPTEN_KEEPALIVE main()
{
    pthread_t th[NUM];
    int er;
    for(int i=0;i<NUM;i++) {

        er = pthread_create(&th[i],NULL,&show_time,( void*)i);

        sleep(1);
     //   clrscr();
        if(er)

        {
            std::cout << "err" << std::endl;
            exit(-1);
        }


    }
    //show_time();
    pthread_exit(NULL);
    return 0;
}
