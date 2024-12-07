#include "bitarray.h"
#include <algorithm> 

// Конструктор с заданным количеством бит и значением
BitArray::BitArray(int num_bits, unsigned long value) { 
    resize(num_bits, false); // Инициализация битов нулями
    // Устанавливаем биты в зависимости от переданного значения
    for (int i = 0; i < static_cast<int>(sizeof(long)) * 8 && i < num_bits; i++) {
        bits[i] = (value & (1L << i)) != 0; // Проверка, установлен ли i-й бит
    }
}

// Конструктор копирования
BitArray::BitArray(const BitArray& b) { 
    bits = b.bits; // Копируем вектор битов
}

// Метод для обмена содержимым двух объектов
//void BitArray::swap(BitArray& b) {
//    std::swap(bits, b.bits); // Меняем местами вектора битов
//}

void BitArray::swap(BitArray& b) {
    // Обмен содержимым вектора битов вручную
    std::vector<bool> temp = bits;
    bits = b.bits;
    b.bits = temp;
}

// Оператор присваивания
BitArray& BitArray::operator=(const BitArray& b) {
    if (this != &b) { // Проверка на самоприсваивание
        bits = b.bits; // Копируем вектор битов
    }
    return *this;
}

// Метод для изменения размера массива бит
//void BitArray::resize(int num_bits, bool value) {
//    bits.resize(num_bits, value); // Изменяем размер и заполняем новыми значениями
//}

void BitArray::resize(int num_bits, bool value) {
    // Если новый размер больше текущего
    if (num_bits > bits.size()) {
        // Добавляем новые элементы
        for (int i = bits.size(); i < num_bits; ++i) {
            bits.push_back(value);
        }
    } else if (num_bits < bits.size()) {
        // Обрезаем вектор
        bits.resize(num_bits);
    }
}
// Метод для очистки всех битов
void BitArray::clear() {
    bits.clear(); // Очищаем вектор битов
}

// Метод для добавления бита в конец массива
void BitArray::push_back(bool bit) {
    bits.push_back(bit); // Добавляем бит в конец
}

// Oператор побитового И (AND)
BitArray& BitArray::operator&=(const BitArray& b) {
    if (bits.size() != b.bits.size()) {
        throw std::invalid_argument("BitArrays must have same size"); // Проверка на совпадение размеров
    }

    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        bits[i] = bits[i] && b.bits[i]; // Побитовое И
    }
    return *this; 
}

// Oператор побитового ИЛИ (OR)
BitArray& BitArray::operator|=(const BitArray& b) {
    if (bits.size() != b.bits.size()) {
        throw std::invalid_argument("BitArrays must have same size");
    }

    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        bits[i] = bits[i] || b.bits[i]; // Побитовое ИЛИ
    }
    return *this;
}

// Oператор побитового исключающего ИЛИ (XOR)
BitArray& BitArray::operator^=(const BitArray& b) {
    if (bits.size() != b.bits.size()) {
        throw std::invalid_argument("BitArrays must have same size");
    }

    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        bits[i] = bits[i] != b.bits[i]; // Побитовое исключающее ИЛИ
    }
    return *this;
}

// Oператор сдвига влево
//BitArray& BitArray::operator<<=(int n) {
//    if (n >= static_cast<int>(bits.size())) {
//        std::fill(bits.begin(), bits.end(), false); // Если сдвиг больше размера, все биты обнуляются
//    } else {
//        std::rotate(bits.begin(), bits.begin() + n, bits.end()); // Сдвигаем биты влево
//        std::fill(bits.end() - n, bits.end(), false); // Заполняем освободившиеся биты нулями
//    }
//    return *this;
//}

// Oператор сдвига вправо
//BitArray& BitArray::operator>>=(int n) {
//    if (n >= static_cast<int>(bits.size())) {
//        std::fill(bits.begin(), bits.end(), false); // Если сдвиг больше размера, все биты обнуляются
//    } else {
//        std::rotate(bits.rbegin(), bits.rbegin() + n, bits.rend()); // Сдвигаем биты вправо
//        std::fill(bits.begin(), bits.begin() + n, false); // Заполняем освободившиеся биты нулями
//    }
//    return *this;
//}

BitArray& BitArray::operator<<=(int n) {
    if (n >= static_cast<int>(bits.size())) {
        // Если сдвиг больше размера, заполняем весь массив нулями
        for (int i = 0; i < bits.size(); ++i) {
            bits[i] = false;
        }
    } else {
        // Сдвигаем биты влево
        for (int i = 0; i < static_cast<int>(bits.size()) - n; ++i) {
            bits[i] = bits[i + n];
        }
        // Заполняем последние n бит нулями
        for (int i = static_cast<int>(bits.size()) - n; i < static_cast<int>(bits.size()); ++i) {
            bits[i] = false;
        }
    }
    return *this;
}

