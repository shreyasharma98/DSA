#include<iostream>
#include"template1.cpp"
#include"template2.cpp"
using namespace std;

int main()
{/*
    box<int,int> b1(10,20);
    b1.show();
    cout<<"The are is : "<<b1.area();
    cout<<endl;


    box<double,double> b2(12.15,7.4);
     b2.show();
    cout<<"The area is : "<<b2.area();
     cout<<endl;

    box<int ,double> b3(2,2.3);
     b3.show();
    cout<<"The area is : "<<b3.area();

    Pair<int,int> p1;
    p1.setX(10);
    p1.setY(20);

    cout<< p1.getX() <<endl;
    cout<< p1.getY() <<endl;

    */

    Pair<Pair<int,int>,int> p1;
    p1.setY(30);
    Pair<int,int> p2;
    p2.setX(10);
    p2.setY(20);
    p1.setX(p2);


    cout<<p1.getX().getX() <<endl;
    cout<<p1.getX().getY() <<endl;
    cout<<p1.getY() <<endl;




}
