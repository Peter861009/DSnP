/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "p2Json.h"

using namespace std;

// Implement member functions of class Row and Table here
string JsonElem::Jsonkey() {
   return _key;
}
int JsonElem::Jsonvalue() {
   return _value;
}
bool Json::read(const string& jsonFile){
   fstream file;  
   file.open(jsonFile);
   string element = "", tmp;
   if (!file) 
      return false;
   else{
      while (getline(file,tmp)){
         element += tmp;
      }
   }
   file.close();
   string str = "\"", com = ":";
   int loc = 0, i = 0;
   string arr;
   while((loc=element.find_first_of(str,loc))!=string::npos)
   {
   //position=s.find_first_of(flag,position);
      arr[i++] = loc;
      loc++;
   }
   if (i != 0){
      string key;
      int value, start, end;
      for (int k = 0; k < i ; k+=2){
         key = element.substr(arr[k]+1,arr[k+1]-arr[k]-1);
         start = element.find_first_not_of(":\t\b\r\n ", arr[k+1]+1);
         end = element.find_first_of(",\t\b\r\n ", start);
         value = atoi(element.substr(start,end-start).c_str());
         add(key, value);
      }
   }
// 版权声明：本文为CSDN博主「monkeyduck」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/monkeyduck/article/details/23541073
   return true;
}
void Json::add(const string& key,int &value){
   JsonElem ele(key, value);
   _obj.push_back(ele);
}
void Json::max(){
   if (_obj.size()==0)
      cout << "Error: No element found!!";
   else{
      string key = _obj[0].Jsonkey();
      int value = _obj[0].Jsonvalue();
      for (unsigned int i = 1; i < _obj.size(); i++){
         if (_obj[i].Jsonvalue() > value){
            key = _obj[i].Jsonkey();
            value = _obj[i].Jsonvalue();
         }
      }
      cout << "The maximum element is: { \"" << key << "\" : " << value << " }.";
   }     
}
void Json::min(){
   if (_obj.size()==0)
      cout << "Error: No element found!!";
   else{
      string key = _obj[0].Jsonkey();
      int value = _obj[0].Jsonvalue();
      for (unsigned int i = 1; i < _obj.size(); i++){
         if (_obj[i].Jsonvalue() < value){
            key = _obj[i].Jsonkey();
            value = _obj[i].Jsonvalue();
         }
      }
      cout << "The minimum element is: { \"" << key << "\" : " << value << " }.";
   }     
}
void Json::sum(){
   if (_obj.size()==0)
      cout << "Error: No element found!!";
   else{
      int tmp = 0;
      for (unsigned int i = 0; i < _obj.size(); i++){
            tmp += _obj[i].Jsonvalue();
      }
      cout << "The summation of the values is: " << tmp << ".";
   }  
}
void Json::ave(){
   if (_obj.size()==0)
      cout << "Error: No element found!!";
   else{
      int tmp = 0;
      for (unsigned int i = 0; i < _obj.size(); i++){
            tmp += _obj[i].Jsonvalue();
      }
      tmp/=int(_obj.size());
      cout << "The average of the values is: " << fixed << setprecision(1) << tmp << ".";
   }
}
void Json::print(){
   if (_obj.size()==0)
      cout << "Error: No element found!!";
   else{  
      cout << endl << "{" << endl;
      for (unsigned int i = 0; i < _obj.size()-1; i++){
         // cout << "   " << _obj[i].Jsonkey(_obj[i]) << " : " << _obj[i].Jsonvalue(_obj[i]) << ","<< endl;
         cout << "   " << _obj[i] << ","<< endl;
      }
      cout << "   " << _obj[_obj.size()-1] << endl;
      cout << "}";
   }     
}

ostream& operator << (ostream& os, const JsonElem& j){
   return (os << "\"" << j._key << "\" : " << j._value);
}

