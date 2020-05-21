#include<iostream>
#include<stack>
using namespace std;
bool checkRedundantBrackets(char *input) {
    stack<char> s;
    int i = 0;
    while(input[i]!='\0')
    {
        if(input[i] == ')')
        {
            int ctr=0;
          while(s.top() != '(')
          {
              ctr++;
              s.pop();
          }
          if(ctr == 0){return false;}
        }
        else
        {
            s.push(input[i]);
        }
        i++;
    }
    if(s.empty())
    return true;
    else{return false;}
}


int main() {
    char input[1000];
    cin.getline(input, 1000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
