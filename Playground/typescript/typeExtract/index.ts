type Languages = "JavaScript" | "TypeScript" | "Elixir";

interface Projects {
  name: string;
  description: string;
  languages: Languages;
}

type Id = string;

interface Project {
  id: Id;
  name: string;
  description: string;
  languages: Languages;
  members: Array<Id>; // => Id[]
}


// Extrair as propriedades compartilhadas entre as interfaces
// SharedKeys = "name" | "description" | "languages"
type SharedKeys = Extract<keyof Projects, keyof Project>; // => type Extract<T, U> = T extends U ? T : never

/*
  K será cada uma das keys de SharedKeys e seu tipo será igual a propriedade correspondente em Project[k].
  Quando k for "name", Project[k] vai ser uma string e assim será com todas as outras propriedades.

  type SharedProjectData = {
    name: string;
    description: string;
    languages: Languages;
  }

  SharedProjectKeys, também, pode ser representado desta forma
  type SharedProjectKeys<T, U> =[K in Extract<keyof T, keyof U>]: T[K];
*/
type SharedProjectKeys = {
  /* [Key in SharedKeys] é do tipo:
      name: string;
      description: string;
      languages: Languages;
   */
  [K in SharedKeys]: Project[K]; // => Key = "name" | "description" | "languages"
};

const projectData: SharedProjectKeys = {
  name: "discovering-typescript",
  languages: 'Elixir',
  description: "help people to understand key concepts of typescript",
};

display(projectData);
