#include "../include/minhajogojanela.hpp" // Nosso próprio cabeçalho
#include "ui_jogo.h"                  // Este arquivo é gerado AUTOMATICAMENTE pelo CMake/uic
                                      // Ele contém a definição da classe Ui::Form
#include <QMessageBox>                // Para mostrar mensagens pop-up
#include <QTimer>                     // Para delays e ações futuras (como proximoTurno após um erro)
#include <random>                     // Para gerar números aleatórios (dado)

// Construtor da nossa janela de jogo
MinhaJogoJanela::MinhaJogoJanha(QWidget *parent) :
    QMainWindow(parent), // Inicializa a parte da janela principal do Qt
    ui(new Ui::Form)     // Cria uma nova instância da interface gerada pelo Qt Designer
{
    ui->setupUi(this); // Configura todos os elementos da interface na nossa janela

    // Conecta os botões da UI aos nossos "slots" (funções) C++.
    // Como renomeamos os botões no Designer, o Qt já tenta fazer a conexão automaticamente.
    // Mas se quisermos ser explícitos ou para garantir, podemos fazer:
    // connect(ui->optionAButton, SIGNAL(clicked()), this, SLOT(on_optionAButton_clicked()));
    // Não é estritamente necessário para nomes "on_ObjectName_signalName()", mas é bom saber.

    iniciarNovoJogo(); // Começa um novo jogo quando a janela é criada
}

// Destrutor da nossa janela
MinhaJogoJanela::~MinhaJogoJanela()
{
    delete ui; // Libera a memória da interface
}

void MinhaJogoJanela::iniciarNovoJogo() {
    jogadores = {
        {"Dom", 0},
        {"Brian", 0}
    };
    meta = 30;
    jogoTerminou = false;
    jogadorAtualIndex = 0;

    // Desabilita o botão de dado no início (só pode ser clicado após acertar a pergunta)
    ui->rollDiceButton->setEnabled(false);
    // Habilita os botões de opção
    ui->optionAButton->setEnabled(true);
    ui->optionBButton->setEnabled(true);
    ui->optionCButton->setEnabled(true);
    ui->optionDButton->setEnabled(true);

    proximoTurno(); // Inicia o jogo com o primeiro turno
}

void MinhaJogoJanela::atualizarUI() {
    // Atualiza o texto da pergunta e das opções nos QLabel e QPushButtons
    ui->questionLabel->setText(perguntaAtual.texto.c_str());
    ui->optionAButton->setText(perguntaAtual.opcoes[0].c_str());
    ui->optionBButton->setText(perguntaAtual.opcoes[1].c_str());
    ui->optionCButton->setText(perguntaAtual.opcoes[2].c_str());
    ui->optionDButton->setText(perguntaAtual.opcoes[3].c_str());

    // Atualiza a posição dos jogadores no label de posição
    QString posText = QString("%1: Posição %2/%5\n%3: Posição %4/%5")
                         .arg(jogadores[0].nome.c_str())
                         .arg(jogadores[0].posicao)
                         .arg(jogadores[1].nome.c_str())
                         .arg(jogadores[1].posicao)
                         .arg(meta);
    ui->playerPositionsLabel->setText(posText);
}

void MinhaJogoJanela::mostrarPergunta(const Pergunta& p) {
    perguntaAtual = p; // Armazena a pergunta atual
    atualizarUI();     // Atualiza a interface com a nova pergunta

    // Habilita os botões de resposta e garante que o de dado está desabilitado
    ui->optionAButton->setEnabled(true);
    ui->optionBButton->setEnabled(true);
    ui->optionCButton->setEnabled(true);
    ui->optionDButton->setEnabled(true);
    ui->rollDiceButton->setEnabled(false);
}

