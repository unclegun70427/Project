#include <iostream>
#include"NODE.h"
#include"LL.h"
using namespace std;

LL::LL(){

    hol = NULL;
    size = 0;

}

LL::~LL(){

    Menu* t=hol,*temp;
    int i;
    for(i=0;i<size;i++){
        temp=t;
        t=t->move_next();
        delete (temp);
    }

}

void LL::AddMenu(Menu *&t){

    hol->insert(t);
    hol=t;
    size++;

}
