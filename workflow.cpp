//
// Created by polov on 15.11.2021.
//
#include <algorithm>
#include "workflow.h"

void Config::read_desc() { //not finished yet
    string str;

    getline(file, str);
    if(str!="desc"){
        while(str!="desc" && file){
            getline(file, str);
        }
    }
    getline(file, str);
    while(str != "csed"){

        getline(file, str);
    }
}

Config::block Config::get_block_from_str(string str) {//not finished yet
    block temp;


    return temp;
}

void Config::read_csed() {//not finished yet
    string str;
    getline(file, str);
}

Config::Config(const string& input) {
    file.open(input, ifstream::in);

}

IWorker *factory::create_worker(int ind) {
    IWorker *worker = nullptr;
    switch (ind) {
        case 0:
            worker = new readfile;
            break;
        case 1:
            worker = new writefile;
            break;
        case 2:
            worker = new grep;
            break;
        case 3:
            worker = new ::sort;
            break;
        case 4:
            //worker = new replace;
            break;
        case 5:
            //worker = new dump;
            break;
        default:
            throw invalid_argument("");
    }
    return worker;
}

Text* readfile::do_work(Text *text, string *args) {
    string path = *args;
    ifstream file;
    file.open(path, ifstream::in);
    if (!file.is_open())
        throw invalid_argument("file isn't open");
    for (string str; getline(file, str); )
    {
        text->push_back(str);
        //cout<<str<<endl;
    }
    return text;
}

Text* IWorker::do_work(Text *text, string *args) {

}

Text* writefile::do_work(Text *text, string *args) {
    string path = *args;
    ofstream file;
    file.open(path);
    if (!file.is_open())
        throw invalid_argument("file isn't open");
    for (const auto& it : *text){
        cout << it << "\n";
        //file << it << "\n";
    }
    file.close();
}

bool grep::contains(string str, string word) {
    int i, j;
    for (i = 0; i < str.size(); i++){
        if (str[i] == word[0]) {
            for (j = 1; j < word.size(); j++){
                if (i+j>=str.size())
                    return false;
                if (str[i+j]!=word[j])
                    break;
                if(j == word.size()-1)
                    return true;
            }
            i += j;
        }
    }
    return false;
}

Text* grep::do_work(Text *text, string *args) {
    Text* returns = new Text;
    string word = *args;
    for (string str : *text){
        if(contains(str, word)){
            returns->push_back(str);
            //cout<<str<<"\n";
        }
    }
    return returns;
}

bool sort::comp(string a, string b) {
        return (a.compare(b) < 0);

}

Text *sort::do_work(Text *text, string *args) {
   std::sort(text->begin(), text->end(), comp);
    return text;
}

Text* replace::do_work(Text *text, string *args) {


}
