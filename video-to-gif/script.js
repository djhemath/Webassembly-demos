import { createFFmpeg, fetchFile } from '@ffmpeg/ffmpeg';

const ffmpeg = createFFmpeg({ log: true });
const videoInput = document.getElementById('videoInput');
const convertButton = document.getElementById('convertButton');
const gifOutput = document.getElementById('gifOutput');

async function loadFFmpeg() {
  await ffmpeg.load();
}

async function convertToGif(videoFile) {
  const videoFileName = videoFile.name;

  // Write the video file to the FFmpeg filesystem
  await ffmpeg.FS('writeFile', videoFileName, await fetchFile(videoFile));

  // Run FFmpeg command to convert video to GIF
  await ffmpeg.run(
    '-i', videoFileName,       // Input file
    '-vf', 'fps=10,scale=320:-1', // Video filter: 10 frames per second, width 320px (height auto)
    '-c:v', 'gif',             // Output format: GIF
    'output.gif'               // Output file name
  );

  // Read the output GIF file
  const data = ffmpeg.FS('readFile', 'output.gif');

  // Convert the data to a URL and display the GIF
  const gifBlob = new Blob([data.buffer], { type: 'image/gif' });
  const gifUrl = URL.createObjectURL(gifBlob);
  gifOutput.src = gifUrl;
}

convertButton.addEventListener('click', () => {
  const videoFile = videoInput.files[0];
  if (videoFile) {
    convertToGif(videoFile);
  } else {
    alert('Please select a video file first!');
  }
});

// Load FFmpeg when the page is ready
loadFFmpeg();