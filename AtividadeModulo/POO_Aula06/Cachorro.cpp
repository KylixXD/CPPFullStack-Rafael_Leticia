/*
 Aula 6 - 15/06/2026
 Linguagem de Programação C++
 Profa. Erika Dilly
 Vetores e Orientação a objetos em C++
*/

#include <iostream>

using namespace std;

class Cachorro {
    private:
        string nome;
        string raca;

    public:
            Cachorro(string nome, string raca){
            this -> nome = nome;
            this -> raca = raca;
        }

        void latir(){
            cout << "AU AU! O cachorro " << this -> nome << " " << "está latindo" << endl;
        }   
};

int main(){
    Cachorro dog1("Bidu", "Salsicha");
    Cachorro dog2("Pretinha", "Viralata");

    dog1.latir();
    dog2.latir();

}
