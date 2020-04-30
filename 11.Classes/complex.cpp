
#include <iostream>
using namespace std;
class ComplexNumbers {
    private :
    		int r;
    		int c;
    public :
    		ComplexNumbers(int r,int c)
            {
                this -> r = r;
                this -> c = c;
            }
    		void print()
            {
                cout<<r<<" + i"<<c<<endl;
            }
    		void add(ComplexNumbers f)
            {
                this -> r += f.r;
                this -> c += f.c;
            }
    		void multiply(ComplexNumbers f)
            {
                int real = (r * f.r )+ ((c * f.c)*(-1));
                int complex = (r * f.c) + (c * f.r);
                this -> r = real;
                this -> c = complex;
            }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if(choice == 1) {
        c1.add(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
}
