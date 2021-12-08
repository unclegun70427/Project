#include<iostream>
#include "NODE.h"

using namespace std;

Menu::Menu(char x[], int y){
      name=x;
      time = y;
      next=NULL;
      //cout<<x<<endl<<endl;
}

Menu::~Menu(){
    //cout<<name<<" is done and ready to delivery!";
}

Menu* Menu::move_next(){
    return next;
}

void Menu::insert(Menu*& t){
     t->next=this;
}
