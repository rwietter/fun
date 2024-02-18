#!/usr/bin/env bash

repos=(
	"git@github.com:rwietter/covid-19-insights.git"
	"git@github.com:rwietter/jhonny.git"
)

for repo in ${repos[@]}; do
  git clone $repo
done