// 이번 과제는 제출 일정을 맞추기 위해 AI의 도움을 받아 작성했으며,
// 주요 로직은 스스로 이해하고 수정하며 구현했습니다.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 동물 class
class Animal {
public:
    // 순수 가상 함수
    virtual void makeSound() = 0;

    // 소멸자
    virtual ~Animal() {}
};

// 강아지 class
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "멍멍" << endl;
    }
};

// 고양이 class
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "야옹" << endl;
    }
};

// 소 class
class Cow : public Animal {
public:
    void makeSound() override {
        cout << "음머" << endl;
    }
};

// random 동물 생성 함수
Animal* createRandomAnimal() {
    int num = rand() % 3;

    if (num == 0) return new Dog();
    else if (num == 1) return new Cat();
    else return new Cow();
}

// 동물원 class
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

    cout << "동물들의 소리를 들어보세요!" << endl;
    myZoo.showAllSounds();

    return 0;
}
