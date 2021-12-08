#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<exception>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include"kitchen.h"

using namespace std;

void gotoXY(int,int); // function defined below if this is new to you.
void header();
void loading();
void PressE_Countdown();
int menu(); // difficulty & exit
int leaderboard();
void regist();
string login();
void space();

class my_cin: public exception{

    virtual const char* what() const throw(){
        return "Please input only characters.";
    }

}my_ex;

int loggedin=0;

int main(){

    int R=1;
    string name;
    Sleep(2000);
    header();

    switch(menu()){

        case 1 : {loggedin = 1;     name = login();             }break;
        case 2 : {regist();         loggedin=1;     name = login();    }break;
        case 3 : {
            header();
            int x=0;
            string t="Good bye..... ";
            gotoXY(49,30);
            while ( t[x] != '\0'){
                cout << t[x];
                Sleep(50);
                x++;
            };
            gotoXY(49,50);  cout<<endl;
            Sleep(1000);
        }break;

    }

    if(loggedin){

        while(R>0){
            header();

            if(R==1){
                gotoXY(20,23);  cout<<" ______________________________________________________________________"<<endl;
                gotoXY(20,24);  cout<<"/                                                                      \\"<<endl;
                gotoXY(20,25);  cout<<"|                                                                       \\"<<endl;
                gotoXY(13,26);  cout<<"       \\_____________________________________________________________________/\\ )"<<endl;
                gotoXY(20,27);  cout<<"                                                                        \\|"<<endl;

                gotoXY(38,28);  cout<<" ___________________________________________"<<endl;
                gotoXY(38,29);  cout<<"/                                           \\"<<endl;
                gotoXY(38,30);  cout<<"|                                             >"<<endl;
                gotoXY(38,31);  cout<<"\\___________________________________________/"<<endl;

                {
                    int x=0;
                    string home="Good morning! Head-chef! The COVID FREE restaurant is opening soon!";
                    gotoXY(22,25);
                    while ( home[x] != '\0'){
                        cout << home[x];
                        Sleep(50);
                        x++;
                    };
                }


                {
                    int x=0;
                    string home="Are you ready to be the best cook?";
                    gotoXY(44,30);
                    while ( home[x] != '\0'){
                        cout << home[x];
                        Sleep(50);
                        x++;
                    };
                }
            }else{

                gotoXY(20,23);  cout<<" ______________________________________________________________________"<<endl;
                gotoXY(20,24);  cout<<"/                                                                      \\"<<endl;
                gotoXY(20,25);  cout<<"|  Good morning! Head-chef! The COVID FREE restaurant is opening soon!  \\"<<endl;
                gotoXY(13,26);  cout<<"       \\_____________________________________________________________________/\\ )"<<endl;
                gotoXY(20,27);  cout<<"                                                                        \\|"<<endl;

                gotoXY(38,28);  cout<<" ___________________________________________"<<endl;
                gotoXY(38,29);  cout<<"/                                           \\"<<endl;
                gotoXY(38,30);  cout<<"|     Are you ready to be the best cook?       >"<<endl;
                gotoXY(38,31);  cout<<"\\___________________________________________/"<<endl;

            }

            fflush(stdin);

            switch(menu()){
                case 1 :{
                    system("CLS");
                    loading();
                    kitchen();
                    PressE_Countdown();
                    kitchen_play(name);
                }break;
                case 2 : {
                    leaderboard();
                }break;
                case 3 : {
                    header();
                    int x=0;
                    string t="Good bye..... ";
                    gotoXY(49,30);
                    while ( t[x] != '\0'){
                        cout << t[x];
                        Sleep(50);
                        x++;
                    };
                    gotoXY(49,50);  cout<<endl;
                    Sleep(1000);
                    R=-999;
                }break;
            }
            R++;
        }

    }

    return 0;
}

