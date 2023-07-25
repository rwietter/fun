<h2>Pesquisa sequencial</h2>
<span>
 A pesquisa sequencial é feita percorrendo todos os elementos da lista, é uma pesquisa que tem alto custo O(n).
</span>

<hr/>

<h2>Pesquisa binária</h2>

<span>A pesquisa binária divide a lista em partes, onde começa verificando o elemento do meio, se não encontrar ele na primeira vez, irá verificar se o elemento está à direta do elemento a ser buscado ou à esquerda, assim, irá repetir o processo de verificação e divisão da lista até encontrar o elemento de busca no meio da lista. O custo desse tipo de pesquisa é relativamente baixo:</span>


<p></p>

<ul>
    <b>
      <li>Complexidade do espaço de pior caso: O(1)</li>
      <li>No melhor caso: O(1)</li>
      <li>Desempenho no pior caso: O(log n)</li>
      <li>Desempenho médio: O(log n)</li>
    </b>
</ul>

<hr/>

## Projeto

__Para executar o projeto, faça um clone do repositório com:__

```shell
git clone https://gitlab.com/ueiciowr/bubble-insert-select-sort-assignment.git
```

__Ou, baixe o projeto compactado, a partir do botão Download do GitLab.__

---

__O projeto foi criado com o Maven, a partir do Visual Studio Code, para executar baixe as seguintes dependências:__

- [Visual Studio Code](https://code.visualstudio.com)

- [Java Extension Pack](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack)

- [Language Support for Java(TM) by Red Hat](https://marketplace.visualstudio.com/items?itemName=redhat.java)

- [Java Language Support](https://marketplace.visualstudio.com/items?itemName=georgewfraser.vscode-javac)


---

#### Configure o path do java no Visual Studio Code, nas Settings, procure por __`Java Home`__, ou adicione nas settings.json o seguinte código, com o referente path para o Java Development Kit:

```json
{
  "java.home": "C:\\Program Files\\Java\\jdk1.8.0_231",
}
```

---

__Feito isso, o projeto estará no caminho:__

```text
java/main/src/binary-search
```

---

__Deverá aparecer, na classe principal `OrdenaObjetoApp`, logo abaixo do nome da classe, `run` e `debug`. Execute, run!__
