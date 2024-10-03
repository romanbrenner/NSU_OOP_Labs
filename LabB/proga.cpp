#include <fstream>   
#include <iomanip>   
#include <iostream>  
#include <locale>    
#include <map>       
#include <set>       
#include <cwctype>

using namespace std;

// Функция для установки русской локали
bool initializeRussianLocale() {
    try {
        // Создание русской локали
        locale russianLocale("ru_RU.UTF-8");
        // Установка глобальной локали
        locale::global(russianLocale);
    } catch (const runtime_error &exception) {
        // Обработка исключения, если локаль не может быть установлена
        cerr << "Ошибка: Не удалось установить локаль - " << exception.what() << endl;
        return false; // Возврат false при неудачной установке локали
    }
    
    // Успешная установка локали
    return true;
}

int main(int argc, char *argv[]) {
    // Проверка успешности установки локали\. Если не удалось, завершение программы с кодом ошибки\.
    if (!initializeRussianLocale()) {
        return 0;
    }

    // Проверка на корректное количество аргументов командной строки
    if (argc != 3) {
        cout << "Необходимые аргументы: " << argv[0] << " input.txt output.csv" << endl;
        return 0;
    }

    // Открытие входного файла для чтения в формате UTF-8
    wifstream fin(argv[1]);
    if (!fin) {
        // Если не удалось открыть файл, выводится соответствующее сообщение и программа завершает выполнение
        cout << "Невозможно открыть входной файл: " << argv[1] << endl;
        return 0;
    }

    // Открытие выходного файла для записи в формате UTF-8
    wofstream fout(argv[2]);
    if (!fout) {
        // Если не удалось открыть файл, выводится соответствующее сообщение и программа завершает выполнение
        cout << "Невозможно открыть выходной файл: " << argv[2] << endl;
        return 0;
    }

    long Words = 0; // Переменная для хранения общего количества слов
    map<wstring, long> Words_map; // Хранение частот встречаемости слов

    wstring line;
    // Чтение файла построчно
    while (getline(fin, line)) {
        wstring current_Word; // Переменная для накопления текущего слова
        // Перебор каждого символа строки
        for (auto it = line.begin(); it != line.end(); it++) {
            if (iswalnum(*it)) { // Проверка, является ли символ частью слова (буква или цифра)
                current_Word+= towlower(*it); // Добавление символа к текущему слову
            } else if (!current_Word.empty()) { // Если найдено разделение слов
                Words_map[current_Word]++; // Увеличиваем счетчик для данного слова
                Words++; // Увеличиваем общий счетчик слов
                current_Word.clear(); // Очистка переменной для нового слова
            }
        }
        // Обработка последнего слова в строке, если оно есть
        if (!current_Word.empty()) {
            Words_map[current_Word]++;
            Words++;
        }
    }

    // Использование set для сортировки слов по частоте
    set<pair<long, wstring>> sortedWords;
    // Перенос слов из map в set
    for (auto it = Words_map.begin(); it != Words_map.end(); it++) {
        sortedWords.insert({it->second, it->first});
    }

    // Запись заголовка в файл
    fout << L"Слово,Частота,Частота(%)" << endl;

    // Запись отсортированных данных в файл
    for (auto it = sortedWords.rbegin(); it != sortedWords.rend(); it++) {
        fout << it->second << "," << it->first << "," << setprecision(5)
             << '"' << static_cast<double>(it->first) * 100 / Words << '"' << endl;
    }

    return EXIT_SUCCESS;
}