void MinhaJogoJanela::processarResposta(char respostaUsuario) {
    // Desabilita os botões de opção para evitar cliques múltiplos
    ui->optionAButton->setEnabled(false);
    ui->optionBButton->setEnabled(false);
    ui->optionCButton->setEnabled(false);
    ui->optionDButton->setEnabled(false);

    if (respostaUsuario == perguntaAtual.correta) {
        QMessageBox::information(this, "Resposta Correta!", "Parabéns! Acertaste! Agora lança o dado.");
        ui->rollDiceButton->setEnabled(true); // Habilita o botão de dado
    } else {
        QMessageBox::warning(this, "Resposta Errada!",
                             QString("Ops! A resposta correta era: %1. Ficas na mesma posição.").arg(perguntaAtual.correta));
        // Usa QTimer::singleShot para chamar proximoTurno depois de um tempo
        QTimer::singleShot(1500, this, &MinhaJogoJanela::proximoTurno);
    }
}

void MinhaJogoJanela::rolarDadoEReagir(int dado) {
    ui->rollDiceButton->setEnabled(false); // Desabilita o botão de dado após a rolagem

    Corredor& jogadorAtual = jogadores[jogadorAtualIndex];
    animarMovimentoUI(jogadorAtual, dado); // Atualiza a posição do jogador na UI

    if (jogadorAtual.posicao >= meta) {
        finalizarJogo(); // Se o jogador alcançou ou passou a meta, o jogo termina
    } else {
        proximoTurno(); // Se não, passa para o próximo turno/jogador
    }
}

void MinhaJogoJanela::proximoTurno() {
    if (jogoTerminou) return; // Não faz nada se o jogo já terminou

    // Troca para o próximo jogador
    jogadorAtualIndex = (jogadorAtualIndex + 1) % jogadores.size();
    Corredor& jogador = jogadores[jogadorAtualIndex];

    QMessageBox::information(this, "Vez do Jogador", QString("É a vez de %1!").arg(jogador.nome.c_str()));

    // Obtém e mostra a nova pergunta para o jogador atual
    perguntaAtual = obterPerguntaAleatoria(); // Reutiliza sua função de perguntas
    mostrarPergunta(perguntaAtual);
}

void MinhaJogoJanela::finalizarJogo() {
    jogoTerminou = true;
    Corredor* vencedor = &jogadores[0];
    for (auto& j : jogadores) {
        if (j.posicao > vencedor->posicao)
            vencedor = &j;
    }
    QMessageBox::information(this, "Fim de Jogo!", QString("🏆 VENCEDOR: %1 🎉🎉🎉").arg(vencedor->nome.c_str()));

    // Opcional: Desabilitar todos os botões ou mostrar um botão "Novo Jogo"
    ui->optionAButton->setEnabled(false);
    ui->optionBButton->setEnabled(false);
    ui->optionCButton->setEnabled(false);
    ui->optionDButton->setEnabled(false);
    ui->rollDiceButton->setEnabled(false);
}

void MinhaJogoJanela::animarMovimentoUI(Corredor& jogador, int dado) {
    // Para uma animação visual mais complexa, você precisaria de mais trabalho (QGraphicsView, QPropertyAnimation).
    // Por enquanto, apenas atualiza a posição e mostra uma mensagem.
    jogador.posicao += dado;
    atualizarUI(); // Atualiza a posição na interface imediatamente
}

// --- Slots que são chamados quando os botões são clicados ---

void MinhaJogoJanela::on_optionAButton_clicked() {
    processarResposta('A');
}

void MinhaJogoJanela::on_optionBButton_clicked() {
    processarResposta('B');
}

void MinhaJogoJanela::on_optionCButton_clicked() {
    processarResposta('C');
}

void MinhaJogoJanela::on_optionDButton_clicked() {
    processarResposta('D');
}

void MinhaJogoJanela::on_rollDiceButton_clicked() {
    // Simula a rolagem do dado
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 6);
    int dado = distrib(gen);

    QMessageBox::information(this, "Rolagem do Dado", QString("🎲 Saiu: %1!").arg(dado));
    rolarDadoEReagir(dado);
}