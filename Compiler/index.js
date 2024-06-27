import lexer from "./lexer.js";
import parser from "./ast.js";

console.log("2 + 3 * 4 =", parser(lexer("2 + 3 * 4")));
console.log("4 * 3 + 2 =", parser(lexer("4 * 3 + 2")));
console.log("(4 + 3 * 2) + 2 =", parser(lexer("(4 + 3 * 2) + 2")));
