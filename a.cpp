
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string dataIn;
    ofstream ofs("header");
    dataIn="hi jahao I am your teacher";
    getline(cin,dataIn);
    ofs <<dataIn <<"\n" <<"screw you";
    ofs.close();
    string dataOut;
    ifstream ifs;
    ifs.open("header");
    while(getline(ifs,dataOut)){
        cout <<dataOut <<endl;
    }
    ifs.close();
}
