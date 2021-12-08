#include <iostream>
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <graphics.h>
#include <fstream>
#include "ingre.h"
#include "NODE.h"
#include "LL.h"

void kitchen();
int kitchen_play(string);
void pan();
void pot();
void bake();
void table();
void plate(int);
void deliver();
void vegetable();
void button(int,int);
void digitalnumber(int,int,int);
void scoring(int,int);
void roll(int,int,string);
void blank();

void Kai(int,int);
void Kaidow(int,int);
void Kaitom(int,int);
void Kaitoon(int,int);

void Pang(int,int);
void Donut(int,int);
void Cookie(int,int);

void Kanompang(int,int);
void Pangping(int,int);
void PangOb(int,int);

using namespace std;

int isEgg=0,isDough=0,isBread=0;

void kitchen(){
system ("CLS");

gotoXY(50,10); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█             "<<endl;
gotoXY(50,11); cout<<"█         |               |════════════════| |                                                          █             "<<endl;
gotoXY(50,12); cout<<"█         |              /                  \\ \\                       ╔════════════╦════════════╗       █             "<<endl;
gotoXY(50,13); cout<<"█         |             /════════════════════\\/╝                      ║            ║            ║       █             "<<endl;
gotoXY(50,14); cout<<"█         |            ╚══════════════════════╝                       ║            ║            ║       █             "<<endl;
gotoXY(50,15); cout<<"█         |                                                           ║            ║            ║       █             "<<endl;
gotoXY(50,16); cout<<"█         |                                                           ║════════════╬════════════╣       █             "<<endl;
gotoXY(50,17); cout<<"█         |                                                           ║            ║            ║       █             "<<endl;
gotoXY(50,18); cout<<"█         |                                                           ║            ║            ║       █             "<<endl;
gotoXY(50,19); cout<<"█         |                                                           ║            ║            ║       █             "<<endl;
gotoXY(50,20); cout<<"█         |             _____________________                         ╚════════════╩════════════╝       █             "<<endl;
gotoXY(50,21); cout<<"█         |            (                     )                                                          █             "<<endl;
gotoXY(50,22); cout<<"█         |____________|_____________________|__________________________________________________________█             "<<endl;
gotoXY(50,23); cout<<"█         |═══════════/═════════════════════/═══════════════════════════════════════════════════════════█             "<<endl;
gotoXY(50,24); cout<<"█        /|══════════(@____@____@____@____@_)════════════╦════════════╦════════════╦════════════╦═══════█             "<<endl;
gotoXY(50,25); cout<<"█      /  |    O     ║══╬════════════════╬══╣     O      ║     O      ║            ║            ║  ═════█             "<<endl;
gotoXY(50,26); cout<<"█    /    |          ║  ║                ║  ║            ║            ║         ╔  ║  ╗         ║       █             "<<endl;
gotoXY(50,27); cout<<"█  /      |══════════╣  ║                ║  ║════════════╬════════════╣         ╚  ║  ╝         ║       █             "<<endl;
gotoXY(50,28); cout<<"█/        |    O     ║  ║                ║  ║     O      ║     O      ║            ║            ║       █             "<<endl;
gotoXY(50,29); cout<<"█         |          ║══╬════════════════╬══╣            ║            ║            ║            ║       █             "<<endl;
gotoXY(50,30); cout<<"█         |══════════╣  ║                ║  ║════════════╬════════════╣            ║            ║	  █             "<<endl;
gotoXY(50,31); cout<<"█         |    O     ║  ║                ║  ║     O      ║     O      ║            ║            ║       █             "<<endl;
gotoXY(50,32); cout<<"█         |          ║  ╚════════════════╝  ║            ║            ║            ║            ║       █             "<<endl;
gotoXY(50,33); cout<<"█         |══════════╩══════════════════════╩════════════╩════════════╩════════════╩════════════╩═══════█             "<<endl;
gotoXY(50,34); cout<<"█         |                                                                                             █             "<<endl;
gotoXY(50,35); cout<<"█         |                                                                                             █             "<<endl;
gotoXY(50,36); cout<<"█         /                                                                                             █             "<<endl;
gotoXY(50,37); cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█             "<<endl;

}

