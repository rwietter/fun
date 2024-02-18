#!/bin/bash

echo "Please enter your age:"
read age

if [ "$age" -lt 18 ]; then
    echo "You are a minor."
    elif [ "$age" -ge 18 ] && [ "$age" -lt 65 ]; then
    echo "You are an adult."
else
    echo "You are a senior citizen."
fi

# -lt: Menor Que
# Sintaxe: if [ "$valor1" -lt "$valor2" ]; then

# -ge: Maior ou Igual a
# Sintaxe: if [ "$valor1" -ge "$valor2" ]; then

# -eq: Igual a
# Sintaxe: if [ "$valor1" -eq "$valor2" ]; then

# -ne: Diferente de
# Sintaxe: if [ "$valor1" -ne "$valor2" ]; then

# -le: Menor ou Igual a
# Sintaxe: if [ "$valor1" -le "$valor2" ]; then

# -gt: Maior Que
# Sintaxe: if [ "$valor1" -gt "$valor2" ]; then