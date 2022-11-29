#include <iostream>
#include <stack>

template <typename T> void reverse_array(T array[], int size)
{   
    std::stack<T> st;
    for(int i=0; i<size; ++i)
        st.push(array[i]);
    
    for(int i=0; i<size; ++i){
        array[i] = st.top();
        st.pop();
    }
};

int main()
{   
    int n = 5;
    int arr[n]{1, 2, 3, 4, 5};
    std::string str_arr[n]{"first", "second", "third", "fourth", "fifth"};
    char ch_arr[n] = "abcde";

    std::cout << ":::Before Refersing ints:::" << std::endl;
    
    for(int i=0; i<n; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << ":::Before Refersing string array:::" << std::endl;
        for(int i=0; i<n; ++i) std::cout << str_arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << ":::Before Refersing car array:::" << std::endl;
        for(int i=0; i<n; ++i) std::cout << ch_arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    reverse_array(arr, n); 
    reverse_array(str_arr, n); 
    reverse_array(ch_arr, n); 

    std::cout << ":::After Refersing ints:::" << std::endl;
    for(int i=0; i<n; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << ":::After Refersing string array:::" << std::endl;
    for(int i=0; i<n; ++i) std::cout << str_arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << ":::After Refersing car array:::" << std::endl;
    for(int i=0; i<n; ++i) std::cout << ch_arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

}