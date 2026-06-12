# Bolão Copa 2026

Projeto em C++ que simula um bolão de jogos da Copa com entrada de palpites, cálculo de pontuação e ranking final dos participantes.

## Autores

- Letícia Alves
- Rafael Nóbrega

## Objetivo do Projeto

Este programa foi desenvolvido para praticar lógica de programação em C++, especialmente:

- Estruturas de repetição (`for`)
- Estruturas condicionais (`if`, `else if`, `else`)
- Leitura de dados com `cin`
- Exibição de resultados com `cout`
- Acumulação de pontos e criação de ranking

O sistema simula um bolão com partidas já definidas, onde cada participante informa seus palpites de placar. Ao final, o programa calcula os pontos e monta um ranking com 1º e 2º colocados.

## Como o Programa Funciona

O código atual está configurado com:

- `totalJogos = 4`
- `totalParticipantes = 2`

### Jogos considerados no bolão

1. BRA x EGY (resultado real: 3 x 0)
2. RSA x MAR (resultado real: 1 x 2)
3. FRA x ARG (resultado real: 2 x 2)
4. GER x ECU (resultado real: 0 x 3)

Para cada participante, o programa:

1. Lê o nome.
2. Mostra cada jogo.
3. Solicita o palpite de gols para os dois times.
4. Calcula a pontuação por jogo.
5. Soma a pontuação total.
6. Atualiza o ranking em tempo real.

No final, exibe:

- Nome e pontuação do 1º colocado
- Nome e pontuação do 2º colocado

## Regras de Pontuação

A pontuação segue esta lógica:

- **10 pontos**: acertou o placar exato (gols dos dois times)
- **5 pontos**: acertou apenas o vencedor da partida
- **3 pontos**: acertou que o jogo terminou empatado (sem precisar acertar o placar exato)
- **0 pontos**: não acertou nem resultado final, nem empate

### Exemplo rápido

Se o resultado real for `2 x 1`:

- Palpite `2 x 1` → 10 pontos
- Palpite `1 x 0` → 5 pontos (acertou vencedor)
- Palpite `0 x 0` → 0 pontos

Se o resultado real for `2 x 2`:

- Palpite `2 x 2` → 10 pontos
- Palpite `1 x 1` → 3 pontos (acertou empate)
- Palpite `2 x 1` → 0 pontos

## Estrutura do Projeto

```text
modulo-8/
|- bolaocopa2026.cpp
|- README.md
`- output/
```

- `bolaocopa2026.cpp`: código-fonte principal
- `README.md`: documentação do projeto
- `output/`: pasta para executável gerado na compilação

## Como Compilar e Executar (Windows + g++)

No PowerShell, dentro da pasta do projeto:

```powershell
g++ -Wall -Wextra -g3 .\bolaocopa2026.cpp -o .\output\bolaocopa2026.exe
```

Depois, execute:

```powershell
.\output\bolaocopa2026.exe
```

## Exemplo de Execução

Fluxo esperado durante o uso:

1. Informar nome do participante 1
2. Digitar palpites para os 4 jogos
3. Informar nome do participante 2
4. Digitar palpites para os 4 jogos
5. Visualizar ranking final na tela

## Pontos de Atenção da Versão Atual

- Número de participantes e jogos está fixo no código.
- Resultados reais também estão fixos no código.
- Não há validação para impedir gols negativos ou entradas inválidas.
- Em caso de empate de pontuação, o critério de desempate não está detalhado.

## Sugestões de Melhoria

- Permitir informar quantidade de participantes dinamicamente.
- Permitir cadastrar jogos e resultados sem alterar o código.
- Salvar ranking em arquivo (`.txt` ou `.csv`).
- Implementar desempate por critérios adicionais.
- Criar menu para repetir campeonato sem reiniciar o programa.

## Tecnologias Utilizadas

- C++
- Biblioteca padrão de entrada/saída (`iostream`)
- Manipulação de texto (`string`)
- Localização (`locale`)

## Conclusão

Este projeto é uma base sólida para aprender lógica em C++ com um cenário prático e fácil de entender. O código já cobre entrada de dados, aplicação de regras e ranking, sendo um ótimo ponto de partida para evoluções futuras.
