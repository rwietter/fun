package main

import "fmt"

type InsertionSort struct {
	Values []int
}

/*
[Book]: Cormen, Thomas H., org. Introduction to Algorithms. 3rd ed. Cambridge, Mass: MIT Press, 2009.
[Exercise]: 2.1 Insertion sort
[Description]: <Insertion sort works the way many people sort a hand of playing cards. We start with an empty left hand and the cards face down on the table. We then remove one card at a time from the table and insert it into the correct position in the left hand. To ﬁnd the correct position for a card, we compare it with each of the cards already in the hand>
*/
func (Data InsertionSort) insertionSort() []int {
	A := Data.Values
	for currentIndex := 1; currentIndex < len(A); currentIndex++ {
		elementToInsert := A[currentIndex]
		previousIndex := currentIndex - 1

		// Move elementos maiores que elementToInsert uma posição à frente
		for previousIndex >= 0 && A[previousIndex] > elementToInsert {
			A[previousIndex+1] = A[previousIndex]
			previousIndex--
		}

		// Insere o elemento na posição correta
		A[previousIndex+1] = elementToInsert
	}
	return A
}

func main() {
	data := InsertionSort{
		Values: []int{5, 3, 4, 1, 2, 43, 0, 93454, 2, -10},
	}
	fmt.Println(InsertionSort.insertionSort(data))
}
