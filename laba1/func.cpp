#include<iostream>
#include <fstream>
#include <unistd.h>
#include "func.hpp"

using namespace std;

long int perev(string buf){
  int i =0,j=0;
  int trig = 0;
  string numb;
  long int res;
  while(buf[i]){
    if(trig == 1){
      numb[j] = buf[i];
      j++;
    }
    if(buf[i]=='='){
      trig = 1;
    }
    i++;
  }
  res = stoi(numb);
  return res;
}
string perev_str(string buf){
  int i =0,j=0;
  int trig = 0;
  string numb;
  while(buf[i]){
    if(trig == 1){
      numb[j] = buf[i];
      j++;
    }
    if(buf[i]=='='){
      trig = 1;
    }
    i++;
  }
    numb[j] = buf[i];
  return numb;
}
void show_type(string type) {
  std::cout << "Type of power supply: " <<type.c_str() <<  '\n';
}
void show_type_of_batary(string type) {
  std::cout << "Type of battery: " <<type.c_str()<<  '\n';
}
void show_capacity(int level) {
    std::cout << "Battery level: " <<level<<"%" << endl;
}
void calac_time(metric a){
    double time;
    int hour;
    int minutes;
    double help;
    long int energyFull = perev(a.EnergyFull);
    long int energy = perev(a.EnergyNow);
    long int power = perev(a.Power);
    string charg = "Charging";
    int i =0;
    int test = 0;
    string norm = perev_str(a.Status).c_str();
    while (charg[i]) {
        if (charg[i] != norm[i]) {
            test = 1;
        }
        i++;
    }
    if (test == 0){

        time = energyFull - energy;
        time = (double )time/power;
        hour = (int)time;
        help = time - hour;
        minutes = 60 * help;
        cout<< "time to full charge = " << hour <<":" << minutes<< endl;
    }
    else {
        time = (double) energy / power;
        hour = (int) time;
        help = time - hour;
        minutes = 60 * help;
        cout << "time = " << hour << ":" << minutes << endl;
    }
}
void all(){

    while(1){
        ifstream fi("/sys/class/power_supply/BAT0/uevent");
        char buf[14][40];
        for(int i =0;i<13;i++)
            fi >> buf[i];
        metric numb(buf[12],buf[0],buf[1],buf[2],buf[3],buf[4],buf[11],buf[10],buf[8]);
        show_type(perev_str(numb.Status));
        show_type_of_batary(perev_str(numb.Technology));
        show_capacity(perev(numb.capacity));
        calac_time(numb);
        fi.close();
        sleep(1);
        system("clear");
    }
}