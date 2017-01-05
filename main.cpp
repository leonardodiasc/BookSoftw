#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <deque>
#include <sstream>

using namespace std;

float toFloat(string s) {
  float r = 0;
  istringstream ss(s);
  ss >> r;
  return r;
}


class Data{
public:
	Data(int dia, int mes, int ano) : dia_{dia}, mes_{mes}, ano_{ano} {}
	Data(Data const& d) : dia_{d.dia_}, mes_{d.mes_}, ano_{d.ano_} {}
	Data() = default;

	void leiaData() {
		cout << " Dia: ";
		cin >> dia_;
		cout << " Mes: ";
		cin >> mes_;
		cout << " Ano: ";
		cin >> ano_;
	}
	void mostreData() { cout << dia_ << "/" << mes_ << "/" << ano_ << endl; }

	string obterData() 
	{
		ostringstream os_data; 
		string data;
		if(dia_ < 10)
		{
			if(mes_ < 10)
			{
				os_data << "0" << dia_ << "/0" << mes_ << "/" << ano_;
				data = os_data.str();
				return data;
			}
			else
			{
				os_data << "0" << dia_ << "/" << mes_ << "/" << ano_;
				data = os_data.str();
				return data;
			}
			
		}
		else if(mes_ < 10)
		{
			os_data << dia_ << "/0" << mes_ << "/" << ano_;
			data = os_data.str();
			return data;
		}
		else
		{
			os_data << dia_ << "/" << mes_ << "/" << ano_;
			data = os_data.str();
			return data;
		}
		
	}

private:
	int dia_;
	int mes_;
	int ano_;
};

class CPF{
public:
	CPF(string cpf) : cpf_{cpf} {}
	CPF(CPF const& c) : cpf_{c.cpf_} {}
	CPF() = default;

	void leiaCPF() {
		cout << " Informe CPF: ";
		cin >> cpf_;
	}
	void mostreCPF() { cout << " CPF: " << cpf_ << endl; }

	string const& obterCPF() const {
		return cpf_;
	}
private:
	string cpf_;
};

class CNPJ{
public:
	CNPJ(string cnpj) : cnpj_{cnpj} {}
	CNPJ(CNPJ const& c) : cnpj_{c.cnpj_} {}
	CNPJ() = default;

	void leiaCNPJ() {
		cout << " Informe CNPJ: ";
		cin >> cnpj_;
	}
	void mostreCNPJ() { cout << " CNPJ: " << cnpj_ << endl; }

	string const& obterCNPJ() const {
		return cnpj_;
	}
private:
	string cnpj_;
};

bool operator==(CPF const& cpf1, CPF const& cpf2){
	return cpf1.obterCPF() == cpf2.obterCPF();
}

bool operator==(CNPJ const& cnpj1, CNPJ const& cnpj2){
	return cnpj1.obterCNPJ() == cnpj2.obterCNPJ();
}

class RG{
public:
	RG(string rg) : rg_{rg} {}
	RG(RG const& r) : rg_{r.rg_} {}
	RG() = default;

	void leiaRG(){
		cout << " Informe RG: ";
		cin >> rg_;
	}

	void mostreRG() { cout << " RG: " << rg_ << endl; }

	string obterRG() {return rg_; }
private:
	string rg_;
};

class Telefone{
public:
	Telefone(string tel) : tel_{tel} {}
	Telefone(Telefone const& t) : tel_{t.tel_} {}
	Telefone() = default;

	void leiaTelefone(){
		cout << " Informe Telefone: ";
		getline(cin,tel_);;
	}

	void mostreTelefone() { cout << " Telefone: " << tel_ << endl; }

	string obterTelefone() {return tel_; }
private:
	string tel_;
};

class Endereco{
public:
	Endereco(string numero, string rua, string bairro, string cep) : numero_{numero}, rua_{rua}, bairro_{bairro}, cep_{cep} {}
	Endereco(Endereco const& e) : numero_{e.numero_}, rua_{e.rua_}, bairro_{e.bairro_}, cep_{e.cep_} {}
	Endereco() = default;

	void leiaEndereco() {
		cout << " Número: ";
		getline(cin,numero_);
		cout << " Logradouro: ";
		getline(cin,rua_);
		cout << " Bairro: ";
		getline(cin,bairro_);
		cout << " CEP: ";
		getline(cin,cep_);
	}
	void mostreEndereco() { cout << rua_ << " , Nº " << numero_ << "\n Bairro:  " << bairro_  << ", " << cep_ << endl; }

	string obterRua() { return rua_; }
	string obterNumero() {return numero_; }
	string obterBairro() {return bairro_; }
	string obterCEP() {return cep_;}
private:
	string numero_;
	string rua_;
	string bairro_;
	string cep_;
};


class Pessoa{
public:
	Pessoa(string nome, Endereco endereco, Telefone telefone)
	: nome_{nome}, endereco_{endereco}, telefone_{telefone} {}
	Pessoa(Pessoa const& p)
	: nome_{p.nome_}, endereco_{p.endereco_}, telefone_{p.telefone_} {}
	Pessoa() = default;

	void leiaPessoa(){
		cout << "Nome: ";
		getline(cin, nome_);
		cout << " Informe o endereco: \n";
		endereco_.leiaEndereco();
		cout << " Informe o telefone: \n";
		telefone_.leiaTelefone();
	}

	void mostrePessoa(){
		cout << " Nome: " << nome_ << "\n Endereco: ";
		endereco_.mostreEndereco();
		telefone_.mostreTelefone();
	}

	string obterPessoaNome() {return nome_;}
	Endereco obterPessoaEndereco() { return endereco_;}
	Telefone obterPessoaTelefone() {return telefone_;}

private:
	string nome_;
	Endereco endereco_;
	Telefone telefone_;
};

class Produto
{
public:
	Produto(string produto_nome, int quantidade, float preco) :
	produto_nome_{produto_nome} , quantidade_{quantidade}, preco_{preco} {}
	Produto(Produto const& produto)
	: produto_nome_{produto.produto_nome_}, preco_{produto.preco_}, quantidade_{produto.quantidade_} {}
	Produto() = default;

	void leiaProduto(){
		cout << " Nome: ";
		getline(cin,produto_nome_);
		cout << " Quantidade: ";
		cin >> quantidade_;
		cout << " Preco: ";
		cin >> preco_;
	}

	void mostreProduto(){
		cout << " Nome: " << produto_nome_ << endl;
		cout << " Quantidade: " << quantidade_ << endl;
		cout << " Preco: R$ " << fixed << setprecision(2) << preco_ << endl;
	}

	string obterProdutoNome() {return produto_nome_;}
	float obterPreco() {return preco_;}
	int obterQuantidade() {return quantidade_;}

private:
	string produto_nome_;
	float preco_;
	int quantidade_;
};

class Livro : public Produto
{
public:
	Livro(Produto produto, string editora, string volume, string livro_genero ) :
	Produto{produto}, editora_{editora}, volume_{volume} , livro_genero_{livro_genero} {}
	Livro() : Produto{}, editora_{}, volume_{}, livro_genero_{} {}

	void leiaLivro(){
		Produto::leiaProduto();
		cout << " Genero: ";
		getline(cin, livro_genero_);
		cout << " Volume: ";
		getline(cin, volume_);
		cout << " Editora: ";
		getline(cin, editora_);
	}

	void mostreLivro(){
		Produto::mostreProduto();
		cout << " Genero: " << livro_genero_ << endl;
		cout << " Volume: " << volume_ << endl;
		cout << " Editora: " << editora_ << endl;
	}

	string obterLivroEditora() {return editora_;}
	string obterLivroVolume() {return volume_;}
	string obterLivroGenero() {return livro_genero_;}

private:
	string editora_, volume_, livro_genero_;
};

class Revista : public Produto
{
public:
	Revista(Produto produto, string edicao, string publicador, string revista_genero ) :
	Produto{produto}, edicao_{edicao}, publicador_{publicador}, revista_genero_{revista_genero} {}
	Revista() : Produto{}, edicao_{}, publicador_{}, revista_genero_{} {}

	void leiaRevista(){
		Produto::leiaProduto();
		cout << " Genero: ";
		getline(cin, revista_genero_);
		cout << " Edicao: ";
		getline(cin, edicao_);
		cout << " Publicador: ";
		getline(cin, publicador_);
	}

	void mostreRevista(){
		Produto::mostreProduto();
		cout << " Genero: " << revista_genero_ << endl;
		cout << " Edicao: " << edicao_ << endl;
		cout << " Publicador: " << publicador_ << endl;
	}

	string obterRevistaEdicao() {return edicao_;}
	string obterRevistaPublicador() {return publicador_;}
	string obterRevistaGenero() {return revista_genero_;}

private:
	string edicao_, publicador_, revista_genero_;
};

class Cliente : public Pessoa{
public:
	Cliente(Pessoa pessoa ) : Pessoa{pessoa} {}
	Cliente() : Pessoa{} {}

	void leiaCliente()
	{
		Pessoa::leiaPessoa();
	}

	void mostreCliente()
	{
		Pessoa::mostrePessoa();
	}

private:
};

class Cliente_fisico : public Cliente
{	
public:
	Cliente_fisico(Cliente cliente, CPF cpf, RG rg) :
	Cliente{cliente}, cpf_{cpf}, rg_{rg} {}
	Cliente_fisico() : Cliente{}, cpf_{}, rg_{} {}

	void leiaCliente_F(){
		cin.ignore();
		Cliente::leiaCliente();
		cout << " CPF: " << endl;
		cpf_.leiaCPF();
		cout << " RG: " << endl;
		rg_.leiaRG();
	}

	void mostreCliente_F(){
		Cliente::mostreCliente();
		cpf_.mostreCPF();
		rg_.mostreRG();
	}

	CPF const& obterCPF() const{
		return cpf_;
	}
	RG obterClienteFRG() { return rg_;}
private:
	CPF cpf_;
	RG rg_;
};

