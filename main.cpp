#include <iostream>
/*2. Написать синглтон, который считает от 100 до 0 (выводит в консоль, после каждого
 * вывода ждет несколько миллисекунд, погугли про wait()), потом завершает работу.*/
class Singleton{
private:
    //Создаём конструктор и диструктор по умолчанию приватными.
    Singleton() = default;
    ~Singleton() = default;
    //Запрещаем создание конструктора копирования и оператора присваивания.
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
    //Запрещаем создание нового объекта при помощи оператора new.
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;

public:
    //Создаём статическую функцию для создания экземпляра объекта, возвращающую ссылку на него.
    static Singleton& GetInstance(){
        //Создаём статический объект класса.
        static Singleton object;
        //Создаём статическую переменную для счётчика.
        static int count = 100;
        //Выводим значение переменной на экран.
        std::cout << count << std::endl;
        //Уменьшаем значение счётчика на единицу
        --count;
        //Возвращаем объект.
        return object; }
};



int main() {

    for (int i = 0; i <= 100; ++i) {
        Singleton::GetInstance();
    }

}
