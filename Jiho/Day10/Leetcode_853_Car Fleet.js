var carFleet = function (target, position, speed) {
  const len = position.length;
  // position, speed 데이터 합치기
  let data = [];
  for (let i = 0; i < len; i++) {
    data.push([position[i], speed[i]]);
  }
  data.sort((a, b) => a[0] - b[0]);
  console.log(data);

  let max_time = (target - data[len - 1][0]) / data[len - 1][1];

  let answer = 0;
  let pos = [data[len - 1][0]];
  for (let i = len - 1; i >= 0; i--) {
    const time = (target - data[i][0]) / data[i][1];
    if (time <= max_time) {
      continue;
    } else if (time > max_time) {
      answer += 1;
      pos = [];
      max_time = time;
    }
    pos.push(data[i][0]);
  }
  if (pos.length !== 0) answer += 1;
  return answer;
};

console.log(carFleet(100, [0, 2, 4], [4, 2, 1]));
