#include<iostream>
#include<cstdlib>
#include "funkcje.h"


int main(int argc, char **argv){
    int m,n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);

    int result = newton(m,n);

    std::cout<< result << std::endl;
}