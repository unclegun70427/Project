#include <iostream>
#include "gotoXY.h"
using namespace std;

class Ingredient{
public:
    Ingredient();
    //int wasted=0;
    /*virtual void fry() = 0;
    virtual void boil() = 0;
    virtual void bake() = 0;*/
    void waste();
    ~Ingredient();
};

class Meat:public Ingredient{
public:
    Meat();
    ~Meat();
};

Meat::Meat(){

}

Meat::~Meat(){

    //cout<<"Meat is gone."<<endl;

}

class EGG:public Meat{
public:
    int fried = 0, boiled = 0, baked = 0;
    int time=10;
    EGG();
    void fry();
    void boil();
    void bake();
    ~EGG();

};

EGG::EGG(){

    gotoXY(98,42);  cout<<"     ,'\"`.     "<<endl;
    gotoXY(98,43);  cout<<"    /     \\    "<<endl;
    gotoXY(98,44);  cout<<"   :       :    "<<endl;
    gotoXY(98,45);  cout<<"   :       :    "<<endl;
    gotoXY(98,46);  cout<<"    '.___,'     "<<endl;

}

void EGG::fry(){

    if(fried==0 && boiled == 0 && baked == 0){
        gotoXY(98,37);  cout<<"       ▄▄▄▄▄▄▄▄       "<<endl;
        gotoXY(98,38);  cout<<"    ▄████████████▄    "<<endl;
        gotoXY(98,39);  cout<<"  ▄████░░░░░░██████▄  "<<endl;
        gotoXY(98,40);  cout<<" ▄████░█░░░░█░██████▄ "<<endl;
        gotoXY(98,41);  cout<<" ████░░░░░░█░░░██████ "<<endl;
        gotoXY(98,42);  cout<<" █████░░░░░░░░███████ "<<endl;
        gotoXY(98,43);  cout<<" ▀██████░░░░████████  "<<endl;
        gotoXY(98,44);  cout<<"  ▀███████████████▀   "<<endl;
        gotoXY(98,45);  cout<<"    ▀██████████▀▀     "<<endl;
        gotoXY(98,46);  cout<<"        ▀▀▀▀▀         "<<endl;

    }else{
        waste();
    }

    fried = 1;

}

void EGG::boil(){

    if(boiled==0 && fried == 0 && baked == 0){

        gotoXY(98,42);  cout<<"     ▄███▄      "<<endl;
        gotoXY(98,43);  cout<<"    ███████     "<<endl;
        gotoXY(98,44);  cout<<"   ███████░█    "<<endl;
        gotoXY(98,45);  cout<<"   ██████░██    "<<endl;
        gotoXY(98,46);  cout<<"    ▀▀███▀▀     "<<endl;

    }else{
        waste();
    }

    boiled = 1;

}

void EGG::bake(){

    if(boiled==0 && fried == 0 && baked == 0){

        gotoXY(98,41);  cout<<"   ▄▄███████████▄▄   "<<endl;
        gotoXY(98,42);  cout<<" ▄███▀██▄██████▀███▄ "<<endl;
        gotoXY(98,43);  cout<<" █▀████████▄██████▀█ "<<endl;
        gotoXY(98,44);  cout<<" █   ▀▀▀█████▀▀▀   █ "<<endl;
        gotoXY(98,45);  cout<<"  █               █  "<<endl;
        gotoXY(98,46);  cout<<"   ▀▄▄         ▄▄▀   "<<endl;
        gotoXY(98,47);  cout<<"      ▀▀▀▀▀▀▀▀▀      "<<endl;

    }else{
        waste();
    }

    baked = 1;

}

EGG::~EGG(){

    gotoXY(70,37);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,38);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,39);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,40);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,41);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,42);   cout<<" █ ▄▀▄                                                              █ "<<endl;
    gotoXY(70,43);   cout<<" █ █ █                      TOSSING YOUR EGG                        █ "<<endl;
    gotoXY(70,44);   cout<<" █ █ █                        IN THE TRASH                          █ "<<endl;
    gotoXY(70,45);   cout<<" █ █ █                                                              █ "<<endl;
    gotoXY(70,46);   cout<<" █  ▀                                                               █ "<<endl;
    gotoXY(70,47);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,48);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,49);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,50);   cout<<" █                                                                  █ "<<endl;

}

class Carb:public Ingredient{
public:
    Carb();
    ~Carb();
};

Carb::Carb(){



}

Carb::~Carb(){

    //cout<<"Carb is gone."<<endl;

}

class Dough:public Carb{
public:
    int fried = 0,boiled=0,baked = 0;
    int time=20;
    Dough();
    void fry();
    void boil();
    void bake();
    ~Dough();

};

Dough::Dough(){

    gotoXY(98,42);  cout<<"     _______     "<<endl;
    gotoXY(98,43);  cout<<"   ,'       ',   "<<endl;
    gotoXY(98,44);  cout<<" ,'           ', "<<endl;
    gotoXY(98,45);  cout<<" ',___________,' "<<endl;
    gotoXY(98,46);  cout<<"                 "<<endl;

}

void Dough::fry(){

    if(fried==0 && baked == 0 && boiled ==0){
        gotoXY(98,37);  cout<<"       ▄▄▄▄▄▄▄       "<<endl;
        gotoXY(98,38);  cout<<"    ▄███████████▄    "<<endl;
        gotoXY(98,39);  cout<<"  ▄███████████████▄  "<<endl;
        gotoXY(98,40);  cout<<" ▄███████▀▀▀███████▄ "<<endl;
        gotoXY(98,41);  cout<<" ███████░░░░░███████ "<<endl;
        gotoXY(98,42);  cout<<" ████████▄▄▄████████ "<<endl;
        gotoXY(98,43);  cout<<" █ ███████████████ █ "<<endl;
        gotoXY(98,44);  cout<<" ▀▄ █▀█████████▀█ ▄▀ "<<endl;
        gotoXY(98,45);  cout<<"  ▀▄   █ ▀  █    ▄▀  "<<endl;
        gotoXY(98,46);  cout<<"    ▀▀▄▄▄▄▄▄▄▄▄▀▀    "<<endl;

    }else{
        waste();
    }

    fried = 1;

}

