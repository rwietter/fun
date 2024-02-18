# Tooling

## Create new Project

```bash
mix new <project-name>
```

## Run project in IEX

```bash
iex -S mix # So, you can use all the functions in the project: Hello.hello
```

## Run fast refresh

```bash
mix run --no-halt
```

## Get dependencies

```bash
mix deps.get
```

## Build project

```bash
mix escript.build
```

## Release project

The release is a folder with all the dependencies and the executable file. It can be run in any machine with the same OS.

```bash
mix release 
```