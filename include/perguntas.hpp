#ifndef PERGUNTAS_HPP
#define PERGUNTAS_HPP

#include <string>
#include <vector>
#include "../include/jogo.hpp"

struct Pergunta {
    std::string texto;
    std::vector<std::string> opcoes;
    char correta;
};

Pergunta obterPerguntaAleatoria();
bool fazerPergunta(const Pergunta& p);

#endif