int kitchen_play(string n){

    system ("CLS");

    int round = 1, i=0;
    clock_t start,startfry,startboil,startbake;
    double duration;

    start = clock();

    EGG *putegg;
    Dough *putdough;
    Bread *putbread;
    LL A;
    Menu *t;

    int x=20,running=1,dur=0,menu_item=1,wasted =0 ,ontable=0,temptime,frying=0,boiling=0,baking=0,delivering=0,k,y,num=0;
    string name,food;
    int fryegg=0,boilegg=0,bakeegg=0;
    int frydough=0,boildough=0,bakedough=0;
    int frybread=0,boilbread=0,bakebread=0;
    int score = 0;
    // time == 60
{

                         //012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789       //156
    gotoXY(25,15);  cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█             "<<endl;
    gotoXY(25,16);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,17);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,18);  cout<<"█                                                                                                                                 ║         ,'\"`.          █             "<<endl;
    gotoXY(25,19);  cout<<"█                                                                                                                                 ║        /     \\         █             "<<endl;
    gotoXY(25,20);  cout<<"█                                                                                                                                 █       :       :        █             "<<endl;
    gotoXY(25,21);  cout<<"█                                                                                                                                 ║       :       :        █             "<<endl;
    gotoXY(25,22);  cout<<"█                                                                                                                                 ║        `.___,'         █             "<<endl;
    gotoXY(25,23);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,24);  cout<<"█                                                                                                                                 ║        [ EGG ]         █             "<<endl;
    gotoXY(25,25);  cout<<"█                                                                                                                                 ╬════════════════════════█             "<<endl;
    gotoXY(25,26);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,27);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,28);  cout<<"█                                                                                                                                 ║        _______         █             "<<endl;
    gotoXY(25,29);  cout<<"█                                                                                                                                 ║      ,'       ',       █             "<<endl;
    gotoXY(25,30);  cout<<"█                                                                                                                                 █    ,'           ',     █             "<<endl;
    gotoXY(25,31);  cout<<"█                                                                                                                                 ║    ',___________,'     █             "<<endl;
    gotoXY(25,32);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,33);  cout<<"█                                                                                                                                 ║       [ FLOUR ]        █             "<<endl;
    gotoXY(25,34);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,35);  cout<<"█                                                                                                                                 ╬════════════════════════█             "<<endl;
    gotoXY(25,36);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,37);  cout<<"█                                                                                                                                 ║     _ _ _ _ _ _ _      █             "<<endl;
    gotoXY(25,38);  cout<<"█                                                                                                                                 ║   ,'\" \" \" \"',    '\\    █             "<<endl;
    gotoXY(25,39);  cout<<"█                                                                                                                                 ║   ',       ,'____ /    █             "<<endl;
    gotoXY(25,40);  cout<<"█                                                                                                                                 █    |       ; ' ' |     █             "<<endl;
    gotoXY(25,41);  cout<<"█                                                                                                                                 ║    |       ;     |     █             "<<endl;
    gotoXY(25,42);  cout<<"█                                                                                                                                 ║    ',_____,'____,'     █             "<<endl;
    gotoXY(25,43);  cout<<"█                                                                                                                                 ║                        █             "<<endl;
    gotoXY(25,44);  cout<<"█                                                                                                                                 ║       [ BREAD ]        █             "<<endl;
    gotoXY(25,45);  cout<<"█                                                                                                                                 ╬════════════════════════█             "<<endl;
    gotoXY(25,46);  cout<<"█                                                                                                                                 ║ ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ █             "<<endl;
    gotoXY(25,47);  cout<<"█                                                                                                                                 ║ ██████████████████████ █             "<<endl;
    gotoXY(25,48);  cout<<"█                                                                                                                                 ║ ██████▀▀▀▀▀▀▀▀▀▀██████ █             "<<endl;
    gotoXY(25,49);  cout<<"█                                                                                                                                 ║ ██████  TRASH   ██████ █             "<<endl;
    gotoXY(25,50);  cout<<"█                                                                                                                                 █ ██████   CAN    ██████ █             "<<endl;
    gotoXY(25,51);  cout<<"█                                                                                                                                 ║ ██████████████████████ █             "<<endl;
    gotoXY(25,52);  cout<<"█                                                                                                                                 ║ ██████████████████████ █             "<<endl;
    gotoXY(25,53);  cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█             "<<endl;

    gotoXY(186,6 ); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
    gotoXY(186,7 ); cout<<"█ ╔══ ╔═╗ ╔═╗ ╔═╗ ╔═╗ █"<<endl;
    gotoXY(186,8 ); cout<<"█ ╚═╗ ║   ║ ║ ║═╝ ╬═  █"<<endl;
    gotoXY(186,9 ); cout<<"█ ══╝ ╚═╝ ╚═╝ ╚ ╚ ╚═╝ █"<<endl;
    gotoXY(186,10); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
    gotoXY(186,11); cout<<"█ ╔═╗ ╔═╗ ╔═╗ ╔═╗ ╔═╗ █"<<endl;
    gotoXY(186,12); cout<<"█ ╬═╣ ╬═╣ ╬═╣ ╬═╣ ╬═╣ █"<<endl;
    gotoXY(186,13); cout<<"█ ╚═╝ ╚═╝ ╚═╝ ╚═╝ ╚═╝ █"<<endl;
    gotoXY(186,14); cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;

    scoring(score,1);

    table();    pan();  pot();  bake(); deliver();  plate(0);
}

    gotoXY(72,16);  cout<<"╔═════════════════════════════════════════════════════════════╗";
    gotoXY(72,17);  cout<<"║                            TIME                             ║";
    gotoXY(72,18);  cout<<"╚═════════════════════════════════════════════════════════════╝";

    srand(time(NULL));

    for(k=0;k<3;k++){
        num = (rand() % 7)+1;
        gotoXY(1,11+k);  //cout<<"randnum = "<<num<<"\t";
        switch(num){
            case 1 : t = new Menu("Fried Egg",10);      break;
            case 2 : t = new Menu("Donut",20);          break;
            case 3 : t = new Menu("Fried Bread",30);    break;
            case 4 : t = new Menu("Boiled Egg",10);     break;
            case 5 : t = new Menu("Cookie",20);         break;
            case 6 : t = new Menu("Baked Bread",30);    break;
            case 7 : t = new Menu("Steamed Egg",10);    break;
        }
        A.AddMenu(t);
    }

    t = A.hol;
    gotoXY(151,20); cout << ">>>";

    while(round<=3){

        ontable = 0;
        wasted = 0;
        name = A.hol->name;
        roll(150,89,name);

        button(ontable,wasted);

        if(dur<180)     running=1;
        else            round=99;

        while(running){

            duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
            dur=duration;

            /*gotoXY(75,20); cout<<"printf: "<< duration<<endl;
            gotoXY(75,21); cout<<"printf: "<< dur<<endl;*/

            if(dur!=0)      {gotoXY(73+(dur/3),17);    cout << "█";}

            if(dur>=180)    running = 0;

            if(GetAsyncKeyState(VK_DOWN) && x !=50){
				gotoXY(151,x); cout << "    ";
				x+=10;
				gotoXY(151,x); cout << ">>>";
				menu_item++;
				Sleep(100);
				continue;
			}

            if(GetAsyncKeyState(VK_UP) && x !=20){
				gotoXY(151,x); cout << "    ";
				x-=10;
				gotoXY(151,x); cout << ">>>";
				menu_item--;
				Sleep(100);
				continue;
			}

			if(GetAsyncKeyState(VK_RETURN)& 0x8000 && (ontable==0 || (ontable && menu_item == 4)) && !frying && !boiling &&!delivering){

                switch(menu_item){

                    case 1: {
                        if(ontable !=1 ){
                            ontable = 1;
                            isEgg=1;
                            putegg = new EGG();
                        }
                        break;
                    }

                    case 2: {
                        if(ontable !=1 ){
                            ontable = 1;
                            isDough=1;
                            putdough = new Dough();
                        }
                        break;
                    }

                    case 3: {
                        if(ontable !=1 ){
                            ontable = 1;
                            isBread=1;
                            putbread = new Bread();
                        }
                        break;
                    }

                    case 4: {
                        if(ontable){
                            ontable = 0;
                            if(isEgg)       delete putegg;
                            if(isDough)     delete putdough;
                            if(isBread)     delete putbread;
                            Sleep(1000);

                            table();
                            button(ontable,wasted);
                            isEgg=0;
                            isDough=0;
                            isBread=0;
                            wasted = 0;
                        }
                        break;
                    }

                }

                button(ontable,wasted);

            }

            if(GetAsyncKeyState(0x51) & 0x8000/*Q -> FRY*/ && ontable && !frying && !boiling && !baking && !delivering && !wasted ){ //EGG & DOUGH
                startfry = clock();
                ontable = 0;
                frying = 1;
                button(ontable,wasted);
                table();

                if(isEgg){          // FRY EGG
                    fryegg=1;
                    if(putegg->fried)               Kaidow(34,21);
                    else if(putegg->boiled)         Kaitom(39,24);
                    else if(putegg->baked)          Kaitoon(34,23);
                    else if(putegg->fried == 0)     Kai(39,24);
                }
                else if(isDough){   // FRY DOUGH
                    frydough=1;
                    if(putdough->fried)             Donut(34,21);
                    else if(putdough->baked)        Cookie(33,24);
                    else                            Pang(36,24);
                }
                else if(isBread){
                    frybread=1;
                    if(putbread->fried)             Pangping(38,23);
                    else if(putbread->baked)        PangOb(37,23);
                    else                            Kanompang(35,23);
                }
				continue;
			}

			if(fryegg){
                temptime = ((clock() - startfry / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putegg->time ){
                    //gotoXY(42,30);          cout<<temptime;

                    if(putegg->baked)           gotoXY(41 + (temptime)/2,30);
                    else if(putegg->fried)      gotoXY(41 + (temptime)/2,31);
                    else                        gotoXY(41 + (temptime)/2,29);
                    if(temptime/2 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    fryegg  = 0;
                    frying  = 0;

                    if(putegg->fried || putegg->boiled || putegg->baked)    {
                        wasted = 1;
                        food = "waste";
                    }else   food = "Fried Egg";
                    putegg->fry();
                    button(ontable,wasted);
                }
			}

            if(frydough){
                temptime = ((clock() - startfry / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putdough->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    if(putdough->fried == 0)   gotoXY(39 + (temptime)/2,29);
                    else if(putdough->fried)   gotoXY(39 + (temptime)/2,31);
                    if(temptime/2 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    frydough = 0;
                    frying = 0;

                    if(putdough->fried || putdough->boiled || putdough->baked)    {
                            wasted = 1;
                            food = "waste";
                    }else   food = "Donut";
                    putdough->fry();
                    button(ontable,wasted);
                }
            }

            if(frybread){
                temptime = ((clock() - startfry / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putbread->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    gotoXY(39 + (temptime)/3,29);
                    if(temptime/3 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    frybread = 0;
                    frying = 0;

                    if(putbread->fried || putbread->baked || putbread->boiled)    {
                            wasted = 1;
                            food = "waste";
                    }else   food = "Fried Bread";
                    putbread->fry();
                    button(ontable,wasted);
                }
            }

			if(GetAsyncKeyState(0x57) & 0x8000/*W -> BOIL*/ && ontable && !frying && !boiling && !baking && !delivering && !wasted ){
                startboil = clock();
                ontable = 0;
                boiling = 1;
                button(ontable,wasted);
                table();

                if(isEgg){  // BOIL EGG
                    boilegg=1;
                    if(putegg->boiled)              Kaitom(77,24);
                    else if(putegg->fried)          Kaidow(72,22);
                    else if(putegg->baked)          Kaitoon(72,24);
                    else if(putegg->boiled == 0)    Kai(77,24);
                }else if(isDough){   // BOIL DOUGH
                    boildough=1;
                    if(putdough->fried)             Donut(72,22);
                    else if(putdough->baked)        Cookie(71,24);
                    else                            Pang(74,24);
                }
                else if(isBread){
                    boilbread=1;
                    if(putbread->fried)             Pangping(77,24);
                    else if(putbread->baked)        PangOb(76,24);
                    else                            Kanompang(74,24);
                }

				continue;
			}

			if(boilegg){
                temptime = ((clock() - startboil / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putegg->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    if(putegg->fried)           gotoXY(79 + (temptime)/2,32);
                    else if(putegg->baked)      gotoXY(79 + (temptime)/2,31);
                    else                        gotoXY(79 + (temptime)/2,29);
                    if(temptime/2 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    boilegg = 0;
                    boiling = 0;

                    if(putegg->fried || putegg->boiled || putegg->baked)    {
                            wasted = 1;
                            food = "waste";
                    }else   food = "Boiled Egg";
                    putegg->boil();
                    button(ontable,wasted);
                }
			}

			if(boildough){
                temptime = ((clock() - startboil / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putdough->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    if(putdough->fried)             gotoXY(77 + (temptime)/2,32);
                    else if(putdough->baked)        gotoXY(77 + (temptime)/2,29);
                    else                            gotoXY(77 + (temptime)/2,29);
                    if(temptime/2 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    boildough = 0;
                    boiling = 0;

                    wasted = 1;
                    food = "waste";
                    putdough->boil();
                    button(ontable,wasted);
                }
			}

			if(boilbread){
                temptime = ((clock() - startboil / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putbread->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    gotoXY(78 + (temptime)/3,30);
                    if(temptime/3 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    boilbread = 0;
                    boiling = 0;

                    wasted = 1;
                    food = "waste";
                    putbread->boil();
                    button(ontable,wasted);
                }
			}

			if(GetAsyncKeyState(0x45) & 0x8000/*E -> BAKE*/ && ontable && !frying && !boiling && !baking && !delivering && !wasted ){
                startbake = clock();
                ontable = 0;
                baking = 1;
                button(ontable,wasted);
                table();

                if(isEgg){  // BOIL EGG
                    bakeegg=1;
                    if(putegg->boiled)              Kaitom(122,24);
                    else if(putegg->fried)          Kaidow(117,22);
                    else if(putegg->baked)          Kaitoon(117,23);
                    else if(putegg->baked == 0)     Kai(122,24);
                }else if(isDough){   // BAKE DOUGH
                    bakedough=1;
                    if(putdough->fried)             Donut(117,21);
                    else if(putdough->baked)        Cookie(115,24);
                    else                            Pang(118,24);
                }else if(isBread){
                    bakebread=1;
                    if(putbread->fried)             Pangping(121,25);
                    else if(putbread->baked)        PangOb(118,23);
                    else                            Kanompang(116,23);
                }
				continue;
			}

			if(bakeegg){
                temptime = ((clock() - startbake / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putegg->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    if(putegg->fried)           gotoXY(124 + (temptime)/2,32);
                    else if(putegg->baked)      gotoXY(124 + (temptime)/2,30);
                    else                        gotoXY(124 + (temptime)/2,29);
                    if(temptime/2 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    bakeegg = 0;
                    baking = 0;

                    if(putegg->fried || putegg->boiled || putegg->baked)    {
                            wasted = 1;
                            food = "waste";
                    }else   food = "Steamed Egg";
                    putegg->bake();
                    button(ontable,wasted);
                }
			}

			if(bakedough){
                temptime = ((clock() - startbake / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putdough->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    if(putdough->fried)         gotoXY(122 + (temptime)/2,31);
                    else                        gotoXY(121 + (temptime)/2,29);
                    if(temptime/2 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    bakedough = 0;
                    baking = 0;

                    if(putdough->fried || putdough->baked || putdough-> boiled)    {
                            wasted = 1;
                            food = "waste";
                    }else   food = "Cookie";
                    putdough->bake();
                    button(ontable,wasted);
                }
            }

            if(bakebread){
                temptime = ((clock() - startbake / (double) CLOCKS_PER_SEC*1000)/1000);
                if(temptime <= putbread->time ){
                    //gotoXY(42,30);          cout<<temptime;
                    if(putbread->fried)         gotoXY(122 + (temptime)/3,31);
                    else                        gotoXY(120 + (temptime)/3,29);
                    if(temptime/3 > 0)    cout<<"•";
                }else{
                    table();
                    ontable = 1;
                    bakebread = 0;
                    baking = 0;

                    if(putbread->fried || putbread->baked || putbread->boiled)    {
                            wasted = 1;
                            food = "waste";
                    }else   food = "Baked Bread";
                    putbread->bake();
                    button(ontable,wasted);
                }
            }

            if(GetAsyncKeyState(0x53) & 0x8000 /*S serve platter*/ && ontable ){

                ontable = 0;
                delivering = 1;
                table();
                for(i=0;i<=26;i++){

                    plate(i);

                    if(!wasted){
                        if(isEgg){
                            if(putegg->fried){
                                gotoXY(43,y=47+i);if(y<=68)         cout<<"▄▄▄▄▄▄▄▄"<<endl;
                                gotoXY(41,y=48+i);if(y<=68)      cout<<"▄████████████▄"<<endl;
                                gotoXY(39,y=49+i);if(y<=68)    cout<<"▄████░░░░░░██████▄"<<endl;
                                gotoXY(38,y=50+i);if(y<=68)   cout<<"▄████░█░░░░█░██████▄"<<endl;
                                gotoXY(38,y=51+i);if(y<=68)   cout<<"████░░░░░░█░░░██████"<<endl;
                                gotoXY(38,y=52+i);if(y<=68)   cout<<"█████░░░░░░░░███████"<<endl;
                                gotoXY(38,y=53+i);if(y<=68)   cout<<"▀██████░░░░████████"<<endl;
                                gotoXY(39,y=54+i);if(y<=68)    cout<<"▀███████████████▀"<<endl;
                                gotoXY(40,y=55+i);if(y<=68)      cout<<"▀██████████▀▀"<<endl;
                                gotoXY(43,y=56+i);if(y<=68)          cout<<"▀▀▀▀▀"<<endl;
                            }
                            else if(putegg->boiled){
                                gotoXY(46,y=49+i);if(y<=68)     cout<<"     "<<endl;
                                gotoXY(45,y=50+i);if(y<=68)    cout<<" ▄███▄ "<<endl;
                                gotoXY(44,y=51+i);if(y<=68)   cout<<" ███████ "<<endl;
                                gotoXY(43,y=52+i);if(y<=68)  cout<<" ███████░█ "<<endl;
                                gotoXY(43,y=53+i);if(y<=68)  cout<<" ██████░██ "<<endl;
                                gotoXY(44,y=54+i);if(y<=68)   cout<<" ▀▀███▀▀ "<<endl;
                                gotoXY(45,y=55+i);if(y<=68)    cout<<"       "<<endl;
                            }
                            else if(putegg->baked){
                                gotoXY(40,y=49+i);if(y<=68)    cout<<" ▄▄███████████▄▄ "<<endl;
                                gotoXY(38,y=50+i);if(y<=68)  cout<<" ▄███▀██▄██████▀███▄ "<<endl;
                                gotoXY(38,y=51+i);if(y<=68)  cout<<" █▀████████▄██████▀█ "<<endl;
                                gotoXY(38,y=52+i);if(y<=68)  cout<<" █   ▀▀▀█████▀▀▀   █ "<<endl;
                                gotoXY(39,y=53+i);if(y<=68)   cout<<" █               █ "<<endl;
                                gotoXY(40,y=54+i);if(y<=68)    cout<<" ▀▄▄         ▄▄▀ "<<endl;
                                gotoXY(43,y=55+i);if(y<=68)       cout<<" ▀▀▀▀▀▀▀▀▀ "<<endl;
                            }
                            else if(putegg->fried == 0){
                                gotoXY(46,y=49+i);if(y<=68)     cout<<"     "<<endl;
                                gotoXY(45,y=50+i);if(y<=68)    cout<<" ,'\"`. "<<endl;
                                gotoXY(44,y=51+i);if(y<=68)   cout<<" /     \\ "<<endl;
                                gotoXY(43,y=52+i);if(y<=68)  cout<<" :       : "<<endl;
                                gotoXY(43,y=53+i);if(y<=68)  cout<<" :       : "<<endl;
                                gotoXY(44,y=54+i);if(y<=68)   cout<<" '.___,' "<<endl;
                                gotoXY(45,y=55+i);if(y<=68)    cout<<"       "<<endl;
                            }
                        }
                        else if(isDough){
                            if(putdough->fried){
                                gotoXY(43,y=47+i);if(y<=68)       cout<<"  ▄▄▄▄▄▄▄  "<<endl;
                                gotoXY(41,y=48+i);if(y<=68)     cout<<" ▄███████████▄ "<<endl;
                                gotoXY(39,y=49+i);if(y<=68)   cout<<" ▄███████████████▄ "<<endl;
                                gotoXY(38,y=50+i);if(y<=68)  cout<<" ▄███████▀▀▀███████▄ "<<endl;
                                gotoXY(38,y=51+i);if(y<=68)  cout<<" ███████░░░░░███████ "<<endl;
                                gotoXY(38,y=52+i);if(y<=68)  cout<<" ████████▄▄▄████████ "<<endl;
                                gotoXY(38,y=53+i);if(y<=68)  cout<<" █ ███████████████ █ "<<endl;
                                gotoXY(38,y=54+i);if(y<=68)  cout<<" ▀▄ █▀█████████▀█ ▄▀ "<<endl;
                                gotoXY(39,y=55+i);if(y<=68)   cout<<" ▀▄   █ ▀  █    ▄▀ "<<endl;
                                gotoXY(41,y=56+i);if(y<=68)     cout<<" ▀▀▄▄▄▄▄▄▄▄▄▀▀ "<<endl;
                            }else if(putdough->baked){
                                gotoXY(44,y=50+i);if(y<=68)        cout<<" ▄▄▄▄▄▄▄▄ "<<endl;
                                gotoXY(39,y=51+i);if(y<=68)   cout<<" ▄▄▀▀▀ ▄   ▄  ▀▀▀▄▄ "<<endl;
                                gotoXY(37,y=52+i);if(y<=68) cout<<" ▄▀   ▄    ▄    ▄    ▀▄ "<<endl;
                                gotoXY(37,y=53+i);if(y<=68) cout<<" ▀▄▄                ▄▄▀ "<<endl;
                                gotoXY(40,y=54+i);if(y<=68)    cout<<" ▀▀▀▄▄▄▄▄▄▄▄▄▄▀▀▀ "<<endl;
                            }else{
                                gotoXY(44,y=50+i);if(y<=68)      cout<<" _______ "<<endl;
                                gotoXY(42,y=51+i);if(y<=68)    cout<<" ,'       ', "<<endl;
                                gotoXY(40,y=52+i);if(y<=68)  cout<<" ,'           ', "<<endl;
                                gotoXY(40,y=53+i);if(y<=68)  cout<<" ',___________,' "<<endl;
                            }
                        }
                        else if(isBread){
                            if(putbread->fried){
                                gotoXY(43 ,y=49+i);if(y<=68)   cout<<" ▄▄▄▄▄▄▄▄▄ "<<endl;
                                gotoXY(42 ,y=50+i);if(y<=68)  cout<<" █ ░ ░ ░ ░░█ "<<endl;
                                gotoXY(43 ,y=51+i);if(y<=68)   cout<<" █░ ░ ░ ░█ "<<endl;
                                gotoXY(43 ,y=52+i);if(y<=68)   cout<<" █░ ░ ░ ░█ "<<endl;
                                gotoXY(43 ,y=53+i);if(y<=68)   cout<<" █░ ░ ░ ░█ "<<endl;
                                gotoXY(44 ,y=54+i);if(y<=68)    cout<<" ▀▀▀▀▀▀▀ "<<endl;
                            }else if(putbread->baked){
                                gotoXY(42 ,y=49+i);if(y<=68)   cout<<" ░▄▄▄▄▄▄▄▄▄░ "<<endl;
                                gotoXY(41 ,y=50+i);if(y<=68)  cout<<" ░█░░░░░░░░░█░ "<<endl;
                                gotoXY(42 ,y=51+i);if(y<=68)   cout<<" ░█░░░░░░░█░ "<<endl;
                                gotoXY(42 ,y=52+i);if(y<=68)   cout<<" ░█░░░░░░░█░ "<<endl;
                                gotoXY(42 ,y=53+i);if(y<=68)   cout<<" ░█░░░░░░░█░ "<<endl;
                                gotoXY(43 ,y=54+i);if(y<=68)    cout<<" ░▀▀▀▀▀▀▀░ "<<endl;
                            }else{
                                gotoXY(40,y=50+i);if(y<=68)     cout<<" _ _ _ _ _ _ _ "<<endl;
                                gotoXY(39,y=51+i);if(y<=68)   cout<<" ,'\" \" \" \"',    '\\ "<<endl;
                                gotoXY(39,y=52+i);if(y<=68)   cout<<" ',       ,'____ / "<<endl;
                                gotoXY(40,y=53+i);if(y<=68)    cout<<" |       ; ' ' | "<<endl;
                                gotoXY(40,y=54+i);if(y<=68)    cout<<" |       ;     | "<<endl;
                                gotoXY(40,y=55+i);if(y<=68)    cout<<" ',_____,'____,' "<<endl;
                            }
                        }
                    }else{

                        gotoXY(45,y=51+i);if(y<=68)         cout<<"  ▄▄▄  "<<endl;
                        gotoXY(42,y=52+i);if(y<=68)      cout<<"  ▄▄█████░▄  "<<endl;
                        gotoXY(40,y=53+i);if(y<=68)    cout<<" ▄▄███████░███▄▄ "<<endl;
                        gotoXY(38,y=54+i);if(y<=68)  cout<<" ▄█████░███████████▄▄ "<<endl;

                    }

                    if(i==0)    Sleep(1000);
                    if(i>=20)   deliver();
                    if(i>=7)
                    Sleep(10);  gotoXY(25,53);  cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
                }
                deliver();
                plate(0);

                Sleep(50);

                if(food.compare(A.hol->name)==0){
                    score+=3000;
                    scoring(score,1);
                    roll(89,26,name);
                    blank();
                    Menu *temp;
                    temp = A.hol;
                    A.hol = temp->move_next();
                    delete temp;
                    round++;
                    running=0;
                }else{
                    if(food.compare("waste")==0){
                        if(score>=3000)     score-=3000;
                        else                score = 0;
                    }else{
                        if(score>=1000)     score-=1000;
                        else                score = 0;
                    }
                    scoring(score,1);
                }

                if(A.hol == NULL)   break;

                isEgg=0;    isDough=0;  isBread=0;  wasted = 0; delivering = 0; table();    button(ontable,wasted);
            }

            //if(GetAsyncKeyState(VK_ESCAPE) & 0x8000 /*ESC PAUSE*/ && !frying && !boiling && !baking && !delivering ){

            /*    for(i=0;i<=2;i++){
                    gotoXY(5,k=i  ); if(k>0)    cout<<"                        "<<endl;
                    gotoXY(5,k=i+1); if(k>0)    cout<<" ▄▄▄▄ ▄   ▄ ▄▄▄▄▄ ▄▄▄▄▄ "<<endl;
                    gotoXY(5,k=i+2); if(k>0)    cout<<" █    █   █   █     █   "<<endl;
                    gotoXY(5,k=i+3); if(k>0)    cout<<" █▄▄▄  ▀▄▀    █     █   "<<endl;
                    gotoXY(5,k=i+4); if(k>0)    cout<<" █    ▄▀ ▀▄   █     █   "<<endl;
                    gotoXY(5,k=i+5); if(k>0)    cout<<" █▄▄▄ █   █ ▄▄█▄▄   █   "<<endl;
                    Sleep(10);
                }
                gotoXY(5,9 );         cout<<"  Press ESC again to EXIT    "<<endl;
                gotoXY(5,10);         cout<<"  Press ENTER to resume      "<<endl;

                i=1;

                while(i){

                    system("pause>nul");

                    if(GetAsyncKeyState(VK_ESCAPE) & 0x8000){
                        round=999;
                        dur=999;
                        for(i=2;i>=-7;i--){
                            gotoXY(5,k=i+1); if(k>0)    cout<<" ▄▄▄▄ ▄   ▄ ▄▄▄▄▄ ▄▄▄▄▄ "<<endl;
                            gotoXY(5,k=i+2); if(k>0)    cout<<" █    █   █   █     █   "<<endl;
                            gotoXY(5,k=i+3); if(k>0)    cout<<" █▄▄▄  ▀▄▀    █     █   "<<endl;
                            gotoXY(5,k=i+4); if(k>0)    cout<<" █    ▄▀ ▀▄   █     █   "<<endl;
                            gotoXY(5,k=i+5); if(k>0)    cout<<" █▄▄▄ █   █ ▄▄█▄▄   █   "<<endl;
                            gotoXY(5,k=i+6); if(k>0)    cout<<"                             "<<endl;
                            Sleep(10);
                        }
                        i=0;
                    }

                }

            }*/

            gotoXY(26,52);
        }//end running
    }//end round

    system("CLS");

        for(i=-17;i<=20;i++){

            gotoXY(27,k=i-1);if(k>0)  cout<<"      █ █                                 █ █      "<<endl;
            gotoXY(27,k=i  );if(k>0)  cout<<"   ▄▄▄█▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄█▄▄▄   "<<endl;
            gotoXY(27,k=i+1);if(k>0)  cout<<" ▄▀ ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ ▀▄ "<<endl;
            gotoXY(27,k=i+2);if(k>0)  cout<<"█ ▄▀                                           ▀▄ █"<<endl;
            gotoXY(27,k=i+3);if(k>0)  cout<<"█ █  █   █  █▀▀▀▀          ▄▀▀▄   █▀▀▀▄  █▀▀▀▀  █ █"<<endl;
            gotoXY(27,k=i+4);if(k>0)  cout<<"█ █  █ █ █  █▄▄▄▄         █    █  █▄▄▄▀  █▄▄▄▄  █ █                                                                              █ █             "<<endl;
            gotoXY(27,k=i+5);if(k>0)  cout<<"█ █  █ █ █  █             █▀▀▀▀█  █   █  █      ▀▄ ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄     "<<endl;
            gotoXY(27,k=i+6);if(k>0)  cout<<"█ █   ▀ ▀   ▀▀▀▀▀         ▀    ▀  ▀   ▀  ▀▀▀▀▀    ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄ ▀▄   "<<endl;
            gotoXY(27,k=i+7);if(k>0)  cout<<"▀▄ ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄         ▄▄▄▄▄▄▄▄           ▄▄            ▄▄▄▄▄▄          ▄▄▄▄▄▄▄▄          ▄▄▄▄▄▄▄▄▄    ▄▄▄▄▄▄▄▄▄▄    ▀▄ ▀▄ "<<endl;
              gotoXY(29,k=i+8);if(k>0)  cout<<"▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄  ▀▄    ▄████████████▄       ████        ▄██████████▄     ▄██████████       ████████████  ▄███████████▄    █ █ "<<endl;
                                              gotoXY(61,k=i+9);if(k>0)  cout<<"█ ▄▀    ███▀       ▀██      ████        ███▀      ▀███    ███▀             ████▀          ███▀     ▀███▄   ▀▄ █"<<endl;
                                              gotoXY(61,k=i+10);if(k>0) cout<<"█ █    ███                 ▄███▀       ███          ███   ████▄           ▄███▀           ███        ███    █ █"<<endl;
                                              gotoXY(61,k=i+11);if(k>0) cout<<"█ █    ███                 ████        ███          ███    ▀████▄▄        ████████████    ███        ███    █ █"<<endl;
                                              gotoXY(61,k=i+12);if(k>0) cout<<"█ █    ███                ████         ███          ███      ▀▀████▄     ████▀▀▀▀▀▀▀▀     ███        ███    █ █"<<endl;
                                              gotoXY(61,k=i+13);if(k>0) cout<<"█ ▀▄    ███▄       ▄██   ▄███▀          ███▄      ▄███          ▀████   ▄███▀             ███▄     ▄███▀   ▄▀ █"<<endl;
                                               gotoXY(62,k=i+14);if(k>0) cout<<"█ █    ▀████████████▀   ████████████    ▀██████████▀    ████████████   ████████████      ▀███████████▀    █ █"<<endl;
                                               gotoXY(62,k=i+15);if(k>0) cout<<"▀▄ ▀▄     ▀▀▀▀▀▀▀▀       ▀▀▀▀▀▀▀▀▀▀        ▀▀▀▀▀▀        ▀▀▀▀▀▀▀▀▀▀     ▀▀▀▀▀▀▀▀▀▀        ▀▀▀▀▀▀▀▀▀▀    ▄▀ ▄▀"<<endl;
                                                 gotoXY(64,k=i+16);if(k>0) cout<<"▀▄ ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀ ▄▀"<<endl;
                                                   gotoXY(66,k=i+17);if(k>0) cout<<"▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀"<<endl;

    }

    gotoXY(96,40); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
    gotoXY(96,41); cout<<"█ ╔══ ╔═╗ ╔═╗ ╔═╗ ╔═╗ █"<<endl;
    gotoXY(96,42); cout<<"█ ╚═╗ ║   ║ ║ ║═╝ ╬═  █"<<endl;
    gotoXY(96,43); cout<<"█ ══╝ ╚═╝ ╚═╝ ╚ ╚ ╚═╝ █"<<endl;
    gotoXY(96,44); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
    gotoXY(96,45); cout<<"█ ╔═╗ ╔═╗ ╔═╗ ╔═╗ ╔═╗ █"<<endl;
    gotoXY(96,46); cout<<"█ ╬═╣ ╬═╣ ╬═╣ ╬═╣ ╬═╣ █"<<endl;
    gotoXY(96,47); cout<<"█ ╚═╝ ╚═╝ ╚═╝ ╚═╝ ╚═╝ █"<<endl;
    gotoXY(96,48); cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;

    int tempscore=0;
    score += ((180-dur)*50);
    cout<<score<<endl;

    while(tempscore<score){
        Sleep(10);
        if(tempscore+100 >= score)  tempscore = score;
        else                        tempscore +=100;
        scoring(tempscore,2);
    }

    fstream file;
    string un,pw;
    char data[100];
    strcpy(data,n.c_str());
    strcat(data,".txt");
    file.open(data,ios::in|ios::out|ios::app);
    file<<endl<<score;
    file.close();

    return score;

}

void pan(){

    gotoXY(26,19);   cout<<"               ▄▄▄▄▄▄▄                "<<endl;
    gotoXY(26,20);   cout<<"          ▄▄▀▀▀       ▀▀▀▄▄           "<<endl;
    gotoXY(26,21);   cout<<"        ▄▀                 ▀▄         "<<endl;
    gotoXY(26,22);   cout<<"      ▄▀                     ▀▄       "<<endl;
    gotoXY(26,23);   cout<<"     ▄▀                       ▀▄      "<<endl;
    gotoXY(26,24);   cout<<"     █                         █      "<<endl;
    gotoXY(26,25);   cout<<"  █═█                           █═█   "<<endl;
    gotoXY(26,26);   cout<<" ██ █                           █ ██  "<<endl;
    gotoXY(26,27);   cout<<"  █═█                           █═█   "<<endl;
    gotoXY(26,28);   cout<<"     █                         █      "<<endl;
    gotoXY(26,29);   cout<<"      █                       █       "<<endl;
    gotoXY(26,30);   cout<<"       ▀▄                   ▄▀        "<<endl;
    gotoXY(26,31);   cout<<"         ▀▄▄             ▄▄▀          "<<endl;
    gotoXY(26,32);   cout<<"            ▀▀▀▄▄▄▄▄▄▄▀▀▀             "<<endl;
    gotoXY(26,33);   cout<<"                 ║║║                  "<<endl;
    gotoXY(26,34);   cout<<"                 ║║║                  "<<endl;
    gotoXY(26,35);   cout<<"                 ║║║                  "<<endl;
    gotoXY(26,36);   cout<<"                 ███                  "<<endl;
    gotoXY(26,37);   cout<<"                 ███                  "<<endl;
    gotoXY(26,38);   cout<<"                 ███                  "<<endl;
    gotoXY(26,39);   cout<<"                  ▀                   "<<endl;

}

void pot(){

    gotoXY(64,20);   cout<<"               ▄▄▄▄▄▄▄                "<<endl;
    gotoXY(64,21);   cout<<"          ▄▄▀▀▀       ▀▀▀▄▄           "<<endl;
    gotoXY(64,22);   cout<<"        ▄▀                 ▀▄         "<<endl;
    gotoXY(64,23);   cout<<"      ▄▀                     ▀▄       "<<endl;
    gotoXY(64,24);   cout<<"     ▄▀                       ▀▄      "<<endl;
    gotoXY(64,25);   cout<<"     █                         █      "<<endl;
    gotoXY(64,26);   cout<<" ██═█                           █═██  "<<endl;
    gotoXY(64,27);   cout<<" ██ █                           █ ██  "<<endl;
    gotoXY(64,28);   cout<<" ██═█                           █═██  "<<endl;
    gotoXY(64,29);   cout<<"     █                         █      "<<endl;
    gotoXY(64,30);   cout<<"      █                       █       "<<endl;
    gotoXY(64,31);   cout<<"       ▀▄                   ▄▀        "<<endl;
    gotoXY(64,32);   cout<<"         ▀▄▄             ▄▄▀          "<<endl;
    gotoXY(64,33);   cout<<"            ▀▀▀▄▄▄▄▄▄▄▀▀▀             "<<endl;

}

void bake(){

    gotoXY(102,20);   cout<<"      ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄   "<<endl;
    gotoXY(102,21);   cout<<"    ▄▀ ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄ ▀▄ "<<endl;
    gotoXY(102,22);   cout<<"    █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █ "<<endl;
    gotoXY(102,23);   cout<<"    █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █ "<<endl;
    gotoXY(102,24);   cout<<"    █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █ "<<endl;
    gotoXY(102,25);   cout<<"    █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █ "<<endl;
    gotoXY(102,26);   cout<<" ██═█ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █═██ "<<endl;
    gotoXY(102,27);   cout<<" ██ █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █ ██ "<<endl;
    gotoXY(102,28);   cout<<" ██═█ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █═██ "<<endl;
    gotoXY(102,29);   cout<<"    █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █  "<<endl;
    gotoXY(102,30);   cout<<"    █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █  "<<endl;
    gotoXY(102,31);   cout<<"    █ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █  "<<endl;
    gotoXY(102,32);   cout<<"    ▀▄ ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀ ▄▀  "<<endl;
    gotoXY(102,33);   cout<<"      ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀    "<<endl;

}

void table(){

    gotoXY(70,35);   cout<<"   ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄   "<<endl;
    gotoXY(70,36);   cout<<" ▄▀                                                                ▀▄ "<<endl;
    gotoXY(70,37);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,38);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,39);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,40);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,41);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,42);   cout<<" █ ▄▀▄                                                              █ "<<endl;
    gotoXY(70,43);   cout<<" █ █ █                                                              █ "<<endl;
    gotoXY(70,44);   cout<<" █ █ █                                                              █ "<<endl;
    gotoXY(70,45);   cout<<" █ █ █                                                              █ "<<endl;
    gotoXY(70,46);   cout<<" █  ▀                                                               █ "<<endl;
    gotoXY(70,47);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,48);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,49);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,50);   cout<<" █                                                                  █ "<<endl;
    gotoXY(70,51);   cout<<" ▀▄                                                                ▄▀ "<<endl;
    gotoXY(70,52);   cout<<"   ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀   "<<endl;

}

void plate(int i){

    gotoXY(29,42+i);if(i<=26)    cout<<"                                       "<<endl;
    gotoXY(29,43+i);if(i<=25)    cout<<"              ▄▄▄▄▄▄▄▄▄▄▄              "<<endl;
    gotoXY(29,44+i);if(i<=24)    cout<<"      ▄▄▄▀▀▀▀▀           ▀▀▀▀▀▄▄▄      "<<endl;
    gotoXY(29,45+i);if(i<=23)    cout<<"    ▄▀  \\                     /  ▀▄   "<<endl;
    gotoXY(29,46+i);if(i<=22)    cout<<"  ▄▀     \\                   /     ▀▄ "<<endl;
    gotoXY(29,47+i);if(i<=21)    cout<<"  █       \\                 /       █ "<<endl;
    gotoXY(29,48+i);if(i<=20)    cout<<" █         \\               /         █ "<<endl;
    gotoXY(29,49+i);if(i<=18)    cout<<" █          \\  _________  /          █ "<<endl;
    gotoXY(29,50+i);if(i<=18)    cout<<"█            ,'         ',            █"<<endl;
    gotoXY(29,51+i);if(i<=17)    cout<<"█            |           |            █"<<endl;
    gotoXY(29,52+i);if(i<=16)    cout<<"█            |           |            █"<<endl;
    gotoXY(29,53+i);if(i<=15)    cout<<"█            |           |            █"<<endl;
    gotoXY(29,54+i);if(i<=14)    cout<<"█            ',_________,'            █"<<endl;
    gotoXY(30,55+i);if(i<=12)     cout<<"█          /             \\          █"<<endl;
    gotoXY(30,56+i);if(i<=12)     cout<<"█         /               \\         █"<<endl;
    gotoXY(31,57+i);if(i<=11)      cout<<"█       /                 \\       █"<<endl;
    gotoXY(31,58+i);if(i<=10)      cout<<"▀▄     /                   \\     ▄▀"<<endl;
    gotoXY(33,59+i);if(i<=9)         cout<<"▀▄  /                     \\  ▄▀"<<endl;
    gotoXY(35,60+i);if(i<=8)           cout<<"▀▀▀▄▄▄▄▄           ▄▄▄▄▄▀▀▀"<<endl;
    gotoXY(43,61+i);if(i<=7 )                  cout<<"▀▀▀▀▀▀▀▀▀▀▀"<<endl;

}

void deliver(){

    gotoXY(25,54);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,55);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,56);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,57);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,58);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,59);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,60);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,61);  cout<<"║                                             ║ "<<endl;
    gotoXY(25,62);  cout<<"╬═════════════════════════════════════════════╣ "<<endl;
    gotoXY(25,63);  cout<<"║ ▄▄▄▄   ▄▄▄▄▄  ▄    ▄▄▄  ▄   ▄  ▄▄▄▄▄  ▄▄▄▄  ║ "<<endl;
    gotoXY(25,64);  cout<<"║ █   █  █      █     █   █   █  █      █   █ ║ "<<endl;
    gotoXY(25,65);  cout<<"║ █   █  █▄▄▄▄  █     █   █   █  █▄▄▄▄  █▄▄▄▀ ║ "<<endl;
    gotoXY(25,66);  cout<<"║ █   █  █      █     █    █ █   █      █   █ ║ "<<endl;
    gotoXY(25,67);  cout<<"║ █▄▄▄▀  █▄▄▄▄  █▄▄▄ ▄█▄    █    █▄▄▄▄  █   █ ║ "<<endl;
    gotoXY(25,68);  cout<<"╚═════════════════════════════════════════════╝ "<<endl;

}

