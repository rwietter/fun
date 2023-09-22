const comida: string[] = [
    "milk shake",
    "banana",
    "suco",
    "batata frita",
    "cachorro quente",
    "frango",
  ];

class PicPau {
  #comida: string[];
  #personagens: string[] = ["Pica-Pau", "Lobo"];

  constructor(comida: string[]) {
    this.#comida = comida;
  }

  comida(personagem: string, comida: string): void {
    console.log(`O ${personagem} recebeu ${comida}`);
  }

  distribuirComida(): void {
    // percorrer a lista de comida
    for (let i = 0; i < this.#comida.length; i++) {
      // Para cada comida que o Pica-Pau pegar, o lobo ganha de 0-n comidas que o Pica-Pau pegou
      // Ex: Pica-Pau pega milk shake, o lobo pega Banana; o Pica-Pau pega suco o lobo pega batata frita e cachorro quente
      // A contagem de comidas do lobo é reiniciada a cada comida que o Pica-Pau pega
      
      
    }
  }

}

const picapau = new PicPau(comida);

picapau.distribuirComida()