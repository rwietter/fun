const handler = {
  get: () => () => handler.count = !('count' in handler) ? 1 : (handler.count + 1),
}

const proxy = new Proxy({}, handler);

if (proxy == 1 && proxy == 2 && proxy == 3) {
  console.log("Hello World");
}

