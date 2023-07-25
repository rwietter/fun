function foo1(...args: [string, number]): number[] {
  return args.map((item: number | string) => +item + 1);
}

function foo2(arg0: string, arg1: number): void {
  // ...
}

foo1('1', 4);
