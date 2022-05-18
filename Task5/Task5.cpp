
 // Task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

struct LAPTOP {
    string name;
    string processor;
    string graphicsCard;
    string ram;
    string hdd;
    string ssd;
    bool isIntPrice = false;

    union
    {
        struct {  int intPrice; } intPriceShop;
        struct { float floatPrice; } floatPriceShop;
    };
    
    void setLaptop() {
        cout << "Введите характеристики ноутбука  \n";

        cout << "Введите имя ноутбука: ";
        cin >> name;
        cout << "Введите название процессора: ";
        cin >> processor;
        cout << "Введите название видеокарты: ";
        cin >> graphicsCard;
        cout << "Введите название оперативной памяти: ";
        cin >> ram;
        cout << "Введите название hdd: ";
        cin >> hdd;
        cout << "Введите название ssd: ";
        cin >> ssd;
        getUnion();
    }

    void getUnion() {
        cout << "Если стоимость ноутбука целочисленная,то напишете 'yes', если нет - то введите любую букву ";
        string answer;
        cin >> answer;
        cout << "Введите значениe: ";
        if (answer == "yes") {
            cin >> intPriceShop.intPrice;
            isIntPrice = true;
        }
        else {
            cin >> floatPriceShop.floatPrice;
        }
        
    }

    string getLaptop(){
        if (isIntPrice) {
        
            cout << intPriceShop.intPrice;
        }
        else {
            cout << floatPriceShop.floatPrice;

        }
        cout << "\n";

        return name + "\n" + processor + "\n" + graphicsCard + "\n"
            + ram + "\n" + hdd + "\n" + ssd + "\n" ;
    }

    void deleteLaptop() {
        delete this;
    }
};

void setLaptops(LAPTOP* laptops, int n) {
    for (size_t i = 0; i < n; i++)
    {
        laptops[i].setLaptop();
        cout << "\n";
    }
}

void getAllLaprtops(LAPTOP* laptops,int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << "--------------- \n";
        cout << laptops[i].getLaptop();
        cout << "--------------- \n";
    }
    
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    cout << "Введите кол-во моделей ноутбука, которые вы хотите добавить: ";

    int n;
    cin >> n;

    LAPTOP* laptops = new LAPTOP[n];

    setLaptops(laptops,n);

    getAllLaprtops(laptops,n);

    delete[] laptops;

    cout << "ok";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
