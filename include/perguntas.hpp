#ifndef PERGUNTAS_HPP
#define PERGUNTAS_HPP

#include <string>
#include <vector>

struct Pergunta {
    std::string texto;
    std::vector<std::string> opcoes;
    char correta;
};

void inicializarPerguntas();
Pergunta obterProximaPergunta();
bool fazerPergunta(const Pergunta& p);

#endif
