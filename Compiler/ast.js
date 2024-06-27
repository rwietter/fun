/**
 * A AST é uma árvore que representa a estrutura do código fonte.
 */

const parser = (tokens) => {
	let pointer = 0;

	const peek = () => tokens[pointer];
	const prev = () => tokens[pointer - 1];

	const match = (t) => {
		if (peek().type == t) {
			pointer++;
			return true;
		}
		return false;
	};

	const expr = () => {
		return add();
	};

	const add = () => {
		let result = mul();
		// (Plus mul)* -> Zero ou mais vezes
		while (match("Plus") || match("Minus")) {
			if (prev().type === "Plus") result += mul();
			if (prev().type === "Minus") result -= mul();
		}
		return result;
	};

	const mul = () => {
		let result = una();
		// (Star num)* -> Zero ou mais vezes
		while (match("Star") | match("Slash")) {
			if (prev().type === "Star") result = result * num();
			if (prev().type === "Slash") result = result / num();
		}
		return result;
	};

	const num = () => {
		if (match("Number")) {
			return prev().value;
		}
		throw new Error("Unexpected token: " + peek().type);
	};

	const prim = () => {
		if (match("Number")) {
			return prev().value;
		}

		if (match("LeftParen")) {
			const result = expr();
			if (match("RightParen")) {
				return result;
			}
			throw Error("Syntax Error: Expecting closing paren");
		}
	};

	const una = () => {
		if (match("Plus") || match("Minus")) {
			if (prev().type === "Plus") return +una();
			if (prev().type === "Minus") return -una();
		}
		// una | num
		return prim();
	};

	return expr();
};

/**
 * Recursive Descend Parser: permite decompor expressões complexas utilizando recursividade.
 */

/**
 * Grammar: é um conjunto de regras que definem a estrutura da linguagem, precedência e associatividade dos operadores.
 *
 * expr → add
 * add  → mul ((PLUS | MINUS) mul)*
 * mul  → una ((STAR | SLASH) una)*
 * una  → ((PLUS | MINUS) una) | num
 * num  → NUMBER
 */

export default parser;
