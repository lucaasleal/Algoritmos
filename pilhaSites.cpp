/* 3a QUESTÃO) Implemente uma pilha usando uma lista encadeada para resolver 
o problema de navegação em sites. O menu do seu programa deve ter: a) inserir um novo site na pilha; 
b) remover um site, isto é, desempilhar; c) mostrar todos os sites da pilha.
*/

#include <iostream>

using namespace std;

struct Node{
    string site;
    Node* next;
};

class Pilha {
    private:
        Node* top;

    public:
        Pilha(){
            top = nullptr;
        }

        bool estaVazia(){
            return top == nullptr;
        }

        void empilhar(string site){
            Node *novo = new Node;
            novo->site = site;
            novo->next = top;
            top = novo;
        }

        void desempilhar(){
            if(estaVazia()){
                cout << "Nenhum site na pilha\n";
                return;
            }
            Node *temp = top;
            top = temp->next;
            cout << "URL removido: " << temp->site << "\n";
            delete temp;
        }

        void imprimir(){
            if(estaVazia()){
                cout << "Nenhum site na pilha\n";
                return;
            }
            Node *temp = top;
            int i=0;
            while(temp!=nullptr){
                i++;
                for(int j=0; j<i; j++){
                    cout << " ";
                }
                cout << temp->site << "\n";
                temp = temp->next;
            }
        }
};

void menu(int *opcao){
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    cout << "Selecione a opcao:\n";
    cout << "1.Inserir site\n2.Remover site\n3.Mostrar sites\n4.Sair do programa\n";
    cin >> *opcao;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}

int main(){
    Pilha pilha;
    int op;
    string site;
    while(op!=4){
        menu(&op);
        switch (op){
            case 1:
                cout << "Insira o URL do site: ";
                cin >> site;
                pilha.empilhar(site);
            break;

            case 2:
                pilha.desempilhar();
            break;

            case 3:
                cout << "-=-=-=-=-=-=-=-Pilha de Sites-=-=-=-=-=-=-=-\n";
                pilha.imprimir();
            break;
            
            case 4:
                cout << "Programa Encerrado!";
            break;
    
        }
    }
    return 0;
}