void loading(){

    int i=0,j=0;;
    while(j<3){
        i=0;
        while(i<=8){

            gotoXY(9+(3*i),19);      cout << "   ";
            gotoXY(9+(3*i),20);      cout << "   ";
            gotoXY(9+(3*i),21);      cout << "   ";
            gotoXY(9+(3*i),22);      cout << "   ";

            gotoXY(12+(3*i),19);     cout << "          \\ | /  ";
            gotoXY(12+(3*i),20);     cout << "    ╔═╦════╦╗     ";
            gotoXY(12+(3*i),21);     cout << " ╔══╝ ╚════╩╩══╗  ";
            gotoXY(12+(3*i),22);     cout << "═╚═(_)════(_)══╝╝ ";

            gotoXY(29+(3*i),19);     cout << "                          ";
            gotoXY(29+(3*i),20);     cout << "                          ";
            gotoXY(29+(3*i),21);     cout << "                          ";
            gotoXY(29+(3*i),22);     cout << "                          ";

            Sleep(200);

            i++;
        }
    j++;
    }

}

void header(){

    gotoXY(10,5 );  cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
    gotoXY(10,6 );  cout<<"█ █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█ █"<<endl;
    gotoXY(10,7 );  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,8 );  cout<<"█ █                     ╔═════════════════════════════════════════╗                    █ █"<<endl;
    gotoXY(10,9 );  cout<<"█ █                     ║    ▄▄▄▄    ▄▄▄▄   ▄    ▄  ▄▄▄   ▄▄▄▄    ║                    █ █"<<endl;
    gotoXY(10,10);  cout<<"█ █                     ║  ▄▀    ▀ ▄▀    ▀▄ █    █ ▀ █ ▀  █   ▀▄  ║                    █ █"<<endl;
    gotoXY(10,11);  cout<<"█ █                     ║  █       █      █ █    █   █    █    █  ║                    █ █"<<endl;
    gotoXY(10,12);  cout<<"█ █                     ║  █       █      █ ▀▄  ▄▀   █    █    █  ║                    █ █"<<endl;
    gotoXY(10,13);  cout<<"█ █                     ║   ▀▄▄▄▄▀  ▀▄▄▄▄▀   ▀▄▄▀  ▀▄█▄▀  █▄▄▄▀   ║                    █ █"<<endl;
    gotoXY(10,14);  cout<<"█ █                     ╚═════════II════════════════════II════════╝                    █ █"<<endl;
    gotoXY(10,15);  cout<<"█ █                          o═o═o═o═o═o═o═o═o═o═o═o═o═o═o═o═o                         █ █"<<endl;
    gotoXY(10,16);  cout<<"█ █                          ║  ▄▄▄▄▄  ▄▄▄▄   ▄▄▄▄▄   ▄▄▄▄▄  ║                         █ █"<<endl;
    gotoXY(10,17);  cout<<"█ █                          o █      █    █ █       █       o                         █ █"<<endl;
    gotoXY(10,18);  cout<<"█ █                          ║ █▄▄▄▄▄ █▄▄▄▄▀ █▄▄▄▄▄  █▄▄▄▄▄  ║                         █ █"<<endl;
    gotoXY(10,19);  cout<<"█ █                          o █      █    █ █       █       o                         █ █"<<endl;
    gotoXY(10,20);  cout<<"█ █                          ║ █      █    █ ▀▄▄▄▄▄  ▀▄▄▄▄▄  ║                         █ █"<<endl;
    gotoXY(10,21);  cout<<"█ █                          o═o═o═o═o═o═o═o═o═o═o═o═o═o═o═o═o                         █ █"<<endl;
    gotoXY(10,22);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,23);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,24);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,25);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,26);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,27);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,28);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,29);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,30);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,31);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,32);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,33);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,34);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,35);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,36);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,37);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,38);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,39);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,40);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,41);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,42);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,43);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,44);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,45);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,46);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,47);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,48);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,49);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,50);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,51);  cout<<"█ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █"<<endl;
    gotoXY(10,52);  cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;

}

