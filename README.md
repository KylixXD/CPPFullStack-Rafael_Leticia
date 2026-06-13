# Bolão Copa 2026

Este projeto foi desenvolvido como atividade acadêmica no curso de Desenvolvimento Full Stack, ministrado pela professora [Erika Dilliany](https://www.linkedin.com/in/erikadilly/).

O objetivo foi praticar conceitos fundamentais de C++, como estruturas de repetição e decisão, funções, vetores, validação de dados e organização da lógica do programa.

## Sobre o projeto

O programa simula um bolão com quatro jogos e dois participantes. Cada pessoa informa seu nome e seus palpites. Ao final, o sistema calcula os pontos e exibe o ranking.

O projeto foi dividido em duas versões:

- **Versão 1:** primeira implementação, feita sem vetores.
- **Versão 2:** evolução do programa, usando vetores para organizar os jogos e validação para impedir textos e números negativos nos palpites.

## Pontuação

- **10 pontos:** placar exato;
- **5 pontos:** acerto do vencedor;
- **3 pontos:** acerto do empate;
- **0 pontos:** resultado incorreto.

## Autores

- Letícia Alves
- Rafael Nóbrega

## Tecnologias

- C++
- Biblioteca padrão do C++

## Estrutura do projeto

```text
modulo-8/
|-- bolaoversao1/
|   `-- bolaocopa1.cpp
|-- bolaoversao2/
|   |-- bolaocopa2.cpp
|   `-- output/
|       `-- bolaocopa2.exe
|-- output/
`-- README.md
```

- `bolaoversao1/`: versão inicial sem vetores.
- `bolaoversao2/`: versão com vetores e validação de entrada.
- `output/`: arquivos executáveis gerados na compilação.

## Como executar

No PowerShell, dentro da pasta principal do projeto:

### Versão 1

```powershell
g++ .\bolaoversao1\bolaocopa1.cpp -o .\output\bolaocopa1.exe
.\output\bolaocopa1.exe
```

### Versão 2

```powershell
g++ .\bolaoversao2\bolaocopa2.cpp -o .\bolaoversao2\output\bolaocopa2.exe
.\bolaoversao2\output\bolaocopa2.exe
```