void button(int ontable, int wasted){

    pan();
    pot();
    bake();

    if(ontable && !wasted ){
        gotoXY(39,25);   cout<<"   ╔═══╗    "<<endl;
        gotoXY(39,26);   cout<<"   ║ Q ║    "<<endl;
        gotoXY(39,27);   cout<<"   ╚═══╝    "<<endl;
        gotoXY(39,28);   cout<<"PRESS TO FRY"<<endl;

        gotoXY(77,25);   cout<<"   ╔═══╗     "<<endl;
        gotoXY(77,26);   cout<<"   ║ W ║     "<<endl;
        gotoXY(77,27);   cout<<"   ╚═══╝     "<<endl;
        gotoXY(77,28);   cout<<"PRESS TO BOIL"<<endl;

        gotoXY(124,25);  cout<<" ╔═══╗ "<<endl;
        gotoXY(124,26);  cout<<" ║ E ║ "<<endl;
        gotoXY(124,27);  cout<<" ╚═══╝ "<<endl;
        gotoXY(120,28);  cout<<" PRESS TO BAKE "<<endl;

        gotoXY(102,48);       cout<<" ╔═══╗ "<<endl;
        gotoXY(97,49);   cout<<"PRESS ║ S ║ TO DELIVER"<<endl;
        gotoXY(102,50);       cout<<" ╚═══╝ "<<endl;

    }else if(wasted){
        gotoXY(102,48);       cout<<" ╔═══╗ "<<endl;
        gotoXY(97,49);   cout<<"PRESS ║ S ║ TO DELIVER"<<endl;
        gotoXY(102,50);       cout<<" ╚═══╝ "<<endl;
    }
    else if(!ontable){
        gotoXY(102,43);     cout<<"SELECT"<<endl;
        gotoXY(100,44);   cout<<"INGREDIENT"<<endl;
    }

    gotoXY(26,52);
}

