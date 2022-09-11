#include<iostream>
#include<fstream>
#include <thread>
#include <pthread.h>
#include "func.hpp"

int pthread_create(pthread_t *pInt);

using namespace std;


int main(){


  int c;
    pthread_t th;
  while(1) {
       cout << "Input what you want to do\n";
       cout << "If you want to exit input 99\n";
       cout << "1: Go to sleep\n";
       cout << "2: Go to hibernates\n";
       cout << "3: show battery inf\n";
       cout << "4: stop show inf\n";
       cin >> c;
       switch (c) {
           case 1:
               pthread_cancel(th);
               cout << "Sleep" << endl;
               system(" systemctl suspend");
               break;
           case 2:
               pthread_cancel(th);
               cout << "Hibernation" << endl;
               system("systemctl hibernate");
           case 3:
               pthread_cancel(th);
               pthread_create(&th, NULL, reinterpret_cast<void *(*)(void *)>(&all), NULL);
               break;
           case 4:
               pthread_cancel(th);
               break;
           case 99:
               break;
           default:
               printf("Error\n");
               break;
       }
       if (c == 99) {
           break;
       }

       rewind(stdin);
   }
    pthread_cancel(th);
  return 0;
}
