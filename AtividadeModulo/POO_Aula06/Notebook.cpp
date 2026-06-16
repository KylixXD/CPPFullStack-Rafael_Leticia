/*
 Aula 6 - 15/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Vetores e Orientação a objetos em C++
*/

#include <iostream>

using namespace std;

class Notebook {
    private:
        std::string marca;
        std::string modelo;

    public:
        Notebook(string marca,string modelo){
            this ->marca = marca;
            this ->modelo = modelo;
        }

        
        void ligarNotebook(){
            cout << "O notebook " << this ->marca << " " << this ->modelo << " está ligando...." << endl;
        }
        
        void desligarNotebook(){
            cout << "O notebook " << this ->marca << " " << this ->modelo << " está desligando...." << endl;
        }
        
        void exibirSpecs(){
            cout << "Marca: " << this ->marca << endl;
            cout << "Modelo: " << this ->modelo << endl;
        }
    };

    int main() {
        Notebook aluno1("Acer", "Nitro 5");
        Notebook aluno2("Dell", "Latitude 3420");
        aluno1.ligarNotebook();
        aluno1.desligarNotebook();

        aluno1.exibirSpecs();
        aluno2.exibirSpecs();

        return 0;
    }
