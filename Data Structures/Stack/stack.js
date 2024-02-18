const log = console.log
  
const stackfn = () => {
  let stack = [];
  const push = (item) => stack = [item, ...stack];
  const size = () => stack.length;
  const pop = () => stack = stack.slice(1);
  const isEmpty = () => !size()
  const display = () => stack;
  return { push, pop, size, isEmpty, display, stack}
}

const stack = stackfn();

log('isEmpty: ', stack.isEmpty());

stack.push(1);
log('isEmpty: ', stack.isEmpty());
stack.push(2);
stack.push(3);
stack.push(4);
stack.push(5);
stack.push(6);
log(stack.display())

log(`size: ${stack.size()}`);

stack.pop();

log(stack.display())

stack.pop();

log(`size: ${stack.size()}`);

log(stack.display())

/*

  isEmpty:  true
  isEmpty:  false
  [ 6, 5, 4, 3, 2, 1 ]
  size: 6
  [ 5, 4, 3, 2, 1 ]
  size: 4
  [ 4, 3, 2, 1 ]

*/
