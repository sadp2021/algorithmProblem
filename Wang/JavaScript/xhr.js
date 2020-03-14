let xhr = new XMLHttpRequest();

// 初始化配置请求
xhr.setRequestHeader('Content-Type', 'application/json'); //设置请求头
xhr.open(method, url, async);
// 配置请求体发送到服务器
xhr.send(data);
xhr.onreadystatechange = () => {
  // 0: 刚刚创建好了请求对象，但还未配置请求（未调用open方法）
  // 1: open方法已被调用
  // 2: send方法已被调用
  // 3: 正在接收服务器的响应消息体
  // 4: 服务器响应的所有内容均已接收完毕

  // xhr.responseText： 获取服务器响应的消息体文本

  // xhr.getResponseHeader("Content-Type") 获取响应头Content-Type
  if (xhr.readyState === 4 && xhr.status === 200) {
    // 成功接受
    console.log(xhr.responseText);
  }
};
