/* ────────────────────────────────────
  ───── create a map of URL like: ─────
  type URLObject = {
    [x: string]: URL;
  }

  -> (property) google: URL
────────────────────────────────────── */
type URLObject = Record<string, URL>;

const urls: URLObject = {
  google: new URL("https://google.com.br/"),
}