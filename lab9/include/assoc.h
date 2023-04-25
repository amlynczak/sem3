#pragma once
#include<iostream>
#include<string>

class Subject{
friend class Assoc;
public:
    Subject(std::string name = "", double val=0): _name(name), _val(val){};
private:
    std::string _name;
    double _val;
};

class Assoc{
friend class Subject;
public:
    Assoc(int lp=0);
    Assoc(const Assoc &copy);
    Assoc(Assoc &&move);
    ~Assoc();
    void insert(const std::string name, double val);
    void print(const std::string preambule)const;
    double &operator[](const std::string name);
    double &operator[](const std::string name)const;
    Assoc &operator=(const Assoc &assign);
    bool contains(const std::string name)const;
private:
    int _l;
    Subject *_head;

};

std::string print(bool check);