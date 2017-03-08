#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

void lexSort(std::vector<std::string>& text, const unsigned int n);
void substringSearch(std::vector<std::string>& text, const unsigned int n, std::string s);

int main(int argc, char* argv[]){
    
    std::ifstream myFile;

    std::string line;
    std::vector<std::string> text;

    myFile.open("testfile.txt");

    while ( getline(myFile,line)){
        text.push_back(line);   
    }
    myFile.close();


    for(int i = 0; i < 3; i++){
        lexSort(text, i);
        std::cout << *text.begin() << std::endl;
    }

    std::cout << std::endl;

    substringSearch(text, 1, "a");
}

void lexSort(std::vector<std::string>& text, const unsigned int n){
    
    auto compFunc = [n](std::string a, std::string b)->int{
        return a.substr(n, a.size()) < (b.substr(n, b.size()));
    };

    std::sort(text.begin(), text.end(), compFunc);
}

void substringSearch(std::vector<std::string>& text, const unsigned n, std::string s){

    std::for_each(text.begin(), text.end(),[s,n](std::string &str){
        if(std::string::npos != (str.find(s,n))){
            std::cout << str << std::endl;
        }
    });

}