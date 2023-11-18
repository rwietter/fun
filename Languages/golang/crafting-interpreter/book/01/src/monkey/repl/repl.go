package repl

import (
	"bufio"
	"fmt"
	"io"

	"lexer/src/monkey/lexer"
	"lexer/src/monkey/token"
)

const PROMPT = ">> "

func Start(in io.Reader, out io.Writer) {
	scanner := bufio.NewScanner(in)

	for {
		fmt.Printf(PROMPT)
		scanned := scanner.Scan()
		if !scanned {
			return
		}

		// Lê o input do usuário no REPL
		line := scanner.Text()

		// Cria um lexer para o input do usuário
		l := lexer.New(line)

		// Itera sobre os tokens do lexer e os imprime
		for tok := l.NextToken(); tok.Type != token.EOF; tok = l.NextToken() {
			fmt.Printf("%+v\n", tok)
		}
	}
}