void Kai(int x,int y){
    gotoXY(x+2,y  );     cout<<" ,'\"`. "<<endl;
    gotoXY(x+1,y+1);    cout<<" /     \\ "<<endl;
    gotoXY(x  ,y+2);   cout<<" :       : "<<endl;
    gotoXY(x  ,y+3);   cout<<" :       : "<<endl;
    gotoXY(x+1,y+4);    cout<<" '.___,' "<<endl;
    gotoXY(x+1,y+5);    cout<<" [ooooo] "<<endl;
}

void Kaidow(int x,int y){
    gotoXY(x+5,y  );       cout<<"  ▄▄▄▄▄▄▄▄  "<<endl;
    gotoXY(x+3,y+1);     cout<<" ▄████████████▄ "<<endl;
    gotoXY(x+1,y+2);   cout<<" ▄████░░░░░░██████▄ "<<endl;
    gotoXY(x  ,y+3);  cout<<" ▄████░█░░░░█░██████▄ "<<endl;
    gotoXY(x  ,y+4);  cout<<" ████░░░░░░█░░░██████ "<<endl;
    gotoXY(x  ,y+5);  cout<<" █████░░░░░░░░███████ "<<endl;
    gotoXY(x  ,y+6);  cout<<" ▀██████░░░░████████ "<<endl;
    gotoXY(x+1,y+7);   cout<<" ▀███████████████▀ "<<endl;
    gotoXY(x+2,y+8);    cout<<"  ▀██████████▀▀ "<<endl;
    gotoXY(x+5,y+9);       cout<<"   ▀▀▀▀▀   "<<endl;
    gotoXY(x+6,y+10);        cout<<" [ooooo] "<<endl;
}

