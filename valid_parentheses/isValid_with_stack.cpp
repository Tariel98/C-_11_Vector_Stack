#include <iostream>
#include <stack>

bool isValid(std::string s) {

   std::stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.size()==0)
                    return false;
                char znak = st.top();
                if(s[i]==')' && znak != '(')
                    return false;
                else if(s[i]=='}' && znak != '{')
                    return false;
                else if(s[i]==']' && znak != '[')
                    return false;
                st.pop();
            }
        }
        if(st.size()==0)
            return true;
        return false;
}

void test_isValid(std::string str, bool expectedResult){

  bool result = isValid(str);

  if (result != expectedResult)
    std::cerr << "Test filed in isValid() for the string " << str << std::endl;

  std::cout << "Test Passed" << std::endl;
  
}

int main()
{
  test_isValid("(){}()", true);
  test_isValid("(){}(", false);
  test_isValid("()", true);
  test_isValid("{}", true);
  test_isValid("{]", false);
  test_isValid("()]", false);
  test_isValid("[)", false);
  test_isValid("{[]}", true);
}