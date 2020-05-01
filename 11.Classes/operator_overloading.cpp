
#include<iostream>
using namespace std;
class fraction
{
    int numerator;
    int denominator;
public :
    fraction(int n,int d)
    {
        numerator = n;
        denominator = d;
    }
    void simplify()         //This function cannot be constant bcz it is casting change in the data-members values.
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
    void show()
    {
        simplify();
        cout<<"The fraction is :"<<numerator<<"/"<<denominator<<endl;
    }
    fraction operator+(fraction const &f)
    {
        int lcm = denominator * f.denominator;
        int x = lcm/denominator;
        int y = lcm/f.denominator;
        int n = (x*numerator)+(y*f.numerator);

        fraction fNew(n,lcm);
        return fNew;
    }
    //Pre-increment
    fraction operator* (fraction const &f)
    {
        int n = this->numerator*f.numerator;
        int d = this->denominator*f.denominator;
        fraction fNew(n,d);
        return fNew;
    }
    fraction& operator++()
    {                                   //The retur type in this case returns refernce in
        numerator+=denominator;         //order to avoid the copy to make in the buffer so the the output woud point to the orignal refernce.

        return *this;
    }

    //post-increment
    fraction operator++(int)
    {
        fraction fnew(numerator,denominator);
        numerator+=denominator;

        return fnew;
    }
    //+= operator
    fraction& operator+=(fraction f)
    {
        int lcm = denominator * f.denominator;
        int x = lcm/denominator;
        int y = lcm/f.denominator;
        int n = (x*numerator)+(y*f.numerator);
        numerator = n;
        denominator = lcm;

        return *this;
    }

};
int main()
{
    fraction f1(10,3);
    fraction f2(5,2);
    /*cout<<"Display the fractions : "<<endl;
    f1.show();
    f2.show();
    fraction f3 = f1+f2;
    cout<<"Display the fractions Addition (+ operator overloaded): "<<endl;
    f3.show();
    fraction f4 = f1 * f2;
    cout<<"Display the fractions Multiplication (* operator overloaded): "<<endl;
    f4.show();
    fraction f5 = ++(++f1);
    cout<<"Display the fractions Pre-increment (++ operator overloaded): "<<endl;
    f1.show();
    f5.show();
    fraction f6 = f1++;
    cout<<"Display the fractions Post-increment (++ operator overloaded): "<<endl;
    f1.show();
    f6.show();
    */
    cout<<"Display the fractions assignment operator (+= operator overloaded): "<<endl;
    (f1+=f2)+=f2;
    f1.show();
    f2.show();

}
