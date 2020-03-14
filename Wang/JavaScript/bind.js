Function.prototype.myBind = function(context) {
  let args = arguments.slice(1);
  // 保存当前的函数
  let func = this;
  var returnFunc = function() {
    // 将两次获取到的参数合并
    Array.prototype.push.apply(args, arguments);
    // 使用apply改变上下文
    return func.apply(this instanceof returnFunc ? this : context, args);
  };
  returnFunc.prototype = new func();
  return returnFunc;
};
