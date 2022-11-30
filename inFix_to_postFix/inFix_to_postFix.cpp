#include <iostream>
#include <stack>


std::string infixToPostFix(std::string  infix)
{
    std::stack<char> st_str;
    std::string result;
  
    for (int i = 0; i < infix.length(); i++) {
        if(infix[i] >= 'a' && infix[i] <= 'z'
         || infix[i] >= 'A' && infix[i] <= 'Z'
         || infix[i] >= '0' && infix[i] <= '9'){ result += infix[i];}

         else if(infix[i] == '('){ st_str.push(infix[i]);}

         else if(infix[i] == ')'){
            while(!st_str.empty()) { 
                if(st_str.top() == '(') { break; }
                result += st_str.top();
                st_str.pop(); 
                }
                st_str.pop();
                if(!st_str.empty() && st_str.top() != '(') {
                    result += st_str.top();
                    st_str.pop();
                    }
         } 

         else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*'){
                st_str.push(infix[i]);
         }

    }
             if(!st_str.empty()){
            while(!st_str.empty()){
                result += st_str.top();
                st_str.pop();
            }
         }
    return result;
}

int main ()
{
    std::string infix = "A*(B+C/D)";
    std::string infix1 = "A*B+C/D";
    std::string infix2 = "A*(B+C)/D";
    std::string infix3 = "((A+(B*C))-D)";

    std::cout << infix << " = " << infixToPostFix(infix) << std::endl;
    std::cout << infix1 << " = " << infixToPostFix(infix1) << std::endl;
    std::cout << infix2 << " = " << infixToPostFix(infix2) << std::endl;
    std::cout << infix3 << " = " << infixToPostFix(infix3) << std::endl;
}