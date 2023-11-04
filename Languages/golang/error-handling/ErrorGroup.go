package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/davecgh/go-spew/spew"
	"golang.org/x/sync/errgroup"

	"errors"
)

func main() {
	eg := errgroup.Group{}

	eg.Go(func() error {
		resp, err := getPage("https://blog.kennycoder.io")
		spew.Dump(resp.Header)
		return err
	})

	eg.Go(func() error {
		_, err := getPage("https://blog.kennycoder.io/2020/01/01/first-post")
		return err
	})

	if err := eg.Wait(); err != nil {
		log.Fatalf("get error: %v", err)
	}
}

func getPage(url string) (*http.Response, error) {
	resp, err := http.Get(url)

	if err != nil {
		return nil, errors.New(fmt.Sprintf("fail to get page: %s, error: %v", url, err))
	}

	if resp.StatusCode != http.StatusOK {
		return nil, errors.New(fmt.Sprintf("fail to get page: %s, wrong statusCode: %d", url, resp.StatusCode))
	}

	return resp, nil
}