class Cliente_juridico : public Cliente
{	
public:
	Cliente_juridico(Cliente cliente, CNPJ cnpj, string razaosocial) :
	Cliente{cliente}, cnpj_{cnpj}, razaosocial_{razaosocial} {}
	Cliente_juridico() : Cliente{}, cnpj_{}, razaosocial_{} {}

	void leiaCliente_J(){
		cin.ignore();
		Cliente::leiaCliente();
		cout << " CNPJ: " << endl;
		cnpj_.leiaCNPJ();
		cout << " Razao Social: " << endl;
		cin >> razaosocial_;
	}

	void mostreCliente_J(){
		Cliente::mostreCliente();
		cnpj_.mostreCNPJ();
		cout << " Razao Social: " << razaosocial_ << endl;
	}

	CNPJ const& obterCNPJ() const{
		return cnpj_;
	}
	string obterRazaoSocial() { return razaosocial_;}
private:
	CNPJ cnpj_;
	string razaosocial_;
};

class Funcionario : public Pessoa{
public:
	Funcionario(Pessoa pessoa, CPF cpf, RG rg, Data dataContratacao, float salario) :
	Pessoa{pessoa}, cpf_{cpf}, rg_{rg} ,dataContratacao_{dataContratacao}, salario_{salario} {}
	Funcionario() : Pessoa{}, cpf_{}, rg_{}, dataContratacao_{}, salario_{0.0} {}

	void leiaFuncionario(){
		Pessoa::leiaPessoa();
		cout << " CPF: " << endl;
		cpf_.leiaCPF();
		cout << " RG: " << endl;
		rg_.leiaRG();
		cout << " Data de Contratacao: " << endl;
		dataContratacao_.leiaData();
		cout << " Salario: ";
		cin >> salario_;
	}

	void mostreFuncionario(){
		Pessoa::mostrePessoa();
		cpf_.mostreCPF();
		rg_.mostreRG();
		cout << " Data de Contratacao: ";
		dataContratacao_.mostreData();
		cout << " Salario: R$ " << fixed << setprecision(2) << salario_ << endl;
	}

	float const obterSalario() const {
		return salario_;
	}

	CPF const& obterCPF() const{
		return cpf_;
	}
	RG obterRG() {return rg_;}
	Data obterData() { return dataContratacao_;}
private:
	CPF cpf_;
	RG rg_;
	Data dataContratacao_;
	float salario_;
};

class Gerente : public Funcionario
{
public:
	Gerente(Funcionario funcionario) : Funcionario{funcionario} {}
	Gerente() : Funcionario{} {}

	void leiaGerente(){
		Funcionario::leiaFuncionario();
	}

	void mostreGerente(){
		Funcionario::mostreFuncionario();
	}

	void inicializarProdutos()
	{
		string nome, str_quantidade, str_preco, revista_genero, livro_editora, livro_volume, livro_genero, revista_edicao ,revista_publicadora;
		string blank_line;
		int quantidade;
		float preco;
		ifstream arquivoLivros, arquivoRevistas, arquivoDiversos;
		arquivoLivros.open("produtos_livros.txt");
		arquivoRevistas.open("produtos_revistas.txt");
		arquivoDiversos.open("produtos_diversos.txt");
		while(!arquivoLivros.eof())
		{
			getline(arquivoLivros, nome);
			getline(arquivoLivros, str_quantidade);
			getline(arquivoLivros, str_preco);
			getline(arquivoLivros, livro_genero);
			getline(arquivoLivros, livro_volume);
			getline(arquivoLivros, livro_editora);
			getline(arquivoLivros, blank_line);
			
			size_t pos_nome = nome.find(": ");
        	size_t pos_quantidade = str_quantidade.find(": ");
        	size_t pos_preco = str_preco.find(": ");
        	size_t pos_genero = livro_genero.find(": ");
        	size_t pos_volume= livro_volume.find(": ");
        	size_t pos_editora = livro_editora.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);
        	str_preco = str_preco.substr(pos_preco + 4);
        	livro_genero = livro_genero.substr(pos_genero + 2);
        	livro_volume = livro_volume.substr(pos_volume + 2);
        	livro_editora = livro_editora.substr(pos_editora + 2);

        	quantidade = stoi(str_quantidade);
        	preco = toFloat(str_preco);

        	Produto p(nome,quantidade,preco);
        	Livro l(p,livro_editora,livro_volume,livro_genero);
        	stockLivros_.push_back(l);
		}

		while(!arquivoRevistas.eof())
		{
			getline(arquivoRevistas, nome);
			getline(arquivoRevistas, str_quantidade);
			getline(arquivoRevistas, str_preco);
			getline(arquivoRevistas, revista_genero);
			getline(arquivoRevistas, revista_edicao);
			getline(arquivoRevistas, revista_publicadora);
			getline(arquivoRevistas, blank_line);

			size_t pos_nome = nome.find(": ");
        	size_t pos_quantidade = str_quantidade.find(": ");
        	size_t pos_preco = str_preco.find(": ");
        	size_t pos_genero = revista_genero.find(": ");
        	size_t pos_edicao= revista_edicao.find(": ");
        	size_t pos_publicadora = revista_publicadora.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);
        	str_preco = str_preco.substr(pos_preco + 2);
        	revista_genero = revista_genero.substr(pos_genero + 2);
        	revista_edicao = revista_edicao.substr(pos_edicao + 2);
        	revista_publicadora = revista_publicadora.substr(pos_publicadora + 2);

        	quantidade = stoi(str_quantidade);
        	preco = toFloat(str_preco);

