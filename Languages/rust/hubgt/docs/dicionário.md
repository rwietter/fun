# Dicionário

- Double free: ocorre quando há duas ou mais chamadas para free() para o mesmo ponteiro (pode levar à corrupção da memória, o que pode, por sua vez, trazer potenciais vulnerabilidades de segurança).

- Non-lexical lifetimes: é uma técnica de análise de tempo de vida que permite que o compilador faça menos suposições sobre o tempo de vida de uma referência. Isso permite que o compilador gere código que usa menos memória e executa mais rapidamente.

- RAII (Resource Acquisition Is Initialization): é um padrão de projeto de software que prevê a aquisição de recursos por meio de um objeto durante sua inicialização e a liberação desses recursos durante sua destruição. O RAII é uma forma de gerenciamento de memória automático ou gerenciamento de recursos. O termo foi cunhado por Bjarne Stroustrup para descrever a abordagem de gerenciamento de memória do C ++.

- Stack: é uma estrutura de dados que armazena itens em uma ordem que respeita o princípio LIFO (Last In First Out). Isso significa que o último item a ser adicionado à pilha será o primeiro a ser removido. A inserção de um item na pilha é chamada de push, e a remoção de um item é chamada de pop.

-  Static dispatch: é um tipo de despacho de método no qual o método invocado é selecionado com base no tipo estático do argumento de destino, em oposição ao tipo dinâmico do objeto no qual o método é chamado. O despacho estático é o tipo de despacho de método padrão em linguagens de programação como C ++ e Java.

- Trait: é um recurso de linguagem que diz ao compilador sobre o comportamento que um tipo deve ter e permite que o compilador verifique se um tipo possui esse comportamento. Os traits são semelhantes às interfaces em outras linguagens, embora com algumas diferenças importantes.

- Packages: A Cargo feature that lets you build, test, and share crates. Package contains one or more crates and a Cargo.toml file that describes how to build those crates.

- Crates: A tree of modules that produces a library or executable

- Modules and use: Let you control the organization, scope, and privacy of paths

- Paths: A way of naming an item, such as a struct, function, or module