BitArray& BitArray::operator>>=(int n) {
    if (n >= static_cast<int>(bits.size())) {
        // Если сдвиг больше размера, заполняем весь массив нулями
        for (int i = 0; i < bits.size(); ++i) {
            bits[i] = false;
        }
    } else {
        // Сдвигаем биты вправо
        for (int i = static_cast<int>(bits.size()) - 1; i >= n; --i) {
            bits[i] = bits[i - n];
        }
        // Заполняем первые n бит нулями
        for (int i = 0; i < n; ++i) {
            bits[i] = false;
        }
    }
    return *this;
}


// Создание копии сдвинутого массива (сдвиг влево)
BitArray BitArray::operator<<(int n) const {
    BitArray res = *this;
    res <<= n; // Используем сдвиг с присваиванием
    return res;
}

// Создание копии сдвинутого массива (сдвиг вправо)
BitArray BitArray::operator>>(int n) const {
    BitArray res = *this;
    res >>= n; // Используем сдвиг с присваиванием
    return res;
}

// Метод для установки значения бита по индексу
BitArray& BitArray::set(int n, bool val) { 
    if (n < 0 || n >= static_cast<int>(bits.size())) {
        throw std::invalid_argument("Error: bit index out of range");
    }
    bits[n] = val; // Устанавливаем значение бита
    return *this;
}

// Метод для установки всех битов в 1
BitArray& BitArray::set() { 
    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        bits[i] = true; // Устанавливаем все биты в 1
    }
    return *this;
}

// Метод для сброса значения бита по индексу
BitArray& BitArray::reset(int n) {
    if (n < 0 || n >= static_cast<int>(bits.size())) {
        throw std::invalid_argument("Error: bit index out of range");
    }
    bits[n] = false; // Сбрасываем бит в 0
    return *this;
}

// Метод для сброса всех битов
BitArray& BitArray::reset() { 
    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        bits[i] = false; // Сбрасываем все биты в 0
    }
    return *this;
}

// Проверка, есть ли хотя бы один установленный бит
bool BitArray::any() const {
    return std::any_of(bits.begin(), bits.end(), [](bool b) { return b; });
}

// Проверка, все ли биты сброшены
bool BitArray::none() const {
    return !any(); // Если нет установленных битов, значит все сброшены
}

// Побитовая инверсия (переопределение оператора ~)
BitArray BitArray::operator~() const {
    BitArray current_res = *this;
    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        current_res.bits[i] = !current_res.bits[i]; // Инвертируем каждый бит
    }
    return current_res;
}

// Метод для подсчета числа установленных битов
int BitArray::count() const {
    int count = 0;
    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        if (bits[i]) {
            count++; // Увеличиваем счетчик за каждый установленный бит
        }
    }
    return count;
}

// Оператор доступа к биту по индексу
bool BitArray::operator[](int i) const {
    if (i < 0 || i >= static_cast<int>(bits.size())) {
        throw std::invalid_argument("Error: bit index out of range");
    }
    return bits[i]; // Возвращаем значение бита по индексу
}

// Метод для получения размера массива
int BitArray::size() const {
    return bits.size(); // Возвращаем размер массива битов
}

// Метод для проверки, пуст ли массив
bool BitArray::empty() const {
    return bits.empty(); // Проверка на пустоту массива битов
}

// Метод для получения строкового представления битов
std::string BitArray::to_string() const {
    std::string res;
    for (int i = 0; i < static_cast<int>(bits.size()); i++) {
        res += bits[i] ? '1' : '0'; // Преобразуем каждый бит в строку '1' или '0'
    }
    return res;
}

// Операторы сравнения
bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return false; // Если размеры массивов не совпадают, возвращаем false
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false; // Если хотя бы один бит отличается, возвращаем false
        }
    }
    return true; // Все биты одинаковые, возвращаем true
}

bool operator!=(const BitArray & a, const BitArray & b) {
    return !(a == b); // Используем оператор == для проверки неравенства
}

// Операторы побитового И, ИЛИ, XOR
BitArray operator&(const BitArray& b1, const BitArray& b2) {
    BitArray res = b1;
    res &= b2; // Применяем операцию побитового И
    return res;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
    BitArray res = b1;
    res |= b2; // Применяем операцию побитового ИЛИ
    return res;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    BitArray res = b1;
    res ^= b2; // Применяем операцию побитового XOR
    return res;
}
/*BitArray::BitArray(int num_bits, unsigned long value) {
    resize(num_bits, false); // Инициализация битов нулями
    for (int i = 0; i < num_bits; i++) {
        bits[num_bits - 1 - i] = (value & (1L << i)) != 0; // Устанавливаем биты начиная с самого старшего
    }
}*/
//переписать swap, resize и битовые сдвиги без использования std::