        	Produto p(nome,quantidade,preco);
        	Revista r(p,revista_edicao,revista_publicadora,revista_genero);
        	stockRevistas_.push_back(r);

		}

		while(!arquivoDiversos.eof())
		{
			getline(arquivoDiversos, nome);
			getline(arquivoDiversos, str_quantidade);
			getline(arquivoDiversos, str_preco);
			getline(arquivoDiversos, blank_line);

			size_t pos_nome = nome.find(": ");
        	size_t pos_quantidade = str_quantidade.find(": ");
        	size_t pos_preco = str_preco.find(": ");
   			
        	nome = nome.substr(pos_nome + 2);
        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);
        	str_preco = str_preco.substr(pos_preco + 4);

        	quantidade = stoi(str_quantidade);
        	preco = toFloat(str_preco);

        	Produto p(nome,quantidade,preco);
        	stockProdutos_.push_back(p);

		}

		arquivoLivros.close();
		arquivoRevistas.close();
		arquivoDiversos.close();
	}

	void inicializarFuncionarios()
	{
		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cpf, rg, data, salario;
		string blank_line;
		ifstream arquivoFuncionarios;
		arquivoFuncionarios.open("funcionarios.txt");
		while(!arquivoFuncionarios.eof())
		{
			getline(arquivoFuncionarios, nome);
			getline(arquivoFuncionarios, e_rua);
			getline(arquivoFuncionarios, e_num);
			getline(arquivoFuncionarios, e_bairro);
			getline(arquivoFuncionarios, e_cep);
			getline(arquivoFuncionarios, telefone);
			getline(arquivoFuncionarios, cpf);
			getline(arquivoFuncionarios, rg);
			getline(arquivoFuncionarios, data);
			getline(arquivoFuncionarios, salario);
			getline(arquivoFuncionarios, blank_line);

			size_t pos_nome = nome.find(": ");
        	size_t pos_rua = e_rua.find(": ");
        	size_t pos_num = e_num.find(": ");
        	size_t pos_bairro = e_bairro.find(": ");
        	size_t pos_cep = e_cep.find(": ");
        	size_t pos_tel = telefone.find(": ");
        	size_t pos_cpf = cpf.find(": ");
        	size_t pos_rg = rg.find(": ");
        	size_t pos_data = data.find(": ");
        	size_t pos_salario = salario.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	e_rua = e_rua.substr(pos_rua + 2);
        	e_num = e_num.substr(pos_num + 2);
        	e_bairro = e_bairro.substr(pos_bairro + 2);
        	e_cep = e_cep.substr(pos_cep + 2);
        	telefone = telefone.substr(pos_tel + 2);
        	cpf = cpf.substr(pos_cpf + 2);
        	rg = rg.substr(pos_rg + 2);
        	data = data.substr(pos_data + 2);
        	salario = salario.substr(pos_salario + 4);


        	string str_dia, str_mes, str_ano;

        	str_dia = data.substr(0,2);
        	str_mes = data.substr(3,2);
        	str_ano = data.substr(6,4);

        	int dia, mes, ano;

        	dia = stoi(str_dia);
        	mes = stoi(str_mes);
        	ano = stoi(str_ano);

        	float salario_f = toFloat(salario);

        	Endereco e_f(e_num, e_rua, e_bairro, e_cep);
        	CPF cpf_f(cpf);
        	RG rg_f(rg);
        	Data data_f(dia,mes,ano);
        	Telefone tel_f(telefone);

        	Pessoa p(nome,e_f,tel_f);
        	Funcionario f_p(p,cpf_f,rg_f,data_f,salario_f);

        	cadastroFuncionario_.push_back(f_p);


		}

		arquivoFuncionarios.close();
	}

	void inicializarClientesF()
	{
		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cpf, rg;
		string blank_line;
		ifstream arquivoClientesF;
		arquivoClientesF.open("clientes_fisicos.txt");
		while(!arquivoClientesF.eof())
		{
			getline(arquivoClientesF, nome);
			getline(arquivoClientesF, e_rua);
			getline(arquivoClientesF, e_num);
			getline(arquivoClientesF, e_bairro);
			getline(arquivoClientesF, e_cep);
			getline(arquivoClientesF, telefone);
			getline(arquivoClientesF, cpf);
			getline(arquivoClientesF, rg);
			getline(arquivoClientesF, blank_line);

			size_t pos_nome = nome.find(": ");
        	size_t pos_rua = e_rua.find(": ");
        	size_t pos_num = e_num.find(": ");
        	size_t pos_bairro = e_bairro.find(": ");
        	size_t pos_cep = e_cep.find(": ");
        	size_t pos_tel = telefone.find(": ");
        	size_t pos_cpf = cpf.find(": ");
        	size_t pos_rg = rg.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	e_rua = e_rua.substr(pos_rua + 2);
        	e_num = e_num.substr(pos_num + 2);
        	e_bairro = e_bairro.substr(pos_bairro + 2);
        	e_cep = e_cep.substr(pos_cep + 2);
        	telefone = telefone.substr(pos_tel + 2);
        	cpf = cpf.substr(pos_cpf + 2);
        	rg = rg.substr(pos_rg + 2);

        	CPF cpf_p(cpf);
        	RG rg_p(rg);
        	Endereco e_p(e_num, e_rua, e_bairro, e_cep);
        	Telefone tel_p(telefone);

        	Pessoa p(nome,e_p,tel_p);
        	Cliente c_p(p);
        	Cliente_fisico cf_p(c_p, cpf_p, rg_p);
        	cadastroClienteF_.push_back(cf_p);
		}

		arquivoClientesF.close();
	}

	void inicializarClientesJ()
	{
		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cnpj, razaosocial;
		string blank_line;
		ifstream arquivoClientesJ;
		arquivoClientesJ.open("clientes_juridicos.txt");
		while(!arquivoClientesJ.eof())
		{
			getline(arquivoClientesJ, nome);
			getline(arquivoClientesJ, e_rua);
			getline(arquivoClientesJ, e_num);
			getline(arquivoClientesJ, e_bairro);
			getline(arquivoClientesJ, e_cep);
			getline(arquivoClientesJ, telefone);
			getline(arquivoClientesJ, cnpj);
			getline(arquivoClientesJ, razaosocial);
			getline(arquivoClientesJ, blank_line);

			size_t pos_nome = nome.find(": ");
        	size_t pos_rua = e_rua.find(": ");
        	size_t pos_num = e_num.find(": ");
        	size_t pos_bairro = e_bairro.find(": ");
        	size_t pos_cep = e_cep.find(": ");
        	size_t pos_tel = telefone.find(": ");
        	size_t pos_cnpj = cnpj.find(": ");
        	size_t pos_razaosocial = razaosocial.find(": ");

        	nome = nome.substr(pos_nome + 2);
        	e_rua = e_rua.substr(pos_rua + 2);
        	e_num = e_num.substr(pos_num + 2);
        	e_bairro = e_bairro.substr(pos_bairro + 2);
        	e_cep = e_cep.substr(pos_cep + 2);
        	telefone = telefone.substr(pos_tel + 2);
        	cnpj = cnpj.substr(pos_cnpj + 2);
        	razaosocial = razaosocial.substr(pos_razaosocial + 2);

        	CNPJ cnpj_j(cnpj);
        	Endereco e_p(e_num, e_rua, e_bairro, e_cep);
        	Telefone tel_p(telefone);

        	Pessoa p(nome,e_p,tel_p);
        	Cliente c_p(p);
        	Cliente_juridico cj_p(c_p, cnpj_j, razaosocial);
        	cadastroClienteJ_.push_back(cj_p);
		}

		arquivoClientesJ.close();
	}

	void mostrarCadastroClientesF()
	{
		int size = cadastroClienteF_.size();
		for(int i = 0; i < size; i++)
		{
			
			cadastroClienteF_[i].mostreCliente_F();
			cout << endl;
		}
	}

	void mostrarCadastroClientesJ()
	{
		int size = cadastroClienteJ_.size();
		for(int i = 0; i < size; i++)
		{
			
			cadastroClienteJ_[i].mostreCliente_J();
			cout << endl;
		}
	}

	void mostrarCadastroProdutosDiversos()
	{
		int size = stockProdutos_.size();
		for(int i = 0; i < size; i++)
		{

			stockProdutos_[i].mostreProduto();
			cout << endl;
		}
	}

	void mostrarCadastroLivros()
	{
		int size = stockLivros_.size();
		for(int i = 0; i < size; i++)
		{

			stockLivros_[i].mostreLivro();
			cout << endl;
		}
	}

	void mostrarCadastroRevistas()
	{
		int size = stockRevistas_.size();
		for(int i = 0; i < size; i++)
		{

			stockRevistas_[i].mostreRevista();
			cout << endl;
		}
	}

	void mostrarCadastroFuncionarios()
	{
		int size = cadastroFuncionario_.size();
		for(int i = 0; i < size; i++)
		{

			cadastroFuncionario_[i].mostreFuncionario();
			cout << endl;
		}
	}
	void adicionarCliente()
	{
		cout << "Qual o tipo do cliente? 1 - Físico | 2 - Jurídico" << endl;
		int op;
		cin >> op;
		switch(op)
		{
			case 1:{adicionarClienteF();break;}
			case 2:{adicionarClienteJ();break;}
		}

		cout << endl;
	}
	void adicionarClienteF()
	{
		Cliente_fisico cf;
		cf.leiaCliente_F();
		cadastroClienteF_.push_back(cf);
	}
	void adicionarClienteJ()
	{
		Cliente_juridico cj;
		cj.leiaCliente_J();
		cadastroClienteJ_.push_back(cj);
	}
	void adicionarFuncionario() 
	{
		Funcionario f;
		f.leiaFuncionario();
		cadastroFuncionario_.push_back(f);
	}
	void adicionarProduto()
	{
		cout << "Qual o tipo de produto? 1 - Livro | 2 - Revista | 3 - Diverso " << endl;
		int op;
		cin >> op;
		switch(op)
		{
			case 1:{adicionarLivro(); break;}
			case 2:{adicionarRevista(); break;}
			case 3:{adicionarDiverso(); break;}
		}
		cout << endl;
	}

	void adicionarLivro()
	{
		Livro l;
		l.leiaLivro();
		stockProdutos_.push_back(l);
	}
	void adicionarRevista()
	{
		Revista r;
		r.leiaRevista();
		stockProdutos_.push_back(r);
	}
	void adicionarDiverso()
	{
		Produto p;
		p.leiaProduto();
		stockProdutos_.push_back(p);
	}

	int buscarClienteF(string str_cpf)
	{
		CPF key(str_cpf);
		int size = cadastroClienteF_.size();

		for(int i = 0; i < size; i++)
		{
			if(key == cadastroClienteF_[i].obterCPF())
			{
				return i;
			}
		}
		cout << "Cliente não encontrado! " << endl;
		return -1;
	}

	int buscarClienteJ(string str_cnpj)
	{
		CNPJ key(str_cnpj);
		int size = cadastroClienteJ_.size();

		for(int i = 0; i < size; i++)
		{
			if(key == cadastroClienteJ_[i].obterCNPJ())
			{
				return i;
			}
		}
		cout << "Cliente não encontrado! " << endl;
		return -1;
	}

	int buscarFuncionario(string str_cpf)
	{
		CPF key(str_cpf);
		int size = cadastroFuncionario_.size();

		for(int i = 0; i < size; i++)
		{
			if(key == cadastroFuncionario_[i].obterCPF())
			{
				return i;
			}
		}
		cout << "Cliente não encontrado! " << endl;
		return -1;
	}

	int buscarProdutoDiverso(string str_nome)
	{
		
		int size = stockProdutos_.size();

		for(int i = 0; i < size; i++)
		{
			if(str_nome == stockProdutos_[i].obterProdutoNome())
			{
				return i;
			}
		}
		cout << "Produto não encontrado! " << endl;
		return -1;
	}

	int buscarLivro(string str_nome)
	{
		
		int size = stockLivros_.size();

		for(int i = 0; i < size; i++)
		{
			if(str_nome == stockLivros_[i].obterProdutoNome())
			{
				return i;
			}
		}
		cout << "Produto não encontrado! " << endl;
		return -1;
	}

	int buscarRevista(string str_nome)
	{
		
		int size = stockRevistas_.size();

		for(int i = 0; i < size; i++)
		{
			if(str_nome == stockRevistas_[i].obterProdutoNome())
			{
				return i;
			}
		}
		cout << "Produto não encontrado! " << endl;
		return -1;
	}

	void removerProdutoDiverso()
	{
		string key;
		cout << " Digite o nome do produto que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarProdutoDiverso(key);

		if(indice == -1)
		{
			cout << "Produto não existe! " << endl;
		}
		else
		{
			stockProdutos_.erase(stockProdutos_.begin() + indice);
		}
	}

	void removerLivro()
	{
		string key;
		cout << " Digite o nome do produto que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarLivro(key);

		if(indice == -1)
		{
			cout << "Produto não existe! " << endl;
		}
		else
		{
			stockLivros_.erase(stockLivros_.begin() + indice);
		}
	}

	void removerRevista()
	{
		string key;
		cout << " Digite o nome do produto que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarRevista(key);

		if(indice == -1)
		{
			cout << "Produto não existe! " << endl;
		}
		else
		{
			stockRevistas_.erase(stockRevistas_.begin() + indice);
		}
	}

	void removerProduto()
	{
		int op;
		cout << "Qual tipo de produto deseja remover? 1 - Livro | 2 - Revista | 3 - Produto Diverso" << endl;
		cin >> op;
		switch(op)
		{
			case 1: {removerLivro();break;}
			case 2: {removerRevista();break;}
			case 3: {removerProdutoDiverso();break;}
		}
		cout << endl;
		
	}


	void removerFuncionario()
	{
		string key;
		cout << " Digite o cpf do funcionario que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		
		int indice = buscarFuncionario(key);

		if(indice == -1)
		{
			cout << "Funcionario não existe! " << endl;
		}
		else
		{
			cadastroFuncionario_.erase(cadastroFuncionario_.begin() + indice);
			cout << "Funcionario removido com sucesso!" << endl;
			cout << endl;
		}
	}
	void removerClienteF()
	{
		string key;
		cout << " Digite o cpf do cliente que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarClienteF(key);

		if(indice == -1)
		{
			cout << "Cliente não existe! " << endl;
		}
		else
		{
			cadastroClienteF_.erase(cadastroClienteF_.begin() + indice);
		}
	}

	void removerClienteJ()
	{
		string key;
		cout << " Digite o cnpj do cliente que deseja remover: ";
		getline(cin, key);
		cin.ignore();
		int indice = buscarClienteJ(key);

		if(indice == -1)
		{
			cout << "Cliente não existe! " << endl;
		}
		else
		{
			cadastroClienteJ_.erase(cadastroClienteJ_.begin() + indice);
		}
	}

	void removerCliente()
	{
		cout << "Qual o tipo do cliente? 1 - Físico | 2 - Jurídico" << endl;
		int op;
		cin >> op;
		switch(op)
		{
			case 1:{removerClienteF();break;}
			case 2:{removerClienteJ();break;}
		}

		cout << endl;
	}

	void salvarClientesF()
	{
		ofstream clientesf;
		clientesf.open("clientes_fisicos2.txt");
		int size = cadastroClienteF_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_nome,os_rua,os_numero,os_bairro,os_cep,os_telefone,os_cpf,os_rg;
			os_nome << "Nome: " << cadastroClienteF_[i].obterPessoaNome();
			os_rua << "Rua: " << cadastroClienteF_[i].obterPessoaEndereco().obterRua();
			os_numero << "Número: " << cadastroClienteF_[i].obterPessoaEndereco().obterNumero();
			os_bairro << "Bairro: " << cadastroClienteF_[i].obterPessoaEndereco().obterBairro();
			os_cep << "CEP: " << cadastroClienteF_[i].obterPessoaEndereco().obterCEP();
			os_telefone << "Telefone: " << cadastroClienteF_[i].obterPessoaTelefone().obterTelefone();
			os_cpf << "CPF: " << cadastroClienteF_[i].obterCPF().obterCPF();
			os_rg << "RG: " << cadastroClienteF_[i].obterClienteFRG().obterRG();

			string nome, rua, numero, bairro, cep, telefone, cpf, rg;
			string blank_line = "";
			nome = os_nome.str();
			rua = os_rua.str();
			numero = os_numero.str();
			bairro = os_bairro.str();
			cep = os_cep.str();
			telefone = os_telefone.str();
			cpf = os_cpf.str();
			rg = os_rg.str();

			

			clientesf << nome << endl;
			clientesf << rua << endl;
			clientesf << numero << endl;
			clientesf << bairro << endl;
			clientesf << cep << endl;
			clientesf << telefone << endl;
			clientesf << cpf << endl;
			clientesf << rg << endl;
			clientesf << blank_line << endl; 
			
		}
		clientesf.close();
	}

	void salvarClientesJ()
	{
		ofstream clientesj;
		clientesj.open("clientes_juridicos.txt");
		int size = cadastroClienteJ_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_nome,os_rua,os_numero,os_bairro,os_cep,os_telefone,os_cnpj,os_razaosocial;
			os_nome << "Nome: " << cadastroClienteJ_[i].obterPessoaNome();
			os_rua << "Rua: " << cadastroClienteJ_[i].obterPessoaEndereco().obterRua();
			os_numero << "Número: " << cadastroClienteJ_[i].obterPessoaEndereco().obterNumero();
			os_bairro << "Bairro: " << cadastroClienteJ_[i].obterPessoaEndereco().obterBairro();
			os_cep << "CEP: " << cadastroClienteJ_[i].obterPessoaEndereco().obterCEP();
			os_telefone << "Telefone: " << cadastroClienteJ_[i].obterPessoaTelefone().obterTelefone();
			os_cnpj << "CNPJ: " << cadastroClienteJ_[i].obterCNPJ().obterCNPJ();
			os_razaosocial << "Razão Social: " << cadastroClienteJ_[i].obterRazaoSocial();

			string nome, rua, numero, bairro, cep, telefone, cnpj, razaosocial;
			string blank_line = "";
			nome = os_nome.str();
			rua = os_rua.str();
			numero = os_numero.str();
			bairro = os_bairro.str();
			cep = os_cep.str();
			telefone = os_telefone.str();
			cnpj = os_cnpj.str();
			razaosocial = os_razaosocial.str();

			

			clientesj << nome << endl;
			clientesj << rua << endl;
			clientesj << numero << endl;
			clientesj << bairro << endl;
			clientesj << cep << endl;
			clientesj << telefone << endl;
			clientesj << cnpj << endl;
			clientesj << razaosocial << endl;
			clientesj << blank_line << endl; 
			
		}
		clientesj.close();
	}

	void salvarClientes()
	{
		salvarClientesF();
		salvarClientesJ();
	}

	void salvarProdutosDiversos()
	{
		ofstream produtos_diversos;
		produtos_diversos.open("produtos_diversos.txt");
		int size = stockProdutos_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_produto_nome,os_produto_quantidade,os_produto_preco;
			os_produto_nome << "Nome: " << stockProdutos_[i].obterProdutoNome();
			os_produto_quantidade << "Quantidade: " << stockProdutos_[i].obterQuantidade();
			os_produto_preco << "Preço: R$" << stockProdutos_[i].obterPreco();
			

			string produto_nome, produto_quantidade, produto_preco;
			string blank_line = "";
			produto_nome = os_produto_nome.str();
			produto_quantidade = os_produto_quantidade.str();
			produto_preco = os_produto_preco.str();
			

			

			produtos_diversos << produto_nome << endl;
			produtos_diversos << produto_quantidade << endl;
			produtos_diversos << produto_preco << endl;
			produtos_diversos << blank_line << endl; 
			
		}
		produtos_diversos.close();
	}
	void salvarLivros()
	{
		ofstream produtos_livros;
		produtos_livros.open("produtos_livros.txt");
		int size = stockLivros_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_livro_nome,os_livro_quantidade,os_livro_preco, os_livro_genero, os_livro_volume, os_livro_editora;
			os_livro_nome << "Nome: " << stockLivros_[i].obterProdutoNome();
			os_livro_quantidade << "Quantidade: " << stockLivros_[i].obterQuantidade();
			os_livro_preco << "Preço: R$" << stockLivros_[i].obterPreco();
			os_livro_genero << "Gênero: " << stockLivros_[i].obterLivroGenero();
			os_livro_volume << "Volume: " << stockLivros_[i].obterLivroVolume();
			os_livro_editora << "Editora: " << stockLivros_[i].obterLivroEditora();
			

			string livro_nome, livro_quantidade, livro_preco, livro_genero, livro_volume, livro_editora;;
			string blank_line = "";
			livro_nome = os_livro_nome.str();
			livro_quantidade = os_livro_quantidade.str();
			livro_preco = os_livro_preco.str();
			livro_genero = os_livro_genero.str();
			livro_volume = os_livro_volume.str();
			livro_editora = os_livro_editora.str();			

			produtos_livros << livro_nome << endl;
			produtos_livros << livro_quantidade << endl;
			produtos_livros << livro_preco << endl;
			produtos_livros << livro_genero << endl;
			produtos_livros << livro_volume << endl;
			produtos_livros << livro_editora << endl;
			produtos_livros << blank_line << endl; 
			
		}
		produtos_livros.close();
	}
	void salvarRevistas()
	{
		ofstream produtos_revistas;
		produtos_revistas.open("produtos_revistas.txt");
		int size = stockRevistas_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_revistas_nome,os_revistas_quantidade,os_revistas_preco, os_revistas_genero, os_revistas_edicao, os_revistas_publicador;
			os_revistas_nome << "Nome: " << stockRevistas_[i].obterProdutoNome();
			os_revistas_quantidade << "Quantidade: " << stockRevistas_[i].obterQuantidade();
			os_revistas_preco << "Preço: R$" << stockRevistas_[i].obterPreco();
			os_revistas_genero << "Gênero: " << stockRevistas_[i].obterRevistaGenero();
			os_revistas_edicao << "Edição: " << stockRevistas_[i].obterRevistaEdicao();
			os_revistas_publicador << "Publicador: " << stockRevistas_[i].obterRevistaPublicador();
			

			string revistas_nome, revistas_quantidade, revistas_preco, revistas_genero, revistas_edicao, revistas_publicador;
			string blank_line = "";
			revistas_nome = os_revistas_nome.str();
			revistas_quantidade = os_revistas_quantidade.str();
			revistas_preco = os_revistas_preco.str();
			revistas_genero = os_revistas_genero.str();
			revistas_edicao = os_revistas_edicao.str();
			revistas_publicador = os_revistas_publicador.str();
			

			

			produtos_revistas << revistas_nome << endl;
			produtos_revistas << revistas_quantidade << endl;
			produtos_revistas << revistas_preco << endl;
			produtos_revistas << revistas_genero << endl;
			produtos_revistas << revistas_edicao << endl;
			produtos_revistas << revistas_publicador << endl;
			produtos_revistas << blank_line << endl; 
			
		}
		produtos_revistas.close();
	}
	void salvarProdutos()
	{
		salvarProdutosDiversos();
		salvarLivros();
		salvarRevistas();
	}
	void salvarFuncionarios()
	{
		ofstream funcionarios;
		funcionarios.open("funcionarios.txt");
		int size = cadastroFuncionario_.size();

		for(int i = 0; i < size; i++)
		{
			ostringstream os_nome,os_rua,os_numero,os_bairro,os_cep,os_telefone,os_cpf,os_rg, os_data, os_salario;
			os_nome << "Nome: " << cadastroFuncionario_[i].obterPessoaNome();
			os_rua << "Rua: " << cadastroFuncionario_[i].obterPessoaEndereco().obterRua();
			os_numero << "Número: " << cadastroFuncionario_[i].obterPessoaEndereco().obterNumero();
			os_bairro << "Bairro: " << cadastroFuncionario_[i].obterPessoaEndereco().obterBairro();
			os_cep << "CEP: " << cadastroFuncionario_[i].obterPessoaEndereco().obterCEP();
			os_telefone << "Telefone: " << cadastroFuncionario_[i].obterPessoaTelefone().obterTelefone();
			os_cpf << "CPF: " << cadastroFuncionario_[i].obterCPF().obterCPF();
			os_rg << "RG: " << cadastroFuncionario_[i].obterRG().obterRG();
			os_data << "Data de Contratação: " << cadastroFuncionario_[i].obterData().obterData();
			os_salario << "Salário: R$ " << cadastroFuncionario_[i].obterSalario();

			string nome, rua, numero, bairro, cep, telefone, cpf, rg, data, salario;
			string blank_line = "";
			nome = os_nome.str();
			rua = os_rua.str();
			numero = os_numero.str();
			bairro = os_bairro.str();
			cep = os_cep.str();
			telefone = os_telefone.str();
			cpf = os_cpf.str();
			rg = os_rg.str();
			data = os_data.str();
			salario = os_salario.str();

			

			funcionarios << nome << endl;
			funcionarios << rua << endl;
			funcionarios << numero << endl;
			funcionarios << bairro << endl;
			funcionarios << cep << endl;
			funcionarios << telefone << endl;
			funcionarios << cpf << endl;
			funcionarios << rg << endl;
			funcionarios << data << endl;
			funcionarios << salario << endl;
			funcionarios << blank_line << endl; 
			
		}
		funcionarios.close();
	}
	void inicalizarTudo()
	{
		inicializarFuncionarios();
		inicializarProdutos();
		inicializarClientesF();
		inicializarClientesJ();
	}
	void salvarBancoDeDados()
	{
		salvarClientes();
		salvarProdutos();
		salvarFuncionarios();
		
	}

