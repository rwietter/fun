## How to use

### 1. Install

```bash
git clone <this-repo>
cd <this-repo>
cargo build --release
```

- Case-insensitive: run `export IGNORE_CASE=1` to enable case-insensitive search.
- Unset `IGNORE_CASE` to disable case-insensitive search: `unset IGNORE_CASE`

### 2. Run

```bash
./ngrep <pattern> <file>
```
