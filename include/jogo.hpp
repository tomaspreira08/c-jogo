#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <string>

struct Corredor {
    std::string nome;
    int posicao = 0;
};

void mostrarCorrida(const std::vector<Corredor>& corredores, int meta);
void animarMovimento(Corredor& jogador, int dado);
void turnoJogador(Corredor& jogador);
void animarChegada(const Corredor& jogador, int meta);

#endif
