#include<iostream>
#include<vector>


template<typename Type>
Type summ(Type a, Type b);


int main(){
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {1, 2, 3};

    std::cout << summ(2, 3) << std::endl;
    std::cout << summ('a', 'a') << std::endl;
    //std::cout << summ(a, b).at(0) << std::endl;
    
    return 0;
}

template<typename Type>
Type summ(Type a, Type b){
    return a + b;
}
