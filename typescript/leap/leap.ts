const yearFactor = (year: number, factor: number): boolean => {
    const isYearDivisibleTo = year % factor === 0;
    return isYearDivisibleTo;
}

const isLeapYear = (year: number): boolean => {
    return yearFactor(year, 4) && year % 100 !== 0 || yearFactor(year, 400) ? true : false;
}

export default isLeapYear
