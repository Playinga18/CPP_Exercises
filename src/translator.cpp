#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

std::set<std::string>make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}

std::string add(std::map<std::string, std::string>& res,std::string w1, std::string w2 ){
    res.insert(std::make_pair(w1, w2));
    std::cout << w1 + " => " + w2 << std::endl;
    return (w1 + " " + w2);
}

std::string translateOne(std::map<std::string, std::string> res, std::string w1) {
    if (res.count(w1)){
        return res[w1];
    }
    return "???";
}

void translate(std::map<std::string, std::string> res){
    std::string word;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    while (ss >> word){
        std::cout << translateOne(res, word) << " ";
    }
    std::cout << std::endl;
}

void print(std::map<std::string, std::string> res){
    for (auto& entry: res){
        std::cout << entry.first << " : " << entry.second << std::endl;
    }
}

void save(std::vector<std::string> history, std::string name){
    std::ofstream outFile(name);
    for (auto& line: history){
        outFile << line << std::endl;
    }
    outFile.close();
    std::cout << name << std::endl;
}

void load(std::vector<std::string>& history,std::map<std::string, std::string>& res ,std::string name){
    std::string line;
    std::ifstream file(name);
    std::string w1;
    std::string w2;
    while (std::getline(file, line)) {
        history.insert(history.begin(), line);
        std::stringstream ss(line);
        ss >> w1 >> w2;
        add(res, w1, w2);
    }
    file.close();
}

int main()
{
    auto exit = make_exit_commands();
    std::string command;
    std::string word1;
    std::string word2;
    std::map<std::string, std::string> res;
    std::vector<std::string> history;
    while (!exit.count(command)) {
        std::cin >> command;

        if (command == "add") {
            std::cin >> word1 >> word2;
            history.insert(history.begin(),  add(res, word1, word2));
        }else if (command == "translate"){
            translate(res);
        }else if (command == "print"){
            print(res);
        }else if (command == "save"){
            std::cin >> command;
            save(history, command);
        }else if (command == "load"){
            std::cin >> command;
            load(history, res, command);
        }else if (command == "clear"){
            history.clear();
        }
    }
    return 0;
}