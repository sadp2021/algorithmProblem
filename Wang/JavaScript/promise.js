class Promise {
  constructor(fn) {
    this.state = 'pending';
    this.value = undefined;
    this.reason = undefined;

    let resolve = value => {
      if (this.state === 'pending') {
        //启动
        this.value = value;
        this.state = 'fulfilled'; //完成
      }
    };

    let reject = value => {
      if (this.state === 'pending') {
        //启动
        this.value = value;
        this.state = 'rejected'; //失败
      }
    };

    try {
      fn(resolve, reject);
    } catch (error) {
      reject(error);
    }
  }

  then(onFulfilled, onRejected) {
    switch (this.state) {
      case 'fulfilled':
        onFulfilled();
        break;
      case 'rejected':
        onRejected();
        break;
    }
  }
}
