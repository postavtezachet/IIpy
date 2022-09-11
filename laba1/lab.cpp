#include<iostream>
#include<fstream>
#include "func.hpp"
using namespace std;
class metric{
  public:
    string capacity;
    string Name;
    string Type;
    string Status;
    string Present;
    string Technology;
    string EnergyNow;
    string Power;

    metric (string capacity,string Name,string Type,string Status,string Present,string Technology,string EnergyNow,string Power){
      this->capacity = capacity;
      this->Name = Name;
      this->Type = Type;
      this->Status = Status;
      this->Present = Present;
      this->Technology = Technology;
      this->EnergyNow = EnergyNow;
      this->Power = Power;
    }

};

int main(){

  ifstream fi("/sys/class/power_supply/BAT0/uevent");
  char buf[14][40];
  for(int i =0;i<13;i++)
    fi.getline(buf[i],50);

  metric numb(buf[12],buf[0],buf[1],buf[2],buf[3],buf[4],buf[8],buf[11]);
  std::cout << numb.capacity << '\n';
  int res = perev(numb.capacity);
  std::cout << res << '\n';
  fi.close();


  return 0;
}
