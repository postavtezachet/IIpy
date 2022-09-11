#include<iostream>
#include <string>
using namespace std;
long int perev(std::string buf);
void show_type(std::string type);
void show_type_of_batary(std::string type);
std::string perev_str(std::string buf);
void show_capacity(int level);

class metric{
public:
    string capacity;
    string Name;
    string Type;
    string Status;
    string Present;
    string Technology;
    string EnergyNow;
    string EnergyFull;
    string Power;

    metric (string capacity,string Name,string Type,string Status,string Present,string Technology,string EnergyNow,string EnergyFull,string Power){
        this->capacity = capacity;
        this->Name = Name;
        this->Type = Type;
        this->Status = Status;
        this->Present = Present;
        this->Technology = Technology;
        this->EnergyNow = EnergyNow;
        this->Power = Power;
        this->EnergyFull = EnergyFull;
    }

};

void calac_time(metric a);
void all();