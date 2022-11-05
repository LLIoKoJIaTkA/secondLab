/*Для реализации структуры данных использовать типы данных "структура" и "указатель".
Базовые операции реализовать с помощью функций и/или процедур.
Создать и продемонстрировать преподавателю программу, реализующую применение разработанной структуры данных.
Исходный код и исполняемый файл программы с указанием компилятора прикрепить в качестве ответа.
Количество элементов в структуре данных храниться не должно.*/

//Реализовать одноосвязный линейный список 
//Проверка на наличие элементов в структуре данных
//Получение количества элементов  в структуре данных
//Добавление элемента  в структуру данных
//Вставка элемента в структуру данных после текущего
//Удаление текущего элемента структуры данных
//Очистка структуры данных
//Перемещение по элементам структуры данных
//Чтение информации из текущего элемента структуры данных

#include <iostream>
#include <string>

using namespace std;

int menu()
{
	int change;
	cout << "1. Проверка на наличие элементов в структуре данных" << endl;
	cout << "2. Получение количества элементов  в структуре данных" << endl;
    cout << "3. Добавление элемента  в структуру данных" << endl;
    cout << "4. Вставка элемента в структуру данных после текущего" << endl;
    cout << "5. Удаление текущего элемента структуры данных" << endl;
    cout << "6. Очистка структуры данных" << endl;
    cout << "7. Перемещение по элементам структуры данных" << endl;
    cout << "8. Чтение информации из текущего элемента структуры данных" << endl;
    cout << "9. Выход из программы" << endl << endl;
	cin >> change;
    cout << endl;
	return change;
}

class cFool
{
public:
    cFool& operator >> (string& a) ///-------------------------std::string:
    {
        getline(cin, a);
        promt = "";
        return *this;
    } 

    cFool& operator >> (unsigned char& a) ///---------------------unsigned char:
    {
        bool      is_error;
        unsigned  n;
        do
        {
            cin >> n;

            is_error = cin.fail() || cin.get() != '\n';
            if (is_error)
            {
                cout << "Error!\n\n" << promt;
                cin.clear();
                cin.ignore(9999, '\n');
                cin.sync();
            }
            else if (n > 255)
            {
                is_error = true;
                cout << "Error bound!\n\n" << promt;
            }
        } while (is_error);

        a = n;
        promt = "";
        return *this;
    }

    template<class T>
    cFool& operator >> (T& a) ///--------------------------------------template:
    {
        cin >> a;

        while (cin.fail() || cin.get() != '\n')
        {
            cin.clear();
            cin.ignore(9999, '\n');
            cin.sync();
            cout << "Error!\n\n" << promt; cin >> a;
        }
        promt = "";
        return *this;
    }

    string promt;
    cFool& operator >>(const char* promt_) ///----------------------------promt
    {
        cout << promt_;
        promt = promt_;
        return *this;
    }
}cin_fool;

class carInfo
{
protected:
    int yearFactory; //Год выпуска
    int fuelTankCapacity; //Объём топливного бака
    int maxSpeed; //Максимальная скорость
    int horsePower; //Кол-во лошадиных сил
    int engineCapacity; //Объём двигателя
    bool spareWheel; //Наличие запасных колёс
    bool configuration; //Комплектация
    string carBrand; //Марка
    string color; //Цвет
    string bodyType; //Тип кузова
public:
    carInfo* next; // Ccылка на след. объект

    carInfo(int factory, int fuel, int speed, int power, int engine, bool wheel ,bool conf, string brand, string color, string type)
    {
        this->yearFactory = factory;
        this->fuelTankCapacity = fuel;
        this->maxSpeed = speed;
        this->horsePower = power;
        this->engineCapacity = engine;
        this->spareWheel = wheel;
        this->configuration = conf;
        this->carBrand = brand;
        this->color = color;
        this->bodyType = type;
        this->next = NULL;
    }