void Kaitom(int x,int y){
    gotoXY(x+2,y  );     cout<<" ▄███▄ "<<endl;
    gotoXY(x+1,y+1);    cout<<" ███████ "<<endl;
    gotoXY(x  ,y+2);   cout<<" ███████░█ "<<endl;
    gotoXY(x  ,y+3);   cout<<" ██████░██ "<<endl;
    gotoXY(x+1,y+4);    cout<<" ▀▀███▀▀ "<<endl;
    gotoXY(x+1,y+5);    cout<<" [ooooo] "<<endl;
}

void Kaitoon(int x,int y){
    gotoXY(x+2,y  );    cout<<" ▄▄███████████▄▄ "<<endl;
    gotoXY(x  ,y+1);  cout<<" ▄███▀██▄██████▀███▄ "<<endl;
    gotoXY(x  ,y+2);  cout<<" █▀████████▄██████▀█ "<<endl;
    gotoXY(x  ,y+3);  cout<<" █   ▀▀▀█████▀▀▀   █ "<<endl;
    gotoXY(x+1,y+4);   cout<<" █               █ "<<endl;
    gotoXY(x+2,y+5);    cout<<" ▀▄▄         ▄▄▀ "<<endl;
    gotoXY(x+5,y+6);       cout<<" ▀▀▀▀▀▀▀▀▀ "<<endl;
    gotoXY(x+6,y+7);        cout<<" [ooooo] "<<endl;
}

