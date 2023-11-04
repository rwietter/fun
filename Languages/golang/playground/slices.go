package main

import "fmt"

type Product struct {
	ID   int
	Name string
}

type Products struct {
	products []Product
}

func addProduct(p Product, prod *Products) {
	prod.products = append(prod.products, p)
}

func main() {
	products := Products{}
	product1 := Product{ID: 1, Name: "Apple"}
	product2 := Product{ID: 2, Name: "Orange"}
	addProduct(product1, &products)
	addProduct(product2, &products)

	for _, product := range products.products {
		fmt.Printf("ID: %d, Name: %s\n", product.ID, product.Name)
	}
}
