#include<iostream>

namespace wymierne{
    class Double{
        public:
            Double(double x): _x(x), _n(0){};
            Double(const Wymierne &w) : Double(static_cast<double>(w.getA())/static_cast<double>(w.getB())) {};
            double getX(){return _x;}
            int getN(){return _n;}
            void setN(int a){_n = a;}
            void setx(Double a);
            void print();
            

        private:
            double _x;
            mutable int _n;
    };

    void print(Double tmp){
        double x = tmp.getX();
        int n = tmp.getN() +1;
        std::cout << "Print nr "<< n << ". Val =" << x << std::endl;
        tmp.setN(n);
    }

    void Double::print(){
        int n = getN() +1;
        double x = getX();
        std::cout << "Print nr " << n << ". Val=" << x << std::endl;
        setN(n);
    }

    void Double::setx(Double a){
        double x = a.getX();
        _x = x;
    }
}