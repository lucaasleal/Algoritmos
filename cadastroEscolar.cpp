#include <iostream>

using namespace std;


class Aluno{
    private:
        string nome;
        string CPF;
        Aluno* proximoAluno;
        Aluno* alunoAnterior;
        Aluno* inicio;
        Aluno* fim;
    public:

        Aluno() : nome(""), CPF(""), proximoAluno(nullptr), 
        alunoAnterior(nullptr), inicio(nullptr), fim(nullptr) {}

        bool estaVazia(){
            return inicio == nullptr;
        }

        void cadastrarAluno(string nome, string CPF){
            Aluno* novo = new Aluno;
            novo->nome = nome;
            novo->CPF = CPF;
            novo->proximoAluno = nullptr;
            if(estaVazia()){
                inicio = novo;
                fim = novo;
            } else {
                fim->proximoAluno = novo;
                novo->alunoAnterior = fim;
                fim = novo;
            }
        }

        void imprimirAlunos(){
            Aluno* temp = inicio;
            int i=0;
            while(temp!=nullptr){
                i++;
                cout << i << ". " << temp->nome << " | CPF = " << temp->CPF << "\n";
                temp = temp->proximoAluno;
            }
            if (i==0){
                cout << "Nenhum aluno cadastrado\n";
            }
        }
};


class Escola{
    private:
        string nome;
        string endereco;
        Aluno alunos;
        Escola* proximaEscola;
        Escola* escolaAnterior;
        Escola* inicio;
        Escola* fim;
    public:
        Escola() : nome(""), endereco(""), 
               proximaEscola(nullptr), escolaAnterior(nullptr),
               inicio(nullptr), fim(nullptr) {}

        bool estaVazia(){
            return inicio == nullptr;
        }

        void cadastrarEscola(string nome, string endereco){
            Escola* novaEscola = new Escola;
            novaEscola->nome = nome;
            novaEscola->endereco = endereco;
            novaEscola->proximaEscola = nullptr;
            if(estaVazia()){
                inicio = novaEscola;
                fim = novaEscola;
            } else {
                fim->proximaEscola = novaEscola;
                novaEscola->escolaAnterior = fim;
                fim = novaEscola;
            }
        }

        void imprimirEscolas(){
            cout << "LISTA DE ESCOLAS CADASTRADAS:\n";
            cout << "---------------------------------\n";
            Escola* temp = inicio;
            int i=0;
            while(temp!=nullptr){
                i++;
                cout << i << ". " << temp->nome << " | Endereco = " << temp->endereco << "\n";
                temp = temp->proximaEscola;
            }
            if (i==0){
                cout << "Nenhuma escola cadastrada\n";
            }
        }

        void procurarEscola(string nome, string nomeAluno, string cpf, int op){
            Escola* temp = inicio;
            if(estaVazia()){
                cout << "Nenhuma escola cadastrada\n";
                return;
            }
            bool encontrado = false;
            while(temp!=nullptr && !encontrado){
                if(temp->nome == nome){
                    encontrado = true;
                }
                if(!encontrado){
                  temp = temp->proximaEscola;
                }
            }
            if (encontrado && op == 3){
                cout << "Escola encontrada!\n";
                cout << "Nome: " << temp->nome << "\n";
                cout << "Endereco: " << temp->endereco << "\n";
                temp->alunos.cadastrarAluno(nomeAluno, cpf);
                cout << "Aluno cadastrado com sucesso!\n";
            } else if (encontrado && op == 4){
                cout << "Escola " << temp->nome << " encontrada!\n";
                cout << "Endereco: " << temp->endereco << "\n";
                cout << "Alunos cadastrados:\n";
                temp->alunos.imprimirAlunos();
            } else if (op == 5){
                cout << "LISTA DE ALUNOS CADASTRADOS:\n";
                Escola* temp = inicio;
                while(temp!=nullptr){               
                    cout << "Escola: " << temp->nome <<"\n";
                    cout << "Endereco: " << temp->endereco << "\n";
                    cout << "Alunos cadastrados:\n";
                    temp->alunos.imprimirAlunos();
                    temp = temp->proximaEscola;
                }
            } else {
                cout << "Escola " << nome << " não encontrada!\n";
            }
        }
};

void menu(int* op){
    cout << "---------------------------------\n";
    cout << "CADASTRO ESCOLAR\n";
    cout << "Escolha uma opção:\n";
    cout << "1. Cadastrar Escola\n";
    cout << "2. Imprimir Escolas\n";
    cout << "3. Cadastrar Aluno\n";
    cout << "4. Imprimir Alunos\n";
    cout << "5. Imprimir todos os alunos cadastrados\n";
    cout << "6. Sair\n";
    cin >> *op;
}

int main(){
    Escola escola;
    int op;
    string nome, endereco, nomeAluno, cpf;
    while(op!=6){
        menu(&op);
        switch(op){
            case 1:
                cout << "Digite o nome da escola: ";
                cin >> nome;
                cout << "Digite o endereco da escola: ";
                cin >> endereco;
                escola.cadastrarEscola(nome, endereco);
                break;
            case 2:
                escola.imprimirEscolas();
                break;
            case 3:
                cout << "Digite o nome da escola: ";
                cin >> nome;
                cout << "Digite o nome do aluno: ";
                cin >> nomeAluno;
                cout << "Digite o CPF do aluno: ";
                cin >> cpf;
                escola.procurarEscola(nome, nomeAluno, cpf, op);
                break;
            case 4:
                cout << "Digite o nome da escola: ";
                cin >> nome;
                escola.procurarEscola(nome, "", "", op);
                break;
            case 5:
                escola.procurarEscola("", "", "", op);
                break;
            case 6:
                cout << "Saindo...\n";
                break;

        }

    }
}