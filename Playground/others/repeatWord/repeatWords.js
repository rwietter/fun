function isRepeat(str) {
  return !/(.).*\1/.test(str);
}

console.log(!isRepeat('AAAAAAAAA'));
console.log(!isRepeat('carlos'));