int menu(){

    int menu_item=0, x=33;
	bool running = true;

	if(!loggedin){
        gotoXY(44,33);  cout<<" _____________________"<<endl;
        gotoXY(44,34);  cout<<"/                     \\"<<endl;
        gotoXY(44,35);  cout<<"|        LOGIN        |"<<endl;
        gotoXY(44,36);  cout<<"\\_____________________/"<<endl;

        gotoXY(44,38);  cout<<" _____________________"<<endl;
        gotoXY(44,39);  cout<<"/                     \\"<<endl;
        gotoXY(44,40);  cout<<"|       REGISTER      |"<<endl;
        gotoXY(44,41);  cout<<"\\_____________________/"<<endl;

        gotoXY(44,43);  cout<<" _____________________"<<endl;
        gotoXY(44,44);  cout<<"/                     \\"<<endl;
        gotoXY(44,45);  cout<<"|         EXIT        |"<<endl;
        gotoXY(44,46);  cout<<"\\_____________________/"<<endl;
	}else{
        gotoXY(44,33);  cout<<" _____________________"<<endl;
        gotoXY(44,34);  cout<<"/                     \\"<<endl;
        gotoXY(44,35);  cout<<"|        READY        |"<<endl;
        gotoXY(44,36);  cout<<"\\_____________________/"<<endl;

        gotoXY(44,38);  cout<<" _____________________"<<endl;
        gotoXY(44,39);  cout<<"/                     \\"<<endl;
        gotoXY(44,40);  cout<<"|      LEADERBOARD    |"<<endl;
        gotoXY(44,41);  cout<<"\\_____________________/"<<endl;

        gotoXY(44,43);  cout<<" _____________________"<<endl;
        gotoXY(44,44);  cout<<"/                     \\"<<endl;
        gotoXY(44,45);  cout<<"|         EXIT        |"<<endl;
        gotoXY(44,46);  cout<<"\\_____________________/"<<endl;
	}

    gotoXY(40,33);  cout<<"╔═"<<endl;   gotoXY(69,33);  cout<<"═╗"<<endl;
    gotoXY(40,34);  cout<<"║"<<endl;    gotoXY(70,34);   cout<<"║"<<endl;

    gotoXY(40,36);  cout<<"║"<<endl;    gotoXY(70,36);   cout<<"║"<<endl;
    gotoXY(40,37);  cout<<"╚═"<<endl;   gotoXY(69,37);  cout<<"═╝"<<endl;

	while(running)
	{

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetAsyncKeyState(VK_DOWN) && x !=43) //down button pressed
			{
				gotoXY(40,x  );  cout<<"  "<<endl;   gotoXY(69,x  );  cout<<"  "<<endl;
                gotoXY(40,x+1);  cout<<" "<<endl;    gotoXY(70,x+1);   cout<<" "<<endl;

                gotoXY(40,x+3);  cout<<" "<<endl;    gotoXY(70,x+3);   cout<<" "<<endl;
                gotoXY(40,x+4);  cout<<"  "<<endl;   gotoXY(69,x+4);  cout<<"  "<<endl;

                x+=5;

				gotoXY(40,x  );  cout<<"╔═"<<endl;   gotoXY(69,x  );  cout<<"═╗"<<endl;
                gotoXY(40,x+1);  cout<<"║"<<endl;    gotoXY(70,x+1);   cout<<"║"<<endl;

                gotoXY(40,x+3);  cout<<"║"<<endl;    gotoXY(70,x+3);   cout<<"║"<<endl;
                gotoXY(40,x+4);  cout<<"╚═"<<endl;   gotoXY(69,x+4);  cout<<"═╝"<<endl;

				menu_item++;
				continue;
			}

		if(GetAsyncKeyState(VK_UP) && x !=33) //up button pressed
			{
				gotoXY(40,x  );  cout<<"  "<<endl;   gotoXY(69,x  );  cout<<"  "<<endl;
                gotoXY(40,x+1);  cout<<" "<<endl;    gotoXY(70,x+1);   cout<<" "<<endl;

                gotoXY(40,x+3);  cout<<" "<<endl;    gotoXY(70,x+3);   cout<<" "<<endl;
                gotoXY(40,x+4);  cout<<"  "<<endl;   gotoXY(69,x+4);  cout<<"  "<<endl;

				x-=5;

				gotoXY(40,x  );  cout<<"╔═"<<endl;   gotoXY(69,x  );  cout<<"═╗"<<endl;
                gotoXY(40,x+1);  cout<<"║"<<endl;    gotoXY(70,x+1);   cout<<"║"<<endl;

                gotoXY(40,x+3);  cout<<"║"<<endl;    gotoXY(70,x+3);   cout<<"║"<<endl;
                gotoXY(40,x+4);  cout<<"╚═"<<endl;   gotoXY(69,x+4);  cout<<"═╝"<<endl;

				menu_item--;
				continue;
			}

        if(GetAsyncKeyState(VK_RETURN) & 0x8000){ // Enter key pressed

            switch(menu_item){
                case 0: {
                    return 1;
                    break;
                }
                case 1: {
                    return 2;
                    break;
                }
                case 2: {
                    return 3;
                    break;
                }
            }

        }

	}

	gotoXY(20,21);

}

