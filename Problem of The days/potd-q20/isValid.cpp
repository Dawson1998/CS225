#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

bool isValid(string input) {
    stack<char> st;
    int len = input.length();
    //int cb = 0;
    //int bb = 0;
    //int sb = 0;
    //char input[len+1];
    char a;
    //strcpy(char,input.c_str());
    for (int i = 0; i<len;i++)
    {
      if(input[i]!='('&&input[i]!='['&&input[i]!='{'&&
            input[i]!=')'&&input[i]!=']'&&input[i]!='}')
      {
        //a='}';
        continue;
      }
      if(input[i]=='('||input[i]=='['||input[i]=='{')
      {
        st.push(input[i]);
        continue;
      }
      if(st.empty())
      {
        return false;
      }
      switch(input[i])
      {
        case ')':
          a=st.top();
          st.pop();
          if(a=='{'||a=='[')
          {
            return false;
          }
          break;
        case '}':
            a=st.top();
            st.pop();
            if(a=='('||a=='[')
            {
              return false;
            }
            break;
        case ']':
              a=st.top();
              st.pop();
              if(a=='{'||a=='(')
              {
                return false;
              }
              break;
      }

    }
    return st.empty();    // modify this!
}
