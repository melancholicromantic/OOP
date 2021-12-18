#include <iostream>
#include <cmath>
#include <ctime>

class tank { // Создаём базовый класс
public:
    int number = 0;
    tank() {
        number = 0;
    }
    virtual ~tank() {
        printf("-tank\n");
    }
    virtual void maintask() = 0; // Задаём виртуальные методы
    virtual void special() = 0;
    virtual int getsmth() = 0;

};

class heavytank : public tank { // Создаём дочерний класс
protected:
    int mass, weapon, armor, speed;
public:
    heavytank(){
        mass = 0;
        armor = 0;
        speed = 0;
        weapon = 0;
    }
    heavytank(int mass, int weapon, int armor, int speed) {
        this->mass = mass;
        this->weapon = weapon;
        this->armor = armor;
        this->speed = speed;
    }
    heavytank(heavytank& t) {
        this->armor = t.armor;
        this->mass = t.mass;
        this->speed = t.speed;
        this->weapon = t.weapon;
    }
    ~heavytank() {
        printf("~heavytank\n");  //Создаём конструкторы и деструкторы
    }
    int tth(int mass, int weapon, int armor, int speed) { // Возвращаем ТТХ танка
        return mass + weapon + armor + speed;
    }
    void maintask() override { // Переопределяем метод
        printf("block damage\n");
    }
    void special() override { // Переопределяем метод
        printf("shot\n");
    }
};

class sovietheavy : public heavytank { // Создаём дочерний класс дочерернего класса класса tank
protected:
    int utility = 0;
public:
    sovietheavy() : heavytank() {
        utility = 0;
    }
    sovietheavy(int mass, int weapon, int armor, int speed, int utility) : heavytank(mass, weapon, armor, speed) {
        this->utility = utility;
    }
    sovietheavy(sovietheavy& t) {
        this->armor = t.armor;
        this->mass = t.mass;
        this->speed = t.speed;
        this->weapon = t.weapon;
        this->utility = t.utility;
    }
    ~sovietheavy() {
        printf("~sovietheavy\n");
    }
    void set_utility(int utility) { // Задаём полезность
        this->utility = utility;
    }
    int getsmth() override { // Возвращаем полезность
        return utility;
    }
};

class store {
private:
    tank** tk;
    int am;
public:
    store(int am) {
        this->am = am;
        tk = new tank * [am];
    }
    ~store() {
        delete[] tk;
        printf("~store\n");
    }
    void settk(int num, tank* newtk) { // Устанавливаем новый элемент
        tk[num] = newtk;
    }
    tank& gettk(int num) { // Возвращаем элемент массива
        return *tk[num];
    }
    void deltk(int num) { // Удаление элементов
       am -= 1;
       tank** newtks = new tank*[am];
       for (int i = 0; i < num; i++) {
           newtks[i] = tk[i];
       }
       for (int i = num; i < am; i++) {
           newtks[i] = tk[i + 1];
       }

       delete[] tk;

       tk = newtks;

       printf("%d deleted\n", num);
    }
    void addtk(tank* t) { // Добавление танка
        am = am + 1;
        tank** newtks = new tank * [am];
        for (int i = 0; i < am - 1; i++) {
            newtks[i] = tk[i];
        }

        newtks[am - 1] = t;
        delete[] tk;

        tk = newtks;

        printf("%d added\n", am);
    }
    void removeinf(int num) { // Зануление
        tk[num] = NULL;
    }
    int retam() { // Возвращаем количество
        return am;
    }
    int not0() { // Количество ненулевых элементов
        int amount = 0;
        for (int i = 0; i < am; i++) {
            if (tk[i] != NULL) {
                amount += 1;
            }
        }
        return amount;
    }
};

void testirovka(int num) {
    store angar(num);
    for (int i = 0; i < num; i++) {
        angar.settk(i, new sovietheavy(10 * (i + 1), 20 * (i + 1), 30 * (i + 1), 40 * (i + 1), 100 - (i + 1)));
        angar.gettk(i).number = i + 1;
    }
    srand(time(NULL));

    int rand1 = 0;
    for (int i = 0; i < angar.retam(); i++) {
        printf("%d\n", i);
        rand1 = rand();
        if ((rand1 % 3) == 0) {
            printf("Вызов функции getsmth\n");
            angar.gettk(i).getsmth();
        }
        else if ((rand1 % 3) == 1) {
            printf("Вызов функции maintask\n");
            angar.gettk(i).maintask();
        }
        else if ((rand1 % 3) == 2) {
            printf("Вызов функции special\n");
            angar.gettk(i).special();
        }
    }
    
    printf("Изначалоьно элементов %d\n", angar.retam());

    int razm = (angar.retam() / 2);
    for (int i = 0; i < razm; i++) {
        angar.addtk(new sovietheavy());
    }

    printf("После добавдения: %d\n", angar.retam());

    razm = (angar.retam() / 2);
    for (int i = 0; i < (angar.retam() / 2); i++) {
        angar.removeinf(rand() % (angar.retam() / 2));
    }

    printf("Нунулевых полей: %d\n", angar.not0());

    razm = (angar.retam() / 2);
    for (int i = 0; i < (angar.retam() / 2); i++) {
        angar.deltk(rand() % (angar.retam() / 2));
    }

    printf("После удаления %d\n", angar.retam());
}
int main()
{
    setlocale(LC_ALL, "rus");
    printf("Тест для 10 элементов\n\n");
    testirovka(10);
    printf("Тест для 100 элементов\n\n");
    testirovka(100);
    printf("Тест для 1000 элементов\n\n");
    testirovka(1000);
}

