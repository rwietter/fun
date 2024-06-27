/**
 * Essa etapa percorre todo o código e transforma e separa
 * cada caractere em um token.
 */

const lexer = (input) => {
	let tokens = [];
	let pointer = 0;

	while (pointer < input.length) {
		let char = input[pointer];

		if (char === " ") {
			pointer++;
			continue;
		}

		if (char === "+") {
			tokens.push({ type: "Plus" });
			pointer++;
			continue;
		}

		if (char == "-") {
			tokens.push({ type: "Minus" });
			pointer++;
			continue;
		}

		if (char == "*") {
			tokens.push({ type: "Star" });
			pointer++;
			continue;
		}

		if (char == "/") {
			tokens.push({ type: "Slash" });
			pointer++;
			continue;
		}

		if (char == "(") {
			tokens.push({ type: "LeftParen" });
			pointer++;
			continue;
		}

		if (char == ")") {
			tokens.push({ type: "RightParen" });
			pointer++;
			continue;
		}

		if (/[0-9]/.test(char)) {
			let value = "";
			while (/[0-9]/.test(char)) {
				value += char;
				pointer++;
				char = input[pointer];
			}
			tokens.push({ type: "Number", value: parseInt(value) });
			continue;
		}

		throw new Error(`Unexpected char ${char}`);
	}
	tokens.push({ type: "EOF" });
	return tokens;
};

export default lexer;
