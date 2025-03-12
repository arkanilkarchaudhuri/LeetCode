/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number}
 */
var maxScore = function(nums1, nums2, k) {
    let res = 0,
    prefixSum = 0,
    minHeap = new MinHeap();

  const s = nums1
    .map((i, idx) => [i, nums2[idx]])
    .sort((a, b) => b[1] - a[1]);

  for (let i = 0; i < s.length; i++) {
    const [num1, num2] = s[i];
    prefixSum += num1;
    minHeap.push(num1);

    if (minHeap.size() === k) {
      const x = prefixSum * num2;
      res = Math.max(res, x);
      prefixSum -= minHeap.pop();
    }
  }

  return res;
};

class MinHeap {
  constructor() {
    this.heap = [];
  }

  size() {
    return this.heap.length;
  }

  isEmpty() {
    return this.size() === 0;
  }

  parent(i) {
    return Math.floor((i - 1) / 2);
  }

  leftChild(i) {
    return 2 * i + 1;
  }

  rightChild(i) {
    return 2 * i + 2;
  }

  swap(i, j) {
    [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
  }

  heapifyUp(i) {
    while (i > 0 && this.heap[this.parent(i)] > this.heap[i]) {
      this.swap(i, this.parent(i));
      i = this.parent(i);
    }
  }

  heapifyDown(i) {
    while (this.leftChild(i) < this.size()) {
      let minChild = this.leftChild(i);
      if (
        this.rightChild(i) < this.size() &&
        this.heap[this.rightChild(i)] < this.heap[minChild]
      ) {
        minChild = this.rightChild(i);
      }
      if (this.heap[i] <= this.heap[minChild]) {
        break;
      }
      this.swap(i, minChild);
      i = minChild;
    }
  }

  push(value) {
    this.heap.push(value);
    this.heapifyUp(this.size() - 1);
  }

  pop() {
    if (this.isEmpty()) {
      return null;
    }
    const min = this.heap[0];
    this.swap(0, this.size() - 1);
    this.heap.pop();
    this.heapifyDown(0);
    return min;
  }
}