private:
	deque<Produto> stockProdutos_;
	deque<Livro> stockLivros_;
	deque<Revista> stockRevistas_;
	deque<Cliente_fisico> cadastroClienteF_;
	deque<Cliente_juridico> cadastroClienteJ_;
	deque<Funcionario> cadastroFuncionario_;

};

/**
 * @file	main.cpp
 * @brief	Cógido fonte principal do Projeto BookSoft da disciplina LP
 * @author	Leonardo Dias, Lucas Novaes, Renan Kimura, Yuri Ferreira
 * @since	27/10/2016
 * @date	01/12/2016
 * @sa		clientes.hpp
 * @sa		funcionarios.hpp
 * @sa		vendedor.hpp
 * @sa		produtos.hpp
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <deque>
#include <sstream>

using namespace std;
/**
 * @details	Função responsável pela transformação de String para float. Será usada para transformar dados float que serão armazenados em String.
 * @param	s String que será transformada em float
 */
float toFloat(string s) {

  float r = 0;

  istringstream ss(s);

  ss >> r;

  return r;

}

class Data{

public:
	 /**
	 * @details O construtor parametrizado da classe Data é utilizado para instanciar um objeto Data.
	 * @param	dia Dia
	 * @param	mes Mês
	 * @param	ano Ano
	 */
	Data(int dia, int mes, int ano) : dia_{dia}, mes_{mes}, ano_{ano} {}
	 /**
	 * @details 	O construtor parametrizado da classe Data é utilizado para instanciar um objeto Data.
	 * @param	d Objeto do tipo data
	 */
	Data(Data const& d) : dia_{d.dia_}, mes_{d.mes_}, ano_{d.ano_} {}
	/**
	 * @details Construtor padrão
	 */
	Data() = default;


