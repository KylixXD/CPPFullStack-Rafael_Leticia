#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <limits>

using namespace std;

// Le e valida o palpite
int lerPalpite(string time)
{
    int palpite;

    cout << "Palpite de gols para " << time << ": ";
    cin >> palpite;

    // Repete enquanto o valor for invalido
    while (cin.fail() || palpite < 0)
    {
        // Limpa o erro do cin
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Entrada invalida. Digite um numero maior ou igual a zero: ";
        cin >> palpite;
    }

    return palpite;
}

int main()
{
    // Configura o idioma
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Quantidade de participantes
    int totalParticipantes = 2;

    // Times de cada jogo
    vector<string> casas = {"BRA", "RSA", "FRA", "GER"};
    vector<string> visitantes = {"EGY", "MAR", "ARG", "ECU"};

    // Resultados de cada jogo
    vector<int> golsCasas = {3, 1, 2, 0};
    vector<int> golsVisitantes = {0, 2, 2, 3};

    // Quantidade de jogos
    int totalJogos = casas.size();

    cout << "=================BOLÃO 2026========================";

    // Primeiro e segundo lugares
    string firstNome = "Nenhum", secNome = "Nenhum";
    int firstPontos = -1, secPontos = -1;

    // Percorre os participantes
    for (int j = 1; j <= totalParticipantes; j++)
    {
        string nomeAtual;
        int pontuacaoTotal = 0;

        // Le o nome
        cout << "\nNome do participante " << j << ": ";
        cin >> nomeAtual;

        // Percorre os jogos
        for (int i = 1; i <= totalJogos; i++)
        {
            // Ajusta o indice do vetor
            int indiceJogo = i - 1;

            // Busca os dados do jogo
            string timeCasa = casas[indiceJogo];
            string timeVisitante = visitantes[indiceJogo];
            int golCasa = golsCasas[indiceJogo];
            int golVisitante = golsVisitantes[indiceJogo];

            int palpiteCasa, palpiteVisitante;
            int pontosAtuais = 0;

            cout << "\nJogo " << i << ": "
                 << timeCasa << " x " << timeVisitante << endl;

            // Le os palpites validos
            palpiteCasa = lerPalpite(timeCasa);
            palpiteVisitante = lerPalpite(timeVisitante);

            // Calcula os pontos
            if (palpiteCasa == golCasa && palpiteVisitante == golVisitante)
            {
                pontosAtuais = 10;
            }
            else if (golCasa == golVisitante &&
                     palpiteCasa == palpiteVisitante)
            {
                pontosAtuais = 3;
            }
            else if ((golCasa > golVisitante && palpiteCasa > palpiteVisitante) ||
                     (golCasa < golVisitante && palpiteCasa < palpiteVisitante))
            {
                pontosAtuais = 5;
            }

            // Soma os pontos
            pontuacaoTotal += pontosAtuais;
        }

        // Mostra o total
        cout << "\n"
             << nomeAtual << " fez "
             << pontuacaoTotal << " pontos no total.\n";

        // Atualiza o ranking
        if (pontuacaoTotal > firstPontos)
        {
            secPontos = firstPontos;
            secNome = firstNome;

            firstPontos = pontuacaoTotal;
            firstNome = nomeAtual;
        }
        else if (pontuacaoTotal > secPontos)
        {
            secPontos = pontuacaoTotal;
            secNome = nomeAtual;
        }
    }

    // Mostra o ranking
    cout << "\n================Ranking====================";
    cout << "\n 1o: " << firstNome << " - " << firstPontos << " pontos";
    cout << "\n 2o: " << secNome << " - " << secPontos << " pontos";
    cout << "\n===========================================";

    return 0;
}
