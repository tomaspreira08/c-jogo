#include <QApplication>            // Inclui a classe principal da aplicação Qt
#include "../include/minhajogojanela.hpp" // Inclui o cabeçalho da sua nova janela

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Cria o objeto que gerencia a aplicação Qt (essencial!)

    MinhaJogoJanela w;          // Cria uma instância da sua janela de jogo
    w.show();                   // Mostra a janela na tela

    return a.exec();            // Inicia o "loop de eventos" do Qt. Seu programa fica rodando aqui até a janela ser fechada.
}