	/**
	 * @details Método de leitura do objeto Data (dia, mês e ano) com tratamento de exceções para manter a proximidade com a realidade.
 	*/
	void leiaData() {

		cout << " Dia: ";
		try{
			cin >> dia_;
			if (dia_ > 0 && dia_ < 32)
			{
				throw 45;
			}
		}catch(int e){
			cout<<"erro, o dia deve ser entre 1 e 31, numero de erro: "<< e <<;
		}

		cout << " Mes: ";

		try{
			cin >> mes_;
			if (mes_ > 0 && mes_ < 12)
			{
				throw 46;
			}
		}catch(int e){
			cout<<"erro, o mes deve ser entre 1 e 12, numero de erro: "<< e <<;
		}

		cout << " Ano: ";

		try{
			cin >> ano_;
			if (ano_ > 0 && ano < 2017)
			{
				throw 47;
			}
		}catch(int e){
			cout<<"erro, o ano deve ser entre 1 e 2016, numero de erro: "<< e <<;
		}

	}
	/**
	 * @details Método de impressão do objeto Data.
 	*/
	void mostreData() { cout << dia_ << "/" << mes_ << "/" << ano_ << endl; }



private:

	int dia_; /**< Dia */

	int mes_; /**< Mês */

	int ano_; /**< Ano */

};



class CPF{

public:
	 /**
	 * @details 	O construtor parametrizado da classe CPF é utilizado para instanciar um objeto CPF.
	 * @param	cpf Número do CPF.
	 */
	CPF(string cpf) : cpf_{cpf} {}
	 /**
	 * @details 	Construtor por cópia.
	 * @param	c Objeto do tipo CPF.
	 */
	CPF(CPF const& c) : cpf_{c.cpf_} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	CPF() = default;


	/**
	 * @details Método de leitura do objeto CPF. Contém tratamento de exceções que mantém a entrada com 11 dígitos.
 	*/
	void leiaCPF() {

		cout << " Informe CPF: ";
		try{
			cin >> cpf_;
			int nDigits = floor(log10(abs(cpf_))) + 1;
			if (nDigits != 11)
			{
				throw 44;
			}
		}catch(int e){
			cout<<"erro, o numero de CPF deve conter 11 digitos, erro numero "<< e <<;
		}

	}
	/**
	 * @details Método de impressão do objeto CPF.
 	*/
	void mostreCPF() { cout << " CPF: " << cpf_ << endl; }



	string const& obterCPF() const {

		return cpf_;

	}

private:

	string cpf_; /**< CPF */

};



class CNPJ{

public:
	 /**
	 * @details 	O construtor parametrizado da classe CNPJ é utilizado para instanciar um objeto CNPJ.
	 * @param	cnpj Número do CNPJ.
	 */
	CNPJ(string cnpj) : cnpj_{cnpj} {}
	 /**
	 * @details 	Construtor por cópia.
	 * @param	c Objeto do tipo CNPJ.
	 */
	CNPJ(CNPJ const& c) : cnpj_{c.cnpj_} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	CNPJ() = default;


	/**
	 * @details Método de leitura do objeto CNPJ. Contém tratamento de exceções que mantém a entrada com 14 dígitos.
 	*/
	void leiaCNPJ() {

		cout << " Informe CNPJ: ";

		try{
			cin >> cnpj_;
			int nDigits = floor(log10(abs(cnpj_))) + 1;
			if (nDigits != 14)
			{
				throw 43;
			}
		}catch(int e){
			cout<<"erro, o numero de CNPJ deve conter 14 digitos, erro numero "<< e <<;
		}

	}
	/**
	 * @details Método de impressão do objeto CNPJ.
 	*/
	void mostreCNPJ() { cout << " CNPJ: " << cnpj_ << endl; }



	string const& obterCNPJ() const {

		return cnpj_;

	}

private:

	string cnpj_; /**< CNPJ */

};

bool operator==(CPF const& cpf1, CPF const& cpf2){

	return cpf1.obterCPF() == cpf2.obterCPF();

}



bool operator==(CNPJ const& cnpj1, CNPJ const& cnpj2){

	return cnpj1.obterCNPJ() == cnpj2.obterCNPJ();

}



class RG{

public:
	 /**
	 * @details 	O construtor parametrizado da classe RG é utilizado para instanciar um objeto RG.
	 * @param	rg Número do RG.
	 */
	RG(string rg) : rg_{rg} {}
	 /**
	 * @details 	Construtor por cópia.
	 * @param	r Objeto do tipo RG.
	 */
	RG(RG const& r) : rg_{r.rg_} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	RG() = default;


	/**
	 * @details Método de leitura do objeto RG. Contém tratamento de exceções que mantém a entrada com 9 dígitos.
 	*/
	void leiaRG(){

		cout << " Informe RG: ";

		try{
			cin >> rg_;
			int nDigits = floor(log10(abs(cpf_))) + 1;
			if (nDigits != 9)
			{
				throw 42;
			}
		}catch(int e){
			cout<<"erro, o numero de RG deve conter 9 digitos, erro numero "<< e <<;
		}

	}


	/**
	 * @details Método de impressão do objeto RG.
 	*/
	void mostreRG() { cout << " RG: " << rg_ << endl; }

private:

	string rg_; /**< RG */

};



class Telefone{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Telefone é utilizado para instanciar um objeto Telefone.
	 * @param	tel Número do Telefone.
	 */
	Telefone(string tel) : tel_{tel} {}
	 /**
	 * @details 	Construtor por cópia.
	 * @param	t Objeto do tipo Telefone.
	 */
	Telefone(Telefone const& t) : tel_{t.tel_} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	Telefone() = default;


	/**
	 * @details Método de leitura do objeto Telefone.
 	*/
	void leiaTelefone(){

		cout << " Informe Telefone: ";

		getline(cin,tel_);;

	}


	/**
	 * @details Método de impressão do objeto Telefone.
 	*/
	void mostreTelefone() { cout << " Telefone: " << tel_ << endl; }

private:

	string tel_; /**< Telefone */

};



