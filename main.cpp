#include <iostream>
#include <typeinfo>

struct TypeA {};
struct TypeB;

struct TypeC {
    virtual ~TypeC() = default;
};
struct TypeD : public TypeC {};

int main() {
    std::cout << typeid(int).name() << std::endl;
    std::cout << typeid(int).name() << std::endl;
    std::cout << typeid(TypeA).name() << std::endl;
    TypeA* ptr = nullptr;
    std::cout << typeid(ptr).name() << std::endl;
    std::cout << typeid(TypeA*).name() << std::endl;

    if (typeid(int) == typeid(int)) {
        std::cout << "same type" << std::endl;
    }

    std::cout << typeid(TypeB*).name() << std::endl;

    TypeC* base_ptr = nullptr;
    base_ptr = new TypeD;
    std::cout << typeid(base_ptr).name() << std::endl;
    std::cout << typeid(*base_ptr).name() << std::endl;
}