void PressE_Countdown(){

gotoXY(50,39); cout<<"                                               ╔═══╗                                                                "<<endl;
gotoXY(50,40); cout<<"                                         PRESS ║ E ║ TO START COOKING                                               "<<endl;
gotoXY(50,41); cout<<"                                               ╚═══╝                                                                "<<endl;

int running=1;
while(running)  if(getch()=='e'||getch()=='E' )  running=0;

gotoXY(50,39); cout<<"                                                                                                                    "<<endl;
gotoXY(50,40); cout<<"                                                                                                                    "<<endl;
gotoXY(50,41); cout<<"                                                                                                                    "<<endl;

gotoXY(95,19); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
gotoXY(95,20); cout<<"█   ████████████   █"<<endl;
gotoXY(95,21); cout<<"█             ██   █"<<endl;
gotoXY(95,22); cout<<"█             ██   █"<<endl;
gotoXY(95,23); cout<<"█   ▄▄▄▄▄▄▄▄▄▄██   █"<<endl;
gotoXY(95,24); cout<<"█   ▀▀▀▀▀▀▀▀▀▀██   █"<<endl;
gotoXY(95,25); cout<<"█             ██   █"<<endl;
gotoXY(95,26); cout<<"█             ██   █"<<endl;
gotoXY(95,27); cout<<"█   ████████████   █"<<endl;
gotoXY(95,28); cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;
Sleep(900);
kitchen();
Sleep(100);
gotoXY(95,19); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
gotoXY(95,20); cout<<"█   ████████████   █"<<endl;
gotoXY(95,21); cout<<"█             ██   █"<<endl;
gotoXY(95,22); cout<<"█             ██   █"<<endl;
gotoXY(95,23); cout<<"█   ▄▄▄▄▄▄▄▄▄▄██   █"<<endl;
gotoXY(95,24); cout<<"█   ██▀▀▀▀▀▀▀▀▀▀   █"<<endl;
gotoXY(95,25); cout<<"█   ██             █"<<endl;
gotoXY(95,26); cout<<"█   ██             █"<<endl;
gotoXY(95,27); cout<<"█   ████████████   █"<<endl;
gotoXY(95,28); cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;
Sleep(900);
kitchen();
Sleep(100);
gotoXY(95,19); cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
gotoXY(95,20); cout<<"█       ████       █"<<endl;
gotoXY(95,21); cout<<"█         ██       █"<<endl;
gotoXY(95,22); cout<<"█         ██       █"<<endl;
gotoXY(95,23); cout<<"█         ██       █"<<endl;
gotoXY(95,24); cout<<"█         ██       █"<<endl;
gotoXY(95,25); cout<<"█         ██       █"<<endl;
gotoXY(95,26); cout<<"█         ██       █"<<endl;
gotoXY(95,27); cout<<"█         ██       █"<<endl;
gotoXY(95,28); cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;
Sleep(900);
kitchen();

}

