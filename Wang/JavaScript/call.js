Function.prototype.myCall = function(context = window) {
  context.fn = this;
  const args = arguments.slice(1);
  let res = context.fn(...args);
  delete context.fn;
  return res;
};

let foo = {
  value: 1
};
function bar(name, age) {
  console.log(name);
  console.log(age);
  console.log(this.value);
}
bar.myCall(foo, 'black', '18'); // black 18 1
