#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <string>

struct Corredor {
    std::string nome;
    int posicao;
};

// Declarações de funções
void animarMovimento(Corredor& jogador, int dado);
void animarChegada(const Corredor& jogador, int meta);
void mostrarCorrida(const std::vector<Corredor>& jogadores, int meta);
void turnoJogador(Corredor& jogador);

#endif