void Dough::boil(){

    waste();
    boiled = 1;

}

void Dough::bake(){

    if(fried==0 && baked==0){
        gotoXY(96,41);  cout<<"        ▄▄▄▄▄▄▄▄        "<<endl;
        gotoXY(96,42);  cout<<"   ▄▄▀▀▀ ▄   ▄  ▀▀▀▄▄   "<<endl;
        gotoXY(96,43);  cout<<" ▄▀   ▄    ▄    ▄    ▀▄ "<<endl;
        gotoXY(96,44);  cout<<" ▀▄▄                ▄▄▀ "<<endl;
        gotoXY(96,45);  cout<<"    ▀▀▀▄▄▄▄▄▄▄▄▄▄▀▀▀    "<<endl;

    }else{
        waste();
    }

    baked = 1;

}

Dough::~Dough(){

    gotoXY(70,37);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,38);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,39);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,40);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,41);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,42);   cout<<" █ ▄▀▄                                                              █ "<<endl;
    gotoXY(70,43);   cout<<" █ █ █                     TOSSING YOUR DOUGH                       █ "<<endl;
    gotoXY(70,44);   cout<<" █ █ █                        IN THE TRASH                          █ "<<endl;
    gotoXY(70,45);   cout<<" █ █ █                                                              █ "<<endl;
    gotoXY(70,46);   cout<<" █  ▀                                                               █ "<<endl;
    gotoXY(70,47);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,48);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,49);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,50);   cout<<" █                                                                  █ "<<endl;

}

class Bread:public Carb{
public:
    int fried = 0,boiled=0,baked=0;
    int time=30;
    Bread();
    void fry();
    void boil();
    void bake();
    ~Bread();

};

Bread::Bread(){

    gotoXY(98,40);  cout<<"    _ _ _ _ _ _ _    "<<endl;
    gotoXY(98,41);  cout<<"  ,'\" \" \" \"',    '\\  "<<endl;
    gotoXY(98,42);  cout<<"  ',       ,'____ /  "<<endl;
    gotoXY(98,43);  cout<<"   |       ; ' ' |   "<<endl;
    gotoXY(98,44);  cout<<"   |       ;     |   "<<endl;
    gotoXY(98,45);  cout<<"   ',_____,'____,'   "<<endl;

}

void Bread::fry(){

    if(fried==0 && baked == 0 && boiled ==0){

        gotoXY(99 ,39);   cout<<" ▄▄▄▄▄▄▄▄▄ "<<endl;
        gotoXY(98 ,40);  cout<<" █ ░ ░ ░ ░░█ "<<endl;
        gotoXY(99 ,41);   cout<<" █░ ░ ░ ░█ "<<endl;
        gotoXY(99 ,42);   cout<<" █░ ░ ░ ░█ "<<endl;
        gotoXY(99 ,43);   cout<<" █░ ░ ░ ░█ "<<endl;
        gotoXY(100,44);    cout<<" ▀▀▀▀▀▀▀ "<<endl;

    }else{
        waste();
    }

    fried = 1;

}

void Bread::boil(){

    waste();
    boiled = 1;

}

void Bread::bake(){

    if(fried==0 && baked == 0 && boiled ==0){

        gotoXY(99 ,39);   cout<<" ░▄▄▄▄▄▄▄▄▄░ "<<endl;
        gotoXY(98 ,40);  cout<<" ░█░░░░░░░░░█░ "<<endl;
        gotoXY(99 ,41);   cout<<" ░█░░░░░░░█░ "<<endl;
        gotoXY(99 ,42);   cout<<" ░█░░░░░░░█░ "<<endl;
        gotoXY(99 ,43);   cout<<" ░█░░░░░░░█░ "<<endl;
        gotoXY(100,44);    cout<<" ░▀▀▀▀▀▀▀░ "<<endl;

    }else{
        waste();
    }

    baked = 1;

}

Bread::~Bread(){

    gotoXY(70,37);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,38);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,39);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,40);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,41);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,42);   cout<<" █ ▄▀▄                                                              █ "<<endl;
    gotoXY(70,43);   cout<<" █ █ █                     TOSSING YOUR BREAD                       █ "<<endl;
    gotoXY(70,44);   cout<<" █ █ █                        IN THE TRASH                          █ "<<endl;
    gotoXY(70,45);   cout<<" █ █ █                                                              █ "<<endl;
    gotoXY(70,46);   cout<<" █  ▀                                                               █ "<<endl;
    gotoXY(70,47);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,48);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,49);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,50);   cout<<" █                                                                  █ "<<endl;

}

Ingredient::Ingredient(){

}

Ingredient:: ~Ingredient(){
      //cout<<"Ingredients are gone"<<endl;
}

void Ingredient::waste(){

    gotoXY(98,42);  cout<<"     ▄   ▄▄▄  ▀       "<<endl;
    gotoXY(98,43);  cout<<"  ▀   ▄▄█████░▄  ▄    "<<endl;
    gotoXY(98,44);  cout<<"   ▄▄███████░███▄▄    "<<endl;
    gotoXY(98,45);  cout<<" ▄█████░███████████▄▄ "<<endl;

}
