#include<iostream>

#include"../../include/person.h"
int main( void ){
  Person * person = new Person( "小代sd","15382","xiaodaima@qq.com" );
  std::cout << person->toString() << std::endl;
  delete person;
  return 0;
}