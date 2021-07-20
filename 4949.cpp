#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string line;
    while (1)
    {
        stack<char> s;
        getline(cin, line);
        if (line.at(0) == '.')
        {
            break;
        }

        for (int i = 0; i < line.length(); i++)
        {
            if (line.at(i) == '(')
            {
                s.push('(');
            }
            else if (line.at(i) == ')')
            {
                if (s.empty())
                {
                    s.push(')');
                    break;
                }
                else if (s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            if (line.at(i) == '[')
            {
                s.push('[');
            }
            else if (line.at(i) == ']')
            {
                if (s.empty())
                {
                    s.push(']');
                    break;
                }
                else if (s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
        }
        if (s.empty())
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}