string login(){
    string username,password,un,pw;
    int run=0;

    space();
    gotoXY(16,26);  cout<<"----------------------------------- LOGIN -----------------------------------"<<endl;

    gotoXY(16,28);  cout<<"                     Username      :                 ";
    gotoXY(16,29);  cout<<"                                                     ";
    gotoXY(16,30);  cout<<"                     Password(6)   :                 ";
    gotoXY(16,31);  cout<<"                                                     ";

    run=1;
    while(run){
        gotoXY(53,28);  cin>>username;

        try{
            if(cin.fail()){
                throw my_ex;
            }
            if(username.length()>10){
                throw 1;
            }
            if(username.length()<4){
                throw 2;
            }
            run=0;
        }
        catch(exception& e){
            cout<<e.what()<<endl;
        }
        catch(int n){
            gotoXY(16,28);  cout<<"                     Username      :                 ";
            if(n==1)    {
                gotoXY(36,34);          cerr<<"Username must be under 10 characters."<<endl;
                system("pause>nul");
                gotoXY(36,34);          cerr<<"                                     "<<endl;
            }
            if(n==2)    {
                gotoXY(35,34);          cerr<<"Username must be more than 3 characters."<<endl;
                system("pause>nul");
                gotoXY(35,34);          cerr<<"                                        "<<endl;
            }
        }

    }

    run = 1;
    while(run){
        gotoXY(53,30);  cin>>password;

        try{
            if(cin.fail())                  throw my_ex;
            if(password.length()!=6)        throw 1;
            run=0;
        }
        catch(exception& e){
            cout<<e.what()<<endl;
        }
        catch(int n){
            gotoXY(16,30);  cout<<"                     Password(6)   :                 ";
            if(n==1){
                gotoXY(36,34);          cerr<<"Password must be 6 characters."<<endl;
                system("pause>nul");
                gotoXY(36,34);          cerr<<"                              "<<endl;
            }
        }
    }

    fstream file;
    char data[100];
    strcpy(data,username.c_str());
    strcat(data,".txt");
    file.open(data,ios::in);
    getline(file,un);
    getline(file,pw);
    if(un==username && pw==password){
        gotoXY(27,28);  cout<<"                  Successfully logged in!!!         "<<endl;
        gotoXY(27,29);  cout<<"                  Press any key to continue         "<<endl;
        gotoXY(27,30);  cout<<"                                                    "<<endl;
        gotoXY(27,31);  cout<<"                                                    "<<endl;
                        system("pause>nul");
                        return username;
                        ///go to play...
    }
    else{
        gotoXY(27,28);  cout<<"              !!!!!You are not registered!!!!!      "<<endl;
        gotoXY(27,29);  cout<<"                  Press any key to register         "<<endl;
        gotoXY(27,30);  cout<<"                                                    "<<endl;
        gotoXY(27,31);  cout<<"                                                    "<<endl;
                        loggedin = 0;
                        system("pause>nul");
                        regist();
                        loggedin=1;
                        login();
    }
}

