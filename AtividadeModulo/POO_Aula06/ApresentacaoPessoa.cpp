/*
 Aula 6 - 15/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Vetores e Orientação a objetos em C++
*/

#include <iostream>

using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;

    public:

        Pessoa(string nome, int idade){
            this -> nome = nome;
            this -> idade = idade;
        }

        void mostrarInfo(){
            cout << "Meu nome é " << this -> nome << " " << "e eu Tenho " << this -> idade << " anos." << endl;
        }     
};

int main() {
    Pessoa aluno1("Rafael", 24);
    Pessoa aluno2("Leticia", 23);
    aluno1.mostrarInfo();
    aluno2.mostrarInfo();

    return 0;
}
