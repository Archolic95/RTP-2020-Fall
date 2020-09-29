let choices = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11];
let palette = {
  1: "rgb(238, 58, 67)",
  2: "rgb(242, 99, 91)",
  3: "rgb(253, 184, 19)",
  4: "rgb(246, 145, 93)",
  5: "rgb(42, 190, 216)",
  6: "rgb(27, 63, 149)",
  7: "rgb(254, 241, 111)",
  8: "rgb(252, 203, 163)",
  9: "rgb(241, 148, 192)",
  10: "rgb(230, 14, 99)",
  11: "rgb(0, 131, 201)"
};
let unitX = 20;
let unitY = 40;
let fr = 5;

function setup() {
  createCanvas(400, 600);
  frameRate(fr);
  background(255);
}

function draw() {
  for (let i = 0; i < 350; i += 50) {
    for (let j = -100; j < 800; j += 100) {
      let r = random(choices);
      let rcolor = color(palette[r]);
      noStroke();
      if (j % 200 == 0) {
        if (i == 0) {
          let r2 = random(choices);
          let rcolor2 = color(palette[r2]);
          beginShape(TRIANGLES);
          fill(rcolor2);
          vertex(i, j);
          vertex(i + 50, j + 100);
          vertex(i, j + 200);
          endShape();
        }
        beginShape(TRIANGLES);
        fill(rcolor);
        vertex(i, j);
        vertex(i + 50, j + 100);
        vertex(i + 100, j + 100);
        vertex(i + 100, j + 100);
        vertex(i + 50, j + 100);
        vertex(i, j + 200);
        endShape();
      } else {
        if (i == 300) {
          let r2 = random(choices);
          let rcolor2 = color(palette[r2]);
          beginShape(TRIANGLES);
          fill(rcolor2);
          vertex(i + 50, j + 100);
          vertex(i + 100, j);
          vertex(i + 100, j + 200);
          endShape();
        }
        beginShape(TRIANGLES);
        fill(rcolor);
        vertex(i + 100, j);
        vertex(i, j + 100);
        vertex(i + 50, j + 100);
        vertex(i + 50, j + 100);
        vertex(i, j + 100);
        vertex(i + 100, j + 200);
        endShape();
      }
    }
  }


}