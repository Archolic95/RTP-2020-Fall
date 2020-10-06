width = 1500;
height = 300;
let xArray = [0];
let yArray = [height / 2];
let wArray = [2];

function setup() {
  createCanvas(1500, 300);
}

function draw() {
  background(0);
  let x = xArray[xArray.length - 1];
  let y = yArray[yArray.length - 1];
  stroke(255);
  strokeCap(PROJECT);
  const r = ceil(randomGaussian(4, 2));
  //console.log(r);
  let w = 4 - abs(r - randomGaussian(1.5, 0.5));
  if (w <= 0) w = 0.5;
  const d = randomGaussian(5, 30);
  switch (r) {
    case 0:
      if (y + d > height) {
        y += (height - y);
        x -= (height - y);
      } else {
        x = x - d;
        y = y + d;
      }
      break;
    case 1:
      if(x - d < 0) x = x + d;
      else x = x - d * 0.5;
      break;
    case 2:
      x = x + d;
      break;
    case 3:
      if (y + d > height) {
        y += height - y;
        x += height - y;
      } else {
        x = x + d;
        y = y + d;
      }
      break;
    case 4:
      if (y - d < 0) {
        y -= y - height;
        x += y - height;
      } else {
        x = x + d;
        y = y - d;
      }
      break;
    case 5:
      y = y - d;
      break;
    case 6:
      y = y + d;
      break;
    case 7:
      if (y - d < 0) {
        y -= y - height;
        x -= y - height;
      } else {
        x = x - d;
        y = y - d;
      }
      break;

  }
  append(xArray, x);
  append(yArray, y);
  append(wArray, w);
  for (let i = 0; i < xArray.length - 2; i++) {
    beginShape(LINES);
    //console.log(i, xArray, yArray);
    strokeWeight(wArray[i + 1]);
    vertex(xArray[i], yArray[i]);
    vertex(xArray[i + 1], yArray[i + 1]);
    endShape();
  }

}