#include <iostream>
#include <locale>
#include <codecvt>
#include <stdexcept>
#include "modPermutation.h"

// Функция для конвертации std::exception сообщений в std::wstring
std::wstring convertExceptionMessage(const std::exception& e) {
    std::string errorMessage = e.what(); // Получаем сообщение об ошибке
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    return converter.from_bytes(errorMessage); // Конвертируем в wstring
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Устанавливаем локаль для работы с русским языком

    try {
        std::wstring key;
        std::wcout << L"Введите ключ (целое число, положительное): ";
        std::getline(std::wcin, key);

        modPermutationCipher cipher(key);

        int operation;
        do {
            std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
            std::wcin >> operation;

            std::wstring text;
            if (operation == 1 || operation == 2) {
                std::wcout << L"Введите текст: ";
                std::wcin.ignore(); // Очищаем буфер ввода
                std::getline(std::wcin, text);
                
                if (operation == 1) {
                    std::wstring encrypted_text = cipher.encrypt(text);
                    std::wcout << L"Зашифрованный текст: " << encrypted_text << std::endl;
                } else if (operation == 2) {
                    std::wstring decrypted_text = cipher.decrypt(text);
                    std::wcout << L"Расшифрованный текст: " << decrypted_text << std::endl;
                }
            } else if (operation != 0) {
                std::wcout << L"Некорректная операция. Пожалуйста, выберите 0, 1 или 2." << std::endl;
            }
        } while (operation != 0);

    } catch (const std::invalid_argument& e) {
        // Используем конвертацию сообщения исключения в wstring для вывода на русском
        std::wcerr << L"Ошибка: " << convertExceptionMessage(e) << std::endl;
    } catch (const std::exception& e) {
        // Общий блок для других исключений
        std::wcerr << L"Произошла ошибка: " << convertExceptionMessage(e) << std::endl;
    }

    return 0;
}