class Endereco{

public:
	/**
	 * @details O construtor parametrizado da classe Endereço é utilizado para instanciar um objeto Endereço.
	 * @param	string numero
	 * @param	string rua
	 * @param	string bairro
	 * @param	string cep
	 */
	Endereco(string numero, string rua, string bairro, string cep) : numero_{numero}, rua_{rua}, bairro_{bairro}, cep_{cep} {}
	 /**
	 * @details 	Construtor por cópia.
	 * @param	e Objeto do tipo Endereco.
	 */
	Endereco(Endereco const& e) : numero_{e.numero_}, rua_{e.rua_}, bairro_{e.bairro_}, cep_{e.cep_} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	Endereco() = default;


	/**
	 * @details Método de leitura do objeto Endereco. Tratamento de exceção para manter o CEP com 8 dígitos.
 	*/
	void leiaEndereco() {

		cout << " Número: ";

		getline(cin,numero_);

		cout << " Logradouro: ";

		getline(cin,rua_);

		cout << " Bairro: ";

		getline(cin,bairro_);

		cout << " CEP: ";
		try{
			getline(cin,cep_);
			int nDigits = floor(log10(abs(cep_))) + 1;
			if (nDigits != 8)
			{
				throw 41;
			}
		}catch(int e){
			cout<<"erro, o numero de CEP deve conter 8 digitos, erro numero "<< e <<;
		}
	}
	/**
	 * @details Método de impressão do objeto Endereco.
 	*/
	void mostreEndereco() { cout << rua_ << " , Nº " << numero_ << "\n Bairro:  " << bairro_  << ", " << cep_ << endl; }



private:

	string numero_; /**< Número da casa */

	string rua_; /**< Rua */

	string bairro_; /**< Bairro */

	string cep_; /**< CEP */

};





class Pessoa{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Pessoa é utilizado para instanciar um objeto Pessoa.
	 * @param	nome Nome da pessoa.
	 * @param	endereco Endereço da pessoa.
	 * @param	telefone Telefone da pessoa.	 
	 */
	Pessoa(string nome, Endereco endereco, Telefone telefone)

	: nome_{nome}, endereco_{endereco}, telefone_{telefone} {}
	 /**
	 * @details 	Construtor por cópia.
	 * @param	p Objeto do tipo Pessoa.
	 */
	Pessoa(Pessoa const& p)

	: nome_{p.nome_}, endereco_{p.endereco_}, telefone_{p.telefone_} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	Pessoa() = default;


	/**
	 * @details Método de leitura do objeto Pessoa.
 	*/
	void leiaPessoa(){

		cout << "Nome: ";

		getline(cin, nome_);

		cout << " Informe o endereco: \n";

		endereco_.leiaEndereco();

		cout << " Informe o telefone: \n";

		telefone_.leiaTelefone();

	}
	/**
	 * @details Método de escrita do objeto Pessoa.
 	*/
	void mostrePessoa(){

		cout << " Nome: " << nome_ << "\n Endereco: ";

		endereco_.mostreEndereco();

		telefone_.mostreTelefone();

	}



private:

	string nome_; /**< Nome da pessoa */

	Endereco endereco_; /**< Endereço */

	Telefone telefone_; /**< Telefone */

};



class Produto

{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Produto é utilizado para instanciar um objeto Produto.
	 * @param	produto_nome Nome do produto.
	 * @param	quantidade Quantidade de produtos.
	 * @param	preco Preço do produto.
	 */
	Produto(string produto_nome, int quantidade, float preco) :

	produto_nome_{produto_nome} , quantidade_{quantidade}, preco_{preco} {}
	 /**
	 * @details 	Construtor por cópia.
	 * @param	produto Objeto do tipo Produto.
	 */
	Produto(Produto const& produto)

	: produto_nome_{produto.produto_nome_}, preco_{produto.preco_}, quantidade_{produto.quantidade_} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	Produto() = default;
	
	/**
	 * @details Método de leitura do objeto Produto.
 	*/
	void leiaProduto(){

		cout << " Nome: ";

		getline(cin,produto_nome_);

		cout << " Quantidade: ";

		cin >> quantidade_;

		cout << " Preco: ";

		cin >> preco_;

	}

	/**
	 * @details Método de escrita do objeto Produto.
 	*/
	void mostreProduto(){

		cout << " Nome: " << produto_nome_ << endl;

		cout << " Quantidade: " << quantidade_ << endl;

		cout << " Preco: R$ " << fixed << setprecision(2) << preco_ << endl;

	}

	/**
	 * @return Nome do produto.
 	*/
	string getProdutoNome() {return produto_nome_;}
	/**
	 * @return Preço do produto.
 	*/
	float getPreco() {return preco_;}
	/**
	 * @return Quantidade do produto.
 	*/
	int getQuantidade() {return quantidade_;}



private:

	string produto_nome_; /**< Nome do produto */

	float preco_; /**< Preço */

	int quantidade_; /**< Quantidade do produto */

};



class Livro : public Produto

{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Livro é utilizado para instanciar um objeto Livro.
	 * @param	produto Objeto do tipo Produto.
	 * @param	editora Nome da editora.
	 * @param	volume Volume da edição.
	 * @param	livro_genero Gênero do livro.
	 */
	Livro(Produto produto, string editora, string volume, string livro_genero ) :

	Produto{produto}, editora_{editora}, volume_{volume} , livro_genero_{livro_genero} {}

	Livro() : Produto{}, editora_{}, volume_{}, livro_genero_{} {}


	/**
	 * @details Método de leitura do objeto Livro.
 	*/
	void leiaLivro(){

		Produto::leiaProduto();

		cout << " Genero: ";

		getline(cin, livro_genero_);

		cout << " Volume: ";

		getline(cin, volume_);

		cout << " Editora: ";

		getline(cin, editora_);

	}


	/**
	 * @details Método de escrita do objeto Livro. 
 	*/
	void mostreLivro(){

		Produto::mostreProduto();

		cout << " Genero: " << livro_genero_ << endl;

		cout << " Volume: " << volume_ << endl;

		cout << " Editora: " << editora_ << endl;

	}



private:

	string editora_; /**< Editora */
	string volume_; /**< Volume */
	string livro_genero_; /**< Gênero */

};



class Revista : public Produto

{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Revista é utilizado para instanciar um objeto Revista.
	 * @param	produto Objeto do tipo Produto.
	 * @param	edicao Edição do produto.
	 * @param	publicador Empresa responsável pela publicação.
	 * @param	revista_genero Gênero da revista.
	 */
	Revista(Produto produto, string edicao, string publicador, string revista_genero ) :

	Produto{produto}, edicao_{edicao}, publicador_{publicador}, revista_genero_{revista_genero} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	Revista() : Produto{}, edicao_{}, publicador_{}, revista_genero_{} {}


	/**
	 * @details Método de leitura do objeto Revista. 
 	*/
	void leiaRevista(){

		Produto::leiaProduto();

		cout << " Genero: ";

		getline(cin, revista_genero_);

		cout << " Edicao: ";

		getline(cin, edicao_);

		cout << " Publicador: ";

		getline(cin, publicador_);

	}


	/**
	 * @details Método de impressão do objeto Revista. 
 	*/
	void mostreRevista(){

		Produto::mostreProduto();

		cout << " Genero: " << revista_genero_ << endl;

		cout << " Edicao: " << edicao_ << endl;

		cout << " Publicador: " << publicador_ << endl;

	}



private:

	string edicao_; /**< Edição da revista */
	string publicador_; /**< Empresa resposável pela publicação da revista */
	string revista_genero_; /**< Gênero da revista */

};



class Cliente : public Pessoa{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Cliente é utilizado para instanciar um objeto Cliente.
	 * @param	pessoa Objeto do tipo Pessoa.
	 */
	Cliente(Pessoa pessoa ) : Pessoa{pessoa} {}
	
	 /**
	 * @details 	Construtor padrão.
	 */
	Cliente() : Pessoa{} {}


	/**
	 * @details Método de leitura do objeto Cliente. 
 	*/
	void leiaCliente()

	{

		Pessoa::leiaPessoa();

	}


	/**
	 * @details Método de impressão do objeto Cliente. 
 	*/
	void mostreCliente()

	{

		Pessoa::mostrePessoa();

	}

private:

};



class Cliente_fisico : public Cliente

{	

public:
	 /**
	 * @details 	O construtor parametrizado da classe Cliente_fisico é utilizado para instanciar um objeto Cliente Físico.
	 * @param	cliente Objeto do tipo Cliente.
	 * @param	cpf Objeto do tipo CPF.
	 * @param	rg Objeto do tipo RG.
	 */
	Cliente_fisico(Cliente cliente, CPF cpf, RG rg) :

	Cliente{cliente}, cpf_{cpf}, rg_{rg} {}
	
	 /**
	 * @details 	Construtor padrão.
	 */
	Cliente_fisico() : Cliente{}, cpf_{}, rg_{} {}


	/**
	 * @details Método de leitura do objeto Cliente_fisico. 
	*/
	void leiaCliente_F(){

		cin.ignore();

		Cliente::leiaCliente();

		cout << " CPF: " << endl;

		cpf_.leiaCPF();

		cout << " RG: " << endl;

		rg_.leiaRG();

	}


	/**
	 * @details Método de impressão do objeto Cliente_fisico. 
	*/
	void mostreCliente_F(){

		Cliente::mostreCliente();

		cpf_.mostreCPF();

		rg_.mostreRG();

	}



	CPF const& obterCPF() const{

		return cpf_;

	}



private:

	CPF cpf_; /**< CPF */

	RG rg_; /**< RG */

};



class Cliente_juridico : public Cliente

{	

public:
	 /**
	 * @details 	O construtor parametrizado da classe Cliente_juridico é utilizado para instanciar um objeto Cliente Jurídico.
	 * @param	cliente Objeto do tipo Cliente.
	 * @param	cnpj Objeto do tipo CNPJ.
	 * @param	razaosocial Nome da razão social.
	 */
	Cliente_juridico(Cliente cliente, CNPJ cnpj, string razaosocial) :

