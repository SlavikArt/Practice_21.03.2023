#include<iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int kg;
public:
    Animal() = default;
    Animal(string n, int k)
    {
        name = n;
        kg = k;
    }
    virtual void Print() = 0;
};

struct IAnimal // интерфейс в стиле С++
{
    virtual void Eat() = 0;
    virtual void Move() = 0;
};
struct IBird
{
    virtual void Fly() = 0;
};
struct ISwim
{
    virtual void Swim() = 0;
};
struct IQuack
{
    virtual void Quack() = 0;
};

class Cat : public Animal, public IAnimal
{
    string color;
public:
    Cat(string n, int k, string c) : Animal(n, k)
    {
        color = c;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }
    // реализация интерфейса
    void Eat()
    {
        cout << "Cat eats\n";
    }
    void Move()
    {
        cout << "Cat moves\n";
    }
};

class Parrot : public Animal, public IAnimal, public IBird
{
public:
    Parrot(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    // реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Parrot eats\n";
    }
    void Move()
    {
        cout << "Parrot moves\n";
    }
    // реализация интерфейса IBird
    void Fly()
    {
        cout << "Parrot flies\n";
    }
};

class Elephant : public Animal, public IAnimal
{
public:
    Elephant(string n, int k) : Animal(n, k)
    {
    }

    void Print()
    {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
    }

    void Eat()
    {
        cout << "Elephant eats\n";
    }
    void Move()
    {
        cout << "Elephant moves\n";
    }
};

class Penguin : public Animal, public IAnimal, public ISwim
{
public:
    Penguin(string n, int k) : Animal(n, k)
    {
    }

    void Print()
    {
        cout << "Name: " << name << "\n";
        cout << "Kg: " << kg << "\n";
    }

    void Eat()
    {
        cout << "Penguin eats\n";
    }
    void Move()
    {
        cout << "Penguin moves\n";
    }
    void Swim()
    {
        cout << "Penguin is swiming\n";
    }
};

class Duck : public Animal, public IAnimal, public IQuack
{
public:
    Duck(string n, int k) :Animal(n, k) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }

    void Eat()
    {
        cout << "Parrot eats\n";
    }
    void Move()
    {
        cout << "Parrot moves\n";
    }
    void Quack()
    {
        cout << "Duck quacks!\n";
    }
};

bool isLuckyNumber(int num);

int main()
{
    IAnimal* ref = new Cat("Cat", 3, "white");
    ref->Eat();
    ref->Move();

    ref = new Parrot("Ara", 2);
    ref->Eat();
    ref->Move();

    IBird* f = new Parrot("Ara", 3);
    f->Fly();

    ref = new Elephant("Boss", 500);
    ref->Eat();
    ref->Move();

    ISwim* p = new Penguin("Mike", 5);
    p->Swim();

    IQuack* d = new Duck("Scrooge", 6);
    d->Quack();

    for (int i = 0; i < 2; i++)
    {
        int number;
        cout << "\nEnter a number (6 digit): ";
        cin >> number;

        try
        {
            bool result = isLuckyNumber(number);
            cout << number << " is " << (result ? "" : "not ") << "lucky number!\n";
        }
        catch (const exception& ex)
        {
            cout << ex.what() << "\n";
        }
    }
}

bool isLuckyNumber(int num)
{
    int cnt = 0;
    int tmp = num;
    while (tmp != 0)
    {
        tmp /= 10;
        cnt++;
    }
    if (cnt <= 5 || cnt >= 7)
        throw exception("Number must contain 6 digits!");

    int sum1 = 0;
    for (int i = 0; i < 3; i++)
    {
        sum1 += num % 10;
        num /= 10;
    }

    int sum2 = 0;
    for (int i = 0; i < 3; i++)
    {
        sum2 += num % 10;
        num /= 10;
    }
    return sum1 == sum2;
}
