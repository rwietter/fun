type boolStr = boolean | string;

function useState<S extends boolStr = boolean>() {
  let state: S;
  function setState(newState: S) {
    state = newState
  }
  function getState() {
    return state
  }
  return { setState, getState }
}
const state = useState<boolean | string>();
state.setState(false)
console.log(state.getState());
state.setState('super hero')
console.log(state.getState());

/* -------------------------------------------- */
/* Tipoa de generics
/* -------------------------------------------- */
/*
Representam um conjunto de tipos - mas que são
definidos pela primeira inferência:
 S => State
 T => Type
 K => Key
 V => Value
 E => Element

 Quando não definido na chamada, o tipo é unknown:

 function useState<unknown>(): {
  setState: (newState: unknown) => void;
  getState: () => unknown;
}

resolvemos definindo o tipo na chamada:
const state = useState<boolean>();

Porém, o tipo definido na chamada pode mudar, então,
precisamos de um extends nos tipos que iremos utilizar:
function useState<S extends boolean | string>() {}

Colocando uma como padrão:

*/
