// �̹� ������ ���� ������ ���߱� ���� AI�� ������ �޾� �ۼ�������,
// �ֿ� ������ ������ �����ϰ� �����ϸ� �����߽��ϴ�.
f

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ���� class
class Animal {
public:
    // ���� ���� �Լ�
    virtual void makeSound() = 0;

    // �Ҹ���
    virtual ~Animal() {}
};

// ������ class
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "�۸�" << endl;
    }
};

// ����� class
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "�߿�" << endl;
    }
};

// �� class
class Cow : public Animal {
public:
    void makeSound() override {
        cout << "����" << endl;
    }
};

// random ���� ���� �Լ�
Animal* createRandomAnimal() {
    int num = rand() % 3;

    if (num == 0) return new Dog();
    else if (num == 1) return new Cat();
    else return new Cow();
}

// ������ class
class Zoo {
private:
    Animal* animals[10];
    int count = 0;

public:
    void addAnimal(Animal* a) {
        if (count < 10) {
            animals[count] = a;
            count++;
        }
    }

    void showAllSounds() {
        for (int i = 0; i < count; i++) {
            animals[i]->makeSound();
        }
    }

    ~Zoo() {
        for (int i = 0; i < count; i++) {
            delete animals[i];
        }
    }
};

int main() {
    srand(time(0));

    Zoo myZoo;

    for (int i = 0; i < 5; i++) {
        Animal* a = createRandomAnimal();
        myZoo.addAnimal(a);
    }

    cout << "�������� �Ҹ��� ������!" << endl;
    myZoo.showAllSounds();

    return 0;
}