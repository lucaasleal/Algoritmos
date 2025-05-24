#include <iostream>

using namespace std;

class Pilha{
    public:
        int cor;
        Pilha* prox;
};


class Lista{
    public:
        int coluna;
        Pilha* topo;
        Lista* prox;
        Lista(){
            topo = NULL;
            prox = NULL;
        } 
};

Lista *inicio = NULL;

void EmpilharOuAdicionar(int coluna, int cor){
    Lista *temp = inicio;
    Lista *anterior = NULL;
    while(temp != NULL && temp->coluna != coluna){
        anterior = temp;
        temp = temp->prox;
    }
    if(temp!=NULL && temp->coluna == coluna){
        Pilha *nova = new Pilha();
        nova->cor = cor;
        nova->prox = temp->topo;
        temp->topo = nova;
    } else {
        Lista *temp = inicio;
        while(temp != NULL && temp->coluna < coluna){
            temp = temp->prox;
        }
        Lista *nova = new Lista();
        nova->coluna = coluna;
        Pilha *novaPilha = new Pilha();
        novaPilha->cor = cor;
        novaPilha->prox = NULL;
        nova->topo = novaPilha;
        if(anterior == NULL){
            nova->prox = inicio;
            inicio = nova;
        } else {
            nova->prox = temp;
            anterior->prox = nova;
        }
    }
}

void imprimir(){
    Lista *temp = inicio;
    while(temp != NULL){
        cout << "Coluna: " << temp->coluna << endl;
        Pilha *p = temp->topo;
        while(p != NULL){
            cout << "Cor: " << p->cor << " ";
            p = p->prox;
        }
        temp = temp->prox;
        cout << endl;
    }
}

int main(){
    int rodadas, coluna=0, cor;
    string entrada;
    cin >> rodadas;
    for(int i=0; i<rodadas; i++){
        cin >> entrada;
        coluna = 0;
        while(entrada!="END"){
            int j=0;
            while(entrada[j]!='\0'){
                coluna = coluna*10 + (entrada[j]-'0');
                j++;
            }
            if (entrada == "END") break;
            cin >> cor;
            cin >> entrada;
            EmpilharOuAdicionar(coluna, cor);
            coluna = 0;
        }
        entrada = "";
        cout << "Rodada " << i + 1 << ":" << endl;
        imprimir();
        cout << endl;

        while (inicio != NULL) {
            Pilha* p = inicio->topo;
            while (p != NULL) {
                Pilha* aux = p;
                p = p->prox;
                delete aux;
            }
            Lista* aux = inicio;
            inicio = inicio->prox;
            delete aux;
        }
    }
    return 0;
}
