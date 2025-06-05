#include <iostream>
#include <vector>
#include "../include/jogo.hpp"
#include "../include/utils.hpp"
#include "../include/perguntas.hpp" // necessário para inicializar perguntas

int main() {
    std::vector<Corredor> jogadores = {
        {"Dom  ", 0},
        {"Brian", 0}
    };

    const int META = 30;
    bool terminou = false;

    // Inicializa perguntas embaralhadas
    inicializarPerguntas();

    std::cout << "\n🏁 VELOCIDADE FURIOSA - CORRIDA NO TERMINAL 🏁\n\n";

    while (!terminou) {
        for (auto& jogador : jogadores) {
            limparEcra();
            mostrarCorrida(jogadores, META);
            turnoJogador(jogador);

            if (jogador.posicao >= META) {
                terminou = true;
                animarChegada(jogador, META);
                break;
            }
        }
    }

    Corredor* vencedor = &jogadores[0];
    for (auto& j : jogadores) {
        if (j.posicao > vencedor->posicao)
            vencedor = &j;
    }

    std::cout << "\n🏆 VENCEDOR: " << vencedor->nome << " 🎉🎉🎉";
    return 0;
}
