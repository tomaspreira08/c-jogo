#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::shuffle
#include "../include/perguntas.hpp"
#include "../include/utils.hpp"

Pergunta obterPerguntaAleatoria() {
    std::vector<Pergunta> perguntas = {
        {"Qual é o carro mais vendido do mundo?", {"Toyota Corolla", "Ford F-Series", "Volkswagen Golf", "Honda Civic"}, 'A'},
        {"Qual é o carro esportivo mais rápido do mundo?", {"Bugatti Chiron", "Koenigsegg Agera RS", "Hennessey Venom F5", "McLaren Speedtail"}, 'B'},
        {"Qual fabricante de automóveis é conhecido por seu logotipo de quatro anéis?", {"BMW", "Audi", "Mercedes-Benz", "Volkswagen"}, 'B'},
        {"Qual é o nome do carro elétrico produzido pela Tesla?", {"Model S", "Model 3", "Model X", "Model Y"}, 'A'},
        {"Qual é o carro que ficou famoso por ser o 'carro do povo' na Alemanha?", {"Volkswagen Beetle", "Ford Model T", "Chevrolet Impala", "Fiat 500"}, 'A'},
        {"Qual é o nome do carro que foi o primeiro a ultrapassar 300 km/h?", {"Bugatti Veyron", "McLaren F1", "Porsche 911", "Ferrari F40"}, 'A'},
        {"Qual é o carro mais caro já vendido em um leilão?", {"Ferrari 250 GTO", "Bugatti La Voiture Noire", "Pagani Zonda", "Lamborghini Veneno"}, 'A'},
        {"Qual é o nome do sistema que ajuda a evitar derrapagens em carros?", {"ABS", "ESP", "ASR", "TCS"}, 'B'},
        {"Qual carro é conhecido como o 'muscle car' americano por excelência?", {"Ford Mustang", "Chevrolet Camaro", "Dodge Charger", "Pontiac GTO"}, 'A'},
        {"Qual é o carro que se tornou famoso por sua participação em 'Velozes e Furiosos' e é conhecido por seu motor V8?", {"Dodge Charger", "Chevrolet Camaro", "Ford Mustang", "Nissan Skyline"}, 'A'},
        {"Quem é o melhor amigo de Dom?", {"Brian", "Roman", "Tej", "Deckard"}, 'A'},
        {"Qual é o carro icônico de Brian?", {"Toyota Supra", "Dodge Charger", "Nissan Skyline", "Ford Mustang"}, 'A'},
        {"Qual personagem é um ex-policial?", {"Brian", "Dom", "Roman", "Tej"}, 'A'},
        {"Qual é o carro do personagem Roman?", {"Ford Mustang", "Dodge Charger", "Toyota Supra", "Chevrolet Camaro"}, 'A'},
        {"Qual foi o primeiro filme da saga?", {"Velocidade Furiosa", "Velocidade Furiosa 2", "Velocidade Furiosa 3", "Velocidade Furiosa 4"}, 'A'},
        {"Qual é o nome do mecânico especialista da equipe?", {"Tej", "Roman", "Brian", "Dom"}, 'A'},
        {"Qual é a cor do Dodge Charger de Dom?", {"Preto", "Vermelho", "Azul", "Branco"}, 'A'},
        {"Qual personagem se casa com Mia?", {"Brian", "Dom", "Roman", "Tej"}, 'A'},
        {"Qual é o carro que aparece na corrida de abertura de Velocidade Furiosa 6?", {"Ford Mustang Shelby GT500", "Dodge Charger", "Toyota Supra", "Mazda RX-7"}, 'A'},
        {"Qual personagem é conhecido pelo seu senso de ?", {"Roman", "Tej", "Brian", "Dom"}, 'A'},
        {"Qual é a primeira corrida ilegal mostrada no filme original?", {"Corrida na rua de Los Angeles", "Corrida no porto", "Corrida em Tóquio", "Corrida em Miami"}, 'A'},
        {"Quem é o líder da equipe principal em Velocidade Furiosa?", {"Dom", "Brian", "Deckard", "Roman"}, 'A'},
        {"Qual é o carro mais famoso de Dom Toretto?", {"Dodge Charger", "Toyota Supra", "Nissan Skyline", "Chevrolet Camaro"}, 'A'},
        {"Em que filme Dom e Brian correm nas ruas de Tóquio?", {"Velocidade Furiosa 2", "Velocidade Furiosa 3", "Velocidade Furiosa 4", "Velocidade Furiosa 5"}, 'B'},
        {"Qual é o nome do personagem interpretado por Paul Walker?", {"Brian", "Dom", "Tej", "Roman"}, 'A'},
        {"Que tipo de carro é o Toyota Supra do Brian?", {"Esportivo japonês", "Muscle car", "Sedan", "Pickup"}, 'A'},
        {"Qual é a principal profissão de Dom?", {"Mecânico", "Policial", "Ladrão de carros", "Caminhoneiro"}, 'A'},
        {"Qual carro aparece no início do primeiro filme?", {"Mazda RX-7", "Dodge Charger", "Ford Mustang", "Nissan Skyline"}, 'A'},
        {"Qual personagem é conhecido como 'Tej'?", {"Especialista em tecnologia", "Piloto de corridas", "Mecânico", "Policial infiltrado"}, 'A'},
        {"Qual é o símbolo que aparece frequentemente no Dodge Charger de Dom?", {"Crânio", "Tigre", "Águia", "Fênix"}, 'A'},
        {"Qual filme apresenta uma corrida dentro do porto de Los Angeles?", {"Velocidade Furiosa 5", "Velocidade Furiosa 3", "Velocidade Furiosa 6", "Velocidade Furiosa 7"}, 'A'},
        {"Em Velocidade Furiosa 7, qual carro Dom dirige numa perseguição na montanha?", {"Lykan Hypersport", "Dodge Charger", "Ford Mustang", "Toyota Supra"}, 'A'},
        {"Qual carro é famoso pelo seu motor turbo em Velocidade Furiosa 2?", {"Nissan Skyline", "Toyota Supra", "Dodge Charger", "Mazda RX-7"}, 'A'},
        {"Qual a nacionalidade do personagem Han?", {"Coreano", "Japonês", "Chinês", "Americano"}, 'A'},
        {"Qual é o nome do filho de Dom?", {"Brian", "Jack", "Roman", "Tej"}, 'B'},
        {"Quem traiu a equipe em Velocidade Furiosa 7?", {"Deckard Shaw", "Owen Shaw", "Cipher", "Letty"}, 'A'},
        {"Qual personagem é especialista em hackear?", {"Tej", "Roman", "Brian", "Dom"}, 'A'},
        {"Qual é o nome do spin-off focado em personagens ?", {"Hobbs & Shaw", "Fast Girls", "Velocity Women", "Fast & Fierce"}, 'A'},
        {"Em qual filme a equipe invade um trem para roubar um computador?", {"Velocidade Furiosa 7", "Velocidade Furiosa 6", "Velocidade Furiosa 5", "Velocidade Furiosa 4"}, 'B'},
        {"Que carro Letty costuma pilotar?", {"Dodge Charger", "Nissan Skyline", "Ford Mustang", "Toyota Supra"}, 'A'},
        {"Quem é o antagonista principal de Velocidade Furiosa 8?", {"Cipher", "Deckard Shaw", "Owen Shaw", "Jakob Toretto"}, 'A'},
        {"Qual personagem é o irmão de Dom?", {"Jakob Toretto", "Brian", "Roman", "Tej"}, 'A'},
        {"Qual é o modelo do carro de Brian em Velocidade Furiosa 2?", {"Nissan Skyline GT-R R34", "Toyota Supra", "Mazda RX-7", "Dodge Charger"}, 'A'},
        {"Em que filme Dom rouba um tanque?", {"Velocidade Furiosa 7", "Velocidade Furiosa 5", "Velocidade Furiosa 6", "Velocidade Furiosa 8"}, 'D'},
        {"Quem é o personagem que morreu em Velocidade Furiosa 7?", {"Paul Walker (Brian)", "Vin Diesel (Dom)", "Dwayne Johnson (Hobbs)", "Tyrese Gibson (Roman)"}, 'A'},
        {"Qual carro Dom usa na perseguição em Lisboa (Velocidade Furiosa 5)?", {"Dodge Charger", "Toyota Supra", "Nissan Skyline", "Ford Mustang"}, 'A'},
        {"Qual é o nome da irmã de Dom?", {"Mia", "Letty", "Roman", "Tej"}, 'A'},
        {"Qual é o nome do ator que interpreta Roman?", {"Tyrese Gibson", "Ludacris" , "Vin Diesel", "Paul Walker"}, 'A'},
        {"Em que filme aparece o personagem 'Jakob Toretto'?", {"Velocidade Furiosa 9", "Velocidade Furiosa 8", "Velocidade Furiosa 7", "Velocidade Furiosa 6"}, 'A'},
        {"Qual é o carro usado por Roman em Velocidade Furiosa 6?", {"Ford Mustang Shelby GT500", "Dodge Charger", "Toyota Supra", "Mazda RX-7"}, 'A'},
        {"Qual é a profissão de Tej?", {"Mecânico e hacker", "Piloto", "Policial", "Ladrão"}, 'A'},
        {"Qual é o nome do personagem interpretado por Jason Statham?", {"Deckard Shaw", "Owen Shaw", "Jakob Toretto", "Roman"}, 'A'},
        {"Qual é o nome do personagem interpretado por Sung Kang?", {"Han", "Roman", "Brian", "Tej"}, 'A'},
        {"Em Velocidade Furiosa 5, qual é o local da grande corrida/fuga?", {"Rio de Janeiro", "Los Angeles", "Miami", "Tóquio"}, 'A'},
        {"Que tipo de corrida é o foco principal da saga?", {"Corridas de rua", "Corridas de pista", "Corridas de rali", "Corridas off-road"}, 'A'},
        {"Qual é o carro de Hobbs?", {"Ford F-150 Raptor", "Dodge Charger", "Toyota Supra", "Nissan Skyline"}, 'A'},
        {"Qual personagem é interpretado por Dwayne Johnson?", {"Hobbs", "Dom", "Brian", "Roman"}, 'A'},
        {"Qual é o nome completo do personagem 'Roman'?", {"Roman Pearce", "Roman Toretto", "Roman Shaw", "Roman O'Conner"}, 'A'},
        {"Quem é o inimigo principal em Velocidade Furiosa 6?", {"Owen Shaw", "Deckard Shaw", "Cipher", "Jakob Toretto"}, 'A'},
        {"Qual é o carro do personagem Deckard Shaw?", {"Aston Martin Vanquish", "Dodge Charger", "Toyota Supra", "Nissan Skyline"}, 'A'},
        {"Qual é o nome do personagem interpretado por Michelle Rodriguez?", {"Letty", "Mia", "Roman", "Tej"}, 'A'},
        {"Quem é a esposa de Brian O'Conner?", {"Mia", "Letty", "Roman", "Tej"}, 'A'},
        {"Qual filme apresenta a volta de Brian O'Conner?", {"Velocidade Furiosa 4", "Velocidade Furiosa 5", "Velocidade Furiosa 6", "Velocidade Furiosa 7"}, 'A'},
        {"Qual ator interpreta Dom Toretto?", {"Vin Diesel", "Paul Walker", "Dwayne Johnson", "Tyrese Gibson"}, 'A'},
        {"Qual ator interpreta Brian O'Conner?", {"Paul Walker", "Vin Diesel", "Dwayne Johnson", "Tyrese Gibson"}, 'A'},
        {"Qual é o nome da equipe principal da saga?", {"Equipe Toretto", "Equipe Shaw", "Equipe O'Conner", "Equipe Roman"}, 'A'},
        {"Quem é o diretor do primeiro filme Velocidade Furiosa?", {"Rob Cohen", "Justin Lin", "James Wan", "F. Gary Gray"}, 'A'},
        {"Qual filme mostra uma corrida ilegal em Tóquio?", {"Velocidade Furiosa 2", "Velocidade Furiosa 3", "Velocidade Furiosa 4", "Velocidade Furiosa 5"}, 'B'},
        {"Que carro Dom usa para correr contra Brian no primeiro filme?", {"Dodge Charger", "Toyota Supra", "Mazda RX-7", "Nissan Skyline"}, 'A'},
        {"Quem é a namorada de Brian na saga?", {"Mia", "Letty", "Roman", "Tej"}, 'A'},
        {"Qual carro é o favorito de Han?", {"Mazda RX-7", "Dodge Charger", "Toyota Supra", "Nissan Skyline"}, 'A'},
        {"Em Velocidade Furiosa 8, qual cidade é principal cenário?", {"Nova York", "Los Angeles", "Miami", "Tóquio"}, 'A'},
        {"Quem é o personagem que pilota o Lykan Hypersport?", {"Dom", "Brian", "Roman", "Tej"}, 'A'}
    };

 // Seleciona uma pergunta aleatória
    Pergunta p = perguntas[rand() % perguntas.size()];

    // Salva o texto da resposta correta antes de embaralhar
    std::string respostaCorretaTexto = p.opcoes[p.correta - 'A'];

    // Embaralha as opções
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(p.opcoes.begin(), p.opcoes.end(), g);

    // Descobre a nova posição da resposta correta
    auto it = std::find(p.opcoes.begin(), p.opcoes.end(), respostaCorretaTexto);
    char novaLetraCorreta = 'A' + std::distance(p.opcoes.begin(), it);

    // Atualiza a letra da resposta correta
    p.correta = novaLetraCorreta;

    return p;
}

bool fazerPergunta(const Pergunta& p) {
    std::cout << p.texto << "\n";
    char opc = 'A';
    for (const auto& o : p.opcoes) {
        std::cout << opc << ") " << o << "\n";
        opc++;
    }

    char resposta;
    std::cout << "Escolha uma opção: ";
    std::cin >> resposta;

    // Converte a resposta para maiúscula para evitar problemas de case
    resposta = toupper(resposta);

    // Verifica se a resposta escolhida é válida
    if (resposta < 'A' || resposta >= 'A' + p.opcoes.size()) {
        std::cout << "Opção inválida! Tente novamente.\n";
        return false; // Retorna falso se a opção for inválida
    }

    // Verifica se a resposta escolhida é a correta
    char respostaCorreta = p.correta; // A letra da resposta correta
    if (resposta == respostaCorreta) {
        std::cout << "Correto!\n";
        return true; // Retorna verdadeiro se a resposta estiver correta
    } else {
        std::cout << "Errado! A resposta correta era: " << respostaCorreta << "\n";
        return false; // Retorna falso se a resposta estiver errada
    }
}
