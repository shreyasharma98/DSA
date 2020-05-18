#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool check(char a,char b)
{
    if( a == '[' && b==']')
    {
        return true;
    }
    else if(a == '(' && b==')')
    {
        return true;
    }
    else if(a == '{' && b == '}')
    {
        return true;
    }
    else
        return false;
}
bool checkBalanced(char *exp) {
	stack<char> s;
    for(int i = 0;i<exp[i]!='\0';i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i]== '{')
        {
            s.push(exp[i]);
        }
        if(exp[i] == ')' || exp[i] == ']' || exp[i]== '}')
        {
            bool x = check(s.top(),exp[i]);
            if(x)
            {
                s.pop();
            }
            else
            {
                return x;
            }
        }
    }

}
int main() {
    char input[100];
    cin.getline(input, 100);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
