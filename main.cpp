#include <iostream>
#include "workflow.h"

void print_text(Text *text){
   for(string it : *text){
       cout<<it<<endl;
   }
}


int main() {
    //Config* conf = new Config("C:\\Users\\polov\\CLionProjects\\oop_3\\inp.txt");
    factory fac;
    Text *text = new Text;
    IWorker *reader, *grep, *sorter;
    reader = fac.create_worker(0);
    sorter = fac.create_worker(3);
    string str = "C:\\Users\\polov\\CLionProjects\\oop_3\\inp.txt";
    grep = fac.create_worker(2);
    reader->do_work(text, &str);
    string args = "string";
    Text* ret = grep->do_work(text, &args);
    sorter->do_work(text, &args);
    print_text(text);
    return 0;
}
