
class Menu{
public:
    Menu *next;
    int time;
    char *name;
    Menu(char[],int);
    void insert(Menu*&);
    Menu* move_next();
    ~Menu();
};
