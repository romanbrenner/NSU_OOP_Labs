#include <gtest/gtest.h>        // Заголовочный файл для Google Test
#include "bitarray.h"

// Тест конструктора по умолчанию
TEST(BitArrayTest, DefaultConstructorTest) {
    BitArray arr;                // Создаем пустой массив битов
    EXPECT_EQ(arr.size(), 0);     // Проверяем, что размер массива равен 0
    EXPECT_TRUE(arr.empty());     // Проверяем, что массив пустой
}

// Тест конструктора с указанием размера и значения
TEST(BitArrayTest, ConstructorWithSizeAndValue) {
    BitArray arr(6, 60);          // Создаем массив из 6 битов с значением 60 (в бинарном виде: 111100)
    EXPECT_EQ(arr.size(), 6);     // Проверяем, что размер массива равен 6
    EXPECT_EQ(arr.to_string(), "001111"); // Проверяем строковое представление (должно быть "001111")
}

// Тест копирующего конструктора
TEST(BitArrayTest, CopyConstructor) {
    BitArray original(5, 27);      // Создаем исходный массив
    BitArray copy(original);       // Создаем копию исходного массива
    EXPECT_EQ(original, copy);     // Проверяем, что копия совпадает с оригиналом
}

// Тест функции swap
TEST(BitArrayTest, SwapTest) {
    BitArray arr1(5, 19);          // Создаем массив arr1 со значением 19 (10011)
    BitArray arr2(5, 27);          // Создаем массив arr2 со значением 27 (11011)
    arr1.swap(arr2);               // Обмениваем значения между arr1 и arr2
    EXPECT_EQ(arr1.to_string(), "11011"); // Проверяем, что arr1 теперь содержит "11011"
    EXPECT_EQ(arr2.to_string(), "11001"); // Проверяем, что arr2 теперь содержит "11001"
}

// Тест оператора присваивания
TEST(BitArrayTest, AssignmentOperatorTest) {
    BitArray arr1(5, 27);         // Создаем массив arr1
    BitArray arr2 = arr1;         // Присваиваем arr1 массиву arr2
    EXPECT_EQ(arr1, arr2);        // Проверяем, что массивы arr1 и arr2 идентичны
}

// Тест метода изменения размера
TEST(BitArrayTest, ResizeTest) {
    BitArray arr(5, 27);          // Создаем массив из 5 битов с начальным значением 19
    arr.resize(7, true);          // Изменяем размер на 7 битов, заполняем новыми битами значением true
    EXPECT_EQ(arr.size(), 7);     // Проверяем, что размер стал 7
    EXPECT_EQ(arr.to_string(), "1101111");  // Проверяем строковое представление (должно быть "1100111")
    arr.resize(3, false);         // Уменьшаем размер до 3, заполняем новыми битами значением false
    EXPECT_EQ(arr.size(), 3);     // Проверяем, что размер стал 3
    EXPECT_EQ(arr.to_string(), "110");  // Проверяем строковое представление (должно быть "110")
}

// Тест метода очистки массива
TEST(BitArrayTest, ClearTest) {
    BitArray arr(5, 27);          // Создаем массив из 5 битов с начальным значением 19
    arr.clear();                  // Очищаем массив
    EXPECT_EQ(arr.size(), 0);     // Проверяем, что размер стал 0
    EXPECT_TRUE(arr.empty());     // Проверяем, что массив теперь пустой
}

// Тест метода добавления нового бита в конец
TEST(BitArrayTest, PushBackTest) {
    BitArray arr(5, 27);          // Создаем массив из 5 битов с начальным значением 19
    arr.push_back(true);          // Добавляем бит со значением true в конец
    EXPECT_EQ(arr.size(), 6);     // Проверяем, что размер стал 6
    EXPECT_EQ(arr.to_string(), "110111");  // Проверяем строковое представление (должно быть "110011")
}

// Тест оператора побитового И
TEST(BitArrayTest, ANDOperatorTest) {
    BitArray arr1(5, 19);         // 10011
    BitArray arr2(5, 27);         // 11011
    arr1 &= arr2;                 // Выполняем побитовое И
    EXPECT_EQ(arr1.to_string(), "11001"); // Проверяем результат (должно быть "11001")
}

// Тест оператора побитового ИЛИ
TEST(BitArrayTest, OROperatorTest) {
    BitArray arr1(5, 19);         // 10011
    BitArray arr2(5, 27);         // 11011
    arr1 |= arr2;                 // Выполняем побитовое ИЛИ
    EXPECT_EQ(arr1.to_string(), "11011"); // Проверяем результат (должно быть "11011")
}

// Тест оператора побитового XOR
TEST(BitArrayTest, XOROperatorTest) {
    BitArray arr1(5, 19);         // 10011
    BitArray arr2(5, 27);         // 11011
    arr1 ^= arr2;                 // Выполняем побитовый XOR
    EXPECT_EQ(arr1.to_string(), "00010"); // Проверяем результат (должно быть "00010")
}

// Тест оператора сдвига влево
TEST(BitArrayTest, LeftShiftOperatorTest) {
    BitArray arr(5, 27);          // 11011
    arr <<= 1;                    // Сдвигаем биты влево на 1
    EXPECT_EQ(arr.to_string(), "10110"); // Проверяем результат (должно быть "10110")
}

