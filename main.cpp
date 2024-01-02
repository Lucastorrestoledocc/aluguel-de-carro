#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cctype> // Para isalpha()
#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include <locale>
#include <chrono>
#include <map>
struct Veiculo
{
    std::string name;
    bool status;
    double diaria;
};


struct Cliente
{
  std::string nome;
  int idade;
  std::string cpf;
  std::string nomeCarro;
  int numeroCarro;
  std::string codigo;
};

std::map<std::string, Veiculo> veiculosDisponiveis;

void mostrarInformacoesCliente(const Cliente& cliente) {
    std::cout << "Informações do Cliente (Código: " << cliente.codigo << "):\n";
    std::cout << "Nome: " << cliente.nome << "\n";
    std::cout << "Idade: " << cliente.idade << "\n";
    std::cout << "CPF: " << cliente.cpf << "\n";
    std::cout << "Carro: " << cliente.nomeCarro << "\n";




    // Adicione mais informações conforme necessário
}

void inicializarVeiculos()
{
    Veiculo esportivo1{ "Porsche 911", true, 180.0 };
    Veiculo esportivo2{ "Ferrari 488 GTB", true, 200.0 };
    Veiculo esportivo3{ "Chevrolet Corvette", true, 150.0 };
    Veiculo esportivo4{ "Audi R8", true, 170.0 };
    Veiculo casual1{ "Honda Civic", true, 100.0 };
    Veiculo casual2{ "Toyota Corolla", true, 110.0 };
    Veiculo casual3{ "Volkswagen Golf", true, 120.0 };
    Veiculo casual4{ "Ford Focus", true, 105.0 };
    Veiculo aventura1{ "Jeep Wrangler", true, 130.0 };
    Veiculo aventura2{ "Toyota Land Cruiser", true, 140.0 };
    Veiculo aventura3{ "Land Rover Defender", true, 135.0 };
    Veiculo aplicativo1{ "Toyota Prius", true, 95.0 };
    Veiculo aplicativo2{ "Hyundai HB20", true, 90.0 };
    Veiculo aplicativo3{ "Chevrolet Onix", true, 85.0 };
    Veiculo aplicativo4{ "Nissan Versa", true, 88.0 };

    veiculosDisponiveis["P9"] = esportivo1;
    veiculosDisponiveis["F4"] = esportivo2;
    veiculosDisponiveis["CC"] = esportivo3;
    veiculosDisponiveis["A8"] = esportivo4;
    veiculosDisponiveis["HC"] = casual1;
    veiculosDisponiveis["TC"] = casual2;
    veiculosDisponiveis["VG"] = casual3;
    veiculosDisponiveis["FF"] = casual4;
    veiculosDisponiveis["JW"] = aventura1;
    veiculosDisponiveis["TLC"] = aventura2;
    veiculosDisponiveis["LRD"] = aventura3;
    veiculosDisponiveis["TP"] = aplicativo1;
    veiculosDisponiveis["HB"] = aplicativo2;
    veiculosDisponiveis["CO"] = aplicativo3;
    veiculosDisponiveis["NV"] = aplicativo4;
}


const Cliente* buscarClientePorCodigo(const std::vector<Cliente>& clientes, const std::string& codigo)
{
    for (auto& cliente : clientes)
    {
        if (cliente.codigo == codigo)
        {
            return &cliente; // Retorna o ponteiro para o cliente encontrado
        }
    }
    return nullptr; // Retorna nullptr se o cliente não for encontrado
}
void alugar_exibir() {
    bool entradaValida = false;

    while (!entradaValida) {
        std::cout << "Veículos disponíveis para aluguel:\n";
        for (const auto& veiculo : veiculosDisponiveis) {
            std::cout << veiculo.second.name << "\n";
        }
        std::cout << "\nDeseja alugar algum desses?\nSe sim, digite a PRIMEIRA letra ou número do carro.\nExemplo: TOYOTA PRIUS = TP\nobs: Tudo em maiúsculo\n";

        std::string entrada;
        std::cin >> entrada;

        if (veiculosDisponiveis.find(entrada) != veiculosDisponiveis.end()) {
            std::cout << "Você escolheu alugar um " << veiculosDisponiveis[entrada].name << ".\n";
            entradaValida = true;



            std::cout << "Digite a data de retirada (DD MM AAAA)(digite o dia e pressione enter, depois o mes e pressione enter, depois o ano e pressione enter)\n\n ";
            int diaRetirada, mesRetirada, anoRetirada;
            std::cin >> diaRetirada >> mesRetirada >> anoRetirada;

            std::cout << "Digite a data de devolução (DD MM AAAA)(digite o dia e pressione enter, depois o mes e pressione enter, depois o ano e pressione enter)\n\n: ";
            int diaDevolucao, mesDevolucao, anoDevolucao;
            std::cin >> diaDevolucao >> mesDevolucao >> anoDevolucao;

            // Obtendo o tempo em segundos desde a época (01/01/1970) para cada data
            std::tm tmRetirada = { 0, 0, 0, diaRetirada, mesRetirada - 1, anoRetirada - 1900 };
            std::tm tmDevolucao = { 0, 0, 0, diaDevolucao, mesDevolucao - 1, anoDevolucao - 1900 };

            std::time_t tempoRetirada = std::mktime(&tmRetirada);
            std::time_t tempoDevolucao = std::mktime(&tmDevolucao);


            int quantidadeDias = (tempoDevolucao - tempoRetirada) / (60 * 60 * 24);

            std::cout << "A quantidade de dias de aluguel: " << quantidadeDias << std::endl;


            double diariaPrius = 120.0;
            double valorTotalAluguel = quantidadeDias * diariaPrius;

            std::cout << "Valor total do aluguel: R$ " << valorTotalAluguel << std::endl;

        }
        else {
            std::cout << "Não foi possível encontrar um veículo para as iniciais inseridas. Tente novamente digitando em letras maiúsculas.\n";
        }
    }
}
std::string mostrarVeiculosAlugados(const std::vector<Cliente>& clientes, const std::string& codigoBusca) {
    std::string nomeCarroEmPosse;
    bool alugouVeiculo = false;

for (const Cliente& cliente : clientes) {
        if (cliente.codigo == codigoBusca && !cliente.nomeCarro.empty()) {
            // Adicione o nome do veículo alugado ao nomeCarroEmPosse (se for relevante)
            nomeCarroEmPosse += cliente.nomeCarro + "\n";
        }
    }

    // Retorna o nome do veículo alugado pelo cliente (ou uma string vazia se nenhum veículo for encontrado)
    return nomeCarroEmPosse;
}




