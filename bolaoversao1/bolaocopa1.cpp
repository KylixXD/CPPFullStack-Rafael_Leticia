#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
  setlocale(LC_ALL,"pt_BR.UTF-8");

    int totalJogos = 4;
    int totalParticipantes = 2;

    char p1[4] = "BRA";
    char p2[4] = "EGY";
    char p3[4] = "RSA";
    char p4[4] = "MAR";
    char p5[4] = "FRA";
    char p6[4] = "ARG";
    char p7[4] = "GER";
    char p8[4] = "ECU";

    cout << "=================BOLÃO 2026========================";


    string firstNome = "Nenhum", secNome = "Nenhum";
    int firstPontos = -1, secPontos = -1;

    // LOOP DOS PARTICIPANTES
    for (int j = 1; j <= totalParticipantes; j++)
    {
        string nomeAtual;
        int pontuacaoTotal = 0;

        cout << "\nNome do participante " << j << ": ";
        cin >> nomeAtual;

        // LOOP DOS JOGOS
        for (int i = 1; i <= totalJogos; i++)
        {
            string timeCasa, timeVisitante;
            int golCasa, golVisitante;

            if (i == 1)
            {
                timeCasa = p1;
                timeVisitante = p2;
                golCasa = 3;
                golVisitante = 0;
            }
            else if (i == 2)
            {
                timeCasa = p3;
                timeVisitante = p4;
                golCasa = 1;
                golVisitante = 2;
            }
            else if (i == 3)
            {
                timeCasa = p5;
                timeVisitante = p6;
                golCasa = 2;
                golVisitante = 2;
            }
            else
            {
                timeCasa = p7;
                timeVisitante = p8;
                golCasa = 0;
                golVisitante = 3;
            }

            int palpiteCasa, palpiteVisitante;
            int pontosAtuais = 0;

            cout << "\nJogo " << i << ": "
                 << timeCasa << " x " << timeVisitante << endl;

            cout << "Palpite de gols para " << timeCasa << ": ";
            cin >> palpiteCasa;

            cout << "Palpite de gols para " << timeVisitante << ": ";
            cin >> palpiteVisitante;

            // Regras de pontuação
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

            pontuacaoTotal += pontosAtuais;
        }

        cout << "\n"
             << nomeAtual << " fez "
             << pontuacaoTotal << " pontos no total.\n";

        // LÓGICA DO RANKING EM TEMPO REAL
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

    // EXIBIÇÃO DO RANKING ATUALIZADO
    cout << "\n================Ranking====================";
    cout << "\n 1o: " << firstNome << " - " << firstPontos << " pontos";
    cout << "\n 2o: " << secNome << " - " << secPontos << " pontos";
    cout << "\n===========================================";

    return 0;
}
