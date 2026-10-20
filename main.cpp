#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

struct Reserva{
    string professor = "";
    string materia = "";
    int qntAlunos = 0;
    bool ocupado = false;
    bool fixa = false;
};

struct Sala{
    string nomeSala;
    int computadores;
    int computadoresDisp;
    char defeito;
    int qntDefeito;
    Reserva grade[5][9];
};

void painelGeral(){
        cout << endl <<" ---- Sistema de Salas ----"  << endl << endl << "  1 - Consultar horarios" << endl << "  2 - Realizar agendamento" << endl << "  3 - Remover agendamento" << endl;
        cout << "  4 - Gerenciar aulas fixas" << endl << "  5 - Gerenciar computadores" << endl << "  0 - Sair" << endl << " R. ";
    }

void painelSala(){
    cout << endl << " Informe a sala: " << endl << "  1 - Leitura" << endl << "  2 - Reuniao" << endl << "  3 - Informatica" << endl << "  R. ";
}

int lerNumero(){
    int numero;
    while(!(cin >> numero)){
        if(cin.eof()){
            exit(0);
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "  Entrada invalida! Digite apenas numeros: ";
    }
    cin.ignore(10000, '\n');
    return numero;
}

char lerLetra(){
    char letra;
    cin >> letra;
    if(cin.eof()){
        exit(0);
    }
    cin.ignore(10000, '\n');
    return letra;
}

string lerTexto(){
    string texto;
    getline(cin, texto);
    while(texto == ""){
        if(cin.eof()){
            exit(0);
        }
        cout << "  Campo nao pode ficar vazio. Digite novamente: ";
        getline(cin, texto);
    }
    return texto;
}

string dias[5] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};

void exibirHorarios(Sala &sala){
    for(int i = 0; i < 5; i++){
        cout << endl << "== " << dias[i] << " ==" << endl;

        for(int j = 0; j < 9; j++){
            cout << "  " << (j+1) << "a aula: ";

            if(sala.grade[i][j].ocupado){
                cout << sala.grade[i][j].materia << " - Prof. " << sala.grade[i][j].professor;
                if(sala.grade[i][j].fixa) cout << " (fixa)";
                cout << endl;
            }
            else{
                cout << "Livre" << endl;
            }
        }
    }
}

const string SENHA_AULAS = "1234";

bool verificarSenha(){
    string senha;

    for(int i = 1; i <= 3; i++){
        cout << endl << "  Insira a senha para gerenciar as aulas fixas (" << i << "/3): ";
        cin >> senha;
        cin.ignore(10000, '\n');

        if(senha == SENHA_AULAS){
            return true;
        }
        cout << "  Senha incorreta!" << endl;
    }
    return false;
}

void aulaFixa(Sala &sala, int dia, int aula, string professor){
    sala.grade[dia][aula].professor = professor;
    sala.grade[dia][aula].materia = "Aula";
    sala.grade[dia][aula].ocupado = true;
    sala.grade[dia][aula].fixa = true;
}