void regist(){
    string username,password,pw;
    int run=0;
    space();
    do{
        gotoXY(16,26);    cout<<"--------------------------------- REGISTER ----------------------------------"<<endl;

        gotoXY(16,28);    cout<<"        Please enter your username       :                    ";
        gotoXY(16,29);    cout<<"                                                              ";
        gotoXY(16,30);    cout<<"        Please enter your password(6)    :                    ";
        gotoXY(16,31);    cout<<"                                                              ";
        gotoXY(16,32);    cout<<"        Please re-enter your password(6) :                    ";

        run = 1;
        while(run){
            gotoXY(59,28);  cin>>username;
            try{
                if(cin.fail())  throw my_ex;
                if(username.length()>10)    throw 1;
                if(username.length()<4)     throw 2;
                run=0;
            }
            catch(exception& e){
                cout<<e.what()<<endl;
            }
            catch(int n){
                gotoXY(16,28);    cout<<"        Please enter your username       :                    ";
                if(n==1){
                    gotoXY(36,34);          cerr<<"Username must be under 10 characters."<<endl;
                    system("pause>nul");
                    gotoXY(36,34);          cerr<<"                                     "<<endl;
                    }
                if(n==2){
                    gotoXY(36,34);          cerr<<"Username must be more than 3 characters."<<endl;
                    system("pause>nul");
                    gotoXY(36,34);          cerr<<"                                        "<<endl;
                }
            }
        }


        run = 1;
        while(run){
            gotoXY(59,30);  cin>>password;
            try{
                if(cin.fail())  throw my_ex;
                if(password.length()!=6)    throw 1;
                run=0;
            }
            catch(exception& e){
                cout<<e.what()<<endl;
            }
            catch(int n){
                gotoXY(16,30);    cout<<"        Please enter your password       :                    ";
                if(n==1){
                    gotoXY(36,34);          cerr<<"Password must be 6 characters."<<endl;
                    system("pause>nul");
                    gotoXY(36,34);          cerr<<"                              "<<endl;
                }
            }
        }

        run=1;
        while(run){
            gotoXY(59,32);  cin>>pw;
            try{
                if(pw != password)     throw 1;
                run=0;
            }
            catch(int n){
                gotoXY(16,32);    cout<<"        Please re-enter your password(6) :                    ";
                if(n==1){
                    gotoXY(36,34);          cerr<<"The password doesn't match!"<<endl;
                    system("pause>nul");
                    gotoXY(36,34);          cerr<<"                           "<<endl;
                }
            }
        }


    }while(password!=pw);

    fstream allfile,file;
    char data[100];
    strcpy(data,username.c_str());
    strcat(data,".txt");
    allfile.open("all.txt",ios::out);
    allfile<<username<<endl;
    file.open(data,ios::out);
    file<<username<<endl<<password;
    allfile.close();
    file.close();
    gotoXY(36,34);      cout<<"Successfully registered!!!"<<endl;
    gotoXY(36,35);      cout<<"Press any key to continue"<<endl;
                        system("pause>nul");
                        ///go to play...
}

