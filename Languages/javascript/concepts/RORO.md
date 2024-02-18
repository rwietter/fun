## Receive an object, return an object (RORO)

Esse padrão é muito bom pois não importa a ordem que os parâmetros são passados, pois os argumentos serão desestruturados.

```js
function findUsersByRole({ role, withContactInfo, includeInactive}) {...}
```

O padrão RORO prevê que um objeto seja retornado

```js
function identity({ id, firstName, lastName, ...rest }) {
  return {
    id,
    firstName,
    lastName,
    ...rest,
  };
}
```
