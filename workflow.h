//
// Created by polov on 15.11.2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <ostream>

#define MIN(X,Y) ((X<Y) ? X : Y)

using namespace std;

typedef vector<string> Text;

class Config{
private:
    ifstream file;

    vector<pair<int,pair<int,string>>> dict_IDs; // <ID in input file<ID workers_ID, args>>
    struct block{
        int id;
        int blocks_name;
        string args;
    };
    block get_block_from_str(string str);
public:
    Config(const string& input);
    void read_desc();
    void read_csed();
    int return_count();
};

class IWorker{
protected:
    //static vector<string> text;
public:
    virtual Text* do_work(Text *text, string *args);
};

class readfile : public IWorker{
private:
    //vector<string>* argparse (string *args);
public:
    Text* do_work(Text *text, string *args) override;
};

class writefile : public IWorker{

public:
    Text* do_work(Text *text, string *args) override;
};

class grep : public IWorker{
private:
    bool contains(string str, string word);
public:
    Text* do_work(Text *text, string *args) override;
};

class sort : public IWorker{
private:
    static bool comp(string a, string b);
public:
    Text* do_work(Text *text, string *args) override;
};

class replace : public IWorker{

public:
    Text* do_work(Text *text, string *args) override;
};
/*
class dump : public IWorker{

public:
    Text* do_work(Text *text, string *args) override;
};
*/
class factory{
public:
    IWorker* create_worker(int ind);
};

