# Projeto em C

## O que o `main.c` faz

Este programa em linguagem C implementa um sistema simples de gerenciamento de tarefas chamado "VaptVupt", permitindo ao usuário organizar e acompanhar suas atividades de forma interativa através do terminal. O sistema possibilita criar tarefas com nome, descrição, prioridade (de 1 a 3) e status (1 para Pendente, 2 para Em Andamento e 3 para Concluída). As tarefas são armazenadas em vetores, e o usuário pode listar todas as tarefas registradas, com a opção de filtrá-las por prioridade ou status. Também é possível editar tarefas já existentes, modificando qualquer uma de suas informações, ou excluí-las da lista. O programa oferece ainda a funcionalidade de salvar todas as tarefas cadastradas em um arquivo de texto chamado "tarefas.txt", garantindo que os dados possam ser acessados posteriormente. O funcionamento do sistema é controlado por um menu em loop que exibe as opções ao usuário até que ele decida encerrar o programa.

## Como compilar o projeto

1. **Abra o terminal integrado do Visual Studio Code** (atalho: `Ctrl + ``).
2. **Navegue até a pasta do projeto** (se necessário):
   ```
   cd caminho/para/o/projeto
   ```
3. **Compile o arquivo main.c** usando o GCC:
   ```
   gcc main.c -o programa
   ```
   Isso irá gerar um executável chamado `programa`.

4. **Execute o programa**:
   - No Windows:
     ```
     .\programa
     ```
   - No Linux/macOS:
     ```
     ./programa
     ```

## Observações

- Certifique-se de ter o GCC instalado. No Windows, pode usar o MinGW ou WSL.
- Se o projeto tiver mais arquivos `.c`, adicione-os ao comando de compilação:
  ```
  gcc main.c outro_arquivo.c -o programa
  ```