	Cliente{cliente}, cnpj_{cnpj}, razaosocial_{razaosocial} {}
	
	 /**
	 * @details 	Construtor padrão.
	 */
	Cliente_juridico() : Cliente{}, cnpj_{}, razaosocial_{} {}

	/**
	 * @details Método de leitura do objeto Cliente_juridico. 
	*/
	void leiaCliente_J(){

		cin.ignore();

		Cliente::leiaCliente();

		cout << " CNPJ: " << endl;

		cnpj_.leiaCNPJ();

		cout << " Razao Social: " << endl;

		cin >> razaosocial_;

	}

	/**
	 * @details Método de escrita do objeto Cliente_juridico. 
	*/
	void mostreCliente_J(){

		Cliente::mostreCliente();

		cnpj_.mostreCNPJ();

		cout << " Razao Social: " << razaosocial_ << endl;

	}



	CNPJ const& obterCNPJ() const{

		return cnpj_;

	}



private:

	CNPJ cnpj_; /**< CNPJ */

	string razaosocial_; /**< Razão Social */

};



class Funcionario : public Pessoa{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Funcionario é utilizado para instanciar um objeto Funcionario.
	 * @param	pessoa Objeto do tipo Pessoa.
	 * @param	cpf Objeto do tipo CPF.
	 * @param	rg Objeto do tipo RG.
	 * @param	dataContratacao Objeto do tipo Data, contem a data da contratação.
	 * @param	salario Valor do salário.
	 */
	Funcionario(Pessoa pessoa, CPF cpf, RG rg, Data dataContratacao, float salario) :

	Pessoa{pessoa}, cpf_{cpf}, rg_{rg} ,dataContratacao_{dataContratacao}, salario_{salario} {}
	 /**
	 * @details 	Construtor padrão.
	 */
	Funcionario() : Pessoa{}, cpf_{}, rg_{}, dataContratacao_{}, salario_{0.0} {}
	/**
	 * @details Método de leitura do objeto Funcionario. 
	*/
	void leiaFuncionario(){

		Pessoa::leiaPessoa();

		cout << " CPF: " << endl;

		cpf_.leiaCPF();

		cout << " RG: " << endl;

		rg_.leiaRG();

		cout << " Data de Contratacao: " << endl;

		dataContratacao_.leiaData();

		cout << " Salario: ";

		cin >> salario_;

	}


	/**
	 * @details Método de escrita do objeto Funcionario. 
	*/
	void mostreFuncionario(){

		Pessoa::mostrePessoa();

		cpf_.mostreCPF();

		rg_.mostreRG();

		cout << " Data de Contratacao: ";

		dataContratacao_.mostreData();

		cout << " Salario: R$ " << fixed << setprecision(2) << salario_ << endl;

	}


	/**
	 * @return Valor do salário do funcionário.
 	*/
	float const obterSalario() const {

		return salario_;

	}


	/**
	 * @return Número do CPF do funcionário.
 	*/
	CPF const& obterCPF() const{

		return cpf_;

	}



private:

	CPF cpf_; /**< CPF */

	RG rg_; /**< RG */

	Data dataContratacao_; /**< Data da contratação */

	float salario_; /**< Salário */

};



class Gerente : public Funcionario

{

public:
	 /**
	 * @details 	O construtor parametrizado da classe Gerente é utilizado para instanciar um objeto Gerente.
	 * @param	funcionario Objeto do tipo Funcionario.
	 */
	Gerente(Funcionario funcionario) : Funcionario{funcionario} {}
	
	/**
	 * @details 	Construtor padrão.
	 */
	Gerente() : Funcionario{} {}


	/**
	 * @details Método de leitura do objeto Gerente. 
	*/
	void leiaGerente(){

		Funcionario::leiaFuncionario();

	}


	/**
	 * @details Método de escrita do objeto Gerente. 
	*/
	void mostreGerente(){

		Funcionario::mostreFuncionario();

	}


	/**
	 * @details Método responsável pela leitura dos objetos Produto (de arquivos ".txt" que foram utilizados como "banco de dados") e conversão dos atributos para seus respectivos tipos.  
	*/
	void inicializarProdutos()

	{

		string nome, str_quantidade, str_preco, revista_genero, livro_editora, livro_volume, livro_genero, revista_edicao ,revista_publicadora;

		int quantidade;

		float preco;

		ifstream arquivoLivros, arquivoRevistas, arquivoDiversos;

		arquivoLivros.open("produtos_livros.txt");

		arquivoRevistas.open("produtos_revistas.txt");

		arquivoDiversos.open("produtos_diversos.txt");

		while(!arquivoLivros.eof())

		{

			getline(arquivoLivros, nome);

			getline(arquivoLivros, str_quantidade);

			getline(arquivoLivros, str_preco);

			getline(arquivoLivros, livro_genero);

			getline(arquivoLivros, livro_volume);

			getline(arquivoLivros, livro_editora);

			

			size_t pos_nome = nome.find(": ");

        	size_t pos_quantidade = str_quantidade.find(": ");

        	size_t pos_preco = str_preco.find(": ");

        	size_t pos_genero = livro_genero.find(": ");

        	size_t pos_volume= livro_volume.find(": ");

        	size_t pos_editora = livro_editora.find(": ");



        	nome = nome.substr(pos_nome + 2);

        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);

        	str_preco = str_preco.substr(pos_preco + 4);

        	livro_genero = livro_genero.substr(pos_genero + 2);

        	livro_volume = livro_volume.substr(pos_volume + 2);

        	livro_editora = livro_editora.substr(pos_editora + 2);



        	quantidade = stoi(str_quantidade);

        	preco = toFloat(str_preco);



        	Produto p(nome,quantidade,preco);

        	Livro l(p,livro_editora,livro_volume,livro_genero);

        	stockProdutos_.push_back(l);

		}



		while(!arquivoRevistas.eof())

		{

			getline(arquivoRevistas, nome);

			getline(arquivoRevistas, str_quantidade);

			getline(arquivoRevistas, str_preco);

			getline(arquivoRevistas, revista_genero);

			getline(arquivoRevistas, revista_edicao);

			getline(arquivoRevistas, revista_publicadora);



			size_t pos_nome = nome.find(": ");

        	size_t pos_quantidade = str_quantidade.find(": ");

        	size_t pos_preco = str_preco.find(": ");

        	size_t pos_genero = revista_genero.find(": ");

        	size_t pos_edicao= revista_edicao.find(": ");

        	size_t pos_publicadora = revista_publicadora.find(": ");



        	nome = nome.substr(pos_nome + 2);

        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);

        	str_preco = str_preco.substr(pos_preco + 2);

        	revista_genero = revista_genero.substr(pos_genero + 2);

        	revista_edicao = revista_edicao.substr(pos_edicao + 2);

        	revista_publicadora = revista_publicadora.substr(pos_publicadora + 2);



        	quantidade = stoi(str_quantidade);

        	preco = toFloat(str_preco);



        	Produto p(nome,quantidade,preco);

        	Revista r(p,revista_edicao,revista_publicadora,revista_genero);

