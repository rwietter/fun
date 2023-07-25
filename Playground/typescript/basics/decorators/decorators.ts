/*
 @Component
 @Selector
 @useState(data)

 * Decorators são uma notação que pode ser usada em classe, propriedade, parametro, método ou acesso.
 * Ele trabalha em cima de onde foi declarado, para que se possa adicionar coisa novas, validações e funções
 * Um decorator retorna um constructor.
*/

/* -------------------------------------------- */
/* Class decorator
/* -------------------------------------------- */
function log(prefix: string) {
  return (_target: Foo) => {
    console.log(`${prefix} and ${_target}`)
    /*
      awesome and function Foo() {}
    */
  }
}

@log('awesome')
class Foo {}

// Other exemple

function setAPIversion(version: string) {
  return (constructor: any) => {
    return class extends constructor{
      newVersion = version;
    }
  }
}
@setAPIversion('v1.0.1:latest')
class API {}
console.log(new API()); // class_1 { newVersion: 'v1.0.1:latest' }

/* -------------------------------------------- */
/* Atributes decorator | validations
/* -------------------------------------------- */
function titleValidation(len: number) {
  return (targ: any, key: string) => {
    let validationIndex = targ[key]

    const getter = () => validationIndex
    const setter = (value: string) => {
      if (value.length < len)
        console.log(`${value} não pode ser menor do que ${len}`);
      else
        validationIndex = value
    }
    Object.defineProperty(targ, key, {
      get: getter,
      set: setter
    })
  }
}

class Movie {
  @titleValidation(5)
  title!: string;

  constructor(title: string) {
    this.title = title
  }
}
console.log(new Movie('Interestellar').title);
console.log(new Movie('Park').title);

/* -------------------------------------------- */
/* Method decorator
/* -------------------------------------------- */

function delay(ms: number) {
  return (Prototype: any, key: string, descriptor: PropertyDescriptor) => {
    let originalMethod = descriptor.value;
    descriptor.value = function (...args: any) {
      console.log(`Esperando.... ${ms}`)
      setTimeout(() => {
        originalMethod.apply(this, args)
      }, ms)
    }
    return descriptor
  }
}

class Greeter {
  greeting!: string

  constructor(greeting: string) {
    this.greeting = greeting;
  }

  @delay(5000)
  greet() {
    console.log('5000....')
    console.log(`Hello ${this.greeting}!`);
  }
}

let greet = new Greeter('Iron Man').greet()
console.log(greet)
