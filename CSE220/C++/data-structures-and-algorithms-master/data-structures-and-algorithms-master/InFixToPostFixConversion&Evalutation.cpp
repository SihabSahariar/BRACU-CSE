#include<bits/stdc++.h>
using namespace std;

void infixToPostfix(char exp[] , char out[]);
void postfixEvalutation(char out[]);
int prec(char c);
int sum (char x , char y , char c);
int main()
{
    char exp[100];
    char out[100];
    cout << "Enter Expression : ";
    cin >> exp;

    infixToPostfix(exp , out);
    cout << "The Postfix Expression is : " << out << endl;

    postfixEvalutation(out);
}

void infixToPostfix(char exp[] , char out[])
{
    int index = strlen(exp);

    exp[index] = '$';
    exp[index+1] = '\0';
    stack <char> st;
    st.push('#');
    int i = 0 , j = 0;
    while(exp[i]!='$')
    {
        if(exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            char x = st.top();
            st.pop();
            while(x != '(')
            {
                out[j++] = x;
                x = st.top();
                st.pop();
            }
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            while(prec(exp[i]) <= prec(st.top()))
            {
                out[j++] = st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
        else
        {
            out[j++] = exp[i];
        }
        i++;
    }
    while(!st.empty())
    {
        char ch = st.top();
        if(ch!='(')
            out[j++] = st.top();
        st.pop();
    }
    out[j-1] = '\0';
}

int prec(char c)
{
    if(c=='*' || c == '/')
        return 4;
    else if(c=='+' || c == '-')
        return 3;
    else if(c == '(')
        return 2;
    else if(c == '$')
        return 1;
    else if(c == '#')
        return 0;

}

void postfixEvalutation(char out[])
{
    stack <char> st;

    for(int i = 0 ; i<strlen(out) ; i++)
    {
        if(out[i]=='+' || out[i]=='-' || out[i]=='*' || out[i]=='/')
        {
            char y = st.top();
            st.pop();
            char x = st.top();
            st.pop();
            int s = sum(x , y , out[i]);
            st.push(s+'0');
        }
        else
        {
            st.push(out[i]);
        }
    }
    cout << "The Result is : " << st.top() << endl;
}

int sum (char x , char y , char c)
{
    if(c=='*')
        return (x-48)*(y-48);
    else if(c=='+')
        return (x-48)+(y-48);
    else if(c == '-')
        return (x-48)-(y-48);
    else if(c == '/')
        return (int) (x-48)/(y-48);

}