    carInfo(int factory, int fuel, int speed, int power, int engine, bool wheel, bool conf, string brand, string color, string type, carInfo* address)
    {
        this->yearFactory = factory;
        this->fuelTankCapacity = fuel;
        this->maxSpeed = speed;
        this->horsePower = power;
        this->engineCapacity = engine;
        this->spareWheel = wheel;
        this->configuration = conf;
        this->carBrand = brand;
        this->color = color;
        this->bodyType = type;
        this->next = address;
    }

    void getCarInfo()
    {
        cout << "Выводится элемент: 0x" << this << endl << endl;
        cout << "Следующий элемент: 0x" << this->next << endl << endl;
        cout << "Год выпуска: " << yearFactory << endl;
        cout << "Объём топливного бака: " << fuelTankCapacity << endl;
        cout << "Максимальная скорость: " << maxSpeed << endl;
        cout << "Кол-во лашдиных сил: " << horsePower << endl;
        cout << "Объём двигателя: " << engineCapacity << endl;
        cout << "Наличие запасных колёс: " << spareWheel << " (1 - есть в наличии; 0 - нет в наличии)" << endl;
        cout << "Комплектация: " << configuration<< " (1 - полная, 0 - не полная)" << endl;
        cout << "Марка автомобиля: " << carBrand << endl;
        cout << "Цвет автомобиля: " << color << endl;
        cout << "Тип кузова автомобиля: " << bodyType << endl << endl;
    }

    ~carInfo()
    {
        cout << "Работает диструктор объекта класса" << endl;
        
    }

    carInfo* getNext()
    {
        carInfo* address = nullptr;
        address = this->next;
        return address;
    }
};

class car
{
    class carInfo* start;
    class carInfo* now;
public:
    car()
    {
        now = NULL;
        start = NULL;
    }

    ~car()
    {
        carInfo* tmp;
        while (start)
        {
            cout << "Удаление объекта: " << start << endl;
            tmp = start->next;
            delete start;
            start = tmp;
        }
        cout << "Деструктор завершил свою работу" << endl << endl;
    }

    void emptyCar()
    {
        if (now == NULL && start == NULL)
            cout << "Элементы не обнаружены" << endl;
        else
            cout << "У данного класса есть элементы" << endl << endl;
    }

    void moveNext()
    {
        if (now->next == NULL)
            now = start;
        else
            now = now->next;
    }

    void create()
    {
        int yearFactory; //Год выпуска
        int fuelTankCapacity; //Объём топливного бака
        int maxSpeed; //Максимальная скорость
        int horsePower; //Кол-во лошадиных сил
        int engineCapacity; //Объём двигателя
        bool spareWheel; //Наличие запасных колёс
        bool configuration; //Комплектация
        string carBrand; //Марка
        string color; //Цвет
        string bodyType; //Тип кузова
        
        cout << endl << "Введите год выпуска:" << endl;
        cin_fool >> yearFactory;
        
        cout << "Введите объём топливного бака:" << endl;
        cin_fool >> fuelTankCapacity;

        cout << "Введите максимальную скорость авто:" << endl;
        cin_fool >> maxSpeed;

        cout << "Введите количество лошадиных сил:" << endl;
        cin_fool >> horsePower;

        cout << "Введите объём двигателя:" << endl;
        cin_fool >> engineCapacity;

        cout << "Наличие запасных колёс: 0 - нет, 1 - да" << endl;
        cin_fool >> spareWheel;

        cout << "Введите тип комплектации авто: 0 - не полная, 1 - полная" << endl;
        cin_fool >> configuration;

        cout << "Введите марку авто:" << endl;
        getline(cin, carBrand);
        cout << "Введите цвет авто:" << endl;
        getline(cin, color);
        cout << "Введите тип кузова авто:" << endl;
        getline(cin, bodyType);
        cout << endl;
        this->start = new carInfo(yearFactory, fuelTankCapacity, maxSpeed, horsePower, engineCapacity, spareWheel, configuration, carBrand, color, bodyType);
        this->now = start;
    }

    void getCarInfo()
    {
        now->getCarInfo();
    }

    int amountOfObjects()
    {
        carInfo* tmp;
        tmp = start;
        int amount = 0;
        do{
            amount++;
            if (tmp->next != NULL)
                tmp = tmp->next;
            else break;
        } while (true);
        return amount;
    }

