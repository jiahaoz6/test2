#include<fstream>
#include<iostream>
#include<vector>
#include<stdio.h>
#include<limits>
#include<algorithm>
#include<iterator>
#include<iomanip>
#include<stdlib.h>
using namespace std;
template<typename T>
char* AsByte(T& obj){
    void* a=&obj;
    return static_cast<char*>(a);
}
struct student{
    char name[255];
    char grade[255];
};
void operator<<(ostream& fs,student a){
    fs <<a.name <<'\t' <<a.grade;
}
void binary_insert(string str,size_t num,student a){
    ofstream ofs1(str,ios::app);
    ofs1.seekp((num)*sizeof(student));
    ofs1.write(AsByte(a),sizeof(student));
    ofs1.close();
}
void binary_update(string str,size_t num,student a){
    ofstream ofs1(str,ios::binary);
    ofs1.seekp((num)*sizeof(student));
    ofs1.write(AsByte(a),sizeof(student));
    ofs1.close();
}
void binary_update(ofstream& ofs,size_t num,student a){
    ofs.seekp((num)*sizeof(student),ios::beg);
    ofs.write(AsByte(a),sizeof(student));
}
void binary_create(string str,student a){
    ofstream ofs2(str,ios::binary);
    ofs2.seekp(ios::beg);
    ofs2.write(AsByte(a),sizeof(student));
    ofs2.close();
}

student binary_read(string str,size_t num){
    ifstream ifs(str,ios::binary);
    ifs.seekg((num)*sizeof(student));
    student a;
    ifs.read(AsByte(a),sizeof(student));
    ifs.close();
    return a;
}
student binary_read(ifstream& ofs,size_t num){
    ofs.seekg((num)*sizeof(student),ios::beg);
    student a;
    ofs.read(AsByte(a),sizeof(student));
    ofs.close();
    return a;
}
int main(){
    char name[]="binary.txt";
    char num[]="1";
    student a{"jahao","2"};student b{"tom","1"};student c{"jim","3"};
    binary_create(name,a);
    binary_insert(name,1,b);
    binary_update(name,1,c);
    student d;
    d=binary_read(name,1);
    cout <<d;
}