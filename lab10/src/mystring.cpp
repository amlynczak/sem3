#include"mystring.h"
#include<string.h>

namespace mystring{

bool String::operator==(const String &str1) const {
        return static_cast<bool> (!strcmp(_name, str1._name));
    }

bool String::operator==(const char *str) const {
        return *this == String(str);
    }

String& String::operator=(const String& str1){
    
    if(*this == str1) return *this;
    delete[] _name;
    _name = new char[strlen(str1._name)+1];
    strcpy(_name, str1._name);

    return *this;
}

String& String::operator=(const char *str){
    delete[] _name;
    _name = new char[strlen(str)+1];
    strcpy(_name, str);

    return *this;
}

String String::operator+(const String &str1)const{
        char *result_char = new char[
            strlen(this->_name) + strlen(str1._name) + 1
        ];
        strcpy(result_char, this->_name);
        strcpy(result_char + strlen(this->_name), str1._name);

        String result(result_char);
        delete[] result_char;
        return result;
    }

String String::operator+(const char *str) const {
        return this->operator+(String(str));
    }

String String::operator+(char c) const {
        char *pointer = new char[2];
        pointer[0] = c;
        pointer[1] = '\0';
        return this->operator+(pointer);
    }

String operator*(int i, const String &s){
        if(i <= 1) {
            return s;    
        }
        else {
            return (s + (i-1) * s);
        }
    }



void String::print(const char *preambule)const{
    std::cout << preambule << _name << std::endl;

}

String::String(const String&& cp): String(cp._name){
    delete[] cp._name;
}

}//koniec namespace