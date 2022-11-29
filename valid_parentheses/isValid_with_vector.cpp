 #include <iostream>
 #include <vector>
 
 bool isValid_vec(std::string s) {

        std::vector<char> s_vec;
        
        for(int i = 0; i < s.size(); i++) {
           if (s[i] == '(' || s[i] == '{'|| s[i] == '['){ s_vec.push_back(s[i]);}
           else if (s[i] == ')' || s[i] == '}'|| s[i] == ']'){
                if(s_vec.empty()) { return false; }
                else {
                    char znak = s_vec.back();
                    s_vec.pop_back();
                    if(znak == '(' && s[i] != ')'
                        || znak == '{' && s[i] != '}'
                        || znak == '[' && s[i] != ']') { return false; }
                }
           }
        }

        return s_vec.empty();
 }

void test_isValid_vec(std::string str, bool expectedResult){

  bool result = isValid_vec(str);

  if (result != expectedResult)
    std::cerr << "Test filed in isValid() for the string " << str << std::endl;

  std::cout << "Test Passed" << std::endl;
  
}

int main()
{
  test_isValid_vec("(){}()", true);
  test_isValid_vec("(){}(", false);
  test_isValid_vec("()", true);
  test_isValid_vec("{}", true);
  test_isValid_vec("{]", false);
  test_isValid_vec("()]", false);
  test_isValid_vec("[)", false);
  test_isValid_vec("{[]}", true);
}