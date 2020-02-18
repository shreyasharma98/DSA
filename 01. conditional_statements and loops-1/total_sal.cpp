
#include<iostream>
#include<cmath>
using namespace std;

int main() {

    int sal;
    char grade;
    cin>>sal>>grade;
    double hra = sal*0.2,da = sal*0.5,pf = sal*0.11;
    int allw;
    if(grade == 'A')
        {
            allw = 1700;
        }
    else if(grade == 'B')
        {
            allw = 1500;
        }
    else
        {
            allw = 1300;
        }

    cout<<int(round(sal + hra + da + allw - pf));
return 0;
}