bool validarCPF(const std::string& cpf)
{
    if (cpf.length() != 11)
    {
        return false;
    }

    for (char c : cpf)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}


bool validarNumeros(const std::string& texto)
{
    for (char c : texto)
    {
        if (!isdigit(c))
        {
            return false; // Se encontrar algum caractere que não seja um dígito, retorna falso
        }
    }
    return true; // Se todos os caracteres forem dígitos, retorna verdadeiro
}


bool validarNome(const std::string& nome)
{
    for (char c : nome)
    {
        if (!isalpha(c) && c != ' ')
        {
            return false; // Se encontrar algum caractere não-alfabético ou espaço, retorna falso
        }
    }
    return true; // Se todos os caracteres forem alfabéticos ou espaços, retorna verdadeiro
}


std::string gerarCodigo()
{
    const std::string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int tamanhoCodigo = 8;
    std::string codigoGerado = "";

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < tamanhoCodigo; ++i)
    {
        codigoGerado += caracteres[rand() % caracteres.length()];
    }

    return codigoGerado;
}

void cadastrarCliente(std::vector<Cliente>& clientes)
{

    std::string nome;
    int idade = 0;
    std::string cpf;
    std::string nomeCarro;
    int numeroCarro;
    bool nomeValido = false;
    bool cpfValido = false;
    bool idadeValida = false;

    while (!nomeValido)
    {
        std::cout << "\nSeu nome completo: ";
        std::cin.ignore();
        std::getline(std::cin, nome);

        if (validarNome(nome))
        {
            nomeValido = true;
        }
        else
        {
            std::cout << "Nome inválido! Use apenas letras e espaços.\n";
        }
    }

    while (!idadeValida)
    {
        std::cout << "Digite sua idade: ";
        std::cin >> idade;

        if (std::cin.fail() || idade <= 0 || idade > 120)
        {
            std::cout << "Idade inválida! Use apenas números e digite uma idade válida (entre 1 e 120 anos).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            idadeValida = true;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (!cpfValido)
    {
        std::cout << "Digite o CPF (apenas números): ";
        std::cin >> cpf;

        if (validarCPF(cpf))
        {
            std::cout << "CPF válido!\n";
            cpfValido = true;
        }
        else
        {
            std::cout << "CPF inválido! Tente novamente.\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string codigoGerado = gerarCodigo();

    Cliente novoCliente;
    novoCliente.nome = nome;
    novoCliente.idade = idade;
    novoCliente.cpf = cpf;
    novoCliente.codigo = codigoGerado;
    clientes.push_back(novoCliente);

    std::cout << "\nSeu código gerado: \n\n" << codigoGerado << std::endl;
    std::cout << "Aperte Qualquer tecla para voltar para o menu";
    std::cin.ignore(); // Limpar o buffer do teclado
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    std::vector<Cliente> clientes;
    int opcao;

    do {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1 - Cadastrar Cliente\n";
        std::cout << "2 - Buscar Cliente por código\n";
        std::cout << "3 - Alugar veículo\n";
        std::cout << "4 - Sair\n";
        std::cin >> opcao;

        switch (opcao) {
        case 1:
            cadastrarCliente(clientes);
            break;
        case 2: {
    std::string codigoBusca;
    std::cout << "Digite o código do cliente que deseja buscar: ";
    std::cin >> codigoBusca;

    const Cliente* clienteEncontrado = buscarClientePorCodigo(clientes, codigoBusca);

    if (clienteEncontrado != nullptr) {
        mostrarInformacoesCliente(*clienteEncontrado);

        // Chama a função mostrarVeiculosAlugados para obter o nome do carro alugado pelo cliente
        std::string nomeCarroAlugado = mostrarVeiculosAlugados(clientes, codigoBusca);

        // Imprime o nome do carro alugado pelo cliente
        if (!nomeCarroAlugado.empty()) {
            std::cout << "Veículo alugado pelo cliente:\n";
            std::cout << nomeCarroAlugado << std::endl; // Corrigido para imprimir 'nomeCarroAlugado'
        } else {
            std::cout << "Cliente não possui veículo alugado ou código não encontrado.\n";
        }
    } else {
        std::cout << "Cliente não encontrado.\n";
    }
    break;
}


        case 3: {
            std::string codigoBusca;
            std::cout << "Digite seu código de cliente: ";
            std::cin >> codigoBusca;

            const Cliente* clienteEncontrado = buscarClientePorCodigo(clientes, codigoBusca);

            if (clienteEncontrado != nullptr) {
                inicializarVeiculos();
                alugar_exibir();
            }
            else {
                std::cout << "Cliente com o código " << codigoBusca << " não encontrado.\n";
            }
            break;
        }
        case 4:
            std::cout << "Saindo do programa...\n";
            break;
        default:
            std::cout << "Opção inválida. Tente novamente.\n";
            break;
        }
    } while (opcao != 4);

    return 0;
}

