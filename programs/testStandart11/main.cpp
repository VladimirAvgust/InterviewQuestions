#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <system_error>




int main(){
    std::cout << "Start" << std::endl;
    std::ifstream in;

    in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        in.open("testText.txt");
        std::cout << "File open" << std::endl;
        
        in.close();
    }catch(const std::ios_base::failure& e){
        std::cerr << "Error in|out " << e.what() << std::endl;
        std::cerr << "Error code: " << e.code() << std::endl;
    }
    
    
    return 0;
}





/*Мини-проект для закрепления
Напишите функцию, которая:

принимает const std::vector<std::string>&;

с помощью auto и range-for выводит все строки длиннее 3 символов;

с помощью auto создаёт лямбду-фильтр и передаёт её в std::count_if;

с помощью auto& модифицирует копию вектора, добавляя "!" к каждой строке.*/