#include<iostream>
using namespace std;
class Polynomial {
    public :
    int *degCoeff;
    int capacity;

    Polynomial()
    {
        degCoeff = new int[5]{0};
        capacity = 5;
    }
    Polynomial(Polynomial const &p)
    {
        this->capacity = p.capacity;
        this->degCoeff = new int[this->capacity];
        for(int i =0;i<this->capacity;i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
    }

    void setCoefficient(int idx,int ele)
    {
        while(capacity<=idx)
        {
            int *arr = new int[2*capacity];
            for(int i = 0;i<capacity;i++)
            {
                arr[i] = degCoeff[i];
            }
            delete []degCoeff;
            degCoeff = arr;
            capacity*=2;
        }
        degCoeff[idx] = ele;
    }
    void print()
    {
        for(int i = 0;i<capacity;i++)
        {
            if(degCoeff[i]!=0)
            {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial new_poly;
        int i =0;
        for(;i<min(this->capacity,p.capacity);i++)
        {
            new_poly.setCoefficient(i,this->degCoeff[i]+p.degCoeff[i]);
        }
        while(i<this->capacity)
        {
            new_poly.setCoefficient(i,this->degCoeff[i]);
            i++;
        }
        while(i<p.capacity)
        {
            new_poly.setCoefficient(i,p.degCoeff[i]);
            i++;
        }
        return new_poly;
    }
    Polynomial operator-(Polynomial const &p)
    {
        Polynomial new_poly;
        int i =0;
        for(;i<min(this->capacity,p.capacity);i++)
        {
            new_poly.setCoefficient(i,this->degCoeff[i]-p.degCoeff[i]);
        }
        while(i<this->capacity)
        {
            new_poly.setCoefficient(i,this->degCoeff[i]);
            i++;
        }
        while(i<p.capacity)
        {
            new_poly.setCoefficient(i,(-1)*p.degCoeff[i]);
            i++;
        }
        return new_poly;
    }


    Polynomial operator*(Polynomial p)
    {
        Polynomial new_poly;
        for(int i = 0;i<this->capacity;i++)
        {
            for(int j =0;j<p.capacity;j++)
            {
                int k = i+j;
                new_poly.setCoefficient(k,degCoeff[k]+(this->degCoeff[i]*p.degCoeff[j]));
            }
        }
        return new_poly;
    }


};
int main()
{
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;

        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }
    return 0;
}
