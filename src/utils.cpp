#include <iostream>
#include <cctype>
#include "../include/utils.hpp"

char lerResposta() {
    char resp;
    std::cout << "Escolhe a opção (A/B/C/D): ";
    std::cin >> resp;
    resp = std::toupper(resp);
    while (resp < 'A' || resp > 'D') {
        std::cout << "Resposta inválida. Tenta novamente (A/B/C/D): ";
        std::cin >> resp;
        resp = std::toupper(resp);
    }
    return resp;
}

void limparEcra() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}