/*��� ���������� ��������� ������ ������������ ���� ������ "���������" � "���������".
������� �������� ����������� � ������� ������� �/��� ��������.
������� � ������������������ ������������� ���������, ����������� ���������� ������������� ��������� ������.
�������� ��� � ����������� ���� ��������� � ��������� ����������� ���������� � �������� ������.
���������� ��������� � ��������� ������ ��������� �� ������.*/

//����������� ������������ �������� ������ 
//�������� �� ������� ��������� � ��������� ������
//��������� ���������� ���������  � ��������� ������
//���������� ��������  � ��������� ������
//������� �������� � ��������� ������ ����� ��������
//�������� �������� �������� ��������� ������
//������� ��������� ������
//����������� �� ��������� ��������� ������
//������ ���������� �� �������� �������� ��������� ������

#include <iostream>
#include <string>

using namespace std;

int menu()
{
	int change;
	cout << "1. �������� �� ������� ��������� � ��������� ������" << endl;
	cout << "2. ��������� ���������� ���������  � ��������� ������" << endl;
    cout << "3. ���������� ��������  � ��������� ������" << endl;
    cout << "4. ������� �������� � ��������� ������ ����� ��������" << endl;
    cout << "5. �������� �������� �������� ��������� ������" << endl;
    cout << "6. ������� ��������� ������" << endl;
    cout << "7. ����������� �� ��������� ��������� ������" << endl;
    cout << "8. ������ ���������� �� �������� �������� ��������� ������" << endl;
    cout << "9. ����� �� ���������" << endl << endl;
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
    int yearFactory; //��� �������
    int fuelTankCapacity; //����� ���������� ����
    int maxSpeed; //������������ ��������
    int horsePower; //���-�� ��������� ���
    int engineCapacity; //����� ���������
    bool spareWheel; //������� �������� ����
    bool configuration; //������������
    string carBrand; //�����
    string color; //����
    string bodyType; //��� ������
public:
    carInfo* next; // Cc���� �� ����. ������

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
        cout << "��������� �������: 0x" << this << endl << endl;
        cout << "��������� �������: 0x" << this->next << endl << endl;
        cout << "��� �������: " << yearFactory << endl;
        cout << "����� ���������� ����: " << fuelTankCapacity << endl;
        cout << "������������ ��������: " << maxSpeed << endl;
        cout << "���-�� �������� ���: " << horsePower << endl;
        cout << "����� ���������: " << engineCapacity << endl;
        cout << "������� �������� ����: " << spareWheel << " (1 - ���� � �������; 0 - ��� � �������)" << endl;
        cout << "������������: " << configuration<< " (1 - ������, 0 - �� ������)" << endl;
        cout << "����� ����������: " << carBrand << endl;
        cout << "���� ����������: " << color << endl;
        cout << "��� ������ ����������: " << bodyType << endl << endl;
    }

    ~carInfo()
    {
        cout << "�������� ���������� ������� ������" << endl;
        
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
            cout << "�������� �������: " << start << endl;
            tmp = start->next;
            delete start;
            start = tmp;
        }
        cout << "���������� �������� ���� ������" << endl << endl;
    }

    void emptyCar()
    {
        if (now == NULL && start == NULL)
            cout << "�������� �� ����������" << endl;
        else
            cout << "� ������� ������ ���� ��������" << endl << endl;
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
        int yearFactory; //��� �������
        int fuelTankCapacity; //����� ���������� ����
        int maxSpeed; //������������ ��������
        int horsePower; //���-�� ��������� ���
        int engineCapacity; //����� ���������
        bool spareWheel; //������� �������� ����
        bool configuration; //������������
        string carBrand; //�����
        string color; //����
        string bodyType; //��� ������
        
        cout << endl << "������� ��� �������:" << endl;
        cin_fool >> yearFactory;
        
        cout << "������� ����� ���������� ����:" << endl;
        cin_fool >> fuelTankCapacity;

        cout << "������� ������������ �������� ����:" << endl;
        cin_fool >> maxSpeed;

        cout << "������� ���������� ��������� ���:" << endl;
        cin_fool >> horsePower;

        cout << "������� ����� ���������:" << endl;
        cin_fool >> engineCapacity;

        cout << "������� �������� ����: 0 - ���, 1 - ��" << endl;
        cin_fool >> spareWheel;

        cout << "������� ��� ������������ ����: 0 - �� ������, 1 - ������" << endl;
        cin_fool >> configuration;

        cout << "������� ����� ����:" << endl;
        getline(cin, carBrand);
        cout << "������� ���� ����:" << endl;
        getline(cin, color);
        cout << "������� ��� ������ ����:" << endl;
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
        int yearFactory; //��� �������
        int fuelTankCapacity; //����� ���������� ����
        int maxSpeed; //������������ ��������
        int horsePower; //���-�� ��������� ���
        int engineCapacity; //����� ���������
        bool spareWheel; //������� �������� ����
        bool configuration; //������������
        string carBrand; //�����
        string color; //����
        string bodyType; //��� ������

        cout << endl << "������� ��� �������:" << endl;
        cin_fool >> yearFactory;

        cout << "������� ����� ���������� ����:" << endl;
        cin_fool >> fuelTankCapacity;

        cout << "������� ������������ �������� ����:" << endl;
        cin_fool >> maxSpeed;

        cout << "������� ���������� ��������� ���:" << endl;
        cin_fool >> horsePower;

        cout << "������� ����� ���������:" << endl;
        cin_fool >> engineCapacity;

        cout << "������� �������� ����: 0 - ���, 1 - ��" << endl;
        cin_fool >> spareWheel;

        cout << "������� ��� ������������ ����: 0 - �� ������, 1 - ������" << endl;
        cin_fool >> configuration;

        cout << "������� ����� ����:" << endl;
        getline(cin, carBrand);
        cout << "������� ���� ����:" << endl;
        getline(cin, color);
        cout << "������� ��� ������ ����:" << endl;
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
        int yearFactory; //��� �������
        int fuelTankCapacity; //����� ���������� ����
        int maxSpeed; //������������ ��������
        int horsePower; //���-�� ��������� ���
        int engineCapacity; //����� ���������
        bool spareWheel; //������� �������� ����
        bool configuration; //������������
        string carBrand; //�����
        string color; //����
        string bodyType; //��� ������

        cout << endl << "������� ��� �������:" << endl;
        cin_fool >> yearFactory;

        cout << "������� ����� ���������� ����:" << endl;
        cin_fool >> fuelTankCapacity;

        cout << "������� ������������ �������� ����:" << endl;
        cin_fool >> maxSpeed;

        cout << "������� ���������� ��������� ���:" << endl;
        cin_fool >> horsePower;

        cout << "������� ����� ���������:" << endl;
        cin_fool >> engineCapacity;

        cout << "������� �������� ����: 0 - ���, 1 - ��" << endl;
        cin_fool >> spareWheel;

        cout << "������� ��� ������������ ����: 0 - �� ������, 1 - ������" << endl;
        cin_fool >> configuration;

        cout << "������� ����� ����:" << endl;
        getline(cin, carBrand);
        cout << "������� ���� ����:" << endl;
        getline(cin, color);
        cout << "������� ��� ������ ����:" << endl;
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