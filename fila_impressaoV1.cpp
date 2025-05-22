/*
  2a QUESTÃO) Implemente a fila de impressão da xérox da área II. 
  Use uma lista encadeada onde o Sr. Armando possa 1) inserir um aluno na fila;
  2) Fazer a fila andar; 3) mostrar o status da fila;
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

    void inserir(string nome){
        No* novo = new No;
        novo->nome = nome;
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

    void remover(){
        No *temp = inicio;
        if(estaVazia()){
            cout << "Nenhum aluno na fila\n";
            return;
        }
        inicio = temp->proximo;
        delete temp;
    }

    void imprimir(){
        No *temp = inicio;
        int i = 0;
        while(temp!=nullptr){
            i++;
            cout << i << ". " << temp->nome << "\n";
            temp = temp->proximo;
        }
        if (i==0){
            cout << "Nenhum aluno na fila\n";
        }
    }

    
};

void menu(int *opcao){
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    cout << "Selecione a opcao:\n";
    cout << "1. Inserir Aluno\n2.Andar a fila\n3.Mostrar status\n4.Sair do programa\n";
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
                cout << "Nome do Aluno";
                cin >> nome;
                lista.inserir(nome);
                break;
            case 2:
                lista.remover();
                break;
            case 3:
                cout << "Fila de Impressao:\n";
                lista.imprimir();
                break;
            case 4:
                cout << "Programa encerrado!";
                finalizar = 1;
                break;
        }
    }
}                                     
