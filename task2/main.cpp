#include "Base.h"

int main() {
    Base myBase;
    myBase["Ivanov"] = MyData(MyData::Sex::MALE, 30, "Ingener", 25000);
    myBase["Petrova"] = MyData(MyData::Sex::FMALE, 22, "Economist", 18000);
    myBase["Ziryanova"] = MyData(MyData::Sex::FMALE, 22, "Electric", 12300);
    myBase["Pudavov"] = MyData(MyData::Sex::MALE, 23, "PizzaDeliver", 10000);

    cout << myBase << endl;

    myBase.deletePair("Petrova");
    cout << myBase << endl;

    Base bd = myBase;
    myBase = bd;

    Base bd2 = move(bd);
    bd = move(bd2);

    myBase.~Base();
    cout << bd << endl;

    bd.~Base();
    cout << bd2 << endl;

    return 0;
}