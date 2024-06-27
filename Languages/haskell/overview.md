## Package Management

### Cabal

Cabal is the standard package manager for Haskell. It is used to install and manage Haskell packages. It is also used to build and install Haskell packages from source.

#### Create a new project

To create a new project, run the following command:

```bash
cabal init
cabal init --interactive
```

The `cabal init` command will create a new project in the current directory. The `--interactive` flag will prompt you for additional information.

#### Run a project

To run a project, run the following command:

```bash
cabal run
```

#### Build a project

To build a project, run the following command:

```bash
cabal build
```

#### Install a package

To install a package, run the following command:

```bash
cabal install <package-name>
```

#### Update package list

To update the package list, run the following command:

```bash
cabal update
```
