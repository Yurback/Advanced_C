function sqrt_time() {
  let start = performance.now();
  performance.now();
  let x;
  for (let i = -2000000000; i < 2000000000; i++) {
    x = Math.sqrt(20);
    // if (i == 1999999999) console.log("i am done");
  }
  let end = performance.now();
  console.log(end - start);
}

sqrt_time();