int leaderboard(){

    gotoXY(10,5 );  cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
    gotoXY(10,6 );  cout<<"█ █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█ █"<<endl;
    gotoXY(10,7 );  cout<<"█ █ ╔═════╗                                                                            █ █"<<endl;
    gotoXY(10,8 );  cout<<"█ █ ║ ESC ║ BACK     ╔═╗     ╔═════╗ ╔═════╗ ╔════╗  ╔═════╗ ╔═════╗                   █ █"<<endl;
    gotoXY(10,9 );  cout<<"█ █ ╚═════╝          ║ ║     ║ ╔═══╝ ║ ╔═╗ ║ ║ ╔╗ ╚╗ ║ ╔═══╝ ║ ╔═╗ ║                   █ █"<<endl;
    gotoXY(10,10);  cout<<"█ █                  ║ ║     ║ ╚═══╗ ║ ║ ║ ║ ║ ║╚╗ ║ ║ ╚═══╗ ║ ╚═╝╔╝                   █ █"<<endl;
    gotoXY(10,11);  cout<<"█ █                  ║ ║     ║ ╔═══╝ ║ ╚═╝ ║ ║ ║╔╝ ║ ║ ╔═══╝ ║    ╚╗                   █ █"<<endl;
    gotoXY(10,12);  cout<<"█ █                  ║ ╚═══╗ ║ ╚═══╗ ║ ╔═╗ ║ ║ ╚╝ ╔╝ ║ ╚═══╗ ║ ╔═╗ ║                   █ █"<<endl;
    gotoXY(10,13);  cout<<"█ █                  ╚═════╝ ╚═════╝ ╚═╝ ╚═╝ ╚════╝  ╚═════╝ ╚═╝ ╚═╝                   █ █"<<endl;
    gotoXY(10,14);  cout<<"█ █                      ╔═════╗ ╔═════╗ ╔═════╗ ╔═════╗ ╔════╗                        █ █"<<endl;
    gotoXY(10,15);  cout<<"█ █                      ║ ╔═╗ ║ ║ ╔═╗ ║ ║ ╔═╗ ║ ║ ╔═╗ ║ ║ ╔╗ ╚╗                       █ █"<<endl;
    gotoXY(10,16);  cout<<"█ █                      ║ ╚═╩ ╣ ║ ║ ║ ╣ ║ ║ ║ ║ ║ ╚═╝╔╝ ║ ║╚╗ ║                       █ █"<<endl;
    gotoXY(10,17);  cout<<"█ █                      ║ ╔═╦ ╣ ║ ║ ║ ╣ ║ ╚═╝ ║ ║    ╚╗ ║ ║╔╝ ║                       █ █"<<endl;
    gotoXY(10,18);  cout<<"█ █                      ║ ╚═╝ ║ ║ ╚═╝ ║ ║ ╔═╗ ║ ║ ╔═╗ ║ ║ ╚╝ ╔╝                       █ █"<<endl;
    gotoXY(10,19);  cout<<"█ █                      ╚═════╝ ╚═════╝ ╚═╝ ╚═╝ ╚═╝ ╚═╝ ╚════╝                        █ █"<<endl;
    gotoXY(10,20);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,21);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,22);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,23);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,24);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,25);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,26);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,27);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,28);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,29);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,30);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,31);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,32);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,33);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,34);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,35);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,36);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,37);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,38);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,39);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,40);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,41);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,42);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,43);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,44);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,45);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,46);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,47);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,48);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,49);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,50);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,51);  cout<<"█ █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█ █"<<endl;
    gotoXY(10,52);  cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;

    fstream allfile,file;
    string readname[100],un[100],pw[100],s[100];
    char data[100],temp[100],username[50][50],score[50][50];
    int i=0,j,c1,c2,k=25,sc[50],t;
    allfile.open("all.txt",ios::in);
    while(getline(allfile,readname[i])){
        //cout<<un[i]<<endl;
        i++;
    }
    for(j=0;j<=i;j++){
        strcpy(data,readname[j].c_str());
        strcat(data,".txt");
        file.open(data,ios::in);
        getline(file,un[j]);
        strcpy(username[j],un[j].c_str());
        getline(file,pw[j]);
        while(getline(file,s[j])){
            strcpy(score[j],s[j].c_str());
            sc[j]=atoi(score[j]);
        }
        //cout<<un[j]<<score[j]<<endl;
        file.close();
    }
    allfile.close();

    for(c1=i;c1>=0;c1--){
        for(c2=0;c2<c1;c2++){
            if(sc[c2]<sc[c2+1]){
                strcpy(temp,username[c2]);
                strcpy(username[c2],username[c2+1]);
                strcpy(username[c2+1],temp);
                t=sc[c2];
                sc[c2]=sc[c2+1];
                sc[c2+1]=t;
            }
        }
    }

    gotoXY(33,23);  cout<<"[NAME]"<<endl;
    gotoXY(68,23);  cout<<"[SCORE]"<<endl;
    for(j=0;j<=i,k<=50;j++){
        gotoXY(33,k);  cout<<username[j];
        fstream read;
        strcat(username[j],".txt");
        read.open(username[j],ios::in);
        while(getline(read,s[j])){}
        gotoXY(68,k);  cout<<s[j];
        read.close();
        k+=2;
    }

    while(1){
        if(GetAsyncKeyState(VK_ESCAPE))     break;
    }

}

void space(){

    gotoXY(10,32);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,33);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,34);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,35);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,36);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,37);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,38);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,39);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,40);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,41);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,42);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,43);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,44);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,45);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,46);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,47);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,48);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,49);  cout<<"█ █                                                                                    █ █"<<endl;
    gotoXY(10,50);  cout<<"█ █                                                                                    █ █"<<endl;

}

