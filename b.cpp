
#include<stdio.h>
#include<iostream>
#include "dance.h"
#include "sing.h"
using namespace std;
int main(){
   sing();
   try{
      dance(-1);
   } catch(out_of_range& e){
      cout <<"do something about this negative value";
   }
}
