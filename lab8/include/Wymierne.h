#include<string>
namespace wymierne{

    class Wymierne{
    public:
    Wymierne(int a, int b): _a(a), _b(b ? b : 1) { simplify(); };
    Wymierne(int a): _a(a), _b(1) { simplify(); };
    Wymierne(): _a(0), _b(1) { simplify(); };
  
    explicit operator double()const;
    void setL(int a) {_a = a;}
    void setM(int b) {_b = b;}
    int getA()const;
    int getB()const;
    void print()const;
    void print(std::string name)const;

    static Wymierne pomnoz(const Wymierne &a, const Wymierne &b);
    void simplify();
  
    private:
    int _a;
    int _b;
    };

    Wymierne pomnoz(Wymierne a, Wymierne b);

    int nwd(int m, int n);
    

}; //koniec namespace