void Pang(int x,int y){
    gotoXY(x+4,y  );      cout<<" _______ "<<endl;
    gotoXY(x+2,y+1);    cout<<" ,'       ', "<<endl;
    gotoXY(x  ,y+2);  cout<<" ,'           ', "<<endl;
    gotoXY(x  ,y+3);  cout<<" ',___________,' "<<endl;
    gotoXY(x+2,y+4);    cout<<"              "<<endl;
    gotoXY(x+2,y+5);    cout<<" [oooooooooo] "<<endl;
}

void Cookie(int x,int y){
    gotoXY(x+7,y  );        cout<<" ▄▄▄▄▄▄▄▄ "<<endl;
    gotoXY(x+2,y+1);   cout<<" ▄▄▀▀▀ ▄   ▄  ▀▀▀▄▄ "<<endl;
    gotoXY(x  ,y+2); cout<<" ▄▀   ▄    ▄    ▄    ▀▄ "<<endl;
    gotoXY(x  ,y+3); cout<<" ▀▄▄                ▄▄▀ "<<endl;
    gotoXY(x+3,y+4);    cout<<" ▀▀▀▄▄▄▄▄▄▄▄▄▄▀▀▀ "<<endl;
    gotoXY(x+5,y+5);      cout<<" [oooooooooo] "<<endl;
}