void carregarAulasFixas(vector<Sala> &salas){

    // SALA LEITURA
    aulaFixa(salas[0], 0, 0, "Limpeza");
    aulaFixa(salas[0], 0, 1, "Helena");
    aulaFixa(salas[0], 0, 2, "Raquel");
    aulaFixa(salas[0], 0, 3, "Debora");
    aulaFixa(salas[0], 0, 4, "Debora");
    aulaFixa(salas[0], 0, 5, "Camila");

    aulaFixa(salas[0], 1, 1, "Helena");
    aulaFixa(salas[0], 1, 3, "Helena");
    aulaFixa(salas[0], 1, 4, "Viviane");
    aulaFixa(salas[0], 1, 5, "Camila");
    aulaFixa(salas[0], 1, 6, "Helena");

    aulaFixa(salas[0], 2, 0, "Helena");
    aulaFixa(salas[0], 2, 3, "Camila");
    aulaFixa(salas[0], 2, 4, "Patricia");
    aulaFixa(salas[0], 2, 6, "Helena");
    aulaFixa(salas[0], 2, 7, "Beatriz");

    aulaFixa(salas[0], 3, 1, "Helena");
    aulaFixa(salas[0], 3, 2, "Beatriz");
    aulaFixa(salas[0], 3, 3, "Beatriz");
    aulaFixa(salas[0], 3, 4, "Helena");
    aulaFixa(salas[0], 3, 7, "Beatriz");

    aulaFixa(salas[0], 4, 0, "Beatriz");
    aulaFixa(salas[0], 4, 1, "Beatriz");
    aulaFixa(salas[0], 4, 4, "Camila");
    aulaFixa(salas[0], 4, 6, "Beatriz");

    // SALA REUNIAO
    aulaFixa(salas[1], 0, 0, "Larissa");
    aulaFixa(salas[1], 0, 2, "Larissa");
    aulaFixa(salas[1], 0, 3, "Larissa");
    aulaFixa(salas[1], 0, 6, "Raquel");

    aulaFixa(salas[1], 1, 1, "Larissa");
    aulaFixa(salas[1], 1, 3, "Raquel");
    aulaFixa(salas[1], 1, 4, "Cristina");
    aulaFixa(salas[1], 1, 5, "Debora");

    aulaFixa(salas[1], 2, 0, "Cristina");
    aulaFixa(salas[1], 2, 1, "Cristina");
    aulaFixa(salas[1], 2, 4, "Fernanda");
    aulaFixa(salas[1], 2, 7, "Raquel");

    aulaFixa(salas[1], 3, 2, "Cristina");
    aulaFixa(salas[1], 3, 3, "Fernanda");
    aulaFixa(salas[1], 3, 4, "Beatriz");
    aulaFixa(salas[1], 3, 6, "Cristina");

    aulaFixa(salas[1], 4, 0, "Larissa");
    aulaFixa(salas[1], 4, 1, "Debora");
    aulaFixa(salas[1], 4, 3, "Cristina");
    aulaFixa(salas[1], 4, 5, "Raquel");
    aulaFixa(salas[1], 4, 6, "Fernanda");

    // SALA INFORMATICA
    aulaFixa(salas[2], 0, 0, "Rafael");
    aulaFixa(salas[2], 0, 1, "Fernanda");
    aulaFixa(salas[2], 0, 3, "Marcelo");
    aulaFixa(salas[2], 0, 4, "Juliana");
    aulaFixa(salas[2], 0, 6, "Juliana");

    aulaFixa(salas[2], 1, 3, "Rafael");
    aulaFixa(salas[2], 1, 4, "Rafael");
    aulaFixa(salas[2], 1, 5, "Marcelo");
    aulaFixa(salas[2], 1, 6, "Marcelo");

    aulaFixa(salas[2], 2, 1, "Rafael");
    aulaFixa(salas[2], 2, 2, "Rafael");
    aulaFixa(salas[2], 2, 4, "Rafael");

    aulaFixa(salas[2], 3, 0, "Marcelo");
    aulaFixa(salas[2], 3, 1, "Marcelo");
    aulaFixa(salas[2], 3, 4, "Marcelo");
    aulaFixa(salas[2], 3, 5, "Marcelo");
    aulaFixa(salas[2], 3, 7, "Marcelo");

    aulaFixa(salas[2], 4, 1, "Marcelo");
    aulaFixa(salas[2], 4, 2, "Marcelo");
    aulaFixa(salas[2], 4, 3, "Marcelo");
    aulaFixa(salas[2], 4, 5, "Rafael");
    aulaFixa(salas[2], 4, 6, "Rafael");
    aulaFixa(salas[2], 4, 7, "Rafael");
}

void removerAulaFixa(Sala &sala){
    int dia, aula;
    char resp;

    exibirHorarios(sala);

    cout << endl << "  Informe o dia da aula fixa (1-Segunda, 2-Terca, 3-Quarta, 4-Quinta, 5-Sexta): ";
    dia = lerNumero();
    cout << "  Informe a aula (1 a 9): ";
    aula = lerNumero();

    if(dia < 1 || dia > 5 || aula < 1 || aula > 9){
        cout << endl << "  Dia ou aula invalidos!" << endl;
    }
    else if(!sala.grade[dia-1][aula-1].ocupado || !sala.grade[dia-1][aula-1].fixa){
        cout << endl << "  Nao ha aula fixa nesse horario." << endl;
    }
    else{
        cout << endl << "  Aula fixa: Prof. " << sala.grade[dia-1][aula-1].professor << endl;
        cout << "  Deseja remover? (S/N): ";
        resp = lerLetra();

        if(resp == 'S' || resp == 's'){
            sala.grade[dia-1][aula-1].professor = "";
            sala.grade[dia-1][aula-1].materia = "";
            sala.grade[dia-1][aula-1].qntAlunos = 0;
            sala.grade[dia-1][aula-1].ocupado = false;
            sala.grade[dia-1][aula-1].fixa = false;
            cout << endl << "  Aula fixa removida!" << endl;
        }
        else{
            cout << endl << "  Nenhuma alteracao feita." << endl;
        }
    }
}

void pausar(){
    cout << endl;
    system("pause");
}

