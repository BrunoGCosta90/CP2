# Quiz Modularizado em C

Projeto desenvolvido como parte do Checkpoint 2 (CP2), com foco no uso de funções, modularização de código, estruturas de controle e manipulação de vetores em Linguagem C.

##  Estrutura do Projeto

O projeto está organizado em três arquivos principais de código, mais este manual de instruções:

* **`main.c`**: Contém a função `main` e o menu interativo controlado por `while` e `switch`.


* **`funcoes.c`**: Contém a implementação e lógica de todas as funções do sistema (cadastro, listagem, jogo e estatísticas).


* **`funcoes.h`**: Contém os protótipos das funções, as definições de tamanho (`#define`) e as declarações globais com `extern`.


* **`README.md`**: Instruções de compilação, execução e documentação do projeto.



##  Funcionalidades

O sistema oferece um menu interativo com as seguintes opções:

1. **Jogar**: Permite responder às perguntas cadastradas, exibindo o placar final e computando os acertos e erros.
2. **Cadastrar Pergunta**: Permite ao usuário adicionar novas perguntas com alternativas de A a D e validação da resposta correta.


3. **Listar Perguntas**: Exibe todas as perguntas cadastradas até o momento no sistema.


4. **Estatísticas**: Mostra o total de perguntas cadastradas e o acompanhamento geral das partidas.


5. **Sair**: Encerra a execução do programa.



##  Instruções de Compilação e Execução

Como o projeto é dividido em múltiplos arquivos (`main.c` e `funcoes.c`), você deve compilá-los juntos.

### Via Linha de Comando (GCC):

Abra o terminal na pasta do projeto e execute o seguinte comando:

```bash
gcc main.c funcoes.c -o quiz

```

Para executar o programa gerado:

* No **Windows**: `quiz.exe`
* No **Linux/Mac**: `./quiz`

### Via IDE (Dev-C++ ou Code::Blocks):

1. Crie um **Project** (Projeto) do tipo Console Application em C.
2. Adicione os arquivos `main.c`, `funcoes.c` e `funcoes.h` dentro do projeto.
3. Clique em **Compile & Run** (F11) para compilar e rodar automaticamente.