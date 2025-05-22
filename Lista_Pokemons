/* 1a QUESTAO) Você foi contratado para desenvolver o sistema de Ash, um exímio caçador de Pokemons. 
Crie um menu onde Ash possa 1) Inserir um Pokemon (para cadastrar, solicite nome e idade do pokemon); 
2) Procurar o Pokemon pelo nome; 3) Remover o Pokemon pelo nome; 4) imprimir todos os Pokemons cadastrados; 
5) Sair do Programa.Utilize uma lista duplamente encadeada como estrutura de dados para armazenar os pokemons. 
*/

#include <iostream>

using namespace std;

struct No {
    string nome;
    int idade;
    No* proximo;
    No* anterior;
};

class Lista {
private:
    No* inicio;
    No* fim;

public:
    Lista(){
        inicio = nullptr;
        fim = nullptr;
    }

    bool estaVazia(){
        return inicio == nullptr;
    }

    void inserir(string nome, int idade){
        No* novo = new No;
        novo->nome = nome;
        novo->idade = idade;
        novo->proximo = nullptr;
        novo->anterior = fim;
        if(estaVazia()){
            inicio = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            novo->anterior = fim;
            fim = novo;
        }
    }

    void procurar(string nome){
        No *temp = inicio;
        if(estaVazia()){
            cout << "Nenhum Pokemon cadastrado\n";
            return;
        }
        bool encontrado = false;
        while(temp!=nullptr && !encontrado){
            if(temp->nome == nome){
                encontrado = true;
            }
            if(!encontrado){
              temp = temp->proximo;
            }
        }
        if (encontrado){
            cout << "Pokemon encontrado\n";
            cout << "Nome: " << temp->nome << "\n";
            cout << "Idade: " << temp->idade << "\n";
        } else {
            cout << nome << " não encontrado!\n";
        }
    }

    void remover(string nome){
        No *temp = inicio;
        bool encontrado = false;
        if(estaVazia()){
            cout << "Nenhum Pokemon cadastrado\n";
            return;
        }
        while(temp!=nullptr && !encontrado){
            if(temp->nome == nome){
                encontrado = true;
            }
            if(!encontrado){
              temp = temp->proximo;
            }
        }
        if (encontrado){
            if (temp->anterior == nullptr){
                inicio = temp->proximo;
            } else if (temp->proximo == nullptr) {
                temp->anterior->proximo = nullptr;
            } else {
                 temp->anterior->proximo = temp->proximo;
            }
            cout << nome << " removido com sucesso!\n";
        } else {
            cout << nome << " não encontrado!\n";
        }
        delete temp;
    }

    void imprimir(){
        No *temp = inicio;
        int i = 0;
        while(temp!=nullptr){
            i++;
            cout << i << ". " << temp->nome << " | Age = " << temp->idade << "\n";
            temp = temp->proximo;
        }
        if (i==0){
            cout << "Nenhum Pokemon cadastrado\n";
        }
    }

    
};

void menu(int *opcao){
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    cout << "Selecione a opcao:\n";
    cout << "1. Inserir Pokemon\n2.Procurar Pokemon\n3.Remover Pokemon\n4.Imprimir Pokemons\n5.Sair do programa\n";
    cin >> *opcao;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}

int main(){
    Lista lista;
    int opcao, valor, num_op;
    string nome;
    int idade;
    bool finalizar;
    while(!finalizar){
        menu(&opcao);
        switch(opcao){
            case 1:
                cout << "Nome do Pokemon: ";
                cin >> nome;
                cout << "Idade do Pokemon: ";
                cin >> valor;
                lista.inserir(nome, valor);
                break;
            case 2:
                cout << "Nome do Pokemon: ";
                cin >> nome;
                lista.procurar(nome);
                break;
            case 3:
                cout << "Nome do Pokemon: ";
                cin >> nome;
                lista.remover(nome);
                break;
            case 4:
                cout << "-=-=-=-=-=- Lista de Pokemons -=-=-=-=-=-\n";
                lista.imprimir();
                break;
            case 5:
                cout << "Programa encerrado!";
                finalizar = 1;
                break;
        }
    }
}