int main()
{
    int opcao;
    int opc;

    vector<Sala> salas = {
        {"Sala  Leitura", 20, 20},
        {"Sala  Reuniao", 25, 25},
        {"Sala  Informatica", 30, 30}
    };

    carregarAulasFixas(salas);

    do{
        system("cls");
        painelGeral();
        opcao = lerNumero();

        switch (opcao){
        case 1:
            painelSala();
            opc = lerNumero();
            system("cls");

            if(opc == 1){
                cout << " Sala selecionada: " << salas[0].nomeSala << endl;
                exibirHorarios(salas[0]);
            }
            else if(opc == 2){
                cout << " Sala selecionada: " << salas[1].nomeSala << endl;
                exibirHorarios(salas[1]);
            }
            else if(opc == 3){
                cout << " Sala selecionada: " << salas[2].nomeSala << endl;
                exibirHorarios(salas[2]);
            }
            else{
                cout << "Opcao Invalida! Tente novamente";
            }
            pausar();
            break;

        case 2:{
            system("cls");

            painelSala();
            opc = lerNumero();
            system("cls");

            if(opc >= 1 && opc <= 3){
                int dia, aula;

                cout << endl << " Sala selecionada: " << salas[opc-1].nomeSala << endl;
                cout << endl << "  Informe o dia (1-Segunda, 2-Terca, 3-Quarta, 4-Quinta, 5-Sexta): ";
                dia = lerNumero();
                cout << "  Informe a aula (1 a 9): ";
                aula = lerNumero();

                if(dia < 1 || dia > 5 || aula < 1 || aula > 9){
                    cout << endl << "  Dia ou aula invalidos!" << endl;
                }
                else if(salas[opc-1].grade[dia-1][aula-1].ocupado){
                    cout << endl << "  Esse horario ja esta agendado por outro professor." << endl;
                }
                else{

                    int capacidade = salas[opc-1].computadoresDisp - salas[opc-1].qntDefeito;

                    if(capacidade <= 0){
                        cout << endl << "  Essa sala nao tem computadores disponiveis no momento." << endl;
                    }
                    else{
                        cout << "  Informe o nome do professor: ";
                        salas[opc-1].grade[dia-1][aula-1].professor = lerTexto();
                        cout << "  Informe a materia: ";
                        salas[opc-1].grade[dia-1][aula-1].materia = lerTexto();

                        cout << "  Informe a quantidade de alunos (maximo " << capacidade << "): ";
                        int alunos = lerNumero();
                        while(alunos < 1 || alunos > capacidade){
                            cout << "  Quantidade invalida! A sala comporta de 1 a " << capacidade << " alunos: ";
                            alunos = lerNumero();
                        }
                        salas[opc-1].grade[dia-1][aula-1].qntAlunos = alunos;

                        salas[opc-1].grade[dia-1][aula-1].ocupado = true;
                        cout << endl << "  Aula agendada com sucesso!" << endl;
                    }
                }
            }
            else{
                cout << " Opcao invalida! Tente novamente" << endl;
            }
            pausar();
            break;
        }

        case 3:{
            system("cls");

            painelSala();
            opc = lerNumero();
            system("cls");

            if(opc >= 1 && opc <= 3){
                int dia, aula;
                char resp;

                cout << endl << " Sala selecionada: " << salas[opc-1].nomeSala << endl;
                cout << endl << "  Informe o dia (1-Segunda, 2-Terca, 3-Quarta, 4-Quinta, 5-Sexta): ";
                dia = lerNumero();
                cout << "  Informe a aula (1 a 9): ";
                aula = lerNumero();

                if(dia < 1 || dia > 5 || aula < 1 || aula > 9){
                    cout << endl << "  Dia ou aula invalidos!" << endl;
                }
                else if(!salas[opc-1].grade[dia-1][aula-1].ocupado){
                    cout << endl << "  Nao ha agendamento nesse horario." << endl;
                }
                else if(salas[opc-1].grade[dia-1][aula-1].fixa){
                    cout << endl << "  Esse horario e de uma aula fixa e nao pode ser removido aqui." << endl;
                }
                else{
                    cout << endl << "  Agendamento: " << salas[opc-1].grade[dia-1][aula-1].materia << " - Prof. " << salas[opc-1].grade[dia-1][aula-1].professor << endl;
                    cout << "  Deseja remover? (S/N): ";
                    resp = lerLetra();

                    if(resp == 'S' || resp == 's'){
                        salas[opc-1].grade[dia-1][aula-1].professor = "";
                        salas[opc-1].grade[dia-1][aula-1].materia = "";
                        salas[opc-1].grade[dia-1][aula-1].qntAlunos = 0;
                        salas[opc-1].grade[dia-1][aula-1].ocupado = false;
                        cout << endl << "  Agendamento removido!" << endl;
                    }
                    else{
                        cout << endl << "  Nenhuma alteracao feita." << endl;
                    }
                }
            }
            else{
                cout << " Opcao invalida! Tente novamente" << endl;
            }
            pausar();
            break;
        }

        case 4:
            system("cls");

            if(verificarSenha()){
                system("cls");
                painelSala();
                opc = lerNumero();
                system("cls");

                if(opc >= 1 && opc <= 3){
                    cout << " Sala selecionada: " << salas[opc-1].nomeSala << endl;
                    removerAulaFixa(salas[opc-1]);
                }
                else{
                    cout << " Opcao invalida! Tente novamente" << endl;
                }
            }
            else{
                cout << endl << "  Acesso negado!" << endl;
            }
            pausar();
            break;

        case 5:
            system("cls");

            painelSala();
            opc = lerNumero();
            system("cls");


            if(opc == 1){

                cout << endl <<" Sala selecionada:" << salas[0].nomeSala << endl;
                cout << endl << "  Quantidade de computadores:" << salas[0].computadores;

                do{
                    cout << endl << endl << "  Informe se ha algum computador com defeito ou chamado em aberto(S/N):";
                    salas[0].defeito = lerLetra();

                    if (salas[0].defeito == 'S' || salas[0].defeito == 's'){
                        cout << endl << "  Informe a quantidade de computadores com defeito ou chamado em aberto:";
                        salas[0].qntDefeito = lerNumero();
                        while(salas[0].qntDefeito < 0 || salas[0].qntDefeito > salas[0].computadores){
                            cout << "  Valor invalido! Informe de 0 a " << salas[0].computadores << ":";
                            salas[0].qntDefeito = lerNumero();
                        }
                        cout << endl << "  Computadores disponiveis: " << (salas[0].computadoresDisp - salas[0].qntDefeito) << endl;
                        break;
                    }

                    else if(salas[0].defeito == 'N' || salas[0].defeito == 'n'){
                        salas[0].qntDefeito = 0;
                        cout << endl << "  Computadores disponiveis: " << salas[0].computadoresDisp << endl;
                        break;
                    }

                    else{
                        cout << "  Opcao indisponivel! " << endl;
                        continue;
                    }
                }while(true);

            }
            else if(opc == 2){
                cout << endl << " Sala selecionada: " << salas[1].nomeSala << endl;
                cout << "  Computadores disponiveis: " << salas[1].computadoresDisp;

                do{
                    cout << endl << endl << "  Informe se ha algum computador com defeito ou chamado em aberto(S/N):";
                    salas[1].defeito = lerLetra();

                    if (salas[1].defeito == 'S' || salas[1].defeito == 's'){
                        cout << endl << "  Informe a quantidade de computadores com defeito ou chamado em aberto:";
                        salas[1].qntDefeito = lerNumero();
                        while(salas[1].qntDefeito < 0 || salas[1].qntDefeito > salas[1].computadores){
                            cout << "  Valor invalido! Informe de 0 a " << salas[1].computadores << ":";
                            salas[1].qntDefeito = lerNumero();
                        }
                        cout << endl << "  Computadores disponiveis: " << (salas[1].computadoresDisp - salas[1].qntDefeito) << endl;
                        break;
                    }

                    else if(salas[1].defeito == 'N' || salas[1].defeito == 'n'){
                        salas[1].qntDefeito = 0;
                        cout << endl << "  Computadores disponiveis: " << salas[1].computadoresDisp << endl;
                        break;
                    }

                    else{
                        cout << "  Opcao indisponivel! " << endl;
                        continue;
                    }
                }while(true);

            }
            else if(opc == 3){
                cout << endl << " Sala selecionada: " << salas[2].nomeSala << endl;
                cout << "  Computadores disponiveis: " << salas[2].computadoresDisp;

                do{
                    cout << endl << endl << "  Informe se ha algum computador com defeito ou chamado em aberto(S/N):";
                    salas[2].defeito = lerLetra();

                    if (salas[2].defeito == 'S' || salas[2].defeito == 's'){
                        cout << endl << "  Informe a quantidade de computadores com defeito ou chamado em aberto:";
                        salas[2].qntDefeito = lerNumero();
                        while(salas[2].qntDefeito < 0 || salas[2].qntDefeito > salas[2].computadores){
                            cout << "  Valor invalido! Informe de 0 a " << salas[2].computadores << ":";
                            salas[2].qntDefeito = lerNumero();
                        }
                        cout << endl << "  Computadores disponiveis: " << (salas[2].computadoresDisp - salas[2].qntDefeito) << endl;
                        break;
                    }

                    else if(salas[2].defeito == 'N' || salas[2].defeito == 'n'){
                        salas[2].qntDefeito = 0;
                        cout << endl << "  Computadores disponiveis: " << salas[2].computadoresDisp << endl;
                        break;
                    }

                    else{
                        cout << "  Opcao indisponivel! " << endl;
                        continue;
                    }
                }while(true);
            }

            else{
                cout << "Opcao Invalida! Tente novamente";
            }
            pausar();
            break;

        case 0:
            break;

        default:
            system("cls");
            cout << endl <<" Opcao indisponivel! Tente novamente" << endl;
            pausar();
            break;
        }
    }while(opcao != 0);

}
