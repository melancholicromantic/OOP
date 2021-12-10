#include <iostream>

class skyscr {
protected:
    int h, l;
public:
    skyscr() {
        printf("skyscr()\n");
        h = 0;
        l = 0;
    }
    skyscr(int h, int l) {
        printf("skyscr(int h, int l)\n");
        this->h = h;
        this->l = l;
    }
    skyscr(const skyscr& s) {
        printf("skyscr(const skyscr& s)\n");
        h = s.h;
        l = s.l;
    }
    virtual ~skyscr() {
        printf("~skyscr\n");
        printf("%d %d\n", h, l);
    }
    void changegeometry(int ch, int cl) {
        h = h + ch;
        l = l + cl;
    }
    int space();
};

int skyscr::space() {
    return h * l;
}

class skyscrfloors : public skyscr {
protected:
    int floors = 0;
public:
    skyscrfloors() : skyscr() {
        printf("skyscrfloors()\n");
        floors = 0;
    }
    skyscrfloors(int h, int l, int floors) : skyscr() {
        printf("skyscrfloors(int h, int l)\n");
        this->h = h;
        this->l = l;
        this->floors = floors;
    }
    skyscrfloors(const skyscrfloors& s) : skyscr() {
        printf("skyscrfloors(const skyscr& s)\n");
        h = s.h;
        l = s.l;
        floors = s.floors;
    }
    ~skyscrfloors() {
        printf("~skyscrfloors\n");
        printf("%d %d %d\n", h, l, floors);
    }
    void changegeometry(int ch, int cl) {
        h = h + ch;
        l = l + cl;
    }
    void change_floors(int newf) {
        floors = newf;
    }
};


class unites {
protected:
    skyscr* s1;
    skyscr* s2;
public:
    unites() {
        printf("unites()\n");
        s1 = new skyscr;
        s2 = new skyscr;
    }
    unites(int h1, int l1, int h2, int l2) {
        printf("unites(int h, int l)\n");
        s1 = new skyscr(h1, l1);
        s2 = new skyscr(h2, l2);
    }
    unites(const unites& s) {
        printf("unites(const skyscr& s)\n");
        s1 = new skyscr(*(s.s1));
        s2 = new skyscr(*(s.s2));
    }
    ~unites() {
        delete s1;
        delete s2;
        printf("~unites\n");
    }
};

int main()
{
    {
        skyscr WTC1;
        skyscr WTC2(415, 63);
        skyscr WTC1rec(WTC1);
    }
    printf("\n\n\n");
    skyscr* WTC7 = new skyscr;
    skyscr* WTC4 = new skyscr(300, 50);
    skyscr* WTC5 = new skyscr(*WTC4);
    printf("\nspace: %d\n\n", WTC4->space());
    WTC4->changegeometry(241, 13);

    delete WTC5;
    delete WTC4;
    delete WTC7;

    printf("\n\n\n");

    skyscrfloors* WTC110f = new skyscrfloors(541, 63, 110);
    delete WTC110f;

    printf("\n\n\n");

    skyscr* s1 = new skyscrfloors(541, 63, 110);
    skyscrfloors* s2 = new skyscrfloors(541, 63, 110);

    delete s1;
    delete s2;

    printf("\n\n\n");

    unites* united1 = new unites();
    unites* united2 = new unites(*united1);

    delete united1;
    delete united2;
}

