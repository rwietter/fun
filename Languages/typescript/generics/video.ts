/**
 * ------------------- Format URL -------------------
 */
type VideoFormatURLs = {
  format360p: URL | string | object;
  format480p: URL | string | object;
  format720p: URL | string | object;
  format1080p: URL | string | object;
};

/**
 * ------------------- Share -------------------
 */

function isAvailable<Formats extends object>(
  obj: Formats,
  key: string | number | symbol
): key is keyof Formats {
  return key in obj;
}
 
/**
 * ─────────────── Subtitles ───────────────
 */
declare const subtitle: SubtitleURLs;

type SubtitleURLs = {
  english: URL | string;
  german: URL | string;
  french: URL | string;
};

// RESULT
type PartialFormatVideo = Partial<VideoFormatURLs>[];
let video = [] as PartialFormatVideo;

function loadFormat(
  fileFormat: PartialFormatVideo,
  format: keyof VideoFormatURLs
) {
  if (!isAvailable<PartialFormatVideo>(video, format)) {
    video.push(...fileFormat);
  }
}

loadFormat(
  [
    { format1080p: "https://www.youtube.com/watch?v=sdPXVQTbvsA" }
  ],
  "format1080p"
);

loadFormat(
  [
    { format720p: "https://www.youtube.com/watch?v=sdPXVQTbvsA" }
  ],
  "format1080p"
);

console.log(video);
