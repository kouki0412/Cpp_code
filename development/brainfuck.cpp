#include<fstream>
#include<iostream>
#include<cstdio>
#include<cassert>
#include<stack>
#define MAXSIZE 300000

int main(){
    unsigned char command[MAXSIZE];
    unsigned char pointer[MAXSIZE];
    int com = 0;
    int itr = 0;
    std::stack<char>loops;
    const char* filename = "sourcecode.txt";
    //std::ofstream ofs(filename);
    std::ifstream ifs(filename);
    while(true){
        if(ifs.eof()) break;
        unsigned char input = ifs.get();
        if(input=='+' or input=='-' or input=='<' or input=='>' or input==',' or input=='.' or input=='[' or input==']'){
            command[com] = input; com++;
        }
    }
    com = 0;
    while(command[com]){
        switch (command[com]){
            case '+':
                pointer[itr]++;
                break;
            case '-':
                pointer[itr]--;
                break;
            case '<':
                assert(itr>0);
                itr--;
                break;
            case '>':
                itr++;
                break;
            case ',':
                std::cin >> pointer[itr];
                break;
            case '.':
                std::cout << pointer[itr];
                break;
            case '[':
                if(pointer[itr]==0){
                    int depth = 1;
                    while(depth>0){
                        com++;
                        if(command[com]=='[') depth++;
                        if(command[com]==']') depth--;
                    }
                }
                else loops.push(itr);
                break;
            case ']':
                com = loops.top()-1;
                loops.pop();
                break;
            default:
                continue;
        }
        com ++;
    }
}
