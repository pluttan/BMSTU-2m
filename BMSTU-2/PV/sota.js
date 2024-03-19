function setup() {
  createCanvas(1200, 1200);
  strokeWeight(3);
}
function draw() {
  drawSota();
}
function mousePressed() {
  sotaPressed();
}
function drawSota() {
  let k = 20;
  for (let j = 0; j < 7; j++) {
    let y = 70 * j;
    for (let i = 0; i < 7 - (j % 2); i++) {
      let x = 120 * i + 60 * (j % 2);
      line(x, 35 + y, x + k, y);
      line(x + k, y, x + 100, y);
      line(x + 100, y, x + 100 + k, 35 + y);
      line(x + 100 + k, 35 + y, x + 100, 70 + y);
      line(x + 100, 70 + y, x + k, 70 + y);
      line(x + k, 70 + y, x, 35 + y);
    }
  }
}
let sotasP = 0;
function sotaPressed() {
  //   point(mouseX, mouseY);
  fill(255);
  let k = 20;

  for (let j = 0; j < 7; j++) {
    let y = 70 * j;
    for (let i = 0; i < 7 - (j % 2); i++) {
      let x = 120 * i + 60 * (j % 2);
      if (mouseX > x && mouseY > y && mouseX < x + 120 && mouseY < y + 70) {
        if (sotasP != 0) {
          line(x + 60, y + 35, sotasP[0], sotasP[1]);
        }
        strokeWeight(9);
        line(x, 35 + y, x + k, y);
        line(x + k, y, x + 100, y);
        line(x + 100, y, x + 100 + k, 35 + y);
        line(x + 100 + k, 35 + y, x + 100, 70 + y);
        line(x + 100, 70 + y, x + k, 70 + y);
        line(x + k, 70 + y, x, 35 + y);
        sotasP = [x + 60, y + 35];
        strokeWeight(3);
      }
    }
  }
}
