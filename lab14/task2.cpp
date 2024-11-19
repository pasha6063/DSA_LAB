#include <iostream>
#include <stack>
#include <string>
using namespace std;
void reverseStringUsingStack(const string &input)
{
    stack<char> stack;
    for (char ch : input)
    {
        stack.push(ch);
    }
    string reversed;
    while (!stack.empty())
    {
        reversed += stack.top();
        stack.pop();
    }
    cout << "Reversed String: " << reversed << endl;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    reverseStringUsingStack(str);

    return 0;
}