// Тест оператора сдвига вправо
TEST(BitArrayTest, RightShiftOperatorTest) {
    BitArray arr(5, 27);          // 11011
    arr >>= 1;                    // Сдвигаем биты вправо на 1
    EXPECT_EQ(arr.to_string(), "01101"); // Проверяем результат (должно быть "01101")
}

// Тест метода set (установка битов)
TEST(BitArrayTest, SetTest) {
    BitArray arr(5, 19);          // 10011
    arr.set(2, true);             // Устанавливаем 2-й бит в значение true
    EXPECT_EQ(arr.to_string(), "11101"); // Проверяем результат
    arr.set();                    // Устанавливаем все биты в true
    EXPECT_EQ(arr.to_string(), "11111"); // Проверяем результат
}

// Тест метода reset (сброс битов)
TEST(BitArrayTest, ResetTest) {
    BitArray arr(5, 19);          // 10011
    arr.reset(0);                 // Сбрасываем 0-й бит
    EXPECT_EQ(arr.to_string(), "01001"); // Проверяем результат
    arr.reset();                  // Сбрасываем все биты
    EXPECT_EQ(arr.to_string(), "00000"); // Проверяем результат
}

// Тест метода any (проверка на наличие хотя бы одного установленного бита)
TEST(BitArrayTest, AnyTest) {
    BitArray arr(5, 0);           // Все биты равны 0
    EXPECT_FALSE(arr.any());      // Проверяем, что нет установленных битов
    arr.set(0, true);             // Устанавливаем первый бит
    EXPECT_TRUE(arr.any());       // Проверяем, что теперь хотя бы один бит установлен
}

// Тест метода none (проверка, что нет установленных битов)
TEST(BitArrayTest, NoneTest) {
    BitArray arr(5, 0);           // Все биты равны 0
    EXPECT_TRUE(arr.none());      // Проверяем, что нет установленных битов
    arr.set(0, true);             // Устанавливаем первый бит
    EXPECT_FALSE(arr.none());     // Проверяем, что теперь есть хотя бы один установленный бит
}

// Тест оператора инверсии (побитовая инверсия)
TEST(BitArrayTest, InversionOperatorTest) {
    BitArray arr(5, 27);          // 11011
    BitArray inverted = ~arr;     // Применяем инверсию
    EXPECT_EQ(inverted.to_string(), "00100"); // Проверяем результат
}

// Тест метода count (подсчет установленных битов)
TEST(BitArrayTest, CountTest) {
    BitArray arr(5, 27);          // 11011
    EXPECT_EQ(arr.count(), 4);    // Проверяем, что установленных битов 3
}

// Тест оператора доступа по индексу
TEST(BitArrayTest, ElementAccessOperatorTest) {
    BitArray arr(5, 27);          // 11011
    EXPECT_TRUE(arr[0]);          // Проверяем первый бит 1
    EXPECT_TRUE(arr[1]);          // Проверяем второй бит 1
    EXPECT_FALSE(arr[2]);         // Проверяем третий бит 0
    EXPECT_TRUE(arr[3]);         // Проверяем четвертый бит 1
    EXPECT_TRUE(arr[4]);          // Проверяем пятый бит 1
}

// Тест метода size (получение размера массива)
TEST(BitArrayTest, SizeTest) {
    BitArray arr(5, 27);          // Создаем массив из 5 битов с начальным значением 27
    EXPECT_EQ(arr.size(), 5);     // Проверяем размер массива
}

// Тест метода empty (проверка, пуст ли массив)
TEST(BitArrayTest, EmptyTest) {
    BitArray arr;                // Создаем пустой массив
    EXPECT_TRUE(arr.empty());     // Проверяем, что массив пустой
    arr.push_back(true);          // Добавляем бит со значением true
    EXPECT_FALSE(arr.empty());    // Проверяем, что массив теперь не пустой
}

TEST(BitArrayTest, ValueTest) {
    BitArray arr1(9, 1024);         // 1000000000
    BitArray arr2(5, 27);         // 11011                // Выполняем побитовое ИЛИ
    EXPECT_TRUE(arr2.size() != arr1.size()); // Проверяем результат (должно быть "11011")
}

// Тест метода to_string (получение строкового представления)
TEST(BitArrayTest, ToStringTest) {
    BitArray arr(5, 27);          // 11011
    EXPECT_EQ(arr.to_string(), "11011"); // Проверяем строковое представление
}

// Тест оператора побитового И с проверкой на разные размеры
TEST(BitArrayTest, ANDOperatorSizeMismatchTest) {
    BitArray arr1(5, 19); //10011        
    BitArray arr2(9, 1023); //111111111   
    try {
        arr1 &= arr2;             // Попытка выполнить побитовое И
        FAIL() << "Expected std::invalid_argument to be thrown";
    } catch (const std::invalid_argument& e) {
        EXPECT_EQ(std::string(e.what()), "BitArrays must have same size");  // Проверка правильности сообщения об ошибке
    } catch (...) {
        FAIL() << "Expected std::invalid_argument, but got different exception";
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);  // Инициализация Google Test
    return RUN_ALL_TESTS();                // Запуск всех тестов
}
//g++ -std=c++14 -o TestResults bitarray_test.cpp bitarray.cpp -lgtest -lgtest_main -pthread