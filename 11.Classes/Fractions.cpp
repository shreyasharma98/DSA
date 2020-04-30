
#include<iostream>
using namespace std;

class Fraction
{
private :
    int numerator;
    int denominator;
public :
    Fraction(int n,int d)
    {
        numerator = n;
        denominator = d;
    }
    void multiply(Fraction F)
    {
        this->numerator *= F.numerator;
        this->denominator *=  F.denominator;

    }
    void Add(Fraction F)
    {
        int lcm = this->denominator * F.denominator;
        int x = lcm /denominator;
        int y = lcm /F.denominator;
        int n = (x*numerator)+(y*F.numerator);
        this->numerator = n;
        this->denominator = lcm;


    }
    void simplify()
    {
        int gcd = 0;
        int j = min(this->numerator,this->denominator);
        for(int i = 1;i<=j;i++)
        {
            if(this->numerator%i == 0 && this->denominator%i== 0)
            {
                gcd = i;
            }
        }
        this->numerator /= gcd;
        this->denominator /= gcd;

    }
    void display()
    {
        simplify();
        cout<<"The Fraction is : "<<this->numerator<<"/"<<this->denominator<<endl;
    }
};

int main()
{
    Fraction F1(2,5);
    Fraction F2(3,4);
    cout<<"Display the fractions : "<<endl;
    F1.display();
    F2.display();
    cout<<"Fraction after Multiplication : "<<endl;
    F1.multiply(F2);
    F1.display();
    F2.display();
    cout<<"Fraction after Addition : "<<endl;
    F1.Add(F2);
    F1.display();
    F2.display();

    return 0;
}
