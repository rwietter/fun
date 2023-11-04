/* -------------------------------------------- */
/* Definindo um conjunto de types com optional operator
/* -------------------------------------------- */
type AccountInfo = {
  id: number;
  name: string;
  email?: string; // ? optional operator
}

const account: AccountInfo = {
  id: 1345,
  name: "Robert Ford",
}

/* -------------------------------------------- */
/* Definindo um outro conjunto de types
/* -------------------------------------------- */
type CharInfo = {
  nickname: string;
  level?: number;
}

const charAccount: CharInfo = {
  nickname: "_ford",
  level: 20
}

/* -------------------------------------------- */
/* Fazendo a intersecção de dois types
/* -------------------------------------------- */
type PlayerInfo = AccountInfo & CharInfo

const playerInfo: PlayerInfo = {
  id: 54,
  name: "Robert",
  nickname: '_ford'
}

console.log(playerInfo) // { id: 54, name: 'Robert', nickname: '_ford' }
