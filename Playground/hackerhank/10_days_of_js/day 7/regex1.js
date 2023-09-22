function regexVar(str) {
  const re = /(Mr|Ms|Mrs|Dr|Er)(\.)\w*([a-zA-Z](?!.))/;
  const [pronoun] = str.match(re);
	return pronoun;
}
const { log } = console;

log(regexVar('Mr.jhosef'));
log(regexVar('Mr.x'));
log(regexVar('Mrs.carlos'));
log(regexVar('Ms.carlos'));
log(regexVar('Er.carlos'));
log(regexVar('Er.carlos'));
