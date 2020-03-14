function deepCopy(obj) {
  if (typeof obj === 'object') {
    var res = obj.constructor == Array ? [] : {};
    for (let i in obj) {
      res[i] = typeof obj[i] == 'object' ? deepCopy(obj[i]) : obj[i];
    }
  } else {
    var res = obj;
  }
  return res;
}
