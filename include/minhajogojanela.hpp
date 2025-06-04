#ifndef MINHAJOGOJANELA_HPP
#define MINHAJOGOJANELA_HPP

#include <QMainWindow> // Ou QWidget, se sua janela for mais simples e não precisar de menus, barras, etc.
#include <vector>
#include "jogo.hpp"      // Para a struct Corredor
#include "perguntas.hpp" // Para a struct Pergunta

// A interface que o Qt Designer criou está dentro de um namespace chamado Ui.
// O nome da classe principal da sua janela no Qt Designer (geralmente "Form" ou "MainWindow")
// define o nome da classe gerada aqui. Pela imagem, parece que o nome do objeto principal é "Form".
namespace Ui {
    class Form; // Se no Qt Designer, no "objectName" da janela principal, for "MainWindow", use "MainWindow" aqui.
}

class MinhaJogoJanela : public QMainWindow // Mude para QWidget se usou QWidget acima
{
    Q_OBJECT // ESSENCIAL para que a classe possa usar "signals" e "slots" do Qt

public:
    // Construtor: cria a janela
    explicit MinhaJogoJanela(QWidget *parent = nullptr);
    // Destrutor: limpa a memória
    ~MinhaJogoJanela();

private slots:
    // Estes são os "slots" (funções) que serão chamados quando os botões forem clicados.
    // O Qt tem uma convenção para conectar automaticamente se os nomes seguirem "on_ObjectName_signalName()".
    // O "ObjectName" é o que renomeamos no Passo 1.
    void on_optionAButton_clicked();
    void on_optionBButton_clicked();
    void on_optionCButton_clicked();
    void on_optionDButton_clicked();
    void on_rollDiceButton_clicked(); // Slot para o botão de lançar dado

private:
    Ui::Form *ui; // Um ponteiro para a interface que o Qt Designer gerou para nós.

    // Variáveis do estado do jogo
    std::vector<Corredor> jogadores;
    int meta;
    bool jogoTerminou;
    int jogadorAtualIndex;
    Pergunta perguntaAtual;

    // Funções internas para gerenciar o jogo e a UI
    void iniciarNovoJogo();
    void atualizarUI();
    void mostrarPergunta(const Pergunta& p);
    void processarResposta(char respostaUsuario);
    void rolarDadoEReagir(int dado);
    void proximoTurno();
    void finalizarJogo();
    void animarMovimentoUI(Corredor& jogador, int dado); // Adaptação da sua função de animação
};

#endif // MINHAJOGOJANELA_HPP