    void addAnObject()
    {
        int yearFactory; //Год выпуска
        int fuelTankCapacity; //Объём топливного бака
        int maxSpeed; //Максимальная скорость
        int horsePower; //Кол-во лошадиных сил
        int engineCapacity; //Объём двигателя
        bool spareWheel; //Наличие запасных колёс
        bool configuration; //Комплектация
        string carBrand; //Марка
        string color; //Цвет
        string bodyType; //Тип кузова

        cout << endl << "Введите год выпуска:" << endl;
        cin_fool >> yearFactory;

        cout << "Введите объём топливного бака:" << endl;
        cin_fool >> fuelTankCapacity;

        cout << "Введите максимальную скорость авто:" << endl;
        cin_fool >> maxSpeed;

        cout << "Введите количество лошадиных сил:" << endl;
        cin_fool >> horsePower;

        cout << "Введите объём двигателя:" << endl;
        cin_fool >> engineCapacity;

        cout << "Наличие запасных колёс: 0 - нет, 1 - да" << endl;
        cin_fool >> spareWheel;

        cout << "Введите тип комплектации авто: 0 - не полная, 1 - полная" << endl;
        cin_fool >> configuration;

        cout << "Введите марку авто:" << endl;
        getline(cin, carBrand);
        cout << "Введите цвет авто:" << endl;
        getline(cin, color);
        cout << "Введите тип кузова авто:" << endl;
        getline(cin, bodyType);
        cout << endl;
        
        carInfo* tmp;
        tmp = now;
        do {
            if (tmp->next != NULL)
                tmp = tmp->next;
            else break;
        } while (true);

        tmp->next = new carInfo(yearFactory, fuelTankCapacity, maxSpeed, horsePower, engineCapacity, spareWheel, configuration, carBrand, color, bodyType);
    }

    void insertAnObject()
    {
        int yearFactory; //Год выпуска
        int fuelTankCapacity; //Объём топливного бака
        int maxSpeed; //Максимальная скорость
        int horsePower; //Кол-во лошадиных сил
        int engineCapacity; //Объём двигателя
        bool spareWheel; //Наличие запасных колёс
        bool configuration; //Комплектация
        string carBrand; //Марка
        string color; //Цвет
        string bodyType; //Тип кузова

        cout << endl << "Введите год выпуска:" << endl;
        cin_fool >> yearFactory;

        cout << "Введите объём топливного бака:" << endl;
        cin_fool >> fuelTankCapacity;

        cout << "Введите максимальную скорость авто:" << endl;
        cin_fool >> maxSpeed;

        cout << "Введите количество лошадиных сил:" << endl;
        cin_fool >> horsePower;

        cout << "Введите объём двигателя:" << endl;
        cin_fool >> engineCapacity;

        cout << "Наличие запасных колёс: 0 - нет, 1 - да" << endl;
        cin_fool >> spareWheel;

        cout << "Введите тип комплектации авто: 0 - не полная, 1 - полная" << endl;
        cin_fool >> configuration;

        cout << "Введите марку авто:" << endl;
        getline(cin, carBrand);
        cout << "Введите цвет авто:" << endl;
        getline(cin, color);
        cout << "Введите тип кузова авто:" << endl;
        getline(cin, bodyType);
        cout << endl;

        carInfo* address = nullptr;
        address = now->getNext();
        now->next = new carInfo(yearFactory, fuelTankCapacity, maxSpeed, horsePower, engineCapacity, spareWheel, configuration, carBrand, color, bodyType, address);
    }

    void deleteAnObject()
    {
        carInfo* tmp = nullptr;
        carInfo* address;
        if (now != start) 
        {
            tmp = start;
            while (tmp->next != now)
            {
                tmp = tmp->next;
            }
            address = now->getNext();
            now = tmp;
            delete tmp->next;
            tmp->next = address;
        }
        else if(now == start)
        {
            int amount = amountOfObjects();
            if (amount == 1)
                start->~carInfo();
            else
            {
                start = start->next;
                tmp = now;
                delete tmp;
                now = start;
            }
        }
    }

};