void Donut(int x,int y){
    gotoXY(x+5,y  );       cout<<"  ▄▄▄▄▄▄▄  "<<endl;
    gotoXY(x+3,y+1);     cout<<" ▄███████████▄ "<<endl;
    gotoXY(x+1,y+2);   cout<<" ▄███████████████▄ "<<endl;
    gotoXY(x  ,y+3);  cout<<" ▄███████▀▀▀███████▄ "<<endl;
    gotoXY(x  ,y+4);  cout<<" ███████░░░░░███████ "<<endl;
    gotoXY(x  ,y+5);  cout<<" ████████▄▄▄████████ "<<endl;
    gotoXY(x  ,y+6);  cout<<" █ ███████████████ █ "<<endl;
    gotoXY(x  ,y+7);  cout<<" ▀▄ █▀█████████▀█ ▄▀ "<<endl;
    gotoXY(x+1,y+8);   cout<<" ▀▄   █ ▀  █    ▄▀ "<<endl;
    gotoXY(x+3,y+9);     cout<<" ▀▀▄▄▄▄▄▄▄▄▄▀▀ "<<endl;
    gotoXY(x+5,y+10);      cout<<"[oooooooooo]"<<endl;
}

void Kanompang(int x,int y){
    gotoXY(x+2,y  );   cout<<" _ _ _ _ _ _ _ "<<endl;
    gotoXY(x  ,y+1); cout<<" ,'\" \" \" \"',    '\\ "<<endl;
    gotoXY(x  ,y+2); cout<<" ',       ,'____ / "<<endl;
    gotoXY(x+1,y+3);  cout<<" |       ; ' ' | "<<endl;
    gotoXY(x+1,y+4);  cout<<" |       ;     | "<<endl;
    gotoXY(x+1,y+5);  cout<<" ',_____,'____,' "<<endl;
    gotoXY(x+1,y+6);  cout<<"   [oooooooooo]  "<<endl;
}

void PangOb(int x,int y){
    gotoXY(x+1,y  );  cout<<" ░▄▄▄▄▄▄▄▄▄░ "<<endl;
    gotoXY(x  ,y+1); cout<<" ░█░░░░░░░░░█░ "<<endl;
    gotoXY(x+1,y+2);  cout<<" ░█░░░░░░░█░ "<<endl;
    gotoXY(x+1,y+3);  cout<<" ░█░░░░░░░█░ "<<endl;
    gotoXY(x+1,y+4);  cout<<" ░█░░░░░░░█░ "<<endl;
    gotoXY(x+2,y+5);   cout<<" ░▀▀▀▀▀▀▀░ "<<endl;
    gotoXY(x+1,y+6);  cout<<" [oooooooooo] "<<endl;
}

void Pangping(int x,int y){
    gotoXY(x+1,y  );   cout<<" ▄▄▄▄▄▄▄▄▄ "<<endl;
    gotoXY(x  ,y+1);  cout<<" █ ░ ░ ░ ░░█ "<<endl;
    gotoXY(x+1,y+2);   cout<<" █░ ░ ░ ░█ "<<endl;
    gotoXY(x+1,y+3);   cout<<" █░ ░ ░ ░█ "<<endl;
    gotoXY(x+1,y+4);   cout<<" █░ ░ ░ ░█ "<<endl;
    gotoXY(x+2,y+5);    cout<<" ▀▀▀▀▀▀▀ "<<endl;
    gotoXY(x  ,y+6);  cout<<" [oooooooooo] "<<endl;
}

void digitalnumber(int num,int digit,int n){

    int x,y;

    if(n==1){
        x=188;
        y=10;
    }else if(n==2){
        x=98;
        y=44;
    }

    switch(num){

        case 0 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"║ ║"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"╚═╝"<<endl;
                    break;
                    }

        case 1 :    {
                    gotoXY(x+(4*digit),y+1); cout<<" ╔╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"  ║"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"  ╩"<<endl;
                    break;
                    }

        case 2 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"╔═╝"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"╚═╝"<<endl;
                    break;
                    }

        case 3 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<" ═╣"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"╚═╝"<<endl;
                    break;
                    }

        case 4 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔ ╔"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"╚═╣"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"  ╝"<<endl;
                    break;
                    }

        case 5 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"╚═╗"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"╚═╝"<<endl;
                    break;
                    }

        case 6 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"╬═╗"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"╚═╝"<<endl;
                    break;
                    }

        case 7 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"  ╬"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"  ╩"<<endl;
                    break;
                    }

        case 8 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"╬═╬"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"╚═╝"<<endl;
                    break;
                    }

        case 9 :    {
                    gotoXY(x+(4*digit),y+1); cout<<"╔═╗"<<endl;
                    gotoXY(x+(4*digit),y+2); cout<<"╚═╣"<<endl;
                    gotoXY(x+(4*digit),y+3); cout<<"╚═╝"<<endl;
                    break;
                    }

    }

}

void scoring(int score, int n){
    digitalnumber(score/10000,0,n);
    digitalnumber((score%10000)/1000,1,n);
    digitalnumber((score%1000)/100,2,n);
    digitalnumber((score%100)/10,3,n);
    digitalnumber((score%10),4,n);
}

