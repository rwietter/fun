## Maybe

Maybe é um tipo de dados que representa um valor que pode ou não estar presente. Ele possui dois construtores:

- Just a: Representa a presença de um valor do tipo a.
- Nothing: Representa a ausência de um valor.

É útil quando você quer indicar que uma operação pode não retornar um valor significativo, mas não precisa fornecer informações detalhadas sobre por que falhou.


## Either

Either é um tipo de dados mais genérico que pode representar dois tipos de resultados possíveis. Ele possui dois construtores:

- Left a: Geralmente usado para representar um erro ou resultado inesperado, onde a é o tipo do erro.
- Right b: Geralmente usado para representar um resultado correto ou esperado, onde b é o tipo do valor.

Either é útil quando você quer fornecer mais informações sobre o erro, como um código de erro ou uma mensagem.
