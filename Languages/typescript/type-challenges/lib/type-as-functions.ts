// ----------------------------------------------------------------
// Type Expression
// ----------------------------------------------------------------

type OnlyStringOrNumber<T> = T extends string ? string : number;
/*
  const OnlyStringOrNumber = (T) => {
    if(T extends string) {
      return string
    }
    return number
  }
*/

// ----------------------------------------------------------------
// Mapped types
// ----------------------------------------------------------------
type MappedType = { [K in string as `get${K}`]: () => string }

/*
type mapped = (K) => {
  for(K in Keys) {
    return {
      key: `get${K}`,
      value: type() => string
    }
  }
}
*/

const data: MappedType = {
  get: () => 'string',
}