void roll(int start,int fin,string name){

    int k;
    if(name.compare("Fried Egg")==0){
        for(k=start;k>=fin;k--){
            gotoXY(k,2 );if(k<=start&&k>=25)  cout<<"╔══════════════════════════╗ F "<<endl;
            gotoXY(k,3 );if(k<=start&&k>=25)  cout<<"║         ▄▄▄▄▄▄▄▄         ║ R "<<endl;
            gotoXY(k,4 );if(k<=start&&k>=25)  cout<<"║      ▄████████████▄      ║ I "<<endl;
            gotoXY(k,5 );if(k<=start&&k>=25)  cout<<"║    ▄████░░░░░░██████▄    ║ E "<<endl;
            gotoXY(k,6 );if(k<=start&&k>=25)  cout<<"║   ▄████░█░░░░█░██████▄   ║ D "<<endl;
            gotoXY(k,7 );if(k<=start&&k>=25)  cout<<"║   ████░░░░░░█░░░██████   ║ "<<endl;
            gotoXY(k,8 );if(k<=start&&k>=25)  cout<<"║   █████░░░░░░░░███████   ║ E "<<endl;
            gotoXY(k,9 );if(k<=start&&k>=25)  cout<<"║   ▀██████░░░░████████    ║ G "<<endl;
            gotoXY(k,10);if(k<=start&&k>=25)  cout<<"║    ▀███████████████▀     ║ G "<<endl;
            gotoXY(k,11);if(k<=start&&k>=25)  cout<<"║      ▀██████████▀▀       ║ "<<endl;
            gotoXY(k,12);if(k<=start&&k>=25)  cout<<"║          ▀▀▀▀▀           ║ "<<endl;
            gotoXY(k,13);if(k<=start&&k>=25)  cout<<"╚══════════════════════════╝ "<<endl;
        }
    }else if(name.compare("Boiled Egg")==0){
        for(k=start;k>=fin;k--){
            gotoXY(k,2 );if(k<=start)  cout<<"╔══════════════════════════╗ B "<<endl;
            gotoXY(k,3 );if(k<=start)  cout<<"║                          ║ O "<<endl;
            gotoXY(k,4 );if(k<=start)  cout<<"║                          ║ I "<<endl;
            gotoXY(k,5 );if(k<=start)  cout<<"║          ▄███▄           ║ L "<<endl;
            gotoXY(k,6 );if(k<=start)  cout<<"║         ███████          ║ "<<endl;
            gotoXY(k,7 );if(k<=start)  cout<<"║        ███████░█         ║ E "<<endl;
            gotoXY(k,8 );if(k<=start)  cout<<"║        ██████░██         ║ G "<<endl;
            gotoXY(k,9 );if(k<=start)  cout<<"║         ▀▀███▀▀          ║ G "<<endl;
            gotoXY(k,10);if(k<=start)  cout<<"║                          ║ "<<endl;
            gotoXY(k,11);if(k<=start)  cout<<"║                          ║ "<<endl;
            gotoXY(k,12);if(k<=start)  cout<<"║                          ║ "<<endl;
            gotoXY(k,13);if(k<=start)  cout<<"╚══════════════════════════╝ "<<endl;
        }
    }else if(name.compare("Steamed Egg")==0){
        for(k=start;k>=fin;k--){
            gotoXY(k,2 );if(k<=start&&k>=25)  cout<<"╔══════════════════════════╗ S "<<endl;
            gotoXY(k,3 );if(k<=start&&k>=25)  cout<<"║                          ║ T "<<endl;
            gotoXY(k,4 );if(k<=start&&k>=25)  cout<<"║                          ║ E "<<endl;
            gotoXY(k,5 );if(k<=start&&k>=25)  cout<<"║     ▄▄███████████▄▄      ║ A "<<endl;
            gotoXY(k,6 );if(k<=start&&k>=25)  cout<<"║   ▄███▀██▄██████▀███▄    ║ M "<<endl;
            gotoXY(k,7 );if(k<=start&&k>=25)  cout<<"║   █▀████████▄██████▀█    ║ E "<<endl;
            gotoXY(k,8 );if(k<=start&&k>=25)  cout<<"║   █   ▀▀▀█████▀▀▀   █    ║ D "<<endl;
            gotoXY(k,9 );if(k<=start&&k>=25)  cout<<"║    █               █     ║ "<<endl;
            gotoXY(k,10);if(k<=start&&k>=25)  cout<<"║     ▀▄▄         ▄▄▀      ║ E "<<endl;
            gotoXY(k,11);if(k<=start&&k>=25)  cout<<"║        ▀▀▀▀▀▀▀▀▀         ║ G "<<endl;
            gotoXY(k,12);if(k<=start&&k>=25)  cout<<"║                          ║ G "<<endl;
            gotoXY(k,13);if(k<=start&&k>=25)  cout<<"╚══════════════════════════╝ "<<endl;
        }
    }else if(name.compare("Donut")==0){
        for(k=start;k>=fin;k--){
            gotoXY(k,2 );if(k<=start&&k>=25)  cout<<"╔══════════════════════════╗ D "<<endl;
            gotoXY(k,3 );if(k<=start&&k>=25)  cout<<"║         ▄▄▄▄▄▄▄          ║ O "<<endl;
            gotoXY(k,4 );if(k<=start&&k>=25)  cout<<"║      ▄███████████▄       ║ N "<<endl;
            gotoXY(k,5 );if(k<=start&&k>=25)  cout<<"║    ▄███████████████▄     ║ U "<<endl;
            gotoXY(k,6 );if(k<=start&&k>=25)  cout<<"║   ▄███████▀▀▀███████▄    ║ T "<<endl;
            gotoXY(k,7 );if(k<=start&&k>=25)  cout<<"║   ███████░░░░░███████    ║ "<<endl;
            gotoXY(k,8 );if(k<=start&&k>=25)  cout<<"║   ████████▄▄▄████████    ║ "<<endl;
            gotoXY(k,9 );if(k<=start&&k>=25)  cout<<"║   █ ███████████████ █    ║ "<<endl;
            gotoXY(k,10);if(k<=start&&k>=25)  cout<<"║   ▀▄ █▀█████████▀█ ▄▀    ║ "<<endl;
            gotoXY(k,11);if(k<=start&&k>=25)  cout<<"║    ▀▄   █ ▀  █    ▄▀     ║ "<<endl;
            gotoXY(k,12);if(k<=start&&k>=25)  cout<<"║      ▀▀▄▄▄▄▄▄▄▄▄▀▀       ║ "<<endl;
            gotoXY(k,13);if(k<=start&&k>=25)  cout<<"╚══════════════════════════╝ "<<endl;
        }
    }else if(name.compare("Cookie")==0){
        for(k=start;k>=fin;k--){
            gotoXY(k,2 );if(k<=start&&k>=25)  cout<<"╔══════════════════════════╗ C "<<endl;
            gotoXY(k,3 );if(k<=start&&k>=25)  cout<<"║                          ║ O "<<endl;
            gotoXY(k,4 );if(k<=start&&k>=25)  cout<<"║                          ║ O "<<endl;
            gotoXY(k,5 );if(k<=start&&k>=25)  cout<<"║         ▄▄▄▄▄▄▄▄         ║ K "<<endl;
            gotoXY(k,6 );if(k<=start&&k>=25)  cout<<"║    ▄▄▀▀▀ ▄   ▄  ▀▀▀▄▄    ║ I "<<endl;
            gotoXY(k,7 );if(k<=start&&k>=25)  cout<<"║  ▄▀   ▄    ▄    ▄    ▀▄  ║ E "<<endl;
            gotoXY(k,8 );if(k<=start&&k>=25)  cout<<"║  ▀▄▄                ▄▄▀  ║ "<<endl;
            gotoXY(k,9 );if(k<=start&&k>=25)  cout<<"║     ▀▀▀▄▄▄▄▄▄▄▄▄▄▀▀▀     ║ "<<endl;
            gotoXY(k,10);if(k<=start&&k>=25)  cout<<"║                          ║ "<<endl;
            gotoXY(k,11);if(k<=start&&k>=25)  cout<<"║                          ║ "<<endl;
            gotoXY(k,12);if(k<=start&&k>=25)  cout<<"║                          ║ "<<endl;
            gotoXY(k,13);if(k<=start&&k>=25)  cout<<"╚══════════════════════════╝ "<<endl;
        }
    }else if(name.compare("Fried Bread")==0){
        for(k=start;k>=fin;k--){
            gotoXY(k,2 );if(k<=start&&k>=25)  cout<<"╔══════════════════════════╗ F "<<endl;
            gotoXY(k,3 );if(k<=start&&k>=25)  cout<<"║                          ║ R "<<endl;
            gotoXY(k,4 );if(k<=start&&k>=25)  cout<<"║                          ║ I "<<endl;
            gotoXY(k,5 );if(k<=start&&k>=25)  cout<<"║        ▄▄▄▄▄▄▄▄▄         ║ E "<<endl;
            gotoXY(k,6 );if(k<=start&&k>=25)  cout<<"║       █ ░ ░ ░ ░░█        ║ D "<<endl;
            gotoXY(k,7 );if(k<=start&&k>=25)  cout<<"║        █░ ░ ░ ░█         ║ "<<endl;
            gotoXY(k,8 );if(k<=start&&k>=25)  cout<<"║        █░ ░ ░ ░█         ║ B "<<endl;
            gotoXY(k,9 );if(k<=start&&k>=25)  cout<<"║        █░ ░ ░ ░█         ║ R "<<endl;
            gotoXY(k,10);if(k<=start&&k>=25)  cout<<"║         ▀▀▀▀▀▀▀          ║ E "<<endl;
            gotoXY(k,11);if(k<=start&&k>=25)  cout<<"║                          ║ A "<<endl;
            gotoXY(k,12);if(k<=start&&k>=25)  cout<<"║                          ║ D "<<endl;
            gotoXY(k,13);if(k<=start&&k>=25)  cout<<"╚══════════════════════════╝ "<<endl;
        }
    }else if(name.compare("Baked Bread")==0){
        for(k=start;k>=fin;k--){
            gotoXY(k,2 );if(k<=start&&k>=25)  cout<<"╔══════════════════════════╗ B "<<endl;
            gotoXY(k,3 );if(k<=start&&k>=25)  cout<<"║                          ║ A "<<endl;
            gotoXY(k,4 );if(k<=start&&k>=25)  cout<<"║                          ║ K "<<endl;
            gotoXY(k,5 );if(k<=start&&k>=25)  cout<<"║       ░▄▄▄▄▄▄▄▄▄░        ║ E "<<endl;
            gotoXY(k,6 );if(k<=start&&k>=25)  cout<<"║      ░█░░░░░░░░░█░       ║ D "<<endl;
            gotoXY(k,7 );if(k<=start&&k>=25)  cout<<"║       ░█░░░░░░░█░        ║ "<<endl;
            gotoXY(k,8 );if(k<=start&&k>=25)  cout<<"║       ░█░░░░░░░█░        ║ B "<<endl;
            gotoXY(k,9 );if(k<=start&&k>=25)  cout<<"║       ░█░░░░░░░█░        ║ R "<<endl;
            gotoXY(k,10);if(k<=start&&k>=25)  cout<<"║        ░▀▀▀▀▀▀▀░         ║ E "<<endl;
            gotoXY(k,11);if(k<=start&&k>=25)  cout<<"║                          ║ A "<<endl;
            gotoXY(k,12);if(k<=start&&k>=25)  cout<<"║                          ║ D "<<endl;
            gotoXY(k,13);if(k<=start&&k>=25)  cout<<"╚══════════════════════════╝ "<<endl;
        }
    }
    Sleep(50);
}

void blank(){
    int k = 25;
            gotoXY(k,2 );cout<<"                                "<<endl;
            gotoXY(k,3 );cout<<"                                "<<endl;
            gotoXY(k,4 );cout<<"                                "<<endl;
            gotoXY(k,5 );cout<<"                                "<<endl;
            gotoXY(k,6 );cout<<"                                "<<endl;
            gotoXY(k,7 );cout<<"                                "<<endl;
            gotoXY(k,8 );cout<<"                                "<<endl;
            gotoXY(k,9 );cout<<"                                "<<endl;
            gotoXY(k,10);cout<<"                                "<<endl;
            gotoXY(k,11);cout<<"                                "<<endl;
            gotoXY(k,12);cout<<"                                "<<endl;
            gotoXY(k,13);cout<<"                                "<<endl;
}

