package main

import (
	"log"
	"net/http"

	"github.com/PuerkitoBio/goquery"
	"github.com/jung-kurt/gofpdf"
	"github.com/k3a/html2text"
)

func main() {
	url := "https://www.wikiwand.com/pt/Teoria_das_categorias"

	response, err := http.Get(url)
	if err != nil {
		log.Fatal(err)
	}

	defer response.Body.Close()

	html, err := goquery.NewDocumentFromReader(response.Body)

	log.Println(html.Selection.Text())

	plain := html2text.HTML2Text(html.Text())

	pdf := gofpdf.New("P", "mm", "A4", "")
	pdf.AddPage()
	pdf.SetFont("Arial", "B", 16)

	pdf.MultiCell(190, 5, plain, "", "0", false)

	err = pdf.OutputFileAndClose("output.pdf")
}
