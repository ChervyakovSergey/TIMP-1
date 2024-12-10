#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; // алфавит
    std::map<wchar_t, int> alphaNum; // карта символов и их индексов
    std::vector<int> key; // ключ в виде числового вектора

    // Преобразование строки в вектор чисел
    std::vector<int> convert(const std::wstring& s);

    // Преобразование вектора чисел в строку
    std::wstring convert(const std::vector<int>& v);

public:
    modAlphaCipher() = delete; // запрет конструктора по умолчанию
    modAlphaCipher(const std::wstring& skey); // конструктор с ключом

    std::wstring encrypt(const std::wstring& open_text);   // шифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};


