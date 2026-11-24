#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct cpu {
    char fabricante [15];
    char modelo [15];
    float valor;
};

struct placa {
    char fabricante [15];
    char modelo [15];
    int capacidade;
    };



// Função que preenche as CPUS

void preencherVetor(cpu vet[], int n){
    strcpy(vet[0].fabricante, "AMD");
    strcpy(vet[0].modelo, "Ryzen 5");
    vet[0].valor = 800.00;

    strcpy(vet[1].fabricante, "AMD");
    strcpy(vet[1].modelo, "Ryzen 3");
    vet[1].valor = 500.00;

    strcpy(vet[2].fabricante, "Intel");
    strcpy(vet[2].modelo, "Core i5");
    vet[2].valor = 700.00;
}

// Função que preenche as placas
void fill_placas (placa vet[], int n) {
    strcpy(vet[0].fabricante, "NVIDIA");
    strcpy(vet[0].modelo, "RTX 3060");
    vet[0].capacidade = 12;

    strcpy(vet[1].fabricante, "AMD");
    strcpy(vet[1].modelo, "RX 6600");
    vet[1].capacidade = 8;

    strcpy(vet[2].fabricante, "NVIDIA");
    strcpy(vet[2].modelo, "RTX 4060");
    vet[2].capacidade = 8;

    strcpy(vet[3].fabricante, "AMD");
    strcpy(vet[3].modelo, "RX 7600");
    vet[3].capacidade = 8;

}
// Função para salvar as CPUs e Placas

void salvar(cpu vetCPU[], int nCPU, placa vetPlacas[], int nPlacas){

    fstream meuArquivo;
    meuArquivo.open("dados.bin", ios::out | ios::binary);
    if(meuArquivo.is_open()){
        meuArquivo.write((char *) vetCPU, sizeof(cpu) * nCPU);
        meuArquivo.write((char *) vetPlacas, sizeof(cpu) * nPlacas);
        meuArquivo.close();

        cout << "Dados salvos com sucesso!\n";
    }

    else {
        cout << "Nao foi possivel salvar.\n";
    }
}

// Função que carrega as CPUS e Placas
void carregar(cpu vetCPU[], int nCPU, placa vetPlacas[], int nPlacas){

    fstream meuArquivo;
    meuArquivo.open("dados.bin", ios::in | ios::binary);
    if(meuArquivo.is_open()){
        meuArquivo.read((char *) vetCPU, sizeof(cpu) * nCPU);
        meuArquivo.read((char *) vetPlacas, sizeof(cpu) * nPlacas);
        meuArquivo.close();

        cout << "Dados carregados com sucesso!\n";
    }

    else {
        cout << "Nao foi possivel carregar informacoes.\n";
    }
}
// Função para mostrar as CPUs

void mostrarVetor(cpu vet[], int n) {
    cout << "Informacoes das CPUs:\n";
    for(int i=0; i<n; i++){
        cout << "\nFabricante: " << vet[i].fabricante << endl;
        cout << "Modelo: " << vet[i].modelo << endl;
        cout << "Valor: " << vet[i].valor << endl;
    }
}

// Função para mostrar as placas
void mostrarPlacas(placa vet[], int n) {

    cout << "Informacoes das Placas de Video:\n";
    for(int i=0; i<n; i++){
        cout << "\nPlaca de video " << i +1 <<endl;
        cout << "Fabricante: " << vet[i].fabricante << endl;
        cout << "Modelo: " << vet[i].modelo << endl;
        cout << "Valor: " << vet[i].capacidade << " GB" << endl;
    }
}

// Função do MENU

void mostrarMenu() {
    cout <<"################################ MENU ####################################\n";
    cout << "1 - Preencher informacoes das CPUs.                                      #\n";
    cout << "2 - Exibir informacoes das CPUs.                                         #\n";
    cout << "3 - Preencher informacoes das Placas de Video.                           #\n";
    cout << "4 - Exibir informacoes das Placas de Video.                              #\n";
    cout << "5 - Salvar informacoes.                                                  #\n";
    cout << "6 - Carregar informacoes.                                                #\n";
    cout << "7 - Sair.                                                                #\n";
    cout <<"##########################################################################\n";
    cout << "Digite sua opcao: ";
}


int main(){

cpu listaCPUs[3] = {};
placa listaPlacas[4] = {};
int opcao;

while(true){
    mostrarMenu();
    cin >> opcao;

    switch(opcao){
    case 1:
       preencherVetor(listaCPUs, 3);
       cout << "CPUs preenchidas com sucesso!\n";
       cout <<"--------------------------------------------------------------------------\n";
       break;

    case 2:
        mostrarVetor(listaCPUs, 3);
        cout <<"--------------------------------------------------------------------------\n";
        break;

    case 3:
        fill_placas(listaPlacas, 4);
        cout << "Placas de Video preenchidas com sucesso!\n";
        cout <<"--------------------------------------------------------------------------\n";
        break;

    case 4:
        mostrarPlacas(listaPlacas, 4);
        cout <<"--------------------------------------------------------------------------\n";
        break;
    case 5:

        salvar(listaCPUs, 3, listaPlacas, 4);
        cout <<"--------------------------------------------------------------------------\n";
        break;
    case 6:

        carregar(listaCPUs, 3, listaPlacas, 4);
        cout <<"--------------------------------------------------------------------------\n";
        break;
    case 7:

        cout << "Programa encerrado.\n";
        cout <<"--------------------------------------------------------------------------\n";
        break;

    default:
        cout << "Opcao invalida! :/\n";
        cout <<"--------------------------------------------------------------------------\n";
        break;

    }
}

return 0;
}
