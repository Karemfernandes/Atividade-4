#include <iostream>
#include <list>

using namespace std;

class jogador
{
private:
    string nome, posicao;
    int numero;

public:
    jogador()
    {
    }
    jogador(string n, string p, int nu)
    {
        nome = n;
        posicao = p;
        numero = nu;
    }

    //sobrecarga operador ==
    bool operator==(const jogador &p) const
    {
        return nome == p.nome;
    }

    void imprimir()
    {
        cout << nome << " - " << posicao << " - " << numero << endl;
    }
};

class equipe
{
private:
    list<jogador> jogadores;
    string nome;
    string naciolidade;
    int ano;

public:
    equipe()
    {
        nome = "";
        naciolidade = "";
        ano = 0;
    }
    equipe(string n, string na, int a)
    {
        nome = n;
        naciolidade = na;
        ano = a;
    }

    //sobrecarga operador ==
    bool operator==(const equipe &p) const
    {
        return nome == p.nome;
    }

    void insereJogador()
    {
        cout << "Time a ser adicionado o jogador: " << nome << endl;
        string nomeJogador, posicaoJogador;
        int numeroJogador;
        cout << "Digite o nome do jogador: ";
        cin >> nomeJogador;
        cout << "Digite a posição do jogador: ";
        cin >> posicaoJogador;
        cout << "Digite o número do jogador: ";
        cin >> numeroJogador;
        jogador temp(nomeJogador, posicaoJogador, numeroJogador);
        jogadores.push_back(temp);
        cout << "\nJogador inserido com sucesso\n";
    }

    void imprimirEquipe()
    {
        cout << "Equipe: " << nome;
        cout << "\nJogadores da equipe:\n";
        for (auto item : jogadores)
        {
            item.imprimir();
        }
    }
    void removeJogador()
    {
        string n;
        cout << "Digite o nome do jogador a ser removido:";
        cin >> n;
        jogador temp(n, "", 0);
        jogadores.remove(temp);
    }
};

void cadastraEquipe(list<equipe> &lista)
{
    string nome;
    string naciolidade;
    int ano;

    cout << "Nome da Equipe: ";
    cin >> nome;
    cout << "Nacionalidade: ";
    cin >> naciolidade;
    cout << "Ano: ";
    cin >> ano;

    lista.push_back(equipe(nome, naciolidade, ano));
}

void removeEquipe(list<equipe> &lista)
{
    string nomeEquipe;
    cout << "Digite o nome da equipe que deseja excluir: ";
    cin >> nomeEquipe;
    equipe aux = equipe(nomeEquipe, "", 0);
    lista.remove(aux);
}

void removeJogador(list<equipe> &lista)
{
    string nomeEquipe;
    cout << "Digite o nome da equipe que deseja excluir: ";
    cin >> nomeEquipe;
    equipe aux = equipe(nomeEquipe, "", 0);

    for (auto &item : lista)
    {
        if (item == aux)
        {
            item.removeJogador();
            break;
        }
    }
}

void imprime(list<equipe> &lista)
{
    for (auto item : lista)
    {
        item.imprimirEquipe();
    }
}

void cadastroJogador(list<equipe> &lista)
{
    cout << "Em qual time deseja adicionar um jogador? ";
    string e;
    cin >> e;
    equipe temp(e, "", 0);
    for (auto &item : lista)
    {
        if (item == temp)
        {
            item.insereJogador();
        }
    }
}

int main()
{
    list<equipe> torneio;

    while (1)
    {
        int i;
        cout << "Menu\n\n";
        cout << "1 - Cadastro de Times\n";
        cout << "2 - Remover de Times\n";
        cout << "3 - Cadastrar Jogador\n";
        cout << "4 - Remover Jogador\n";
        cout << "5 - Imprimir\n";
        cout << "0 - Sair\n\n";

        cin >> i;

        switch (i)
        {
        case 1:
            cadastraEquipe(torneio);
            break;
        case 2:
            removeEquipe(torneio);
            break;
        case 3:
            cadastroJogador(torneio);
            break;
        case 4:
            removeJogador(torneio);
            break;
        case 5:
            imprime(torneio);
            break;
        default:
            break;
        }

        if (i == 0)
        {
            break;
        }
    }
}
