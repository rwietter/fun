class Transcriptor {
    toRna(geneticCode: string): string {
        const dnaNucleotides = ['G', 'C', 'T', 'A'];
        const rnaNucleotides = ['C', 'G', 'A', 'U'];
        
        const nucleotides: string[] = this.dnaUpper(geneticCode)

        const dnaMapped = nucleotides.map((dna, idx) => {
            if (!dnaNucleotides.includes(dna)) throw new Error('Invalid input DNA.');
            const dnaIdx = dnaNucleotides.indexOf(nucleotides[idx])
            dna = rnaNucleotides[dnaIdx]
            return dna;
        }, '')
        
        const rna = this.rnaJoin(dnaMapped)
        return rna;
    }
        
    private dnaUpper(geneticCode: string): string[] { return [...geneticCode.toUpperCase()] }
    
    private rnaJoin(rna: string[]): string { return rna.join('').toString() }
}

export default Transcriptor
