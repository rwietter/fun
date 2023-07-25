interface Bird {
  fly(): void;
	layEggs(): void;
}

interface Fish {
	swim(): void;
  layEggs(): void;
}

const fly = () => {}
const swim = () => {}
const layEggs = () => {}

const aPet = (): Partial<Bird> | Partial<Fish> => {
	return {
    layEggs
	}
}


const { layEggs: eggs  } = aPet()