        	stockProdutos_.push_back(r);



		}



		while(!arquivoDiversos.eof())

		{

			getline(arquivoDiversos, nome);

			getline(arquivoDiversos, str_quantidade);

			getline(arquivoDiversos, str_preco);



			size_t pos_nome = nome.find(": ");

        	size_t pos_quantidade = str_quantidade.find(": ");

        	size_t pos_preco = str_preco.find(": ");

   			

        	nome = nome.substr(pos_nome + 2);

        	str_quantidade = str_quantidade.substr(pos_quantidade + 2);

        	str_preco = str_preco.substr(pos_preco + 4);



        	quantidade = stoi(str_quantidade);

        	preco = toFloat(str_preco);



        	Produto p(nome,quantidade,preco);

        	stockProdutos_.push_back(p);



		}



		arquivoLivros.close();

		arquivoRevistas.close();

		arquivoDiversos.close();

	}


	/**
	 * @details Método responsável pela leitura dos objetos Funcionario (de arquivos ".txt" que foram utilizados como "banco de dados") e conversão dos atributos para seus respectivos tipos.  
	*/
	void inicializarFuncionarios()

	{

		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cpf, rg, data, salario;

		ifstream arquivoFuncionarios;

		arquivoFuncionarios.open("funcionarios.txt");

		while(!arquivoFuncionarios.eof())

		{

			getline(arquivoFuncionarios, nome);

			getline(arquivoFuncionarios, e_rua);

			getline(arquivoFuncionarios, e_num);

			getline(arquivoFuncionarios, e_bairro);

			getline(arquivoFuncionarios, e_cep);

			getline(arquivoFuncionarios, telefone);

			getline(arquivoFuncionarios, cpf);

			getline(arquivoFuncionarios, rg);

			getline(arquivoFuncionarios, data);

			getline(arquivoFuncionarios, salario);



			size_t pos_nome = nome.find(": ");

        	size_t pos_rua = e_rua.find(": ");

        	size_t pos_num = e_num.find(": ");

        	size_t pos_bairro = e_bairro.find(": ");

        	size_t pos_cep = e_cep.find(": ");

        	size_t pos_tel = telefone.find(": ");

        	size_t pos_cpf = cpf.find(": ");

        	size_t pos_rg = rg.find(": ");

        	size_t pos_data = data.find(": ");

        	size_t pos_salario = salario.find(": ");



        	nome = nome.substr(pos_nome + 2);

        	e_rua = e_rua.substr(pos_rua + 2);

        	e_num = e_num.substr(pos_num + 2);

        	e_bairro = e_bairro.substr(pos_bairro + 2);

        	e_cep = e_cep.substr(pos_cep + 2);

        	telefone = telefone.substr(pos_tel + 2);

        	cpf = cpf.substr(pos_cpf + 2);

        	rg = rg.substr(pos_rg + 2);

        	data = data.substr(pos_data + 2);

        	salario = salario.substr(pos_salario + 4);





        	string str_dia, str_mes, str_ano;



        	str_dia = data.substr(0,2);

        	str_mes = data.substr(3,2);

        	str_ano = data.substr(6,4);



        	int dia, mes, ano;



        	dia = stoi(str_dia);

        	mes = stoi(str_mes);

        	ano = stoi(str_ano);



        	float salario_f = toFloat(salario);



        	Endereco e_f(e_rua, e_num, e_bairro, e_cep);

        	CPF cpf_f(cpf);

        	RG rg_f(rg);

        	Data data_f(dia,mes,ano);

        	Telefone tel_f(telefone);



        	Pessoa p(nome,e_f,tel_f);

        	Funcionario f_p(p,cpf_f,rg_f,data_f,salario_f);



        	cadastroFuncionario_.push_back(f_p);





		}



		arquivoFuncionarios.close();

	}


	/**
	 * @details Método responsável pela leitura dos objetos Cliente (de arquivos ".txt" que foram utilizados como "banco de dados") e conversão dos atributos para seus respectivos tipos.  
	*/
	void inicializarClientesF()

	{

		string nome, e_rua, e_num, e_bairro, e_cep, telefone, cpf, rg;

		ifstream arquivoClientesF;

		arquivoClientesF.open("clientes_fisicos.txt");

		while(!arquivoClientesF.eof())

		{

			getline(arquivoClientesF, nome);

			getline(arquivoClientesF, e_rua);

			getline(arquivoClientesF, e_num);

			getline(arquivoClientesF, e_bairro);

			getline(arquivoClientesF, e_cep);

			getline(arquivoClientesF, telefone);

			getline(arquivoClientesF, cpf);

			getline(arquivoClientesF, rg);



			size_t pos_nome = nome.find(": ");

        	size_t pos_rua = e_rua.find(": ");

        	size_t pos_num = e_num.find(": ");

        	size_t pos_bairro = e_bairro.find(": ");

        	size_t pos_cep = e_cep.find(": ");

        	size_t pos_tel = telefone.find(": ");

        	size_t pos_cpf = cpf.find(": ");

        	size_t pos_rg = rg.find(": ");



        	nome = nome.substr(pos_nome + 2);

        	e_rua = e_rua.substr(pos_rua + 2);

        	e_num = e_num.substr(pos_num + 2);

        	e_bairro = e_bairro.substr(pos_bairro + 2);

        	e_cep = e_cep.substr(pos_cep + 2);

        	telefone = telefone.substr(pos_tel + 2);

        	cpf = cpf.substr(pos_cpf + 2);

        	rg = rg.substr(pos_rg + 2);



        	CPF cpf_p(cpf);

        	RG rg_p(rg);

        	Endereco e_p(e_rua, e_num, e_bairro, e_cep);

        	Telefone tel_p(telefone);



        	Pessoa p(nome,e_p,tel_p);

        	Cliente c_p(p);

        	Cliente_fisico cf_p(c_p, cpf_p, rg_p);

        	cadastroClienteF_.push_back(cf_p);

		}



		arquivoClientesF.close();

	}


	/**
	 * @details Método de leitura dos objetos do tipo Cliente Físico. São impressos todos os objetos armazenados no vetor "cadastroClienteF_".
	*/
	void mostrarCadastroClientesF()

	{

		int size = cadastroClienteF_.size();

		for(int i = 0; i < size; i++)

		{

			

			cadastroClienteF_[i].mostreCliente_F();

			cout << endl;

		}

	}


	/**
	 * @details Método de leitura dos objetos do tipo Cliente Jurídico. São impressos todos os objetos armazenados no vetor "cadastroClienteJ_".
	*/
	void mostrarCadastroClientesJ()

	{

		int size = cadastroClienteJ_.size();

		for(int i = 0; i < size; i++)

		{

			

			cadastroClienteJ_[i].mostreCliente_J();

			cout << endl;

		}

	}


	/**
	 * @details Método de leitura dos objetos do tipo Produto. São impressos todos os objetos armazenados no vetor "stockProdutos_".
	*/
	void mostrarCadastroProdutos()

	{

		int size = stockProdutos_.size();

		for(int i = 0; i < size; i++)

		{



			stockProdutos_[i].mostreProduto();

			cout << endl;

		}

	}


	/**
	 * @details Método de leitura dos objetos do tipo Funcionario. São impressos todos os objetos armazenados no vetor "cadastroFuncionario_".
	*/
	void mostrarCadastroFuncionarios()

	{

		int size = cadastroFuncionario_.size();

		for(int i = 0; i < size; i++)

		{



			cadastroFuncionario_[i].mostreFuncionario();

			cout << endl;

		}

	}
	/**
	 * @details Método para seleção de adição de um novo Objeto do tipo Cliente: invoca "adicionarClienteF" ou "adicionarClienteJ".
	*/
	void adicionarCliente()

	{

		cout << "Qual o tipo do cliente? 1 - Físico | 2 - Jurídico" << endl;

		int op;

		cin >> op;

		switch(op)

		{

			case 1:{adicionarClienteF();break;}

			case 2:{adicionarClienteJ();break;}

		}



		cout << endl;

	}
	/**
	 * @details Método  de adição de um novo Objeto do Cliente Físico. 
	*/
	void adicionarClienteF()

	{

		Cliente_fisico cf;

		cf.leiaCliente_F();

		cadastroClienteF_.push_back(cf);

	}
	/**
	 * @details Método  de adição de um novo Objeto do Cliente Jurídico. 
	*/
	void adicionarClienteJ()

	{

		Cliente_juridico cj;

		cj.leiaCliente_J();

		cadastroClienteJ_.push_back(cj);

	}
	
	/**
	 * @details Método de adição de um novo Objeto do Funcionário. 
	*/
	void adicionarFuncionario() 

	{

		Funcionario f;

		f.leiaFuncionario();

		cadastroFuncionario_.push_back(f);

	}
	
	/**
	 * @details Método para seleção da adição de um novo Objeto do tipo Produto: invoca "adicionarLivro" ou "adicionarRevista" ou "adicionarDiverso".
	*/
	void adicionarProduto()

	{

		cout << "Qual o tipo de produto? 1 - Livro | 2 - Revista | 3 - Diverso " << endl;

		int op;

		cin >> op;

		switch(op)

		{

			case 1:{adicionarLivro(); break;}

			case 2:{adicionarRevista(); break;}

			case 3:{adicionarDiverso(); break;}

		}

		cout << endl;

	}


	/**
	 * @details Método da adição de um Objeto Livro.
	*/
	void adicionarLivro()

	{

		Livro l;

		l.leiaLivro();

		stockProdutos_.push_back(l);

	}
	/**
	 * @details Método da adição de um Objeto Revista.
	*/
	void adicionarRevista()

	{

		Revista r;

		r.leiaRevista();

		stockProdutos_.push_back(r);

	}
	/**
	 * @details Método da adição de um Objeto Diverso.
	*/
	void adicionarDiverso()

	{

		Produto p;

		p.leiaProduto();

		stockProdutos_.push_back(p);

	}


	/**
	 * @details Recebe uma string contendo o CPF e retorna os dados do Cliente Físico, caso encontre.
	 * @param str_cpf String com o CPF
	 * @return i
	*/
	int buscarClienteF(string str_cpf)

	{

		CPF key(str_cpf);

		int size = cadastroClienteF_.size();



		for(int i = 0; i < size; i++)

		{

			if(key == cadastroClienteF_[i].obterCPF())

			{

				return i;

			}

		}

		cout << "Cliente não encontrado! " << endl;

		return -1;

	}


	/**
	 * @details Recebe uma string contendo o CNPJ e retorna os dados do Cliente Jurídico, caso encontre.
	 * @param str_cpf String com o CPF
	 * @return i
	*/
	int buscarClienteJ(string str_cnpj)

	{

		CNPJ key(str_cnpj);

		int size = cadastroClienteJ_.size();



		for(int i = 0; i < size; i++)

		{

			if(key == cadastroClienteJ_[i].obterCNPJ())

			{

				return i;

			}

		}

		cout << "Cliente não encontrado! " << endl;

		return -1;

	}


	/**
	 * @details Recebe uma string contendo um CPF e retorna os dados do Funcionário, caso encontre.
	 * @param str_cpf String com o CPF
	 * @return i
	*/
	int buscarFuncionario(string str_cpf)

	{

		CPF key(str_cpf);

		int size = cadastroFuncionario_.size();



		for(int i = 0; i < size; i++)

		{

			if(key == cadastroFuncionario_[i].obterCPF())

			{

				return i;

			}

		}

		cout << "Cliente não encontrado! " << endl;

		return -1;

	}


	/**
	 * @details Recebe uma string contendo o nome de um produto e retorna a posição do produto, caso encontre. Caso contrário, imprime uma mensagem.
	 * @param str_nome String com o nome do produto.
	 * @return i Posição do produto.
	*/
	int buscarProduto(string str_nome)

	{

		

		int size = stockProdutos_.size();



		for(int i = 0; i < size; i++)

		{

			if(str_nome == stockProdutos_[i].getProdutoNome())

			{

				return i;

			}

		}

		cout << "Produto não encontrado! " << endl;

		return -1;

	}



	/*void removerProduto()

	{

		string key;

		cout << " Digite o nome do produto que deseja remover: ";

		getline(cin, key);

		cin.ignore;

		int indice = buscarProduto(key);

	}*/



private:

	deque<Produto> stockProdutos_; /**< Deque para armazenar os objetos Produtos. */

	deque<Cliente_fisico> cadastroClienteF_; /**< Deque para armazenar os objetos Cliente Físico. */

	deque<Cliente_juridico> cadastroClienteJ_; /**< Deque para armazenar os objetos Cliente Jurídico. */

	deque<Funcionario> cadastroFuncionario_; /**< Deque para armazenar os objetos Funcionário. */



};

int main(){


};
