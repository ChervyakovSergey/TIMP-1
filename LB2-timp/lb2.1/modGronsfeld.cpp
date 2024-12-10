#include "modGronsfeld.h"

modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Invalid character in text.");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (size_t i = 0; i < v.size(); i++) {
        if (static_cast<size_t>(v[i]) >= numAlpha.size()) {
            throw std::out_of_range("Index out of bounds in decryption.");
        }
        result.push_back(numAlpha[v[i]]);
    }
    return result;
}

std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    try {
        std::vector<int> work = convert(open_text);
        for (size_t i = 0; i < work.size(); i++) {
            work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Encryption error: " << e.what() << std::endl;
        throw;
    }
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    try {
        std::vector<int> work = convert(cipher_text);
        for (size_t i = 0; i < work.size(); i++) {
            work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Decryption error: " << e.what() << std::endl;
        throw;
    }
}



