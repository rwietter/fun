const icons = {
  Home: {
    lib!: "ant",
    name!: "home",
  },
};

const objectName = Object.keys(icons)[0].toString();

const { lib: Icon, name } = icons[objectName]!;

console.log(Icon, name);
