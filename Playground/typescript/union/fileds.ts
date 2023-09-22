interface Bird {
  fly(): void;
  layEggs(): void;
}

interface Fish {
  swim(): void;
  layEggs(): void;
}

declare function getSmallPet(): Fish | Bird; // [Fish: layEggs(): void] and [Bird: layEggs(): void] => Union

let pet = getSmallPet();
pet.layEggs();

pet.swim(); // swim isn't contained in Bird 
pet.fly(); // swim isn't contained in Fish 
