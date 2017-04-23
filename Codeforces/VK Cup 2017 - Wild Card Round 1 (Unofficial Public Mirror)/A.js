function test(line1, s, len) {
  var ans = 0;
  for(var i = 0; i < line1[0]; ++i) {
    var qtd = 0;
    var exist = false;
    for(var j = 0; j < len && j + i < line1[0]; ++j) {
      qtd++;
      if(s[j] ==  '1') exist = true;
    }
    if(exist == false) return -12341231;
    ans += (qtd - 1) * (qtd - 1) * line1[2] + line1[1];
  }
  return ans;
}


var line1 = readline().split(' ');
var s = readline();

var lo = 0, hi = line[1];

while(lo < hi) {
  var r = Math.floor((hi - lo) / 3);
  var m1 = lo + r;
  var m2 = hi - r;
  if(test(line1, s, m1) > test(line1, s, m2)) hi = m2;
  else lo = m1;
}

print(test(line1, s, lo));

