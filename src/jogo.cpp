#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "../include/jogo.hpp"
#include "../include/perguntas.hpp"
#include "../include/utils.hpp"

void animarMovimento(Corredor& jogador, int dado) {
    jogador.posicao += dado; // Atualiza a posição do jogador com base no dado
    // Aqui você pode adicionar lógica para animar o movimento, se necessário
}

void animarChegada(const Corredor& jogador, int meta) {
    std::cout << "\n🎉 " << jogador.nome << " está chegando à meta!\n";
    for (int i = jogador.posicao; i <= meta; ++i) {
        std::cout << "\r" << jogador.nome << " está na casa " << i << " " << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Tempo de espera para a animação
    }
    std::cout << "\n🏁 " << jogador.nome << " cruzou a linha de chegada! 🎉\n";
}

void mostrarCorrida(const std::vector<Corredor>& jogadores, int meta) {
    std::cout << "🏁 Corrida (meta: " << meta << " casas)\n\n";
    for (const auto& j : jogadores) {
        std::cout << j.nome << ": ";
        for (int i = 0; i < meta; ++i) {
            if (i == j.posicao)
                std::cout << "🚗";
            else if (i == meta - 1)
                std::cout << "🏁";
            else
                std::cout << "-";
        }
        std::cout << " (" << j.posicao << "/" << meta << ")\n";
    }
    std::cout << "\n";
}


void turnoJogador(Corredor& jogador) {
    std::cout << "\n🎮 Turno de " << jogador.nome << "\n";
    Pergunta p = obterPerguntaAleatoria();
    bool acertou = fazerPergunta(p);

    if (acertou) {
        std::cout << "🎯 Correto! A lançar o dado...\n";
        for (int i = 0; i < 10; ++i) {
            int n = rand() % 6 + 1;
            std::cout << "\r🎲 A girar... " << n << "   " << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        int dado = rand() % 6 + 1;
        std::cout << "\r🎲 Saiu: " << dado << "! Avanças " << dado << " casas.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        animarMovimento(jogador, dado);
    } else {
        std::cout << "❌ Errado! Ficas na mesma posição.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
}

