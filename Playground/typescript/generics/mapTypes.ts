type FormatURLs = {
  format360p: URL;
  format480p: URL;
  format720p: URL;
  format1080p: URL;
};

type Split = {
  [P in keyof FormatURLs]: P;
};

/* ──────────────────────────────────
Equivalent to ───────────────────────
  type Split = {
    format360p: “format360p”,
    format480p: "format480p”,
    format720p: “format720p”,
    format1080p: “format1080p”
  }
────────────────────────────────────*/

type SplitType<T extends object> = {
  [P in keyof T]: Record<P, T[P]>
} [keyof T];

type AvailableFormats = SplitType<FormatURLs>;

const uri: AvailableFormats = {
  format720p: new URL("https://www.youtube.com/watch?v=sdPXVQTbvsA"),
};  