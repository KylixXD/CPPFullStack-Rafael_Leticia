#include <iostream>
#include <string>
#include <locale>
#include <limits>

using namespace std;


struct Placar {
    int golsCasa;
    int golsVisitante;
};

class Jogo {
public:
    string timeCasa;
    string timeVisitante;
    Placar placarReal;
    bool resultadoRegistrado;

    Jogo(string casa = "", string visitante = "") {
        timeCasa = casa;
        timeVisitante = visitante;
        placarReal.golsCasa = -1;
        placarReal.golsVisitante = -1;
        resultadoRegistrado = false;
    }
};

class Apostador {
public:
    string nome;
    int pontuacaoTotal;
    Placar* palpites; 
    bool palpitesRegistrados;

    Apostador(string n = "", int numJogos = 4) {
        nome = n;
        pontuacaoTotal = 0;
        palpitesRegistrados = false;
        palpites = new Placar[numJogos]; 
    }

    ~Apostador() {
        delete[] palpites; 
    }
};

int lerEntrada(string mensagem) {
    int valor;
    cout << mensagem;
    cin >> valor;

    while (cin.fail() || valor < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Digite um numero maior ou igual a zero: ";
        cin >> valor;
    }
    return valor;
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    const int TOTAL_JOGOS = 4;
    const int TOTAL_APOSTADORES = 3;

    // 1. Vetor estático para armazenar os 4 jogos
    Jogo jogos[TOTAL_JOGOS] = {
        Jogo("BRA", "EGY"),
        Jogo("RSA", "MAR"),
        Jogo("FRA", "ARG"),
        Jogo("GER", "ECU")
    };

    Apostador* apostadores[TOTAL_APOSTADORES];
    for (int i = 0; i < TOTAL_APOSTADORES; i++) {
        apostadores[i] = new Apostador("", TOTAL_JOGOS);
    }

    int opcao = 0;
    bool pontosCalculados = false;

    while (opcao != 5) {
        cout << "\n================= MENU BOLAO 2026 =================";
        cout << "\n1. Cadastrar resultados dos jogos";
        cout << "\n2. Cadastrar palpites dos apostadores";
        cout << "\n3. Calcular pontuacao";
        cout << "\n4. Exibir ranking";
        cout << "\n5. Sair";
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: { 
                cout << "\n--- Cadastro de Resultados Reais ---\n";
                for (int i = 0; i < TOTAL_JOGOS; i++) {
                    cout << "Jogo " << i + 1 << ": " << jogos[i].timeCasa << " x " << jogos[i].timeVisitante << endl;
                    jogos[i].placarReal.golsCasa = lerEntrada("Gols " + jogos[i].timeCasa + ": ");
                    jogos[i].placarReal.golsVisitante = lerEntrada("Gols " + jogos[i].timeVisitante + ": ");
                    jogos[i].resultadoRegistrado = true;
                    cout << endl;
                }
                pontosCalculados = false; 
                break;
            }

            case 2: { 
                cout << "\n--- Cadastro de Palpites ---\n";
                for (int i = 0; i < TOTAL_APOSTADORES; i++) {
                    cout << "Nome do Apostador " << i + 1 << ": ";
                    cin >> apostadores[i]->nome;

                    for (int j = 0; j < TOTAL_JOGOS; j++) {
                        cout << "\nPalpite para " << jogos[j].timeCasa << " x " << jogos[j].timeVisitante << ":" << endl;
                        apostadores[i]->palpites[j].golsCasa = lerEntrada("Gols " + jogos[j].timeCasa + ": ");
                        apostadores[i]->palpites[j].golsVisitante = lerEntrada("Gols " + jogos[j].timeVisitante + ": ");
                    }
                    apostadores[i]->palpitesRegistrados = true;
                    cout << "-----------------------------------\n";
                }
                pontosCalculados = false;
                break;
            }

            case 3: { 
                bool todosJogosRegistrados = true;
                for (int i = 0; i < TOTAL_JOGOS; i++) {
                    if (!jogos[i].resultadoRegistrado) todosJogosRegistrados = false;
                }

                bool todosPalpitesRegistrados = true;
                for (int i = 0; i < TOTAL_APOSTADORES; i++) {
                    if (!apostadores[i]->palpitesRegistrados) todosPalpitesRegistrados = false;
                }

                if (!todosJogosRegistrados || !todosPalpitesRegistrados) {
                    cout << "\n[ERRO] Registre os resultados dos jogos e os palpites antes de calcular!\n";
                    break;
                }

                for (int i = 0; i < TOTAL_APOSTADORES; i++) {
                    apostadores[i]->pontuacaoTotal = 0; 

                    for (int j = 0; j < TOTAL_JOGOS; j++) {
                        int golCasa = jogos[j].placarReal.golsCasa;
                        int golVis = jogos[j].placarReal.golsVisitante;
                        int palCasa = apostadores[i]->palpites[j].golsCasa;
                        int palVis = apostadores[i]->palpites[j].golsVisitante;

                        // Exato (10 pontos)
                        if (palCasa == golCasa && palVis == golVis) {
                            apostadores[i]->pontuacaoTotal += 10;
                        }
                        // Empate, mas placar diferente (3 pontos)
                        else if (golCasa == golVis && palCasa == palVis) {
                            apostadores[i]->pontuacaoTotal += 3;
                        }
                        // Acertou o vencedor (5 pontos)
                        else if ((golCasa > golVis && palCasa > palVis) || 
                                 (golCasa < golVis && palCasa < palVis)) {
                            apostadores[i]->pontuacaoTotal += 5;
                        }
                    }
                }
                pontosCalculados = true;
                cout << "\n[SUCESSO] Pontuacoes calculadas com sucesso!\n";
                break;
            }

            case 4: { 
                if (!pontosCalculados) {
                    cout << "\n[ERRO] Calcule as pontuacoes (Opcao 3) antes de exibir o ranking!\n";
                    break;
                }

                // Ordenação simples usando o Bubble Sort para montar o ranking
                for (int i = 0; i < TOTAL_APOSTADORES - 1; i++) {
                    for (int j = 0; j < TOTAL_APOSTADORES - i - 1; j++) {
                        if (apostadores[j]->pontuacaoTotal < apostadores[j + 1]->pontuacaoTotal) {
                            Apostador* temp = apostadores[j];
                            apostadores[j] = apostadores[j + 1];
                            apostadores[j + 1] = temp;
                        }
                    }
                }

                cout << "\n================ RANKING FINAL ================\n";
                for (int i = 0; i < TOTAL_APOSTADORES; i++) {
                    cout << i + 1 << "º Lugar: " << apostadores[i]->nome 
                         << " - " << apostadores[i]->pontuacaoTotal << " pontos\n";
                }
                cout << "===============================================\n";
                break;
            }

            case 5:
                cout << "\nEncerrando o programa...\n";
                break;

            default:
                cout << "\nOpcao invalida. Tente novamente.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Liberação de memória dos objetos Apostador
    for (int i = 0; i < TOTAL_APOSTADORES; i++) {
        delete apostadores[i]; 
    }

    return 0;
}
