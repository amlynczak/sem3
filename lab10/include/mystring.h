#pragma once
#include<string.h>
#include<iostream>

namespace mystring{

class String{
friend std::ostream& operator <<(std::ostream& strm, const String& str){
    strm << str._name << std::endl;
    return strm;
};
public:
    String(const char *name): _name(new char[strlen(name)+1]), _l(strlen(name)) { strcpy(_name, name);};
    ~String(){delete[] _name;};
    String(const String& cp): String(cp._name){};
    String(const String&& cp);

    void print(const char *preambule)const;
    char *getChar(){return _name;};

    bool operator==(const char* str)const;
    bool operator==(const String& str1)const;
    String& operator=(const String& str1);
    String& operator=(const char *str);
    String operator+(const String &str1)const;
    String operator+(const char *str)const;
    String operator+(const char c)const;
private:
    char *_name;
    int _l;
};

String operator*(int i, const String &s);

}//koniec namespace