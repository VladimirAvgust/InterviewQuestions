#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <system_error>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <ctime>

std::string outString(std::ifstream &in);
std::vector<std::string> vectStr(const std::string &str);
void autoProgramm();

std::unique_ptr<int[]> createMass(int size);
void testUnuque();

int main(){
    std::cout << "Start" << std::endl;
    
    testUnuque();

    return 0;
}
void testUnuque(){
    int size = 0;
    std::cin >> size;
    auto mass = createMass(size);
    for (int i = 0; i < size; i++){
        mass[i] = i*i;
        std::cout << mass[i] << std::endl;
        
    }
}

std::unique_ptr<int[]> createMass(int size){
    std::unique_ptr<int[]> mass = std::make_unique<int[]>(size);
    return mass;
}


void autoProgramm(){
    std::ifstream in;

    in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        in.open("testText.txt");
        std::cout << "File open" << std::endl;
        std::string str = outString(in);
        std::vector<std::string> vectWords = vectStr(str);
        for ( auto const& a : vectWords){
            if (a.size() > 3){
                std::cout << a << std::endl;
            }
            
        }

        in.close();
    }catch(const std::ios_base::failure& e){
        std::cerr << "Error in|out " << e.what() << std::endl;
        std::cerr << "Error code: " << e.code() << std::endl;
    }
    
}

std::string outString(std::ifstream &in){
        std::cout << "read file" << std::endl;
        std::string line;
        std::getline(in, line, '\0');
        return line;
}
std::vector<std::string> vectStr(const std::string &str){
     std::stringstream ss(str);
        std::vector<std::string> vectWords;
        std::string word;
        while (ss >> word){
            std::string newWord;
            for (auto c : word) {
                if(!std::isspace(c) && !std::ispunct(c)){
                    newWord += c;
                }
            }
            if (newWord.size() != 0){
                vectWords.push_back(newWord);
            }
        }
        return vectWords;
}


/*Мини-проект для закрепления
Напишите функцию, которая:

принимает const std::vector<std::string>&;

с помощью auto и range-for выводит все строки длиннее 3 символов;

с помощью auto создаёт лямбду-фильтр и передаёт её в std::count_if;

с помощью auto& модифицирует копию вектора, добавляя "!" к каждой строке.*/

/*Напишите программу, в которой пользователь вводит размер массива, 
и программа создает smart-указатель типа unique_ptr и
 инициализирует его динамическим массивом такого размера 
 (пусть массив хранит значения типа int). 
 Инициализируйте все элементы массива так, чтобы значение элемента по индексу i было равно i * i 
 (то есть квадрату числа i). Вычислите сумму элементов и выведите результат на консоль.*/