#include<iostream>
#include<fstream>
using namespace std;

int perev(string buf){
  int i =0,j=0;
  int trig = 0;
  string numb;
  int res;
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
  std::cout << numb << '\n';
  res = stoi(numb);
  return res;
}
